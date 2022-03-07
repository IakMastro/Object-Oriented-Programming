/**
 * @file main.cpp
 * @author Iakovos Mastrogiannopoulos (iakmastro@sexycoders.org)
 * @brief This is a simple C++ example to introduce new people to the language
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */

// Libraries used
#include <iostream>

// Namespace used (WARNING: Not normally recommended)
using namespace std;


// Main function decleration
int main(int argc, char **argv) {
  // stdout
  cout << "Hello to your first C++ code!" << endl;

  // string decleration (same as char * in C)
  string name;

  cout << "What is your name? Give it here: ";
  cin >> name; // stdin

  // Printing a variable in C++ way
  cout << "Hello " << name << "!" << endl;

  // Return 0 to outside
  return 0;
}