//=======================================================================================//
//=02/20/2017                                                            Alexander Alava=//
//=MemoryManager.cpp                                                           U35432961=//
//=                                                                                     =//
//=             This is the implementation file for the MemoryManager class             =//
//=======================================================================================//

#include <cassert>
#include <iostream>
#include "dlUtils.h"
#include "MemoryManager.h"

// Defining the constructor of MemoryManager //
MemoryManager::MemoryManager(unsigned int memtotal): memsize(memtotal)
{
  // Declaring and initializing the base pointer //
  baseptr = new unsigned char[memsize];

  // Declaring and defining a dummy block for header and trailer //
  blockdata dummyBlock(0,false,0);

  // Declaring and initializing the original block of memory //
  blockdata originalBlock(memsize,true,baseptr);

  // Declaring and initializing the header //
  header = new dlNode<blockdata>(dummyBlock,nullptr,nullptr);

  // Declaring and initializing the trailer //
  trailer = new dlNode<blockdata>(dummyBlock,nullptr,nullptr);

  // Making header point to the block of memory and this block to the trailer //
  header->next = new dlNode<blockdata>(originalBlock,header,trailer);

  // Making the trailer point to the block of memory //
  trailer->prev = header->next;
}

// Defining the destructor of MemoryManager //
MemoryManager::~MemoryManager()
{
  delete [] baseptr;
  clearList(header);
}

// Defining the output function //
void MemoryManager::showBlockList()
{
  printDlList(header,trailer,"->");
}

// Defining the function that will split a block into two blocks //
void MemoryManager::splitBlock(dlNode<blockdata> *p, unsigned int chunksize)
{
  // Calculating new size of the new block //
  unsigned int newSize = p->info.blocksize - chunksize;

  // Declaring and initializing the new block of data //
  blockdata newBlock(newSize, true, (p->info.blockptr + chunksize));

  // Inserting the new block of data after the current //
  insertAfter(trailer, p, newBlock);
}

// Defining the function that will allocate a block of memory //
unsigned char * MemoryManager::malloc(unsigned int request)
{
  // Declaring and initializing a flag to check if the allocation was successful //
  int flag = 0;

  // Declaring a dlNode pointer to use in the for loop //
  dlNode<blockdata> *current;

  // Establishing a for loop that will run through the list of blocks //
  for (current = header->next; current != trailer; current = current->next)
  {
    // Checking if the current block is eligible for allocation //
    if (current->info.free == true && current->info.blocksize >= request)
    {
      // Checking if there is more space than needed in the block //
      if (current->info.blocksize > request)
      {
        // Splitting the block in order to use memory efficiently //
        splitBlock(current, request);
      }

      // Adjusting the data members of the block that is being allocated //
      current->info.blocksize = request;
      current->info.free = false;

      // Adjusting the flag and breaking from the for loop //
      flag = 1;
      break;
    }
  }

  // Checking if the allocation was successful //
  if (!flag)
  {
    // Returning NULL as instructed //
    return 0;
  }

  return current->info.blockptr;
}

// Defining the function that will merge a block with the next one //
void MemoryManager::mergeForward(dlNode<blockdata> *p)
{
  // Declaring and initializing a new pointer that will hold the node to be deleted //
  dlNode<blockdata> *hold;
  hold = p->next;

  // Adding the sizes of the blocks //
  p->info.blocksize += p->next->info.blocksize;

  // Making the new next node point to the current //
  p->next->next->prev = p;

  // Making the previous node point to the next node //
  p->next = p->next->next;

  // Deleting the node redundant node //
  delete hold;
  hold = NULL;
}

// Defining the function that will merge a block with the previous one //
void MemoryManager::mergeBackward(dlNode<blockdata> *p)
{
  // Declaring and initializing a new pointer that will hold the node to be deleted //
  dlNode<blockdata> *hold;
  hold = p->prev;

  // Adding the sizes of the blocks //
  p->info.blocksize += p->prev->info.blocksize;

  // Adjusting the block pointer //
  p->info.blockptr = p->prev->info.blockptr;

  // Making the new previous node point to current //
  p->prev->prev->next = p;

  // Making the current node point to its new previous //
  p->prev = p->prev->prev;

  // Deleting the node redundant node //
  delete hold;
  hold = NULL;
}

// Defining the function that will deallocate a block of memory //
void MemoryManager::free(unsigned char *ptr2block)
{
  // Declaring a dlNode pointer to use in the for loop //
  dlNode<blockdata> *current;

  // Declaring and initializing a flag //
  int flag = 0;

  // Establishing a for loop that will run through the list of blocks //
  for (current = header->next; current != trailer; current = current->next)
  {
    // Checking if the current block is the block to be freed //
    if (current->info.blockptr == ptr2block)
    {
      // Freeing the current block //
      current->info.free = true;

      // Checking if the block before the current is also free //
      if (current->prev->info.free == true)
      {
        // Merging the current block with the previous block //
        mergeBackward(current);
      }
      // Checking if the block after the current is also free //
      if (current->next->info.free == true)
      {
        // Merging the current block with the next one //
        mergeForward(current);
      }

      // Adjusting the flag //
      flag = 1;

      break;
    }
  }
  // Checking if the deallocation was successful //
  if (!flag)
  {
    // Terminating the program //
    exit(EXIT_FAILURE);
  }
}
