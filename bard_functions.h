#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdexcept>
#include "bard_functions.h"
#include <string>
#include <string.h>
#include <string>
using namespace std;

typedef struct Node {
  std::string word;
  int frequency;
  Node *next;
} Node;


class LinkedList {
  public:
    Node *head;
    LinkedList(); 
};

void sort(LinkedList*);
bool checkWord(string, LinkedList*);
void insert(string, LinkedList*);



#endif
