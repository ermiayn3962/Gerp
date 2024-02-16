/*
 *  Gerp.h
 *  Yoda Ermias and Cooper Golemme
 *  04/15/2023
 *
 *  CS 15 Proj 4: Gerp
 *
 *  Purpose: Outlines the functionality of the Gerp class. Gerp will 
 *           create FileObjects for each file in the directory/subdirectories
 *           and runs a query loop for user provided commands on the 
 *           vector of FileObjects.
 *
 */
#ifndef __GERP_H__
#define __GERP_H__

#include "FileObject.h"
#include "FSTree.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;


class Gerp {
public:
    Gerp(string directory_name, string filename);
    ~Gerp();
private:
    vector <FileObject*> files;
    string output_filename;

    void print(string word, bool case_sensitive, ostream &output_file);
    void query();
    void traverseTree(DirNode *curr, string dir, 
                      vector<FileObject*> &filenames);
    void populate_hash_table(string directory_name);

};

#endif 