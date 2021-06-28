/*
Dominant Letters
Author: Thomas Abel
Date: 2021-06-26
*/

#include <iostream>
#include <cstring>

const int SIZE = 64;

int analyze(char* word){
// Analyzes a single word to find the dominant letter count.
// Uses an array of the 26 lower-case letters to store counts.
  int alphabet[26];
  for (int j = 0; j < 26; j++){
    alphabet[j] = 0;
  } 

  for (int i = 0; i < (int)strlen(word); i++){
    // Make all characters lower-case
    char letter = tolower(word[i]);
    // Ignore new line characters.
    if (letter == '\n')
      continue;
    // Reject if there are any non-letter characters.
    if (letter < 'a' || letter > 'z'){
      return 0;
    }
    // Add to array.
    alphabet[letter - 'a'] += 1;
  }

  // Find max value from array.
  int total = 0;
  for (int j = 0; j < 26; j++){
    if (alphabet[j] > total)
      total = alphabet[j];
  }
  return total;
}

int readinput(){
// Reads word by word from standard input.
// Stops when empty string is read.
  int total = 0;
  char* word = new char[SIZE];

  do {
    std::cin.getline(word, SIZE, ' ');
    total += analyze(word);
  } while(word[0] != '\0');

  return total;
}

int main(){
  int total = readinput();

  std::cout
    << "The dominant letter total is " 
    << total << '.' << std::endl;

  return 1;
}
