/*
 *  main.cpp
 *  Yoda Ermias and Cooper Golemme
 *  04/15/2023
 *
 *  CS 15 Proj 4: Gerp
 *
 *  Purpose: Traverses a given directory and creates files for each file found
 *           in a directory/subdirectory. It then pushes that FileObject 
 *           instance to a vector of FileObjects.
 *
 */

#include "stringProcessing.h"
#include "FileObject.h"
#include "FSTree.h"
#include "DirNode.h"
#include <vector>
#include <string>
using namespace std;

void traverseTree(DirNode *curr, string dir, vector<FileObject *> &filenames);
void populate_hash_table(string directory_name);

void populate_hash_table(string directory_name){
    
    vector<FileObject *> filenames;
    FSTree tree(directory_name);
    string test = "";
    
    traverseTree(tree.getRoot(), test, filenames);

    for (unsigned long int i = 0; i < filenames.size(); i ++){
        cerr << filenames.at(i)->filepath << endl;
    }

}

/*
 * name:      traverseTree
 * purpose:   traverses the FSTree and prints the path of any file 
 *            found in the tree
 * arguments: takes in a DirNode pointer to the root of the FSTree
 *            and the address of a string which is used to hold the
 *            directories. 
 * returns:   none
 * effects:   prints to the terminal the path of every file
 */
void traverseTree(DirNode *curr, string dir, vector<FileObject *> &filenames){
    dir += curr->getName();
    dir += "/";

    //Base Case
    if (curr->hasFiles()){
        for (int i = 0; i < curr->numFiles(); i++){
            //create a FileObject instance here
            FileObject *file = new FileObject(dir + curr->getFile(i),
                                              curr->getFile(i));
            //then push the object to the vector
            filenames.push_back(file);
        }
    }

    //Recursive Case
    if (curr->hasSubDir()){
        for (int i = 0; i < curr->numSubDirs(); i++){
            traverseTree(curr->getSubDir(i), dir, filenames);
        }
    }

    return;
}