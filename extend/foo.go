package main

// #cgo CFLAGS: -DPNG_DEBUG=1
// #cgo amd64 386 CFLAGS: -DX86=1
// extern void Abc();
// extern int Abf();
import "C"

func Abc() {}
func Abf() int {
	return 0
}

func main() {
    C.Abc()
}