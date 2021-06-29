/*
Dominant Letters
Author: Thomas Abel
Date: 2021-06-26
*/

#include <iostream>
#include <cstring>

// Constant values
// SIZE is the size of the input line.
// ABSZ is the size of the character set to be analyzed.
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
// Reads all text from standard input.
  int total = 0;
  char* line = new char[SIZE];
  char* word;

  // Reads by line.
  while (std::cin.getline(line, SIZE)){
    // Check again for blank lines.
    if (strlen(line) == 0)
      continue;
    // Tokenize the line into individual words and analyze.
    word = strtok(line, " ");
    while(word != NULL){
      total += analyze(word);
      word = strtok(NULL, " ");
    }
  }
  // Clean up.
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
