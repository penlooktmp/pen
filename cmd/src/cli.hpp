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

#include <library/cmdline.hpp>
using namespace std;

class Cli
{
  protected:
  	cmdline::parser cli;

  public:
	template <class T>
	Cli addOption(const string &name,
           char short_name=0,
           const string &desc="") 
    {
        cli.add(name, short_name, desc);
        return *this;
    }

  	template <class T>
  	Cli addOption(const string &name,
           char short_name=0,
           const string &desc="",
           bool need=true,
           const T def=T()) 
    {
        cli.add<T>(name, short_name, desc, need, def);
        return *this;
  	}

  	template <class T, class F>
  	Cli addOption(const string &name,
           char short_name=0,
           const string &desc="",
           bool need=true,
           const T def=T(),
           F reader=F())
    {
        cli.add<T, F>(name, short_name, desc, need, def, reader);
        return *this;
	}
    
    Cli setName(const string &name)
    {
        cli.set_program_name(name);
        return *this;
    }
};