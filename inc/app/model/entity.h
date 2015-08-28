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

#ifndef APP_MODEL_ENTITY_H_
#define APP_MODEL_ENTITY_H_

#include <iostream>
#include <sys/func.h>

using std::string;

namespace app
{
	namespace model
	{
		class Entity
		{
			public:
				/*
				virtual Entity getSource();
				virtual Entity *save();
				virtual Entity *clear();
				virtual Entity *find();
				virtual Entity *findFirst(string);
				virtual Entity *count();
				virtual Entity *sum();
				virtual Entity *average();
 				virtual Entity *max();
				virtual Entity *min();
				*/
		};
	}
}

// Export
using app::model::Entity;

#endif