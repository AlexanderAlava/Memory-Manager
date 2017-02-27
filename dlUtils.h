//=================================================================================================//
//=02/20/2017                                                                      Alexander Alava=//
//=dlUtils.h                                                                             U35432961=//
//=                                                                                               =//
//=              This is the file of all the utilities to be used in other classes                =//
//=================================================================================================//

#ifndef __DLNODE__
#define __DLNODE__

#include <iostream>
#include <cassert>

// Declaring and defining a node struct //
template <class T>
class dlNode
{
  public:
  // Decaring data members and pointers //
  T info;
  dlNode<T> *prev;
  dlNode<T> *next;

  // Declaring and defining the constructor of the node //
  dlNode<T>(T val, dlNode<T> *p, dlNode<T> *n):info(val),prev(p),next(n){};
};

// Defining the print function that will display the information of the list //
template <class T>
void printDlList(dlNode<T>* header,dlNode<T> *trailer,const char *sep)
{
  // Checking if the list is empty and aborting if so //
  assert(header != NULL && trailer != NULL);

  // Declaring and initializing a node pointer //
  dlNode<T> *cursor = header->next;

  // Establishing a while loop to run through the whole list //
  while(cursor->next != trailer)
  {
    // Displaying the information of the current node //
    std::cout << cursor->info << sep;

    // Moving the node pointer to th next node //
    cursor = cursor->next;
  }

  // Checking if the current node is the last one with information //
  if (cursor->next == trailer)
  {
    // Displaying the information of the last node //
    std::cout << cursor->info << std::endl;
  }
}

// Defining a function that will insert a new node after the current one //
template <class T>
void insertAfter(dlNode<T> *trailer, dlNode<T> *current, T newval)
{
  // Checking if the current node is not the trailer //
  assert(current != trailer);

  // Initializing a new node and placing it after the current one //
  current->next = new dlNode<T>(newval,current,current->next);

  // Adjusting respective pointers //
  current = current->next;
  current->next->prev = current;
}

// Defining the function that will be used to clear the list //
template <class T>
void clearList(dlNode<T> *p)
{
  // Declaring and initializing a node pointer //
  dlNode<T> *hold = p;

  // Establishing a while loop to run through the whole list //
  while(p != NULL)
  {
    // Saving next node and deleting the current one //
    p = p->next;
    delete hold;
    hold = p;
  }
}

#endif
