/**
 * Author: Tiemo Jung
 * contact: tiemo dot jung at mni dot fh-giessen dot de
 * licencse: zlib Licencse
 * Copyright (c) 2013 Tiemo Jung
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented; you must not
 *  claim that you wrote the original software. If you use this software
 *  in a product, an acknowledgment in the product documentation would be
 *  appreciated but is not required.
 *
 *  2. Altered source versions must be plainly marked as such, and must not be
 *  misrepresented as being the original software.
 *
 *  3. This notice may not be removed or altered from any source
 *  distribution.
 */
#pragma once

#include <typeindex>
#include <type_traits>
#include <stdexcept>

template<size_t space = sizeof(int)
        ,size_t aligment = std::alignment_of<std::max_align_t>::value>
class any {
    enum class handler_mode {
        destruct,
        copy,
        move,
        get_type,
    };

    typedef typename std::aligned_storage<space,aligment>::type storage_type;
    typedef const std::type_info* (*handler_type)(void*,void*,handler_mode);

    storage_type            _store;
    handler_type            _handler;

    template<typename Type>
    static const std::type_info* type_handler(void* src,void* dst,handler_mode mode) {
        auto src_typed = reinterpret_cast<Type*>( src );
        auto dst_typed = reinterpret_cast<Type*>( dst );
        switch ( mode ) {
        case handler_mode::destruct:
            dst_typed->~Type();
            break;
        case handler_mode::copy:
            new (dst) Type(( *src_typed ));
            break;
        case handler_mode::move:
            new (dst) Type(std::move(( *src_typed )));
            break;
        case handler_mode::get_type:
            break;
        }
        return &typeid(Type);
    }

    void destruct() {
        if ( !empty() ) {
            _handler(&_store, &_store, handler_mode::destruct);
            _handler = nullptr;
        }
    }

    template<typename Type>
    bool is_matching_type() const {
        return ( _handler != nullptr ) && ( *_handler(nullptr,nullptr,handler_mode::get_type) == typeid(Type) );
    }

    template<typename Type>
    void assign(Type v_) {
        typedef typename std::aligned_storage<sizeof(Type),std::alignment_of<Type>::value>::type target_store_type;
        static_assert(sizeof(target_store_type) <= sizeof(storage_type),"inplace space is too smal to hold Type");
        destruct();
        _handler = &type_handler<Type>;
        type_handler<Type>( &v_, &_store, handler_mode::move );
    }
public:
    any() : _handler(nullptr) {}
    template<typename Type>
    any(Type v_) : _handler(nullptr) {
        assign(std::forward<Type>(v_));
    }
    any(const any& o_) : _handler(nullptr) {
        *this = o_;
    }
    any(any&& o_) : _handler(nullptr) {
        *this = std::move(o_);
    }

    bool empty() const { return _handler == nullptr; }
    const std::type_info& type() const {
        if ( _handler ) {
            return *_handler(nullptr,nullptr,handler_mode::get_type);
        } 
        return typeid(void);
    }

    template<typename Type>
    any& operator=(Type v_) {
        assign(std::forward<Type>(v_));
        return *this;
    }
    any& operator=(const any& o_) {
        destruct();
        _handler    = o_._handler;
        if ( _handler ) {
            _handler(&const_cast<any&>(o_)._store,&_store,handler_mode::copy);
        }
        return *this;
    }

    any& operator=(any&& o_) {
        destruct();
        _handler    = o_._handler;
        if ( _handler ) {
            _handler(&o_._store,&_store,handler_mode::move);
        }
        return *this;
    }

    template<typename Type>
    Type cast() const {
        if ( is_matching_type<Type>() ) {
            return *reinterpret_cast<const Type*>(&_store);
        }
        throw std::bad_cast("any::cast(): unable to cast type");
    }

    template<typename Type>
    const Type* cast_ptr() const {
        if ( is_matching_type<Type>() ) {
            return reinterpret_cast<const Type*>(&_store);
        }
        return nullptr;
    }

    template<typename Type>
    Type* cast_ptr() {
        if ( is_matching_type<Type>() ) {
            return reinterpret_cast<Type*>(&_store);
        }
        return nullptr;
    }
};

template<size_t space,size_t aligment>
inline void swap(any<space,aligment>& lhr,any<space,aligment>& rhs) {
    auto t = std::move(lhr);
    lhr = std::move(rhs);
    rhs = std::move(t);
}

template<typename Type,size_t space,size_t aligment>
inline Type any_cast(any<space,aligment>& operand) {
    return operand.cast<Type>( );
}

template<typename Type,size_t space,size_t aligment>
inline Type any_cast(const any<space,aligment>& operand) {
    return operand.cast<Type>( );
}

template<typename Type,size_t space,size_t aligment>
inline Type* any_cast(any<space,aligment>* operand) {
    return operand->cast_ptr<Type>( );
}

template<typename Type,size_t space,size_t aligment>
inline const Type* any_cast(const any<space,aligment>* operand) {
    return operand->cast_ptr<Type>();
}