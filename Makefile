#******************************************************************************
# Copyright (C) 2020 by Shriram Ravindranathan
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.
# 
#*****************************************************************************

#------------------------------------------------------------------------------
# This is the makefile which is used to compile the source code of all the data 
# structures implemented in the DataStructuresLibrary repository
#
# Use: make [TARGET] 
#
# Build Targets:
#      use the target 'compile-all' to generate the object files
#
#
#------------------------------------------------------------------------------
include sources.mk 

#makefile variables 
CC = g++
LD = -L ./
LDFLAGS =-Wl,-Map=dsl.map
CFLAGS =-Wall\
	-Werror\
	-g\
	-O0\
	-std=c++17\
	-fpic
CPPFLAGS = $(INCLUDES)

#Generating Compiled object files
%.o: %.cpp
	$(CC) -c $<  $(CFLAGS) $(CPPFLAGS)  -o $@

#Target to be built
DSL.a: $(SOURCES:.cpp=.o)
	ar rcs $@ $^

#Compile all without linking
.PHONY:compile-all
compile-all: $(SOURCES:.cpp=.o)

#Clean all generated files
.PHONY:clean
clean: 
	rm -rf ./src/*.o ./src/*.i ./src/*.asm ./*.out ./*.map ./src/*.d





