#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "bard_functions.h"
#include <string>

using namespace std;

//Constructor for LinkedList, sets head to NULL
LinkedList :: LinkedList(){
  head = NULL;
}


//Algorithm for selection sort of a LinkedList
void sort(LinkedList *start){
	//Each iteration store the node to be compared to other nodes
  Node *prev = start->head;
  while(prev){
    Node *curr = prev->next; //Start comparing the other nodes starting with the next node of the compared node
    while(curr){
			//If frequency of the comparing Node is greater than then compared Node, or
			//If frequency is the same between the two Nodes, and the comparing Node is smaller
			//lexicographically than the compared Node, switch the data stored in each respective Node
      if(prev->frequency < curr->frequency || (prev->frequency == curr->frequency && prev->word > curr->word)){
        int temp_freq = prev->frequency;
        prev->frequency = curr->frequency;
        curr->frequency = temp_freq;
        string temp_word = prev->word;
        prev->word = curr->word;
        curr->word = temp_word;
      }
      curr = curr->next; //Change to next comparing Node
    }
    prev = prev->next; //Change to next compared Node
  }
}

//Function to check if a word exists in a given LinkedList
bool checkWord(string word, LinkedList *start){
  Node *temp = start->head;
  while(temp != NULL){ //Iterate through the LinkedList
    if(temp->word == word){ //If the desired word is found, increment it's frequency and return true
      temp->frequency += 1;
      return true;
      break;
    }
    temp = temp->next;
  }
  return false; //If word is not found, then word does not exist, return false
}

//Function to insert a word into the LinkedList
void insert(string word, LinkedList *start){
  if(checkWord(word, start)){ //Check to see if word exists already in LinkedList. If it does, word does not need to be inserted
    return; 
  }
	//Otherwise, create a new Node for the new word to be inserted at the head
  Node *latest = new Node;
  latest->word = word;
  latest->frequency = 1;
  latest->next = start->head;
  start->head = latest;
  return;
}


