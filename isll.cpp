/*
** file: isll.cpp
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

#include <iostream>
#include "isll.h"

// Construtor
Isll::Isll() : head(nullptr), n(0) {}

// Destrutor
Isll::~Isll()
{
  clear();
}

// Inserir item no início da lista
void Isll::insert_0(int item)
{
  Inode *newNode = new Inode(); // Cria um novo bebé (nó) e guarda o apontador para ele
  newNode->item = item;         // Dá um nome (valor) ao bebé
  newNode->next = head;         // Aponta para o bebé que estava antes no início (o antigo mais velho)
  head = newNode;               // Agora este novo bebé é o primeiro da fila (o novo head)
  n++;                          // Aumenta o número de bebés (nós) na lista
}

// Inserir item em posição específica
void Isll::insert_pos(int pos, int item)
{
  if (pos < 0 || pos > n)
    return; // Posicao inválida

  Inode *newNode = new Inode; // Cria um novo bebé (nó) e guarda o apontador para ele
  newNode->item = item;       // Dá um nome (valor) ao bebé

  if (pos == 0)
  {
    newNode->next = head;
    head = newNode;
  }
  else
  {
    Inode *current = head;            // Começa no início da lista (na primeira criança da fila)
    for (int i = 0; i < pos - 1; i++) // Avança até ao nó que está imediatamente antes da posição onde queremos inserir
    {
      current = current->next; // Vai andando pela fila, passando de criança em criança
    }
    newNode->next = current->next; // O novo bebé dá a mão ao que vinha a seguir ao current
    current->next = newNode;       // O current agora passa a dar a mão ao novo bebé
  }

  n++;
}

void Isll::insert_end(int item)
{
  Inode *newNode = new Inode; // Cria um novo nó (bebê)
  newNode->item = item;       // Dá o nome ao bebê
  newNode->next = nullptr;    // Diz que este nó é o último (não aponta para nada)

  if (head == nullptr) // Se a lista estiver vazia
  {
    head = newNode; // O novo nó se torna o primeiro da lista
  }
  else
  {
    Inode *current = head;           // Começa a partir da cabeça da lista
    while (current->next != nullptr) // Enquanto não chegarmos ao último nó
    {
      current = current->next; // Avança para o próximo nó
    }
    current->next = newNode; // O último nó agora aponta para o novo nó
  }
  n++; // Aumenta a contagem de nós
}

// Remover item da lista
void Isll::remove(int item)
{
  if (head == nullptr)
  {
    std::cout << "Lista vazia!" << std::endl;
    return;
  }

  // Caso especial: remover o primeiro nó
  if (head->item == item)
  {
    Inode *temp = head;
    head = head->next;
    delete temp;
    n--;
    return;
  }

  Inode *current = head;
  while (current->next != nullptr && current->next->item != item)
  {
    current = current->next;
  }

  if (current->next == nullptr)
  {
    std::cout << "Item não encontrado!" << std::endl;
  }
  else
  {
    Inode *temp = current->next;
    current->next = current->next->next;
    delete temp;
    n--;
  }
}

// Alterar item na posição
void Isll::alter(int pos, int item)
{
  if (pos < 0 || pos >= n)
  {
    std::cout << "Posição inválida!" << std::endl;
    return;
  }

  Inode *current = head;
  for (int i = 0; i < pos; ++i)
  {
    current = current->next;
  }

  current->item = item;
}

// Procurar item na lista
void Isll::find(int item)
{
  Inode *current = head;
  while (current != nullptr)
  {
    if (current->item == item)
    {
      std::cout << "Item encontrado: " << item << std::endl;
      return;
    }
    current = current->next;
  }
  std::cout << "Item não encontrado!" << std::endl;
}

// Imprimir a lista
void Isll::print()
{
  if (head == nullptr)
  {
    std::cout << "Lista vazia!" << std::endl;
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

// Limpar a lista
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