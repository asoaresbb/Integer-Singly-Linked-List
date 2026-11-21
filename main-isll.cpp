/*
** file: main-isll.cpp
**
** single linked list
** UC: 21046 - EDAF @ UAb
** e-fólio A 2024-25
**
** Aluno: André Bernardo
*/

// Defina neste ficheiro:
//   A entrada/saída de dados
//   As instâncias da classe da estrutura de dados
//   A implementação dos comandos através dos métodos da classe
//   Código auxiliar
//   Não utilize variáveis globais!

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

      // Processa o comando
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
         int oldItem, newItem;
         ss >> oldItem >> newItem;
         list.alter(oldItem, newItem);
      }
      else
      {
         cout << "Comando desconhecido: " << command << endl;
      }
   }

   return 0;
}

// EOF
