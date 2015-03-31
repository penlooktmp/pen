package pengo

import (
	. "github.com/penlook/pengo/model"
)

type Model struct {
	Table_ Table
	Document_ Document
	KeyValue_ KeyValue
	Graph_ Graph
}

func (model Model) New() {

}

func (model Model) Build() {
	model.UseTable()
	model.UseDocument()
	model.UseKeyValue()
	model.UseGraph()
}

func (model Model) Table(table string) {}
func (model Model) Document(document string) {}
func (model Model) Key(key string) {}
func (model Model) Graph(document string) {}


