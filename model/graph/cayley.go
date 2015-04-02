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
package doc

import (
	"fmt"
	"github.com/google/cayley/config"
	"github.com/google/cayley/db"
	"github.com/google/cayley/graph"
	"sync"

	// Load all supported backends.
	_ "github.com/google/cayley/graph/bolt"
	_ "github.com/google/cayley/graph/leveldb"
	_ "github.com/google/cayley/graph/memstore"
	_ "github.com/google/cayley/graph/mongo"
	_ "github.com/google/cayley/writer"
)

type Graph struct {
	Config *config.Config
	Handle *graph.Handle
}

var err error
var create sync.Once

func (g Graph) Init() {

	create.Do(func() {

		if graph.IsPersistent(g.Config.DatabaseType) {
			err = db.Init(g.Config)
			if err != nil {
				fmt.Println("Could not initialize database: %v", err)
			}
		}

		g.Handle, err = db.Open(g.Config)

		if err != nil {
			fmt.Println("Failed to open %q: %v", g.Config.DatabasePath, err)
		}

	})
}