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
 	"github.com/olekukonko/tablewriter"
 	"container/list"
 	"os"
 	"strconv"
 	"time"
 	"strings"
 	"runtime"
 	"fmt"
)

type Block struct {
	Time int64
	Message string
	Function string
}

type Flow struct {
	Mode string
	Tracking *list.List
	Unit time.Duration
}

func (flow Flow) getLastFunction() string {
	last := "Unknown"

	for i:=2; i<20; i++ {
		pc := make([]uintptr, 10)
    	runtime.Callers(i, pc)
    	f := runtime.FuncForPC(pc[0])
	    funcName := f.Name()
	    if strings.HasPrefix(funcName, "main") {
	    	break
	    } else {
	    	last = funcName
	    }
	}

	array := strings.Split(last, "/")
	last = array[len(array) - 1]
	return last
}

func (flow *Flow) Pick(message string) {
	funcName := flow.getLastFunction()
	fmt.Println(funcName)

	flow.Tracking.PushBack(Block {
		Time: time.Now().UnixNano(),
		Message: message,
		Function: funcName,
	})
}

func (flow Flow) Graph() {

	if flow.Tracking.Len() < 2 {
		fmt.Println("Not enough data to generate graph")
		return
	}

	firstnode := flow.Tracking.Front()
	timepoint := firstnode.Value.(Block).Time
	var segment []Block
	count := 0

	for node := firstnode.Next(); node != nil; node = node.Next() {
		block := node.Value.(Block)
		duration := block.Time - timepoint
		segment = append(segment, Block {
			Time: duration,
			Message: block.Message,
			Function: block.Function,
		})
		timepoint = block.Time
		count++
	}

	data := [][]string{}

	for i:=0; i<count; i++ {
		block := segment[i]
		data = append(data, []string { block.Function, block.Message, strconv.FormatInt(block.Time, 10)})
	}

	table := tablewriter.NewWriter(os.Stdout)
	table.SetHeader([]string{"Function", "Message", "Elapsed"})
	table.SetFooter([]string{"", "Total", "$146.93"})
	table.SetBorder(false)
	table.AppendBulk(data)
	table.Render()
}