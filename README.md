# Pengo [![Build Status](https://travis-ci.org/penlook/pengo.svg)](https://travis-ci.org/penlook/pengo) [![GoDoc](https://godoc.org/github.com/penlook/pengo?status.svg)](https://godoc.org/github.com/penlook/pengo) [![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/scala-ide/scala-ide?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

[![Join the chat at https://gitter.im/penlook/pengo](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/penlook/pengo?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

![Pengo](http://s16.postimg.org/g7no9g5k5/Capture.png)

###Taste of Pengo (technical preview)

```go
@Controller App

@Route /login/:uid/:password
@Method GET
@Pick "Login Form"
func Login(uid int, password string) {

	// Using table
	user := #User {
		Id: uid,
		Password: password,
	}

	// Object relational mapping
	me := user.First()

	// Pass my information to view
	$name  = me.Name
	$email = me.Email

	// Model of current controller
	// Pass list user to view
	$users = @ListUser()
}
```

### Pengo syntax
- You can use Go mixed with Pengo syntax to create web application faster, more meaningful
- Eliminating the complexity of the Go syntax and deep integrated with framework
- All of your code will be compiled into Go as you wrote it.

###Roadmap

- MVC Architecture (testing)
- Template engine (testing)
- Hot-code reload (not started)
- Improve performance (implementing)
- Command line for development (implementing)
- Model engine (not started)
- Unit - Integration test structure (implementing)
- Multiple languages (implementing)
- Documentation (not started)
- Flow Tracking (testing)
- Extend framework by using C (implementing)
- Annotation Parser (not started)
- Rest API (not started)
- Pengo website (not started)

####Support Database

- SQLite	  -   Table      - ORM  (implementing)
- MySQL      -   Table      - ORM  (testing)
- Cassandra  -   Table      - CQL  (not started)
- MongoDB    -   Document   - ODM  (implemeting)
- CouchDB    -   Document          (not started)
- Memcache   -   Key-value         (not started)
- Redis      -   Key-value         (implemeting)
- Cayley     -   Graph             (not started)

###Contributors
We look forward to your pull requests. If you would like to be the contributor please accept some rules.

- The pull requests will be accepted only in "development" branch
- All modifications or additions should be tested

Thank you for your understanding.
Open a pull request, we are waiting.

###License
This is open source project for community development under GNU Affero General Public License

Authors
	- Loi Nguyen <loint@penlook.com>
	- and contributors





