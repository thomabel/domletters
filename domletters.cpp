/*
Dominant Letters
Author: Thomas Abel
Date: 2021-06-26
*/

#include <iostream>

const int SIZE = 64;

int analyze(char* word){
  int total = 0;

  for (int i = 0; i < strlen(word); i++){
    char letter = tolower(word[i]);
    if (letter < 'a' || letter > 'z'){
      return 0;
    }
  }
  return total;
}

int readinput(){
  int total = 0;
  char* word = new char[SIZE];

  while(!EOF){
    std::cin.getline(word, SIZE, ' ');
    total += analyze(word);
  }  

  return total;
}

int main(){
  int total = readinput();

  std::cout
    << "The dominant letter total is " 
    << total << '.' << std::endl;

  return 1;
}
