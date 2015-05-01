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

package main

import (
    "os"
  	"github.com/codegangsta/cli"
    "github.com/penlook/pengo/cmd/pengo/library"
    "github.com/penlook/pengo/cmd/pengo/server"
)

func main() {
    app := cli.NewApp()
    app.Name = "pengo"
  	app.Commands = [] cli.Command {
        {
            Name:      "debug",
            Aliases:   []string{"-d"},
            Usage:     "Run application in development mode",
            Action: func(context *cli.Context) {
                proxy := server.Server {
                    Name: "Proxy Server",
                    Port: 80,
                }
                proxy.Handle(func(url string) {
                    runner := library.Run {
                        Context: context,
                    }
                    runner.Development()
                })
                proxy.Listen()
            },
        },
        {
            Name:      "build",
            Aliases:   []string{"-b"},
            Usage:     "Build pengo application and ready for production",
            Action: func(context *cli.Context) {
                runner := library.Run {
                    Context: context,
                }
                runner.Production()
            },
        },
    }

  	app.Run(os.Args)
}