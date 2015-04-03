package main

// extern void Abc();
import "C"

func Abc() {}

func main() {
    C.Abc()
}