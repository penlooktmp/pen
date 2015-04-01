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
package pengo

import (
	"time"
	"fmt"
	"strings"
	"os/exec"
    "sync"
)

func Now() time.Time {
	return time.Now()
}

func Runtime(start time.Time, name string) {
    elapsed := time.Since(start)
    fmt.Printf("%s took %s", name, elapsed)
    fmt.Println("")
}

func run(cmd string, wg *sync.WaitGroup) [] byte {
    out, err := exec.Command(cmd).Output()
    if err != nil {
        fmt.Println("error occured")
        fmt.Printf("%s", err)
    }
    wg.Done()
    return out
}

func System(bash string) {
	commands := strings.Split(bash, `\n`)
	for _ , command := range commands {
		command = strings.TrimSpace(command)
		wg := new(sync.WaitGroup)
    	wg.Add(len(commands))
		fmt.Println(run(command, wg))
	}
}

