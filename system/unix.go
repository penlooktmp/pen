package system

import (
	"time"
	"fmt"
	"strings"
	"os/exec"
    "sync"
)

func Now() time.Time {
	return time.Now()
}

func Runtime(start time.Time, name string) {
    elapsed := time.Since(start)
    fmt.Printf("%s took %s", name, elapsed)
}

func run(cmd string, wg *sync.WaitGroup) [] byte {
    out, err := exec.Command(cmd).Output()
    if err != nil {
        fmt.Println("error occured")
        fmt.Printf("%s", err)
    }
    wg.Done()
    return out
}

func System(bash string) {
	commands := strings.Split(bash, `\n`)
	for _ , command := range commands {
		command = strings.TrimSpace(command)
		wg := new(sync.WaitGroup)
    	wg.Add(len(commands))
		fmt.Println(run(command, wg))
	}
}

