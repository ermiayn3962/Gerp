/*
 *  stringProcessing.h
 *  Yodahie Ermias and Cooper Golemme
 *  04/15/2023
 *
 *  CS 15 Proj 4: Gerp
 *
 *  Purpose: Declares the stripNonAlphaNum function and any helpers it needs
 *           for Gerp
 *
 */

#ifndef __String_Processing_H__
#define __String_Processing_H__

#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

string stripNonAlphaNum(string input);
bool isAlphaNum(char c);

#endif