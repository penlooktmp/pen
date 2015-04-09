# pengo [![Build Status](https://travis-ci.org/penlook/pengo.svg)](https://travis-ci.org/penlook/pengo)
[![GoDoc](https://godoc.org/github.com/penlook/pengo?status.svg)](https://godoc.org/github.com/penlook/pengo)

![Pengo](http://s16.postimg.org/g7no9g5k5/Capture.png)

###Taste of Pengo (technical preview)

```go
@Controller App

@Route /login/:uid/:password
@Method GET
@Pick "Simple Login Form"
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
	$users = #@ListUser()
}
```

### Pengo Syntax
- You can use Go mixed with Pengo syntax to create web application faster, more meaningful
- Eliminating the complexity of the Go syntax and deep integrated with framework
- All of your code will be compiled into Go as you wrote it.
```
	1. Flexible annotation
	2. Template variable
	3. Cross-context variable
	4. Model accessible
	5. Component declaration
	6. Automatically imported
```

###Road map

1. MVC Architecture (testing)
2. Template engine (testing)
3. Hot-code reload (not started)
4. Improve performance (implementing)
5. Command line for development (implementing)
6. Model engine (not started)
7. Unit - Integration test structure (implementing)
8. Multiple languages (implementing)
9. Documentation (not started)
10. Flow Tracking (testing)
11. Extend framework by using C (implementing)
12. Annotation Parser (not started)
13. Rest API

####Database Model

1. SQLite	  -   Table      - ORM  (implementing)
1. MySQL      -   Table      - ORM  (testing)
2. Cassandra  -   Table      - CQL  (not started)
3. MongoDB    -   Document   - ODM  (implemeting)
4. CouchDB    -   Document          (not started)
5. Memcache   -   Key-value         (not started)
4. Redis      -   Key-value         (implemeting)
5. Cayley     -   Graph             (not started)

###Quality Assurance

1. Unit Testing
2. Integration Testing
3. Benchmark Performance
2. Continuous Integration
3. Coding Convention
4. Documentation

###Author - License
This is open source project for community development under GNU Affero General Public License

Author
	- Loi Nguyen <loint@penlook.com>





