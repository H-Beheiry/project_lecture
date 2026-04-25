#ifndef CONSOLE_UTILS_H
#define CONSOLE_UTILS_H

#include <iostream>
#include <string>
using namespace std;

const string RESET=   "\033[0m";
const string BOLD=    "\033[1m";
const string RED=     "\033[31m";
const string GREEN=   "\033[32m";
const string CYAN=    "\033[36m";
const string MAGENTA= "\033[35m";
const string YELLOW=  "\033[33m";
const string WHITE=   "\033[37m";
const string BLUE=    "\033[34m";


void clearScreen();
void pauseConsole();
void printHeader();

#endif