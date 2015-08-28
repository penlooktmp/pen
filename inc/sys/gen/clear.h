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

#ifndef SYS_GEN_FREE_H_
#define SYS_GEN_FREE_H_

namespace sys
{
	namespace func
	{

		// Free memory for vector array
		template <typename T>
		inline void clear(vector<T*> &target)
		{
			for (int i=0; i<target.size(); i++)
				delete target[i];
			target.clear();
			vector<T*>().swap(target);
		}

		// Free memory for map array
		template <typename T>
		inline void clear(map<string, T*> &target)
		{
			for (auto it : target)
			{
				delete it.second;
			}
			target.clear();
			map<string, T*>().swap(target);
		}
	}
}

#endif