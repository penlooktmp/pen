package pengo

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestService(t *testing.T) {
	assert := assert.New(t)
	assert.Equal("test", "test")
}