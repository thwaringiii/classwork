/*
main.cpp
CSE250 Project 1
Written and developed by Thomas Waring

This is the driver source file for my program. It contains the breakdown
of functionality for the user through outputs. If has error proofing to
prevent program failure, but a few segmentation fault errors slipped
through my fingers due to time constraints. Much of the program exists
within the sorts.cpp and sorts.h files.


 */

#include "sorts.h"
#include "Lexer.h"
#include "error_handling.h"
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void prompt() {
  cout << "> " << flush;
}

int main() {
  
  sorts mySorts;
  Lexer lexer;
  string line;
  vector<Token> token;
  string t1, t2, column, table, out;
  
  cout << endl << "Welcome to the future of sorting!" << endl;
  
  while(cin){

    cout << endl;
    cout << "When using the join or display functions, please use the " <<
      "following format:" << endl;
    cout << left << setw(13) << "For display: " << setw(8) << "display " <<
      "['filename.txt'] sortedby " << "[column name]" << endl;
    cout << left << setw(13) << "For nljoin: " << setw(8) << "nljoin " <<
      "['file1.txt'] ['file2.txt] " << 
      "[column name] ['outputfile.txt']" << endl;
    cout << left << setw(13) << "For smjoin: " << setw(8) << "smjoin " <<
      "['file1.txt'] ['file2.txt] " << 
      "[column name] ['outputfile.txt']" << endl << endl;
    cout << "Don't forget to put quotes around any filenames!" << endl;
    cout << "Please enter a command:" << endl << endl;
    prompt();
    
    getline(cin, line);
    lexer.set_input(line);
    token = lexer.tokenize();
    lexer.restart();
    
    if(token[0].value == "display"){
      if(token.size() == 4 && token[2].value == "sortedby"){
	table = token[1].value;
	column = token[3].value;
	mySorts.display(table, column);
	continue;
      } else {
	syntax_error();
      }
    }
    
    if(token[0].value == "nljoin"){
      if(token.size() == 5){
	t1 = token[1].value;
	t2 = token[2].value;
	column = token[3].value;
	out = token[4].value;
	mySorts.nljoin(t1, t2, column, out);
	continue;
      } else {
	syntax_error();
      }
    }
    
    if(token[0].value == "smjoin"){
      if(token.size() == 5){
	t1 = token[1].value;
	t2 = token[2].value;
	column = token[3].value;
	out = token[4].value;
	mySorts.smjoin(t1, t2, column, out);
	continue;
      } else {
	syntax_error();
      }
    }
    
    if(token[0].value == "exit"){
      cout << endl <<  "Sorting program exited successfully" << endl <<  endl;
      exit(0);
      continue;
      
    }
    
  }
}
