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

#ifndef APP_STORAGE_H_
#define APP_STORAGE_H_

#include <app/controller.h>
#include <app/model.h>
#include <app/view.h>
#include <app/language.h>
#include <sys/func.h>
#include <functional>
#include <vector>
#include <map>

using std::string;

namespace app {
	class Storage {

		private:
			MappingList mapping;
			ControllerList controllers;
			ModelList models;
			ViewList views;
			LanguageList languages;
			int status;

		public:

			static const int EMPTY;
			static const int READY;

			Storage();
			~Storage();

			Storage *buildMappingList();
			MappingList getMappingList();

			Storage *setControllers(ControllerList);
			ControllerList getControllers();

			Storage *setModels(ModelList);
			ModelList getModels();

			Storage *setViews(ViewList);
			ViewList getViews();

			Storage *setStatus(int);
			int getStatus();

	};
}

// Export
using app::Storage;
#endif