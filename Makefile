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
GCC     = gcc
G++		= g++
GCCVER  = c11  
G++VER 	= c++11
FGCC    = -std=$(GCCVER) -O3 -fPIC
FG++    = -std=$(G++VER) -O3 -fPIC
DEBUG   = -std=$(G++VER) -pipe -g0 -fno-inline -Wall -fPIC
EXECUTE = /usr/bin/$(LIB)
LIBSYS  = /usr/lib
TESTF	= -std=$(G++VER) -g -pthread -L/usr/lib/gtest/lib -I/usr/lib/gtest/include -I/usr/lib/pen
INCLUDE = inc
SOURCED = src
TESTD   = pkg/test
OBJECTD = pkg/obj/
HEADERS = $(shell find /usr/lib/pen -name *.h)
SOURCES = $(shell find src -name *.c*)
TESTS   = $(shell find test -name *.cpp)
SOURCE  = $(patsubst %.cpp, %.o, $(SOURCES))
SOURCE  := $(patsubst %.c, %.o, $(SOURCE))
HEADER  = $(patsubst %.h, %.h.gch, $(HEADERS))
OBJECTS = $(addprefix $(OBJECTD), $(SOURCE))
OHEADER = $(addprefix $(OHEADERD), $(HEADER))
BINARY  = $(OBJECTD)/$(SOURCED)/$(LIB)
OBJECTT = $(addprefix $(TESTD)/, $(patsubst %.cpp, %.o, $(TESTS)))
G++FLAG = $(FG++)
GCCFLAG = $(FGCC)

all: $(LIB)
$(LIB): $(OBJECTS)
	$(G++) $(OBJECTS) -fPIC -shared -o bin/lib$(LIB).so -lcurl -lpthread

$(OBJECTD)%.o: %.cpp
	$(G++) -c $(G++FLAG) -I$(INCLUDE) $< -o $@

$(OBJECTD)%.o: %.c
	$(GCC) -c $(GCCFLAG) -I$(INCLUDE) $< -o $@ -Wno-implicit-function-declaration

$(OHEADERD)%.h.gch: %.h
	$(G++) -c $(G++FLAG) -I$(INCLUDE) -I/usr/lib/gtest/include $< -o $@

$(OBJECTS): objectmk

objectmk:
	mkdir -p bin
	for file in $(OBJECTS) ; do if [ ! -e $$file ]; then mkdir -p $$file && rm -rf $$file; fi done

debug:
	mkdir -p $(LIBSYS)/$(LIB)
	cp -ru $(INCLUDE)/* $(LIBSYS)/$(LIB)
	rm -rf $(shell find $(LIBSYS)/$(LIB) -name *.h)
	cp -f bin/lib$(LIB).so $(LIBSYS)/
	ldconfig

install:
	mkdir -p /usr/lib/pen
	cp -ru $(INCLUDE)/* /usr/lib/pen
	$(MAKE) $(OHEADER)
	rm -rf $(shell find /usr/lib/pen -name *.h)
	cp -f bin/lib$(LIB).so $(LIBSYS)/
	ldconfig
	$(shell python ./setup.py install > /dev/null)

$(OBJECTT): testmk
testmk:
	mkdir -p bin
	for file in $(OBJECTT) ; do if [ ! -e $$file ]; then mkdir -p $$file && rm -rf $$file; fi done

$(TESTD)/%.o: %.cpp
	$(G++) -c $(TESTF) -I$(INCLUDE) $< -o $@

test: $(TEST)
$(TEST): $(OBJECTT)
	$(G++) $(TESTF) $(OBJECTT) -o bin/$(TEST) -lpen -lpthread -lgtest -lgtest_main
	./bin/$(TEST)

clean:
	rm -rf $(OBJECTD)
	rm -rf $(LIBSYS)/$(LIB)
	rm -rf $(LIBSYS)/lib$(LIB).so

remove:
	rm -rf $(EXECUTE)

.PHONY: all clean debug test