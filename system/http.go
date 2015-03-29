package system

import (
	"net/http"
)

type Http struct {
	Request *http.Request
	Response http.ResponseWriter
	Controller string
	Action string
}