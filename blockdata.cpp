//=================================================================================================//
//=02/20/2017                                                                      Alexander Alava=//
//=blockdata.cpp                                                                         U35432961=//
//=                                                                                               =//
//=                   This is the implementation file for the blockdata class                     =//
//=================================================================================================//

#include "dlUtils.h"
#include "blockdata.h"
#include <iostream>
using namespace std;

// Defining the constructor of the blockdata struct //
blockdata::blockdata(unsigned int s, bool f, unsigned char *p)
{
  // Assigning values inputted as parameters to the data members //
  blocksize = s;
  free = f;
  blockptr = p;
}

// Overloading the << operator in order to use it for blockdata //
ostream &operator << (ostream &out, const blockdata &B)
{
  // Outputting the blocksize of the node to an ostream variable //
  out << "[" << B.blocksize << ",";

  // Checking if the node is free or not and adding the value to the outstream variable //
  if (B.free)
    out << "free";
  else
    out << "allocated";
  out << "]";

  // Returning the outstream variable //
  return out;
}
