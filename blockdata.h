//=================================================================================================//
//=02/20/2017                                                                      Alexander Alava=//
//=blockdata.h                                                                           U35432961=//
//=                                                                                               =//
//=                       This is the header file for the blockdata class                         =//
//=================================================================================================//

#ifndef _BLOCKDATA_
#define _BLOCKDATA_

#include <iostream>

using namespace std;

// Declaring and defining the blockdata struct //
class blockdata
{
  // Declaring the overloading operator << function to be a friend of this class //
  friend ostream& operator << (ostream&, const blockdata &);

  public:
  // Declaring the constructor of the blockdata struct //
  blockdata(unsigned int s, bool f, unsigned char *p);

  // Declaring the data members and pointers of the struct //
  int blocksize;
  bool free;
  unsigned char *blockptr;
};


#endif
