/**
 * Pengo Project
 *
 * Copyright (c) 2015 Penlook Development Team
 *
 * --------------------------------------------------------------------
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 * --------------------------------------------------------------------
 *
 * Author:
 *     Loi Nguyen       <loint@penlook.com>
 */

package compiler

import (
  	"github.com/codegangsta/cli"
  	"log"
    "os"
    "os/exec"
    "bytes"
    //"strings"
    "fmt"
    "path/filepath"
    . "github.com/penlook/pengo/cmd/pengo/compiler/template"
)

type Run struct {
	Context *cli.Context
	Directory string
	Parser Parser
    Mode int
    Data Data
    Daemon chan bool
}

func (run *Run) GetCurrentDirectory(appName string) {
	dir, err := filepath.Abs(filepath.Dir(os.Args[0]) + "/" + appName)
    if err != nil {
        log.Fatal(err)
    }
    run.Directory = dir
}

func (run *Run) ParseApplication() {
    parser := Parser {}
    run.Data = Data {}

    // Parse controller
    dir, err := filepath.Abs(run.Directory + "/build/generate/controller")
    if err != nil {
        panic("Folder name 'controller' does not exist !")
    }
    run.Data["controller"] = parser.Controller(dir)

    // Parse model
    dir, err = filepath.Abs(run.Directory + "/model")
    if err != nil {
        panic("Folder name 'model' does not exist !")
    }
    run.Data["model"] = parser.Model(dir)

    // Parse extend
    dir, err = filepath.Abs(run.Directory + "/extend")
    if err != nil {
        panic("Folder name 'extend' does not exist !")
    }
    run.Data["extend"] = parser.Extend(dir)
}

func (run *Run) Generate() string {
    template  := ""
    buildpath := ""

    if run.Mode == MODE_DEVELOPMENT {
        template  = TemplateDevelopment
        buildpath = "/build/development"
    } else {
        template  = TemplateProduction
        buildpath = "/build/production"
    }

    generator := Generator {}

    mainPath, _ := filepath.Abs(run.Directory + buildpath + "/main.go")
    generator.Main(template, mainPath, run.Data)

    schemaPath, _ := filepath.Abs(run.Directory + "/build/generate/controller/schema.go")
    generator.Schema(TemplateSchema, schemaPath, run.Data)

    return buildpath
}

func (run Run) Compile() {
    path, _ := filepath.Abs(run.Directory)
    compiler := Compiler {
        Directory : path,
    }
    compiler.ParseController()
}

func (run Run) Run(buildDir string) {
    go func() {
        os.Chdir(buildDir)
        cmd := exec.Command("go", "run", "./main.go")
        var out bytes.Buffer
        cmd.Stdout = &out
        go func() {
            select {
                case mode := <- run.Daemon:
                    if mode == false {
                        cmd.Process.Kill()
                    }
            }
        }()
        cmd.Start()
        cmd.Wait()
    }()
}

func (run *Run) CheckHistory() {
    buildHistory := run.Directory + "/build/build.json"
    if _, err := os.Stat(buildHistory); err == nil {
        
    }
}

func (run *Run) HasChanged() bool {

    run.CheckHistory()
    
    //checklist := [] string {"controller", "model", "library", "extend"}
    //appDirectories := [] string {
    //    "controller",
    //    "model",
    //}
    
    //for _, directory := range appDirectories {
    //}
    
    os.Exit(0)
    /*
    filepath.Walk(run.Directory, func(path string, f os.FileInfo, err error) error {
        paths := strings.Split(path, run.Directory)
        relativeFilePath := paths[1]
        if len(relativeFilePath) > 1 {
            relativeFilePath := relativeFilePath[1:]
            for _, directoryName := range appDirectories {
                if strings.HasPrefix(relativeFilePath, directoryName) {
                    
                }
            }
        }
        return nil
    })
    os.Exit(1)*/
    return true
}

func (run *Run) Development() {
    run.Mode = MODE_DEVELOPMENT
    run.GetCurrentDirectory(run.Context.Args().First())
    if run.HasChanged() {
        run.Compile()
        run.ParseApplication()
        run.Generate()
    }
    run.Run(run.Directory + "/build/development")
}

func (run *Run) Production() {
    run.Mode = MODE_PRODUCTION
    //run.GetCurrentDirectory(run.Context.Args().First())
    //run.Compile()
    //run.ParseApplication()
    //run.Generate()
}


