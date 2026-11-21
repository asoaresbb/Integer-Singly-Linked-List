/*
** file: isll.cpp
**
** Integer singly linked list: the list operations.
*/

#include <iostream>
#include "isll.h"

Isll::Isll() : n(0), head(nullptr) {}

Isll::~Isll()
{
  clear();
}

// Insert at the start: the new node points to the old first node and becomes the head
void Isll::insert_0(int item)
{
  Inode *newNode = new Inode();
  newNode->item = item;
  newNode->next = head;
  head = newNode;
  n++;
}

// Insert at position pos (0 = start, n = end); invalid positions are ignored
void Isll::insert_pos(int pos, int item)
{
  if (pos < 0 || pos > n)
    return;

  Inode *newNode = new Inode;
  newNode->item = item;

  if (pos == 0)
  {
    newNode->next = head;
    head = newNode;
  }
  else
  {
    // Walk to the node just before the position, then link the new node after it
    Inode *current = head;
    for (int i = 0; i < pos - 1; i++)
    {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }

  n++;
}

// Insert at the end: walk to the last node and link the new node after it
void Isll::insert_end(int item)
{
  Inode *newNode = new Inode;
  newNode->item = item;
  newNode->next = nullptr;

  if (head == nullptr)
  {
    head = newNode;
  }
  else
  {
    Inode *current = head;
    while (current->next != nullptr)
    {
      current = current->next;
    }
    current->next = newNode;
  }
  n++;
}

// Remove the first node with this value
void Isll::remove(int item)
{
  if (head == nullptr)
  {
    std::cout << "The list is empty." << std::endl;
    return;
  }

  // The first node is a special case: the head moves to the next node
  if (head->item == item)
  {
    Inode *temp = head;
    head = head->next;
    delete temp;
    n--;
    return;
  }

  // Stop at the node before the one to remove, so it can be unlinked
  Inode *current = head;
  while (current->next != nullptr && current->next->item != item)
  {
    current = current->next;
  }

  if (current->next == nullptr)
  {
    std::cout << "Item not found." << std::endl;
  }
  else
  {
    Inode *temp = current->next;
    current->next = current->next->next;
    delete temp;
    n--;
  }
}

// Change the value at position pos (0 to n - 1)
void Isll::alter(int pos, int item)
{
  if (pos < 0 || pos >= n)
  {
    std::cout << "Invalid position." << std::endl;
    return;
  }

  Inode *current = head;
  for (int i = 0; i < pos; ++i)
  {
    current = current->next;
  }

  current->item = item;
}

// Report whether a value is in the list
void Isll::find(int item)
{
  Inode *current = head;
  while (current != nullptr)
  {
    if (current->item == item)
    {
      std::cout << "Item found: " << item << std::endl;
      return;
    }
    current = current->next;
  }
  std::cout << "Item not found." << std::endl;
}

// Print the values from start to end, separated by spaces
void Isll::print()
{
  if (head == nullptr)
  {
    std::cout << "The list is empty." << std::endl;
    return;
  }

  Inode *current = head;
  while (current != nullptr)
  {
    std::cout << current->item << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

// Free every node and leave the list empty
void Isll::clear()
{
  while (head != nullptr)
  {
    Inode *temp = head;
    head = head->next;
    delete temp;
  }
  n = 0;
}

// EOF
