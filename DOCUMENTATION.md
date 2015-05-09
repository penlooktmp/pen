# Pengo Cli
+ Create new application

```bash
pengo new app
```

+ Create new controller

```bash
pengo new controller:home
```

+ Create new model

```bash
pengo new mysql>user
```

+ Create new view

```bash
pengo new app/index
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
pengo debug controller
pengo debug model
```

# Pengo syntax

+ Router & Action

```go
@Router /hello/:username
Login(username string) {
	// Assign username to view
	$username = username
}
```

+ Model manipulation - For Key - Value

Session, Redis, Memcache
```go
	// Multiple assignation
   	#session <- {
   		"username": "Bob",
   		"password": "123",
   	}

   	// Single assignation
   	#session["username"] = "Bob"

	// Single retrieve
	fmt.Println(#session["username"])
```

+ Model manipulation - For Table Family

Cassandra, MySQL, SQL Server, PostgreSQL, Oracle
```go
	user := #mysql["user"]

	// Insert new record
	user.Create({
		FirstName: "Loi",
		LastName: "Nguyen",
	})

	// Pass all users to view
	$listUser = user.Find()
```

+ Model manipulation - For Document Family

Mongo, Couch, Rethink
```go
	status := #mongo["status"]
```

