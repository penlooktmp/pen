# pen framework [![Build Status](https://travis-ci.org/penlook/pen.svg)](https://travis-ci.org/penlook/pen)

### Instruction

- Install library and tools (pen command)
```bash
git clone https://github.com/penlook/pen.git
cd pen
make && sudo make install
```
- Create new project (not implemented)
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
###Benchmark

```
Server Software:        nginx/1.9.1
Server Hostname:        localhost
Server Port:            8080
*Concurrency Level:      500
*Time taken for tests:   1.048 seconds
*Complete requests:      10000
Failed requests:        0
Requests per second:    9543.04 [#/sec] (mean)
*Time per request:       0.105 [ms] (mean, across all concurrent requests)
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