package controller

import (
	"net/http"
)

type Controller struct {
	Request *http.Request
	Response http.ResponseWriter
}
