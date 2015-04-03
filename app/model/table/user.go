package model

import (
	"github.com/penlook/pengo/model"
	"strings"
)

type User struct {
	Model model.Table
	Id       int64
	Username string `sql:"type:varchar(100);"`
	Email    string `sql:"type:varchar(100);"`
	Password string `sql:"type:varchar(200);"`
}

// Custom model function
func (user User) FormatUserName() string {
	return strings.ToLower(user.Username)
}


