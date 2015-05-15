// Copyright 2012 The Go Authors.  All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package extend

import (
	"testing"
	"fmt"
)

func TestCall(t *testing.T) {
	c := NewCaller()
	a := c.Hello()
	fmt.Println(a)
}