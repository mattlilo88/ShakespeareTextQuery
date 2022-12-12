#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdexcept>
#include "bard_functions.h"
#include <string>
#include <string.h>

using namespace std;


int main(int argc, char** argv){
  
  //Checks if user provides two valid arguments, if not throw an error message
  if (argc != 3) {
    throw std::invalid_argument("Usage: ./bard <INPUT FILE> <OUTPUT FILE>");
  }

	//Store the biggest length of a word in shakespeare-cleaned5.txt file
  int maxLen = 36;

	//Stream for the shakespeare-cleaned5.txt file
  ifstream txtfile("shakespeare-cleaned5.txt");

	//Create an array of LinkedList of size maxLen to store the words from shakespeare-cleaned5.txt
  LinkedList **table;
  table = new LinkedList*[maxLen];
  for(int i = 0; i <= maxLen; i++){
    table[i] = new LinkedList(); //Initialize each array element with a LinkedList
  }
  
	//Open the shakespeare-cleaned5.txt file for reading. Loop through each line of the file to store each word in the array of LinkedList
  string word; 
  while(getline(txtfile, word)){
    int length = word.length();
    if (table[length]->head == NULL){ //If LinkedList's head in the corresponding array element is NULL, create a new Node to store word
      Node *temp = new Node;
      temp->word = word;
      temp->frequency = 1;
      temp->next = NULL;
      table[length]->head = temp;
    }
    else {
      insert(word, table[length]); //Insert the respective word at its corresponding LinkedList
    }
  }
  txtfile.close(); //Close the txt file
  
  //Loop through each LinkedList in the array, sorting each LinkedList by decreasing order of frequency
  //and increasing lexicographic order
  for(int i = 0; i <= maxLen; i++){
    sort(table[i]);
  }

  //Stream for input and output files
  ifstream inputBard;
  ofstream outputBard;

  //Open input file for reading and output file for writing
  inputBard.open(argv[1]);
  outputBard.open(argv[2]);

  string inputLine; //Stores each line of Input in a string
  char *strLength; //Stores the length part of the Input in a string
  char *strRank; //Stores the rank part of the Input in a string
  char *query; //Used to store the inputLine as a C-style string
  int length; //Used to store the length part of the Input as an Int
  int rank; //Used to store the rank part of the Input as an Int
  int counter; //Used to get to the specific rank in a LinkedList
  char *placeHolder; //Used for strtol

  //Loop through the input file, processing the given query, storing the length and rank inputs then 
  //finding the corresponding word if it exists
  while(getline(inputBard, inputLine)){
    counter = 0;
    if(inputLine.length() == 0){
      continue;
    }
		//Process the current line, 
    query = strdup(inputLine.c_str());
    strLength = strtok(query, " \t");
    strRank = strtok(NULL, " \t");
    length = strtol(strLength, &placeHolder, 10);
    rank = strtoul(strRank, &placeHolder, 10); //Used strtoul here to permit negative numbers
    if(length > maxLen || length < 0){
      outputBard << "-" << endl;
      continue;
    }
    Node *curr = table[length]->head;
    if(curr == NULL){
      outputBard << "-" << endl;
      continue;
    }
		if(rank < 0){
			outputBard << "-" << endl;
			continue;
		}
    while(counter < rank){
      if(curr->next == NULL){
        outputBard << "-" << endl;
        break;
      }
      curr = curr->next;
      counter += 1;
    }
    if(counter == rank){
      outputBard << curr->word << endl;
    }
  }
  inputBard.close();
  outputBard.close();
}