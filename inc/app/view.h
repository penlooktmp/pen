/**
 * Pengo Project
 *
 * Copyright (c) 2015 Penlook Development Team
 *
 * --------------------------------------------------------------------
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 * --------------------------------------------------------------------
 *
 * Author:
 *     Loi Nguyen       <loint@penlook.com>
 */

#ifndef APP_VIEW_H_
#define APP_VIEW_H_

#include <sys/func.h>
#include <sys/type.h>
#include <iostream>
#include <string>
#include <typeinfo>

#define ViewList vector<View>
#define ViewValueHolder map<string, any>

namespace app
{
	class ViewData
	{
		private:
			ViewValueHolder valueHolder;
		public:
			// Set variable
			template <typename T>
			ViewData *set(string variable_, T const& value_)
			{
				this->valueHolder[variable_] = value_;
				return this;
			}
			
			template <typename T>
			ViewData *set(string variable_, T* value_)
			{
				this->valueHolder[variable_] = value_;
				return this;
			}

			// Get variable
			template <typename T>
			T& get(string variable_)
			{
				any v = this->valueHolder[variable_];
				return v.cast<T>();
			}
			// Value Holder
			ViewData *setValueHolder(ViewValueHolder);
			ViewValueHolder getValueHolder();
	};

	class View
	{
		private:
			char *content;
			ViewData *data;
		public:
			// public stream
			string stream;

			View();
			~View();
			// Data
			View *setData(ViewData*);
			ViewData *getData();
			// Content
			View *setContent(char*);
			View *appendContent(char*);
			char *getContent();
			char *getStream();
	};
}

#endif
