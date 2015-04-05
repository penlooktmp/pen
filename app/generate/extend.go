// AUTO GENERATED
package generate

// #include "extend_parser.h"
import "C"

func Pk() {
	C.Pk()
}

func Abc() string {
	return C.GoString(C.Abc())
}