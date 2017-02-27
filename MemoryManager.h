//=======================================================================================//
//=02/20/2017                                                            Alexander Alava=//
//=MemoryManager.h                                                             U35432961=//
//=                                                                                     =//
//=                 This is the header file for the MemoryManager class                 =//
//=======================================================================================//

#ifndef __MM__
#define __MM__

#include <iostream>
#include <sstream>
#include "blockdata.h"
#include "dlUtils.h"

using namespace std;

// Declaring and defining the MemoryManager class //
class MemoryManager
{
   public:
   // Declaring the constructor of the class //
   MemoryManager(unsigned int memsize);

   // Declaring the destructor of the class //
   ~MemoryManager();

   // Declaring the allocation function //
   unsigned char * malloc(unsigned int request);

   // Declaring the deallocation function //
   void free(unsigned char * ptr2block);

   // Declaring the displaying function //
   void showBlockList();

   private:

   // Declaring data members and pointers of the class //
   unsigned int memsize;
   unsigned char *baseptr;
   dlNode<blockdata>* header;
   dlNode<blockdata>* trailer;

   // Declaring the merging functions //
   void mergeForward(dlNode<blockdata> *p);
   void mergeBackward(dlNode<blockdata> *p);

   // Declaring the function that will split our blocks of memory //
   void splitBlock(dlNode<blockdata> *p,unsigned int chunksize);
};


#endif
