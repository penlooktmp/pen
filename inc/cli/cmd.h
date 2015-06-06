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

#include <functional>
#include <iostream>
#include <map>
#include <vector>
#include <cli/option.h>

#define cli_callback function<void(string)>

using namespace std;

namespace cli {
    class Cmd {
    private:
        map<string, Option> options;
        string view;
        int argc;
        char **argv;

    public:
        Cmd(int, char* argv[]);
        Cmd &addOption(string, string, cli_callback);
        Cmd &setView(string);
        string getView();
        void run();
        void runOption(string name, string param);
    };
}