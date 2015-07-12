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
#include <sys/func.h>

using namespace std;
using namespace app;

class FuncTest : public Test {};

TEST_F(FuncTest, md5)
{
	char* expect1 = md5("123");
	EXPECT_EQ("202cb962ac59075b964b07152d234b70", string(expect1));
	
/*
	static const char *const test[7] = {
	"", // d41d8cd98f00b204e9800998ecf8427e
	"945399884.61923487334tuvga", // 0cc175b9c0f1b6a831c399e269772661
	"abc", // 900150983cd24fb0d6963f7d28e17f72
	"message digest", // f96b697d7cb7938d525a2f31aaf161d0
	"abcdefghijklmnopqrstuvwxyz", // c3fcd3d76192e4007dfb496cca67e13b
	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
				//d174ab98d277d9f5a5611c2c9f419d9f
	"12345678901234567890123456789012345678901234567890123456789012345678901234567890" // 57edf4a22be3c955ac49da2e2107b67a
    };
    int i;

    for (i = 0; i < 7; ++i) {
	md5_state_t state;
	md5_byte_t digest[16];
	int di;

	md5_init(&state);
	md5_append(&state, (const md5_byte_t *)test[i], strlen(test[i]));
	md5_finish(&state, digest);
	printf("MD5 (\"%s\") = ", test[i]);
	for (di = 0; di < 16; ++di)
	    printf("%02x", digest[di]);
	printf("\n");
*/
}