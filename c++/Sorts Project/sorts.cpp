/*
sorts.cpp
CSE250 Project 1
Written and developed by Thomas Waring

This is the source file for my nljoin, smjoin, and display functions.
We ran into a number of segmentation faults that we understood, but
had trouble avoiding without causing syntactical problems or unreadable
outputs.

My biggest problem lies in the overuse of the "lexerize" function,
which was used to remove the awful parenthesis found at the top of 
Prof. Ngo's .txt files, used to identify the column type. I attempted
to flush out these ()'s by tweaking the Lexer.cpp file to remove any ()'s
and replace them with spaces. By running tokenize a second time, these
spaces would be removed. Unfortunately, I ran out of time attempting to 
identify my columns at their proper width and token type. Because of
that, you see sorted/joined output files that lack the identified types.
Full names and Course_ID's (ex. CSE 250) break into two strings. While
this made displaying sorted/joined files look terrible, all three
functions work fine on their own.

 */

#include <string>
#include <fstream>
#include <iostream>
#include "Lexer.h"
#include "sorts.h"
#include "search_sort.h"
#include <vector>
#include "error_handling.h"

using namespace std;

ifstream file1, file2;
ofstream output;

void sorts::nljoin(string t1, string t2, string cname, string out){
  vector<Token> first, second;
  string line1, line2, temp;
  int match1, match2;
  Record rec1, rec2;
  file1.open(t1.c_str());
  file2.open(t2.c_str());
  if(file1.is_open()){
    getline(file1, line1);
    first = lexerize(line1);
    temp = displayPrint(first);
    first = lexerize(temp);
    match1 = findmatch(cname, first);
    rec1 = recordize(print(first), match1);
  } else {
    error_return("Unable to open first file!");
  }
  if(file2.is_open()){
    getline(file2, line2);
    second = lexerize(line2);
    temp = displayPrint(second);
    second = lexerize(temp);
    match2 = findmatch(cname, second);
    rec2 = recordize(print(second), match2);
  } else {
    error_return("Unable to open second file!");
  }
  output.open(out.c_str());
  
  if(file1.is_open() && file2.is_open()){
    output << combo(rec1, rec2) << endl;
    file2.close();
    while(getline(file1, line1)){
      file2.open(t2.c_str());
      rec1 = recordize(line1, match1);
      while(getline(file2, line2)){
	rec2 = recordize(line2, match2);
	if(rec1.key == rec2.key){
	  output << combo(rec1, rec2) << endl;
	}
      }
      file2.close();
    }
    file1.close();
    output.close();
    cout << endl << "nljoin Completed Successfully" << endl;
  }
}

void sorts::smjoin(string st1, string st2, string scname, string sout){
  vector<Token> first, second;
  string line1, line2, temp;
  int match1, match2;
  vector<string> content1, content2;
  Record rec1, rec2;
  file1.open(st1.c_str());
  file2.open(st2.c_str());
  
  if(file1.is_open()){
    getline(file1, line1);
    first = lexerize(line1);
    temp = displayPrint(first);
    first = lexerize(temp);
    match1 = findmatch(scname, first);
    while(getline(file1, line1)){
      content1.push_back(line1);
    }
  } else {
    error_return("Unable to open first file!");
  }
  if(file2.is_open()){
    getline(file2, line2);
    second = lexerize(line2);
    temp = displayPrint(second);
    second = lexerize(temp);
    match2 = findmatch(scname, second);
    while(getline(file2, line2)){
      content2.push_back(line2);
    }
  } else {
    error_return("Unable to open second file!");
  }
  output.open(sout.c_str());
  if(file1.is_open() && file2.is_open()){
    
    rec1 = recordize(print(first), match1);
    rec2 = recordize(print(second), match2);
    output << combo(rec1, rec2) << endl;
    sortby(match1, content1);
    sortby(match2, content2);
    vector<Record> records1, records2;
    Record null;
    null.key = "Null Key";
    null.rest = "Null the Rest";
    for(int i = 0; i <= content1.size()-1; i++){
      records1.push_back(recordize(content1[i], match1));
    }
    for(int i = 0; i <= content2.size()-1; i++){
      records2.push_back(recordize(content2[i], match2));
    }
    records1.push_back(null);
    records2.push_back(null);
    if(check_unique(records1) && check_unique(records2)){
      vector<Record>::iterator it, it2;
      it = records1.begin();
      it2 = records2.begin();
      while(it->key != records1[records1.size()-1].key or
	    it2->key != records2[records2.size()-1].key) {
	if(it->key == it2->key){
	  output << combo(*it, *it2) << endl;
	  it++; it2++;
	} else {
	  if(it->key < it2->key){
	    it++;
	  } else {
	    it2++;
	  }
	}
      }
      cout << endl << "smjoin Completed Successfully" << endl;
      
    } else {
      error_return("Cannot smjoin over a non-unique column!");
    }
    file1.close();
    file2.close();
    output.close();
    
  }//end of if files are open loop
}

