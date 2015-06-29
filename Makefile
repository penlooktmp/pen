#
# Pengo Project
#
# Copyright (c) 2015 Penlook Development Team
#
# --------------------------------------------------------------------
#
# This program is free software: you can redistribute it and/or
# modify it under the terms of the GNU Affero General Public License
# as published by the Free Software Foundation, either version 3
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public
# License along with this program.
# If not, see <http://www.gnu.org/licenses/>.
#
# --------------------------------------------------------------------
#
# Authors:
#     Loi Nguyen       <loint@penlook.com>

LIB     = pen
TEST	= pentest
CC      = g++
CCVER 	= c++11
BUILD   = -std=$(CCVER) -O3 -fPIC
DEBUG   = -std=$(CCVER) -pipe -g0 -fno-inline -Wall -fPIC
EXECUTE = /usr/bin/$(LIB)
LIBSYS  = /usr/lib
TESTF	= -std=$(CCVER) -g -pthread -L/usr/lib/gtest/lib -I/usr/lib/gtest/include -I/usr/lib/pen
INCLUDE = inc
SOURCED = src
TESTD   = pkg/test
OBJECTD = pkg/obj
SOURCES = $(shell find $(SOURCED) -name *.cpp)
TESTS   = $(shell find ./test -name *.cpp)
OBJECTS = $(addprefix $(OBJECTD)/, $(patsubst %.cpp, %.o, $(SOURCES)))
BINARY = $(OBJECTD)/$(SOURCED)/$(LIB)
OBJECTT = $(addprefix $(TESTD)/, $(patsubst %.cpp, %.o, $(TESTS)))
FLAGS   = $(BUILD)

all: $(LIB)
$(LIB): $(OBJECTS)
	$(CC) $(OBJECTS) -fPIC -shared -o bin/lib$(LIB).so -lcurl -lpthread

$(OBJECTD)/%.o: %.cpp
	$(CC) -c $(FLAGS) -I$(INCLUDE) $< -o $@

$(OBJECTS): objectmk

objectmk:
	mkdir -p bin
	for file in $(OBJECTS) ; do if [ ! -e $$file ]; then mkdir -p $$file && rm -rf $$file; fi done

debug:
	make SOURCED="$(SOURCED)$(path)" FLAGS="$(DEBUG)"
	mkdir -p $(LIBSYS)/$(LIB)
	cp -rf $(INCLUDE)/* $(LIBSYS)/$(LIB)
	cp -f bin/lib$(LIB).so $(LIBSYS)/
	ldconfig

install:
	mkdir -p $(LIBSYS)/$(LIB)
	cp -ru $(INCLUDE)/* $(LIBSYS)/$(LIB)
	cp -f bin/lib$(LIB).so $(LIBSYS)/
	ldconfig
	$(shell python ./setup.py install > /dev/null)

$(OBJECTT): testmk
testmk:
	mkdir -p bin
	for file in $(OBJECTT) ; do if [ ! -e $$file ]; then mkdir -p $$file && rm -rf $$file; fi done

$(TESTD)/%.o: %.cpp
	$(CC) -c $(TESTF) -I$(INCLUDE) $< -o $@

test: $(TEST)
$(TEST): $(OBJECTT)
	$(CC) $(TESTF) $(OBJECTT) -o bin/$(TEST) -lpen -lpthread -lgtest -lgtest_main
	./bin/$(TEST)

clean:
	rm -rf $(OBJECTD)
	rm -rf $(LIBSYS)/$(LIB)
	rm -rf $(LIBSYS)/lib$(LIB).so

remove:
	rm -rf $(EXECUTE)

.PHONY: all clean debug test