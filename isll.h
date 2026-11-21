/*
** file: isll.h
**
** Integer singly linked list: the node and list types.
*/

#ifndef _ISLL_H
#define _ISLL_H

#include <iostream>
using namespace std;

// A node holds one integer and a pointer to the next node
struct Inode
{
   int item;    // the value stored in the node
   Inode *next; // the next node, or nullptr for the last one
};

// A singly linked list of integers, indexed from 0 to n - 1
class Isll
{
private:
   int n;       // number of nodes in the list
   Inode *head; // first node, or nullptr when the list is empty

public:
   Isll();
   ~Isll(); // frees every node

   void insert_0(int item);            // insert at the start
   void insert_pos(int pos, int item); // insert at a position (0 to n)
   void insert_end(int item);          // insert at the end
   void remove(int item);              // remove the first node with this value
   void alter(int pos, int item);      // change the value at a position
   void find(int item);                // report whether a value is in the list
   void print();                       // print the values from start to end
   void clear();                       // remove every node
};

#endif
// EOF
