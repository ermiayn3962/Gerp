/*
 *  main.cpp
 *  Yoda Ermias and Cooper Golemme
 *  04/15/2023
 *
 *  CS 15 Proj 4: Gerp
 *
 *  Purpose: Takes in input from the command line, checks if the input 
 *           is per the usage of gerp (otherwise prints usage to cerr).
 *           Sends user input for starting directory and output filename
 *           to the Gerp class constructor and starts the gerp program.
 *           Lastly, prints the good bye message.
 *
 */

#include "Gerp.h"

using namespace std;

int main(int argc, char *argv[])
{

    if (argc != 3){
        cerr << "Usage: ./gerp inputDirectory outputFile";
        cerr << endl;
        return EXIT_FAILURE;
    }
    
    Gerp main_program(argv[2], argv[1]);

    cout << "Goodbye! Thank you and have a nice day.\n";
    return 0;

}


