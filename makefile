###########################################################################
##02/20/2017																              Alexander Alava##
##makefile																				 					    U35432961##
##																																   	   ##
## This is the makefile for the file "testMemMgr" and all its dependants ##
###########################################################################

heap:  MemoryManager.o blockdata.o testMemMgr.o
	g++ -std=c++11 blockdata.o MemoryManager.o testMemMgr.o -o heap

testMemMgr.o:  testMemMgr.cpp
	g++ -std=c++11 -c testMemMgr.cpp

blockdata.o: blockdata.h blockdata.cpp dlUtils.h
	g++ -std=c++11 -c blockdata.cpp

MemoryManager.o: MemoryManager.cpp MemoryManager.h
	g++ -std=c++11 -c MemoryManager.cpp

clean:
	rm *.o
