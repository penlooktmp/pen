# pen framework [![Build Status](https://travis-ci.org/penlook/pen.svg)](https://travis-ci.org/penlook/pen)

###Features
- MVC Web framework is written in C++
- Performance orientation (everything is compiled)
- High traffic with low resources (integrated with Nginx)
- Support Pen Syntax besides C++ for rapid development

###Benchmark
- Pen is faster than 8~10 times to compare with [fastest PHP Framework (Phalcon)](http://systemsarchitect.net/performance-benchmark-of-popular-php-frameworks/#content)
- CPU : 2 | RAM : 4GB | $ ab -c 100 -n 100000  http://localhost/
```
Server Software:        nginx/1.9.1
Server Hostname:        localhost
Server Port:            80
Concurrency Level:      100
Time taken for tests:   11.361 seconds
Complete requests:      100000
Failed requests:        0
Requests per second:    8801.97 [#/sec] (mean)
Time per request:       11.361 [ms] (mean)
Time per request:       0.114 [ms] (mean, across all concurrent requests)
```

### Instruction

- Install library and tools (pen command)
```bash
git clone https://github.com/penlook/pen.git
cd pen
make && sudo make install
```
- Create new project
```bash
$ pen new app
```
- Run project under development mode
```bash
$ pen run app
```
- Build project as Nginx module
```bash
$ pen build app
```
- Test benchmark
```bash
$ pen test
```
###Development
- pen-cli
```bash
$ python cmd/pen.py -h
```
- pen-framework
```bash
$ pen run app
```

###Roadmap

- MVC Architecture (in progress)
- Template engine (in progress)
- Hot-code reload (in progress)
- Improve performance (in progress)
- Command line for development (in progress)
- Model engine (not started)
- Unit - Integration test structure (not started)
- Multiple languages (not started)
- Documentation (not started)
- Flow Tracking (not started)
- Annotation Parser (not started)
- Rest API (not started)

####Support Database

- SQLite	  -   Table      - ORM  (not started)
- MySQL      -   Table      - ORM  (not started)
- Cassandra  -   Table      - CQL  (not started)
- MongoDB    -   Document   - ODM  (not started)
- CouchDB    -   Document          (not started)
- Memcache   -   Key-value         (not started)
- Redis      -   Key-value         (not started)
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