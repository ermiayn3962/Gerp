###
### Makefile for Gerp Project
### Gerp is a Huffman Compression Program
###
### Author:  Cooper Golemme and Yoda Ermias

MAKEFLAGS += -L

CXX      = clang++
CXXFLAGS = -g3 -O2 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

## Linking Rules
gerp: main.o FileObject.o stringProcessing.o FSTree.o DirNode.o HashTable.o Gerp.o
	$(CXX) $(CXXFLAGS) -o gerp $^

main.o: main.cpp stringProcessing.o FileObject.o HashTable.o Gerp.o FSTree.o DirNode.o

Gerp.o: Gerp.cpp FileObject.o FSTree.o DirNode.o

FileObject.o: FileObject.cpp FileObject.h DirNode.o HashTable.o stringProcessing.o

stringProcessing.o: stringProcessing.cpp 

HashTable.o: HashTable.cpp

## Rule for Unit Testing
unit_test: unit_test_driver.o HashTable.o FileObject.o stringProcessing.o Gerp.o FSTree.o DirNode.o
	$(CXX) $(CXXFLAGS) $^

## Rule for provide
provide: 
	provide comp15 proj4_gerp README Makefile FileObject.cpp FileObject.h\
	 						  Gerp.cpp Gerp.h HashTable.cpp HashTable.h main.cpp\
							  stringProcessing.cpp stringProcessing.h unit_tests.h\
							  FileObject_test_file.txt FileObject_test_file2.txt\
							  inputCommands_test_1.txt inputCommands_test.txt