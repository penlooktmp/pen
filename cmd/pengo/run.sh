#!/usr/bin/env bash
go build
./pengo.exe debug app
cd app/build/development
go run main.go

