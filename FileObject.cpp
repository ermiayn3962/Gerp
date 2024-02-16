/*
 *  FileObject.cpp
 *  Yoda Ermias and Cooper Golemme
 *  04/15/2023
 *
 *  CS 15 Proj 4: Gerp
 *
 *  Purpose: Implements the FileObject class where each file in a directory
 *           has its own hash table associated with it as well as the 
 *           print_occurances function which will be vital to running the 
 *           various search queries in the Gerp program
 *
 */

#include "FileObject.h"
#include <algorithm>

using namespace std;

/*
 * name:      FileObject
 * purpose:   constructor for the FileObject class that initalizes
 *            the private member variables in the class and calls
 *            the read_file operation
 * arguments: takes in a string path containing the filepath of
 *            the instance of the class 
 * returns:   none
 * effects:   creates an object of the FileObject class and files
 *            a hash table containing the data from the file
 */
FileObject::FileObject(string path)
{

    filepath = path;
    read_file(path); //intializes the hash table for the object
    
}

/*
 * name:      read_file
 * purpose:   reads in all the words in a file and inserts them 
 *            into a hash table
 * arguments: takes in a string filename 
 * returns:   none
 * effects:   creates a hash table associated with a file
 */
void FileObject::read_file(string filename)
{
    
    ifstream infile(filename);

    if (not infile.is_open()){
        throw runtime_error("Unable to open file " + filename);
    }

    string current_word = "";
    string current_line = "";
    int line_count = 0;

    while (getline(infile, current_line)){ 
        line_count++;

        //storing for getlined string for printing purposes
        lines.push_back(current_line);

        istringstream line_stream(current_line);
        while (line_stream >> current_word){
            current_word = stripNonAlphaNum(current_word);

            /* adding to hash table */
            words_hash.insert(current_word, line_count);
        }
    }
    infile.close();
}

/*
 * name:      print_occurances
 * purpose:   checks if a given key is in the hash table and
 *            also checks if the case sensitivity should be 
 *            considered when looking for that key
 * arguments: takes in a string key, a bool case_sensitivity,
 *            and an ostream pointer to the location the instances
 *            should be printed to 
 * returns:   a bool true or false if the key was found in a file
 * effects:   none
 */
bool FileObject::print_occurances(string key, bool case_sensitity, 
                                  ostream &output)
{
    bool found = false;
    int idx = words_hash.find(key);

    if (idx == -1 or key == ""){
        return false;
    }

    for (auto &it : *words_hash.getList(idx)){
        if (case_sensitity){
            if (it.second == key){
                print_list(it.first, output, case_sensitity);
                found = true;
            }
        }
        else {
            print_list(it.first, output, case_sensitity);
            found = true;
        }
    }

    int size = prevLines.size();
    for (int i = 0; i < size; i++){
        prevLines.pop_back();
    }

    return found;
}

/*
 * name:      print_list
 * purpose:   prints the lines where a specific key occurs in
 *            a file 
 * arguments: takes in a vector of integers which hold the lines
 *            a particular key is located at as well as an
 *            output stream to a specific location and a bool
 *            for the case sensitivity
 * returns:   none
 * effects:   prints to desired output location
 */
void FileObject::print_list(vector<int>list_lines, ostream &output, 
                            bool case_sensititive)
{
    
    for (auto &it : list_lines){
        if (find(prevLines.begin(), prevLines.end(), it) == prevLines.end() or
            case_sensititive){
            output << filepath << ":" << it << ": ";
            output << lines.at(it - 1) << endl;
            prevLines.push_back(it);
        }
    } 
    
}
