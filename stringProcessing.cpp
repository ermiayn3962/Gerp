/*
 *  stringProcessing.cpp
 *  Yodahie Ermias and Cooper Golemme
 *  04/15/2023
 *
 *  CS 15 Proj 4: Gerp
 *
 *  Purpose: Implements the stripNonAlphaNum function necessary for various
 *           aspects of the gerp program such as AnyString queries and hashing
 *
 */

#include "stringProcessing.h"


/*
 * name:      stripNonAlphaNum
 * purpose:   to remove trailing and leading non alpha numeric characters
 *            from a string
 * arguments: a string to remove from
 * returns:   the input string without leading and trailing non alpha numeric
 *            characters
 * effects:   none
 */
string stripNonAlphaNum(string input)
{
    int front_index = 0;
    int back_index = input.length() - 1;

    while (not isalnum(input[front_index])){
        front_index ++;
    }

    while (not isalnum(input[back_index])){
        back_index --;
    }

    if (back_index < front_index){
        return "";
    }
   
    int len_to_read = back_index - front_index + 1;

    return input.substr(front_index, len_to_read);
}