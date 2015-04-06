// AUTO GENERATED
package generate

// #include "extend_parser.h"
import "C"

func Pengo() {
	C.Pengo()
}

func Abc() string {
	return C.GoString(C.Abc())
}