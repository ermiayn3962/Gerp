/*
 *  FileObject.h
 *  Yoda Ermias and Cooper Golemme
 *  04/15/2023
 *
 *  CS 15 Proj 4: Gerp
 *
 *  Purpose: Declares various functions associated with the FileObject 
 *           class as well as the public function print_occurances
 *           which will be vital to running the various search queries 
 *           in the Gerp class
 *
 */

#ifndef __FILE_OBJECT__
#define __FILE_OBJECT__

#include "HashTable.h"
#include "stringProcessing.h"
#include <string>
#include <vector>
#include <fstream>


class FileObject {
public:
    FileObject(string path);
    bool print_occurances(string key, bool case_sensitive, ostream &output);

private:
    string filepath;
    HashTable words_hash;
    vector <string> lines; //stores the strings getline got from file
    vector <int> prevLines;
    
    void read_file(string filename);
    void create_file_path();
    void print_list(vector<int> list_lines, ostream &output,
                    bool case_sensitive);
    void remove_dups(vector <int> vtr);
    bool contains_line(vector<int>list_lines, int line_to_add);

};

#endif