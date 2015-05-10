# Pengo Framework Design 

### Pengo Cli
+ Create new application

```bash
pengo new app
```

+ Create new controller

```bash
pengo new home:index
```

+ Create new model

```bash
pengo new mysql>user
```

+ Create new view

```bash
pengo new home/index
```

+ Run application under debugging mode

```bash
pengo run app
```

+ Build application and ready for production

```bash
pengo build app
```

+ Analyze application for debugging mode

```bash
pengo debug router
```
```bash
pengo debug controller
```
```bash
pengo debug model
```

### Pengo Controller

+ Controller declaration
- @Controller [controller]
```go
@Controller app
```

+ Controller declaration and extend from another controller
- @Controller [controller] [parent controller]
```go
@Controller app base
```

+ Router - Method - Action mapping
```go
@Router /hello/:userid/:password
@Method GET POST PUT
func Login(userid int, password string) {
}
```

### Pengo Model
```
instance := [entity]>[field | key]
[entity]>[field | key] = value
[entity]>"[field string | key string ]" = value
```

+ Select all users from user table
```go
user := mysql>User 
listUser = user.Find({
	Id: 3
})
```

+ Create new status
```go
status := mongo>Status {
	Username: "Loi Nguyen",
	Content: "Have a nice day !",
}
status.Create()
```

+ Save login information using session
```go
session>Username = "loint"
session>Login = true 
```

+ Assign and retrive dynamic key to redis
```go
redis>"abc" = "hello"
fmt.Println(redis>"abc")
```

### Pengo Template
+ Assign function to template
```go
@compress = func(html string) {
	return html + " is using compress function"
}
```

+ Assign variable to template
```go
$title = "Pengo Application"	
$messsage = "Hello World"
```