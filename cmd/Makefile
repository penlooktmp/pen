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

PROG    = pengo
TEST	= ptest
CC      = g++
CCVER 	= c++0x
BUILD   = -std=$(CCVER) -Wall -O3
DEBUG   = -std=$(CCVER) -pipe -g0 -fno-inline -Wall
TESTF	= -std=$(CCVER) -g -L/opt/gtest/lib -lgtest -lgtest_main -lpthread -I/opt/gtest/include
EXECUTE = /usr/bin/$(PROG)
INCLUDE = ./inc
SOURCED = src
OBJECTD = obj
SOURCES = $(shell find $(SOURCED) -name *.cpp)
TESTS   = $(shell find ./test -name *.cpp )
OBJECTS = $(addprefix $(OBJECTD)/, $(patsubst %.cpp, %.o, $(SOURCES)))
BINARY = $(OBJECTD)/$(SOURCED)/$(PROG)
OBJECTT = $(TESTS:.cpp=.o)
FLAGS   = $(BUILD)

all: $(PROG)

$(PROG): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINARY)

$(OBJECTD)/%.o: %.cpp
	$(CC) -c $(FLAGS) -I$(INCLUDE) $< -o $@

$(OBJECTS): mk

mk:
	for file in $(OBJECTS) ; do if [ ! -e $$file ]; then mkdir -p $$file && rm -rf $$file; fi done

debug:
	make SOURCED="$(SOURCED)$(path)" FLAGS="$(DEBUG)"
	cp -f $(BINARY) $(EXECUTE)

install:
	cp -f $(BINARY) $(EXECUTE)

test:
	make OBJECTS="$(OBJECTT)" FLAGS="$(TESTF)" PROG="$(TEST)"
	./$(TEST)
	rm -rf ./$(TEST)
		
clean:
	rm -rf $(OBJECTS)
	rm -rf $(BINARY)

remove:
	rm -rf $(EXECUTE)

.PHONY: all clean debug