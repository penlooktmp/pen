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

#include <cli/handler.hpp>

using namespace std;

// Controller
// Model
// View
void handler::create(string component) 
{
	cout << "Create new component";
}

// Unit test
// Benchmark
void handler::test(string type)
{
	cout << "Test pengo application";
}

// Build application
void handler::build(string mode)
{	
	cout << "Build application for production";
}

// Debug application components
void handler::debug(string mode)
{
	cout << "Debug mode";
}

// Run application under hot-code reload
void handler::run(string mode)
{	
	cout << "Run application under hot-code reload";
}

void handler::help(string doc)
{
	cout << "Pengo help !";
}
