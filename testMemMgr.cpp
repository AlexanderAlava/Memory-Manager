//=================================================================================================//
//=02/20/2017                                                                      Alexander Alava=//
//=testMemMgr.cpp                                                                        U35432961=//
//=                                                                                               =//
//=                 This is the driver/test file for the memory manager project                   =//
//=================================================================================================//

#include <iostream>
#include "MemoryManager.h"
using namespace std;

int main()
{

//=================================     Memory manager 1     ================================//

  // Printing header //
  cout << "\n------------------------------------------------------\n";
  cout << "-------------------  HEAP 1 TEST  --------------------\n";
  cout << "------------------------------------------------------\n\n";

  // Initializing the first heap and printing an informational message //
  MemoryManager heaper(2048);
  cout << "\nFirst heap initialized\n";

  // Printing the initial status of the heap //
  cout << "\n-------------BlockList start------------------\n";
  heaper.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";

  // Doing the first allocation and printing the current status //
  unsigned char * p1 = heaper.malloc(10);
  cout << "\n-------------BlockList start------------------\n";
  heaper.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";

  // Doing the second allocation and printing the current status //
  unsigned char *p2 = heaper.malloc(20);
  cout << "\n-------------BlockList start------------------\n";
  heaper.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";

  // Doing the first deallocation and printing the current status //
  heaper.free(p1);
  cout << "\n-------------BlockList start------------------\n";
  heaper.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";

  // Doing an allocation too big for the freed block of memory and printing the current status //
  p1 = heaper.malloc(15);
  cout << "\n-------------BlockList start------------------\n";
  heaper.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";

  // Doing a deallocation of the most recently allocated memory and printing the current status //
  heaper.free(p1);
  cout << "\n-------------BlockList start------------------\n";
  heaper.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";

  // Doing the deallocation of the middle pointer of memory and printing the current status //
  heaper.free(p2);
  cout << "\n-------------BlockList start------------------\n";
  heaper.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";

  // Doing an allocation too big for the size of the heap and printing the current status //
  unsigned char * p3 = heaper.malloc(3000);
  if (!p3)
  {
    cout << "Invalid allocation of memory!\nNot enough memory available.\n";
  }
  cout << "\n-------------BlockList start------------------\n";
  heaper.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";


//=================================     Memory manager 2     ================================//


  // Printing header //
  cout << "\n------------------------------------------------------\n";
  cout << "-------------------  HEAP 2 TEST  --------------------\n";
  cout << "------------------------------------------------------\n\n";

  // Initializing the second heap and printing an informational message //
  MemoryManager heaper2(50);
  cout << "\nSecond heap initialized\n";

  // Printing the initial status of the heap //
  cout << "\n-------------BlockList start------------------\n";
  heaper2.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";

  // Doing the first allocation and printing the current status //
  unsigned char * p4 = heaper2.malloc(5);
  cout << "\n-------------BlockList start------------------\n";
  heaper2.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";

  // Doing the second allocation and printing the current status //
  unsigned char * p5 = heaper2.malloc(9);
  cout << "\n-------------BlockList start------------------\n";
  heaper2.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";

  // Doing the third allocation and printing the current status //
  unsigned char * p6 = heaper2.malloc(7);
  cout << "\n-------------BlockList start------------------\n";
  heaper2.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";

  // Doing the first deallocation and printing the current status //
  heaper2.free(p4);
  cout << "\n-------------BlockList start------------------\n";
  heaper2.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";

  // Doing the second deallocation and printing the current status //
  heaper2.free(p6);
  cout << "\n-------------BlockList start------------------\n";
  heaper2.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";

  // Doing the third deallocation and printing the current status //
  heaper2.free(p5);
  cout << "\n-------------BlockList start------------------\n";
  heaper2.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";

  // Doing an allocation too big for the size of the heap and printing the current status //
  unsigned char * p7 = heaper2.malloc(200);
  if (!p7)
  {
    cout << "Invalid allocation of memory!\nNot enough memory available.\n";
  }
  cout << "\n-------------BlockList start------------------\n";
  heaper2.showBlockList();
  cout << "--------------BlockList end-------------------\n\n";

  return 0;
}
