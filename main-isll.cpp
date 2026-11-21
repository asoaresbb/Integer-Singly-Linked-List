/*
** file: main-isll.cpp
**
** Reads commands from the standard input, one per line, and runs them on
** an integer singly linked list. Unknown commands are reported.
*/

#include <iostream>
#include <sstream>
#include <string>
#include "isll.h"

using namespace std;

int main()
{
   Isll list;
   string command;

   // Reads one command per line until the end of the input (end of file or Ctrl+D)
   while (getline(cin, command))
   {
      if (command.empty())
      {
         continue;
      }

      // The first word is the command; the rest are its numbers
      stringstream ss(command);
      string cmd;
      ss >> cmd;

      if (cmd == "insert_0")
      {
         int item;
         while (ss >> item)
         {
            list.insert_0(item);
         }
      }
      else if (cmd == "insert_pos")
      {
         int pos, item;
         ss >> pos >> item;
         list.insert_pos(pos, item);
      }
      else if (cmd == "insert_end")
      {
         int item;
         while (ss >> item)
         {
            list.insert_end(item);
         }
      }
      else if (cmd == "find")
      {
         int item;
         ss >> item;
         list.find(item);
      }
      else if (cmd == "remove")
      {
         int item;
         ss >> item;
         list.remove(item);
      }
      else if (cmd == "print")
      {
         list.print();
      }
      else if (cmd == "clear")
      {
         list.clear();
      }
      else if (cmd == "alter")
      {
         int pos, item;
         ss >> pos >> item;
         list.alter(pos, item);
      }
      else
      {
         cout << "Unknown command: " << command << endl;
      }
   }

   return 0;
}

// EOF
