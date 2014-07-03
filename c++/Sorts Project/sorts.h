
/*
sorts.h
CSE250 Project 1
Written and developed by Thomas Waring
*/

#ifndef _SORTS_H
#define _SORTS_H

#include "Lexer.h"
#include <string>
#include <vector>
#include <fstream>

struct Record {

  std::string key;
  std::string rest;

Record(std::string k = "", std::string r = "") : key(k), rest(r) {}
};

class sorts {

 public:
  
  void display(std::string, std::string);
  void nljoin(std::string, std::string, std::string, std::string);
  void smjoin(std::string, std::string, std::string, std::string);
  Record recordize(std::string, int);
  sorts() {}

 private:

  std::vector<Token> lexerize(std::string);
  std::string combo(Record, Record);
  std::string print(std::vector<Token>);

  std::string displayPrint(std::vector<Token>);

  int findmatch(std::string, std::vector<Token>);
  void sortby(int, std::vector<std::string>&);
  bool check_unique(std::vector<Record>);
};

#endif
