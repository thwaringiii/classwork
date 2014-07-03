/*
 * *****************************************************************************
 * file name : error_handling.h
 * author    : Hung Ngo
 * description : error reporting functions
 * *****************************************************************************
 */


#ifndef _ERROR_HANDLING_H
#define _ERROR_HANDLING_H

#include <string>
#include <stdexcept>

struct DBZ_Exception : public std::runtime_error {
    DBZ_Exception() : std::runtime_error("Divide by zero") {}
};

struct Syntax_Error_Exception : public std::runtime_error {
    Syntax_Error_Exception() : std::runtime_error("Syntax Error") {}
};

void error_quit(std::string);
void syntax_error();
void error_return(std::string);
void print_warning(std::string);
void note(std::string);

#endif
