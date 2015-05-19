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
BINARY  = /usr/bin/$(PROG)
INCLUDE = ./inc
CURRENT = ./src/
SOURCES = $(shell find $(CURRENT)  -name *.cpp)
TESTS   = $(shell find ./test -name *.cpp )
OBJECTS = $(SOURCES:.cpp=.o)
OBJECTT = $(TESTS:.cpp=.o)
FLAGS   = $(BUILD)

.PHONY: all test clean

all: $(PROG)

$(PROG): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROG)

%.o: %.cpp
	$(CC) -c $(FLAGS) -I$(INCLUDE) $< -o $@

debug:
	make CURRENT="$(CURRENT)$(path)" FLAGS="$(DEBUG)"
	mv -f ./$(PROG) $(BINARY)

install:
	cp -f ./$(PROG) $(BINARY)

test:
	make OBJECTS="$(OBJECTT)" FLAGS="$(TESTF)" PROG="$(TEST)"
	./$(TEST)
	rm ./$(TEST)
		
clean:
	rm $(EXEC) $(OBJECTS)
	rm ./$(PROG) 
	rm $(BINARY) 