// AUTO GENERATED
package generate

// #include "parser.h"
import "C"

func Pk() {
	C.Pk()
}

func Abc() string {
	return C.GoString(C.Abc())
}