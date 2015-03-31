package pengo

import (
	. "github.com/penlook/pengo/builtin"
	"github.com/stretchr/testify/assert"
	"testing"
	"time"
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

	controller.AddDataToView(Data{
		"key1" : "value1",
		"key2" : "value2",
		"key3" : "value1",
		"key4" : "value3",
	})

	assert.Equal(4, len(controller.ViewData))
	controller.Signal <- SignalResponse
}

func TestControllerOnSignal(t *testing.T) {
	assert := assert.New(t)
	controller := Controller {}
	controller.Initialize()
	assert.NotNil(controller.View)
	assert.NotNil(controller.ViewData)

	controller.View <- Data {
		"key1" : "value1",
		"key2" : "value2",
		"key3" : "value1",
		"key4" : "value3",
	}

	count := 0
	controller.TotalDeclared = len(controller.View)

	go func(count *int, controller *Controller) {
		for {
			if controller.TotalEmit == controller.TotalDeclared {
				*count = 1
				assert.Equal(4, len(controller.ViewData))
			}
		}
	}(&count, &controller)

	// Waiting for all channel
	time.Sleep(time.Millisecond * 1)
	assert.Equal(1, count)
}