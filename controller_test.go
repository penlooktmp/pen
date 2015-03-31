package pengo

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestController(t *testing.T) {
	assert := assert.New(t)
	assert.Equal("test", "test")
}