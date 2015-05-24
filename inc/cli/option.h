/**
 * Pen++ Project
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

#include <iostream>
#include <functional>

#define option_callback function<void(string)>

using namespace std;

namespace cli {
	class Option {
	private:
		string name;
		string description;
		string param;
		option_callback callback;
		
	public:
		Option &setName(string _name) {
			name = _name;
			return *this;
		}
		
		Option &setDescription(string _desc) {
			description = _desc;
			return *this;	
		}
		
		Option setParam(string _param) {
			param = _param;
			return *this;
		}
		
		Option &setCallback(option_callback _callback) {
			callback = _callback;
			return *this;
		}
		
		string getName() {
			return name;
		}
		
		string getDescription() {
			return description;
		}
		
		string getParam() {
			return param;
		}
		
		option_callback getCallback() {
			return callback;
		}
	};
}
