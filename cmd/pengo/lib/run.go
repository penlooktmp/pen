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
package lib

import (
  	"github.com/codegangsta/cli"
  	"log"
    "os"
    "path/filepath"
)


type Run struct {
	Context *cli.Context
	Directory string
	Parser Parser
}

func (run *Run) GetCurrentDirectory(appName string) {
	dir, err := filepath.Abs(filepath.Dir(os.Args[0]) + "/" + appName)
    if err != nil {
        log.Fatal(err)
    }
    run.Directory = dir
}

func (run *Run) Run() {
	run.GetCurrentDirectory(run.Context.Args().First())
	parser := Parser {}
    dir, err := filepath.Abs(run.Directory + "/controller")
    if err != nil {
        panic("Controller does not exist !")
    }
	parser.Controller(dir)
}