void sorts::display(string dt1, string dcname){
  file1.open(dt1.c_str());
  string line, temp;
  int match;
  vector<string> content;
  vector<Token> first;
  
  if(file1.is_open()){
    getline(file1, line);
    first = lexerize(line);

    //first = lexerize(line);
    temp = displayPrint(first);
    first = lexerize(temp);
    cout << displayPrint(first) << endl;
    match = findmatch(dcname, first);
    while(getline(file1, line)){
      content.push_back(line);
    }
  } else {
    cout << "Unable to open file!" << endl;
  }
  sortby(match, content);
  for(int i = 0; i <= content.size()-1; i++){
    cout << content[i] << endl;
  }
  file1.close();
}


/* These member functions help out the sorts, and decrease code bloat */

vector<Token> sorts::lexerize(string line){
  Lexer lexer;
  vector<Token> ret;
  lexer.set_input(line);
  ret = lexer.tokenize();
  return ret;
}

string sorts::combo(Record first, Record second){
  string ret;
  ret.append(first.key + " " +first.rest + " " + second.rest);
  return ret;
}

int sorts::findmatch(string match, vector<Token> vec){
  vector<int> secondvec;
  for(int i = 0; i <=vec.size()-1; i++){
    secondvec.push_back(1);
    if(vec[i].value == match){
      break;
    }
    if(i == vec.size()-1){
      error_return("No match for " + match + " found!");
    }
  }
  int ret = secondvec.size()-1;
  return ret;
}


string sorts::displayPrint(vector<Token> vec){
  string ret;
  for(int i = 0; i <= vec.size()-1; i++){
      ret.append( vec[i].value + " ");
  }
  return ret;
}



string sorts::print(vector<Token> vec){
  string ret;
  for(int i = 0; i <= vec.size()-1; i++){
    if(vec[i].type = STRING){
      ret.append('"' + vec[i].value + '"' + " ");
    } else {
      ret.append( vec[i].value + " ");
    }
  }
  return ret;
}

void sorts::sortby(int match, vector<string> &vec){
  string temp;
  vector<Token> tempvec;
  vector<Token>::iterator it;
  for(int i = 0; i <= vec.size()-1; i++){
    temp = vec[i];
    tempvec = lexerize(temp);
    it = tempvec.begin();
    tempvec.insert(it, 1, tempvec[match]);
    temp = print(tempvec);
    vec[i] = temp;	
  }
  randomized_quick_sort(vec);
  for(int j = 0; j <= vec.size()-1; j++){
    temp = vec[j];
    tempvec = lexerize(temp);
    it = tempvec.begin();
    tempvec.erase(it);
    temp = print(tempvec);
    vec[j] = temp;
  }
  
}

Record sorts::recordize(string st, int match){
  vector<Token> temp = lexerize(st);
  string key = temp[match].value;
  string rest;
  for(int i = 0; i <= temp.size()-1; i++){
    if(temp[i].value != temp[match].value)
      rest.append(temp[i].value + " ");
  }
  Record ret;
  ret.key = key;
  ret.rest = rest;
  return ret;
}

bool sorts::check_unique(vector<Record> vec){
  string temp;
  temp = vec[0].key;
  bool ret;
  for(int i = 1; i <= vec.size()-1; i++){
    if(temp != vec[i].key){
      ret = true;
    } else {
      ret = false;
      break;
    }
    temp = vec[i].key;
  }
  return ret;
}
