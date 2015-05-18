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

#include <limits.h>
#include <gtest/gtest.h>
#include <setup.hpp>

class SetupTest : public ::testing::Test {
	protected:
  	virtual void SetUp() {
  	}
  	virtual void TearDown() {
    }
};

TEST_F(SetupTest, setup){
    const int x = 4;
    const int y = 5;
    Addition addition;
    EXPECT_EQ(9, addition.twoValues(x,y));
    EXPECT_EQ(5, addition.twoValues(2,3));
}