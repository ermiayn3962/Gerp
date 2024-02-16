/*
 *  Gerp.cpp
 *  Yoda Ermias and Cooper Golemme
 *  04/15/2023
 *
 *  CS 15 Proj 4: Gerp
 *
 *  Purpose: Implements the Gerp class which creates a file object for every
 *           file in the directory, hashes the words in the file, and runs
 *           queries on the files in the directory. Gerp has two class
 *           variables: A vector of FileObjects (see FileObject) and an ouput
 *           file name.
 *
 */

#include "Gerp.h"

/*
 * name:      Gerp
 * purpose:   initialize class variables output_file, populates the hash table,
 *            and calls the query function
 * arguments: takes in a string output_file and a string for the given
 *            directory name provided by the user
 * returns:   none
 * effects:   initializes class variables, builds the hash table,
 *            and calls query function
 */
Gerp::Gerp(string output_file, string directory_name)
{
    output_filename = output_file;
    populate_hash_table(directory_name);
    query();
}

/*
 * name:      ~Gerp
 * purpose:   recycles memory used when storing the vector of FileObjects
 * arguments: none
 * returns:   none
 * effects:   clears heap memory used when declaring FileObjects
 */
Gerp::~Gerp()
{
    for (auto &it : files){
        delete it;
    }
}


/*
 * name:      query
 * purpose:   provides the query functionality for the gerp program
 * arguments: none
 * returns:   none
 * effects:   writes to the output file provided in the constuctor
 *            or a new file if @f is entered followed by a new filename.
 */
void Gerp::query()
{
    string word = "\0";
    string action = "\0";
    ofstream output_file;

    output_file.open(output_filename);
    
    while (cout << "Query? " and cin >> action and 
           action != "@q" and action != "@quit"){ 
        bool case_sensitive = true;

        if (action == "@f"){
            cin >> output_filename;
            output_file.close();
            output_file.open(output_filename);
        }
        else{
            if (action == "@i" or action == "@insensitive"){
                cin >> word;
                case_sensitive = false;
            }
            else {
                word = action;
            }
            print(word, case_sensitive, output_file);
        }
    }
    output_file.close();
}

/*
 * name:      print
 * purpose:   writes to the output file the result of the query
 * arguments: takes in a string word, a boolean for case sensitivity
 *            and an output file stream to the output file
 * returns:   none
 * effects:   writes to the output file the result of the query
 */
void Gerp::print(string word, bool case_sensitive, ostream &output_file)
{
    string error_message = "";
    int count = 0;
    
    for (auto &it : files) {
        word = stripNonAlphaNum(word);
        bool result = it->print_occurances(word, case_sensitive, output_file);
        if (result){
            count++;
        }
    }

    bool printError = true;
    if (count > 0){
        printError = false;
    }

    if (printError){
        if (case_sensitive){
            output_file << word + " Not Found. Try with @insensitive or @i.\n";
        }
        else{
            output_file << word + " Not Found.\n";
        }
    }
    
}

/*
 * name:      populate_hash_table
 * purpose:   populates the hash table given a starting directory
 * arguments: takes in a string directory_name which holds the 
 *            name of the starting directory
 * returns:   none
 * effects:   creates the FSTree associated to the provided 
 *            directory and fills the hash table
 */
void Gerp::populate_hash_table(string directory_name)
{
    FSTree tree(directory_name);
    string test = "";
    
    traverseTree(tree.getRoot(), test, files);

}

/*
 * name:      traverseTree
 * purpose:   traverses the FSTree and prints the path of any file 
 *            found in the tree
 * arguments: takes in a DirNode pointer to the root of the FSTree,
 *            a string which is used to hold the
 *            directories and a vector of FileObject instances. 
 * returns:   none
 * effects:   populates the vector of FileObjects
 */
void Gerp::traverseTree(DirNode *curr, string dir, 
                        vector <FileObject *> &filenames)
{
    dir += curr->getName();
    dir += "/";

    //Base Case
    if (curr->hasFiles()){
        for (int i = 0; i < curr->numFiles(); i++){
            //create a FileObject instance here
            FileObject *file = new FileObject(dir + curr->getFile(i));
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