/*
** file: isll.h
**
** single linked list
** UC: 21046 - EDAF @ UAb
** e-fólio A 2024-25
**
** Aluno: André Bernardo
*/

// Defina:
//   Em isll.h as classes da estrutura de dados
//   Em isll.cpp a implementação dos métodos das classes da estrutura de dados
// ** Não altere o nome das classes nem dos atributos obrigatórios! **

#ifndef _ISLL_H
#define _ISLL_H

#include <iostream>
using namespace std;

// definir nó
struct Inode
{
   // atributos obrigatórios
   int item;    // informação em cada nó
   Inode *next; // ponteiro para o próximo nó
   // outros atributos e métodos (protótipos) livres
};

// definir lista simplesmente ligada
class Isll
{
private:
   // atributos obrigatórios
   int n;       // Dimensão atual da lista (indexação de 0 a n-1)
   Inode *head; // Ponteiro para o primeiro nó da lista
   // outros atributos e métodos (protótipos) livres

public:
   Isll();  // construtor
   ~Isll(); // destrutor

   // Métodos
   void insert_0(int item);            // inserir no início
   void insert_pos(int pos, int item); // inserir em posição específica
   void insert_end(int item);          // inserir no fim
   void remove(int item);              // remover item
   void alter(int pos, int item);      // alterar item na posição
   void find(int item);                // procurar item
   void print();                       // imprimir a lista
   void clear();                       // limpar a lista
};

#endif
// EOF
