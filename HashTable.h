/*
 *  HashTable.h
 *  Yoda Ermias and Cooper Golemme
 *  04/15/2023
 *
 *  CS 15 Proj 4: Gerp
 *
 *  Purpose: Declares the various components required to build a hash table
 *           where the buckets of the table are comprised of pointers to a 
 *           list of pairs. Each pair contains an integer vector which holds 
 *           the line number a particular case of a key is found on, as well 
 *           as a string key.
 *
 */

#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include <list>
#include <string>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

class HashTable {
public:
    HashTable();
    ~HashTable();
    int find(string key);
    void insert(string key, int line_num);
    list <pair<vector<int>, string>> *getList(int idx);
    void print_table(); //only used for testing
private:
    const int INITIAL_TABLE_SIZE = 10;
    int capacity;
    int numItems;
    
    /* array of buckets which contain lists that hold pairs of int vectors
    (indicates the line number a certain case of a word appears on) and a 
    string (indicates the case of the word) */
    list<pair<vector<int>, string>> *words_hash =
        new list<pair<vector<int>, string>> [INITIAL_TABLE_SIZE];
    

    /* Helper Functions for the Hash Table */
    string makeLower(string input);
    void make_ListEntry(string key, int line_num, int idx);
    size_t hash_word(string word);
    bool exists_on_line(int index, int line_num, string key);
    void expand();
    void calc_loadFactor();


};

#endif