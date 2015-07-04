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

#include <app/test.h>
#include <func/core.h>

using namespace std;
using namespace app;

class StringBenmarkTest : public Test {};

TEST_F(StringBenmarkTest, count)
{
	int NUM = 10000;
	char** data2 = (char**) calloc(NUM + 1, sizeof(char*));
	for (int i=0; i<NUM; i++) {
		data2[i] = (char*) "test";
	}
	data2[NUM] = '\0';
	int times = 0;
	for (int i=0; i<10000; i++) {
		times += len(data2);
	}
	EXPECT_EQ(NUM*10000, times);
}