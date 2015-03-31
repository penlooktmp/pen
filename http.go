package pengo

import (
	"net/http"
)

type Http struct {
	Request *http.Request
	Response http.ResponseWriter
}