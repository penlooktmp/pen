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
CC      = g++
BUILD   = -O3 -W 
DEBUG   = -g0 -fno-inline
BINARY  = /usr/bin/$(PROG)
INCLUDE = ./src
SOURCES = $(shell find ./ -name '*.cpp')
OBJECTS = $(SOURCES:.cpp=.o)
FLAGS   = $(BUILD)

all: $(PROG)

$(PROG): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROG)

%.o: %.cpp
	$(CC) -c $(FLAGS) -I$(INCLUDE) $< -o $@

debug:
	make FLAGS="$(DEBUG)"
	rm -f $(EXEC) $(OBJECTS)
	mv -f ./$(PROG) $(BINARY)

install:
	cp -f ./$(PROG) $(BINARY)

clean:
	rm $(EXEC) $(OBJECTS)
	rm ./$(PROG) 
	rm $(EXECUTE) 