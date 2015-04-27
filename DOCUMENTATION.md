# Pengo syntax

+ Router & Action

```go
@Router /hello/username
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
	user {
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

