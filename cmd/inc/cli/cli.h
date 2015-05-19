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

#include "cmdline.h"
#include <functional>
#include <iostream>
#include <map>
#define cli_callback function<void(string)>

using namespace std;
using namespace cmdline;

class Cli {

  private:

  	parser cmd;
    map<string, cli_callback> func;
    map<string, string> argument;
    bool is_valid;

  public:

    map<string, cli_callback> getFunction() {
        return func;
    }
    
    map<string, string> getArgument() {
        return argument;
    }
    
	Cli &add(
           const string &name,
           const cli_callback &func_name,
           char  short_name = 0,
           const string &desc = "") {
        func[name] = func_name;
        cmd.add(name, short_name, desc);
        return *this;
    }

  	template <class T>
  	Cli &add(
           const string &name,
           const cli_callback &func_name,
           char  short_name = 0,
           const string &desc ="",
           bool  need = true,
           const T def = T()){
        func[name] = func_name;
        cmd.add<T>(name, short_name, desc, need, def);
        return *this;
  	}

  	template <class T, class F>
  	Cli &add(
           const string &name,
           const cli_callback &func_name,
           char  short_name = 0,
           const string &desc = "",
           bool  need = true,
           const T def = T(),
           F reader = F()) {
        func[name] = func_name;
        cmd.add<T, F>(name, short_name, desc, need, def, reader);
        return *this;
	}
    
    Cli &name(const string &name) {
        cmd.set_program_name(name);
        return *this;
    }

    Cli &parse(int argc, const char * const argv[]) {
        is_valid = cmd.parse(argc, argv);
        return *this;
    }

    bool valid() {
        return is_valid;
    }

    string error() const {
        return cmd.error();
    }

    string usage() const {
        return cmd.usage();
    }

    int size() {
        return cmd.rest().size();
    }

    void run();
    string get(string option_name);
};