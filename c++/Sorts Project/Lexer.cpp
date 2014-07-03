/**
 * *****************************************************************************
 * file name : Lexer.cpp
 * author    : Hung Q. Ngo
 * description: implementation of Lexer interface
 * *****************************************************************************
 */
#include "Lexer.h"
#include <iostream>
#include <cctype> // for isalpha(), isalnum(), isdigit()
using namespace std;

/**
 * -----------------------------------------------------------------------------
 *  scan and return the next token
 *  cur_pos then points to one position right past the token
 *  the token type is set to ERRTOK on error
 * -----------------------------------------------------------------------------
 */
Token Lexer::next_token() {
    Token ret(ENDTOK, ""); // the default token is the ENDTOK
    size_t last;

    if (has_more_token()) {
        last = cur_pos++; // input_str[last] is a non-space char
        switch (input_str[last]) {
            case '+': case '-': case '*': case '/': case '=':
                ret.type = OPERATOR;
                ret.value = input_str[last];
                break;
            case '[': case ']': case '{': case '}':
                ret.type = DELIM;
                ret.value = input_str[last];
                break;
	    case '(':
	      while (cur_pos < input_str.length() && input_str[cur_pos] != ')')
		cur_pos++;
	      if (cur_pos < input_str.length()) {
		ret.type = DROPIT;
		ret.value = "";
		cur_pos++;        // move past the closing "
	      } else {
		ret.type = ERRTOK;
		ret.value = "";
		cur_pos = last+1; // move past the error "
	      }
	      break;
	  
            case '"': // scanning for STRING
	      while (cur_pos < input_str.length() && input_str[cur_pos] != '"')
		cur_pos++;
	      if (cur_pos < input_str.length()) {
		ret.type = STRING;
		ret.value = input_str.substr(last+1, cur_pos-last-1);
		cur_pos++;        // move past the closing "
	      } else {
		ret.type = ERRTOK;
		ret.value = '"';
		cur_pos = last+1; // move past the error "
	      }
	      break;
	    case '#': // scanning to '\n' or end of input
	      while (cur_pos < input_str.length() 
		     && input_str[cur_pos] != '\n')
		cur_pos++;
	      ret.type = COMMENT;
	      ret.value = input_str.substr(last, cur_pos-last);
	      break;
	    default:
                if (isdigit(input_str[last])) { 
                    // scanning for INTEGER
                    while (cur_pos < input_str.length() &&
                           isdigit(input_str[cur_pos])) 
                        cur_pos++;
                    ret.type  = INTEGER;
                    ret.value = input_str.substr(last, cur_pos-last);
                } else if (isalpha(input_str[last]) || input_str[last] == '_') {
                    // scanning for IDENT, can start with alpha or _
                    while ( cur_pos < input_str.length() &&
                            (isalnum(input_str[cur_pos]) ||
                            input_str[cur_pos] == '_') )
                        cur_pos++;
                    ret.type  = IDENT;
                    ret.value = input_str.substr(last, cur_pos-last);
                } else { 
                    // just an error token here
                    ret.type = ERRTOK;
                    ret.value = input_str[last];
                }
        }
    }
    return ret;
}

/**
 * -----------------------------------------------------------------------------
 *  return a vector of all tokens left
 *  we will not restart after tokenizing
 * -----------------------------------------------------------------------------
 */
vector<Token> Lexer::tokenize() {
    vector<Token> ret;
    Token tok;
    while (has_more_token()) {
        tok = next_token();
        ret.push_back(tok);
    }
    return ret;
}

/**
 * -----------------------------------------------------------------------------
 *  set a new input string, restart
 * -----------------------------------------------------------------------------
 */
void Lexer::set_input(string str) {
    input_str = str;
    restart();
}

/**
 * -----------------------------------------------------------------------------
 * -----------------------------------------------------------------------------
 */
bool Lexer::has_more_token() {
    while (cur_pos < input_str.length() && 
            separators.find(input_str[cur_pos]) != string::npos) {
        cur_pos++;
    }
    return (cur_pos < input_str.length());
}

/**
 * -----------------------------------------------------------------------------
 *  restart from the beginning
 * -----------------------------------------------------------------------------
 */
void Lexer::restart() {
    cur_pos = 0;
}
