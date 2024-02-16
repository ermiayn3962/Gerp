/*
 *  HashTable.cpp
 *  Yoda Ermias and Cooper Golemme
 *  04/15/2023
 *
 *  CS 15 Proj 4: Gerp
 *
 *  Purpose: Implements the necessary functions to build a hash table
 *           that hashes the lowercase version of a key and stores
 *           the actual case of the key in a list in the indexed bucket 
 *
 */

#include "HashTable.h"
#include <sstream>
#include <iostream>

using namespace std;

/*
 * name:      HashTable
 * purpose:   Constructor for the HashTable class
 * arguments: none
 * returns:   none
 * effects:   initializes the private variables of the class
 */
HashTable::HashTable()
{
    capacity = INITIAL_TABLE_SIZE;
    numItems = 0;
}

/*
 * name:      ~HashTable
 * purpose:   deconstructor for the HashTable class
 * arguments: none
 * returns:   none
 * effects:   recycles the heap memory associated with the
 *            hash table
 */
HashTable::~HashTable()
{
    delete [] words_hash;
}

/*
 * name:      calc_loadFactor
 * purpose:   calculates the load factor and calls the expand
 *            function if the load factor is greater than 0.7
 * arguments: none
 * returns:   none
 * effects:   none
 */
void HashTable::calc_loadFactor()
{
    float loadFactor = static_cast <float> (numItems) / 
                       static_cast <float> (capacity);

    if (loadFactor > 0.7){
        expand();
    }
}

/*
 * name:      expand
 * purpose:   expands the hash table
 * arguments: none
 * returns:   none
 * effects:   increases the capacity of the hash table and
 *            rehashes all elements to new indexes
 */
void HashTable::expand()
{
    int oldCap = capacity;
    capacity = capacity * 2 + 2;

    //creating the new expanded hash table
    list<pair<vector<int>, string>> *new_wordsHash =
        new list<pair<vector<int>, string>> [capacity];

    for (int i = 0; i < oldCap; i++){
        if (not getList(i)->empty()){
            //getting word from old hash table
            string key = makeLower(getList(i)->front().second);

            int attempt = 0;
            bool found = false;

            while (not found){
                //rehashing word for new hash table
                int idx = (hash_word(key) + attempt) % capacity;

                if (new_wordsHash[idx].empty()){
                    for (auto &it : *getList(i)){
                        new_wordsHash[idx].push_back(it);
                    }
                    found = true; 
                }
                else {
                    attempt++;
                }
            }
        }
    }
    delete [] words_hash;
    words_hash = new_wordsHash;
}

/*
 * name:      insert
 * purpose:   inserts a key and its value (its line number) into the
 *            hash table
 * arguments: takes in a string key and int line_num
 * returns:   none
 * effects:   inserts an element to the hash table
 */
void HashTable::insert(string key, int line_num)
{
    int attempt = 0;
    bool found = false;

    while (not found){
        //hashing and compressing the lowercase key
        int idx = (hash_word(makeLower(key)) + attempt) % capacity;

        if (getList(idx)->empty() or 
            makeLower(key) == makeLower(getList(idx)->front().second)){
            
            bool case_matches = false;
            //looping through list to see if key's case exists
            for (auto &it : *getList(idx)){
                if (it.second == key){
                    if (not exists_on_line(idx, line_num, key)){
                        it.first.push_back(line_num);
                    }
                    case_matches = true;
                }
            }
            if (not case_matches){
                make_ListEntry(key, line_num, idx);
            }
            found = true;
        }
        else {
            attempt++;
        }
    }

    numItems++;
    calc_loadFactor();
}

/*
 * name:      exists_on_line
 * purpose:   checks if a case of a word already exists on a line
 * arguments: takes in a string key, int index in the hash table,
 *            and int line_num of the key
 * returns:   returns either true or false depending on if the specific
 *            case of the key already has a line number associated with it
 * effects:   none
 */
bool HashTable::exists_on_line(int index, int line_num, string key)
{
    for (auto &it : *getList(index)){
        for (unsigned long int i = 0; i < it.first.size(); i++){
            if (it.first.at(i) == line_num and it.second == key){
                return true;
            }
        }
    }

    return false;
}

/*
 * name:      find
 * purpose:   gets the index of a particular key in the hash
 *            table
 * arguments: takes in a string key
 * returns:   returns an integer which is the index of the key
 *            in the hash table or -1 if that key wasn't found
 *            in the table
 * effects:   none
 */
int HashTable::find(string key)
{
    for (int i = 0; i < capacity; i++){
        for (auto &it : *getList(i)){
            if (makeLower(it.second) == makeLower(key)){
                return i;
            }
        }
    }

    return -1;
}

/*
 * name:      getList
 * purpose:   gets a list for a given location in 
 *            the words_hash array
 * arguments: takes in an int index
 * returns:   returns a pointer to the list at the idx in array
 *            words_hash
 * effects:   none
 */
list<pair<vector<int>, string>> *HashTable::getList(int idx)
{
    return &words_hash[idx];
}

/*
 * name:      makeLower
 * purpose:   converts any string into lowercase
 * arguments: takes in a string input to convert
 * returns:   returns a string of the lowercase version of the
 *            input
 * effects:   none
 */
string HashTable::makeLower(string input)
{
    stringstream s(input);
    char temp = '\0';
    string send = "";

    while (s.get(temp)){
        send += tolower(temp);
    }

    return send;
}

/*
 * name:      hash_word
 * purpose:   hashes a word using the included C++ hash function
 * arguments: takes in a string word
 * returns:   returns the size_t (the integer result of the hash)
 * effects:   none
 */
size_t HashTable::hash_word(string word)
{
    return hash <string> {} (word);
}   

/*
 * name:      make_ListEntry
 * purpose:   makes a new node in the list at words_hash[idx] where the first
 *            element in the pair is a vector of ints, which holds the line
 *            numbers a particular case of the key is found on in a file. 
 * arguments: takes in a string key, an int idx, and an int line_num 
 * returns:   none
 * effects:   creates a new node in the list at words_hash[idx]
 */
void HashTable::make_ListEntry(string key, int line_num, int idx)
{
    //creating the vector of line number instances for case of the key
    vector<int> lineNums (1, line_num);

    list<pair<vector<int>, string>> word;
    words_hash[idx].emplace_back(lineNums, key);
}

/*
 * name:      print_table
 * purpose:   prints the entire hash table (only used for testing
 *            purposes)
 * arguments: none
 * returns:   none
 * effects:   prints to cout the elements of the hash table
 */
void HashTable::print_table()
{
    //looping through the array of lists
    for (int i = 0; i < capacity; i++){
        if (not getList(i)->empty()){
            //looping through list at current bucket
            for (auto &it : *getList(i)){
                cout << "Word: " << it.second << endl;
                cout << "Line(s): ";
                //looping through the vectors of line numbers
                for (auto &vector_it : it.first){
                    cout << vector_it << " ";
                }
                cout << endl;
            }
        }
    }
}


