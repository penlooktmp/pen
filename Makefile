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
CC      = g++
CCVER 	= c++0x
BUILD   = -std=$(CCVER) -O3 -fPIC
DEBUG   = -std=$(CCVER) -pipe -g0 -fno-inline -Wall -fPIC
TESTF	= -std=$(CCVER) -g -L/opt/gtest/lib -lgtest -lgtest_main -lpthread -I/opt/gtest/include
EXECUTE = /usr/bin/$(LIB)
LIBSYS  = /usr/lib
INCLUDE = inc
SOURCED = src
OBJECTD = pkg/obj
SOURCES = $(shell find $(SOURCED) -name *.cpp)
TESTS   = $(shell find ./test -name *.cpp)
OBJECTS = $(addprefix $(OBJECTD)/, $(patsubst %.cpp, %.o, $(SOURCES)))
BINARY = $(OBJECTD)/$(SOURCED)/$(LIB)
OBJECTT = $(TESTS:.cpp=.o)
FLAGS   = $(BUILD)

all: $(LIB)

$(LIB): $(OBJECTS)
	$(CC) $(OBJECTS) -fPIC -shared -o bin/lib$(LIB).so -lcurl -lpthread

$(OBJECTD)/%.o: %.cpp
	$(CC) -c $(FLAGS) -I$(INCLUDE) $< -o $@

$(OBJECTS): mk

mk:
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

test:
	make OBJECTS="$(OBJECTT)" FLAGS="$(TESTF)" LIB="$(TEST)"
	./$(TEST)
	rm -rf ./$(TEST)

clean:
	rm -rf $(OBJECTD)
	rm -rf $(LIBSYS)/$(LIB)
	rm -rf $(LIBSYS)/lib$(LIB).so

remove:
	rm -rf $(EXECUTE)

.PHONY: all clean debug