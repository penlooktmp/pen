#include <sys/core.h>

template <typename T> const string typeof(T&) { return "unknown"; }
template<> const string typeof(int&) { return "int"; }
template<> const string typeof(short&) { return "short"; }
template<> const string typeof(long&) { return "long"; }
template<> const string typeof(unsigned&) { return "unsigned"; }
template<> const string typeof(unsigned short&) { return "unsigned short"; }
template<> const string typeof(unsigned long&) { return "unsigned long"; }
template<> const string typeof(float&) { return "float"; }
template<> const string typeof(double&) { return "double"; }
template<> const string typeof(long double&) { return "long double"; }
template<> const string typeof(string&) { return "string"; }
template<> const string typeof(char&) { return "char"; }
template<> const string typeof(signed char&) { return "signed char"; }
template<> const string typeof(unsigned char&) { return "unsigned char"; }
template<> const string typeof(char*&) { return "char*"; }
template<> const string typeof(signed char*&) { return "signed char*"; }
template<> const string typeof(unsigned char*&) { return "unsigned char*"; }
