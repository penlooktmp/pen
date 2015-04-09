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
	"github.com/stretchr/testify/assert"
	"testing"
	//"time"
)

func TestControllerInitialize(t *testing.T) {
	assert := assert.New(t)
	controller := Controller {}
	controller.Initialize()

	assert.NotNil(controller.View)
	assert.NotNil(controller.ViewData)
	assert.Equal(0, controller.TotalDeclared)
	assert.Equal(0, controller.TotalEmit)

	assert.NotNil(controller.Template)
	assert.NotNil(controller.Signal)
	assert.NotNil(controller.StopOnSignal)
	assert.NotNil(controller.End)

	controller.Signal <- SignalResponse
}

func TestControllerAddDataToView(t *testing.T) {
	assert := assert.New(t)
	controller := Controller {}
	controller.Initialize()
	assert.NotNil(controller.ViewData)

	/*controller.AddDataToView(Data{
		"key1" : "value1",
		"key2" : "value2",
		"key3" : "value1",
		"key4" : "value3",
	})

	assert.Equal(4, len(controller.ViewData))
	controller.Signal <- SignalResponse
	*/
}

func TestControllerOnSignal(t *testing.T) {
	assert := assert.New(t)
	controller := Controller {}
	controller.Initialize()
	assert.NotNil(controller.View)
	assert.NotNil(controller.ViewData)

	/*
	controller.View <- Data {
		"key1" : "value1",
		"key2" : "value2",
		"key3" : "value1",
		"key4" : "value3",
	}

	controller.View <- Data {
		"key5" : "value1",
		"key6" : "value2",
		"key7" : "value1",
		"key8" : "value3",
	}

	controller.View <- Data {
		"key9"  : "value1",
		"key10" : "value2",
		"key11" : "value1",
		"key12" : "value3",
	}

	controller.View <- Data {
		"key13" : "value1",
		"key14" : "value2",
		"key15" : "value1",
		"key16" : "value3",
	}

	count := 0
	controller.TotalDeclared = len(controller.View)

	go func(count *int, controller *Controller) {
		for {
			if controller.TotalEmit == controller.TotalDeclared {
				*count = 1
				assert.Equal(16, len(controller.ViewData))
			}
		}
	}(&count, &controller)

	// Waiting for all channel
	time.Sleep(time.Millisecond * 1)
	assert.Equal(1, count)
	controller.Signal <- SignalResponse
	*/
}

func TestControllerProcessSignal(t *testing.T) {
	/*
	assert := assert.New(t)
	controller := Controller {}
	controller.Initialize()
	loop := true
	controller.ProcessSignal(SignalResponse, &loop)
	assert.Equal(false, loop)
	*/
}

func TestControllerAfterAction(t *testing.T) {
	// Ignore
}

func TestControllerRenderTemplate(t *testing.T) {
	// Ignore
}