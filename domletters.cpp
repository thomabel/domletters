/*
Dominant Letters
Author: Thomas Abel
Date: 2021-06-26
*/

#include <iostream>
#include <cstring>

const int SIZE = 128;
const int ABSZ = 26;

int analyze(char* word){
// Analyzes a single word to find the dominant letter count.
// Uses an array of the 26 lower-case letters to store counts.
  int alphabet[ABSZ];
  for (int j = 0; j < ABSZ; j++)
    alphabet[j] = 0;

  for (int i = 0; i < (int)strlen(word); i++){
    // Make all characters lower-case
    char letter = tolower(word[i]);
    // Ignore new line characters.
    if (letter == '\n')
      continue;
    // Reject if there are any non-letter characters.
    if (letter < 'a' || letter > 'z')
      return 0;

    // Add to array.
    alphabet[letter - 'a'] += 1;
  }

  // Find max value from array.
  int total = 0;
  for (int j = 0; j < ABSZ; j++){
    if (alphabet[j] > total)
      total = alphabet[j];
  }
  return total;
}

int readinput(){
// Reads from standard input.
  int total = 0;
  char* line = new char[SIZE];
  char* word;
  //char peek;

  while (std::cin.getline(line, SIZE)){
    if (strlen(line) == 0)
      continue;
    word = strtok(line, " ");
    while(word != NULL){
      total += analyze(word);
      word = strtok(NULL, " ");
    }
  }
/*
  do {
    // Gets a line from the input.
    std::cin.getline(line, SIZE);
    // Breaks it down into separate words.
    word = strtok(line, " ");
    while(word != NULL){
      total += analyze(word);
      word = strtok(NULL, " ");
    }
    // Peek the next character.
    //peek = std::cin.peek();
    //std::cout << peek << std::endl;
  } while(line != "" || cin.good());
*/
  delete[] line;
  return total;
}

// MAIN
int main(){
  int total = readinput();

  std::cout
    << "The dominant letter total is " 
    << total << '.' << std::endl;

  return 1;
}
