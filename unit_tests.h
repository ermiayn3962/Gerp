/*
 *  unit_tests.h
 *  Yoda Ermias and Cooper Golemme
 *  04/15/2023
 *
 *  CS 15 Proj 4: Gerp
 *
 *  Purpose: Tests various functions and componenets required to build
 *           Gerp
 *
 */

#include "HashTable.h"
#include "FileObject.h"
#include <cassert>
#include <iostream>

using namespace std;

/* UNIT TESTS COMMENTED OUT SINCE THEY TEST PRIVATE FUNCTIONS/VARIABLES */

// // Testing the read_file function of the FileObject class
// void read_file_test(){
//     string path = "FileObject_test_file.txt";
//     FileObject test (path);

//     // printing the hash table
//     test.words_hash.print_table();
// }

// // Testing the print_occurances operation of the FileObject class
// void print_occurances_test_0(){
//     string path = "FileObject_test_file.txt";
//     FileObject test (path);
//     test.print_occurances("randomly", false, cout);
// }

// // Testing the print_occurances operation of the FileObject class
// // Checking the behavior when case sensitivity is true
// void print_occurances_test_1(){
//     string path = "FileObject_test_file.txt";
//     FileObject test (path);
//     test.print_occurances("randomly", true, cout);
// }

// // Testing the print_occurances operation of the FileObject class
// void print_occurances_test_3(){
//     string path = "tinyData/test.txt";
//     FileObject test (path);
//     test.print_occurances("we", false, cout);
// }

// // Testing the print_occurances operation of the FileObject class
// // Checking the behavior when word isn't found w/o case sensitivity
// void print_occurances_test_4(){
//     string path = "tinyData/test.txt";
//     FileObject test (path);
//     test.print_occurances("random", false, cout);
// }

// // Testing the print_occurances operation of the FileObject class
// // Checking the behavior when word isn't found w/o case sensitivity
// void print_occurances_test_5(){
//     string path = "tinyData/test.txt";
//     FileObject test (path);
//     test.print_occurances("random", true, cout);
// }

// // Testing the makeLower function of the HashTable class
// void makeLower_test(){
//     string test = "TEST";
//     HashTable table;

//     assert(table.makeLower(test) == "test");
// }

// // Tests the makeList operation of the HashTable class
// void makeList_test(){
//     string key = "Test";
//     int line_num = 3;
//     int idx = 0;

//     HashTable table;
//     table.make_ListEntry(key, line_num, idx);
    
//     for (auto &it : *table.getList(idx)){
//         for (int i = 0; i < it.first.size(); i++){
//             cout << "word: " << it.second << endl;
//             cout << "Line num: " << it.first.at(i) << endl;
//         }
//     }
// }

// // Testing the insert function of the HashTable class
// void insert_test_1(){
//     string test1 = "TEST";
//     string test2 = "test";
//     string test3 = "TeSt";

//     HashTable table;

//     int attempts[3];
    
//     table.insert(test1, 10);
//     table.insert(test2, 20);
//     table.insert(test3, 30);

//     int idx = table.find("test");
//     for (auto &it : *table.getList(idx)){
//         for (int j = 0; j < it.first.size(); j++){
//             cout << "word: " << it.second << endl;
//             cout << "Line num: " << it.first.at(j) << endl;
//         }
//     }
// }

// // Testing the insert function of the HashTable class
// // Testing the behavior with different words
// void insert_test_2(){
//     string test1 = "TEST";
//     string test2 = "test";
//     string test3 = "raNdoM";

//     HashTable table;

//     int attempts[3];
    
//     table.insert(test1, 10);
//     table.insert(test2, 20);
//     table.insert(test3, 30);

//     string words[2] = {"Test", "RANDOM"};

//     for (int i = 0; i < 2; i++){
//         int idx = table.find(words[i]);
//         for (auto &it : *table.getList(idx)){
//             for (int j = 0; j < it.first.size(); j++){
//                 cout << "word: " << it.second << endl;
//                 cout << "Line num: " << it.first.at(j) << endl;
//             }
//         }
//     }
// }

// // Testing the insert function of the HashTable class
// // Testing the behavior with same case words on different lines
// void insert_test_3(){
//     string test1 = "TeSt";
//     string test2 = "TeSt";
//     string test3 = "TEST";

//     HashTable table;

//     int attempts[3];
    
//     table.insert(test1, 10);
//     table.insert(test2, 20);
//     table.insert(test3, 30);

//     int idx = table.find("TeSt");

//     for (auto &it : *table.getList(idx)){
//         cout << "word: " << it.second << endl;
//         cout << "Line num: ";
//         for (int j = 0; j < it.first.size(); j++){
//             cout << it.first.at(j) << " ";
//         }
//         cout << endl;
//     }
    
// }

// // Testing the insert function of the HashTable class
// // Testing the behavior with same case words on the same lines
// void insert_test_4(){
//     string test1 = "TeSt";
//     string test2 = "TeSt";
//     string test3 = "TEST";

//     HashTable table;

//     int attempts[3];
    
//     table.insert(test1, 10);
//     table.insert(test2, 10);
//     table.insert(test3, 10);

//     int idx = table.find("TeSt");

//     for (auto &it : *table.getList(idx)){
//         cout << "word: " << it.second << endl;
//         cout << "Line num: ";
//         for (int j = 0; j < it.first.size(); j++){
//             cout << it.first.at(j) << " ";
//         }
//         cout << endl;
//     }
    
// }

// //Testing the expand function of HashTable class
// void expand_test(){
//     string test1 = "teSt";
//     string test2 = "randOm";
//     string test3 = "wAlK";

//     HashTable table;

//     table.insert(test1, 10);
//     table.insert(test2, 20);

//     cout << "This is the capacity before expansion: " << table.capacity 
//     cout << endl;
//     table.expand();
//     cout << "This is the capacity after expansion: " << table.capacity 
//     cout << endl;

//     string words[2] = {"Test", "RANDOM"};

//     //Checking if elements were copied properly
//     for (int i = 0; i < 2; i++){
//         int idx = table.find(words[i]);
//         for (auto &it : *table.getList(idx)){
//             for (int j = 0; j < it.first.size(); j++){
//                 cout << "word: " << it.second << endl;
//                 cout << "Line num: " << it.first.at(j) << endl;
//             }
//         }
//     }

//     table.insert(test3, 30);
//     int idx = table.find(test3);
//     for (auto &it : *table.getList(idx)){
//         for (int j = 0; j < it.first.size(); j++){
//             cout << "word: " << it.second << endl;
//             cout << "Line num: " << it.first.at(j) << endl;
//         }
//     }
// }

// // Testing the calc_loadFactor function of the HashTable class
// // Load factor was tested with when table had inital capacity = 3
// void calc_loadFactor_test(){
//     HashTable table;

//     table.calc_loadFactor();

//     string test1 = "teSt";
//     string test2 = "randOm";
//     string test3 = "wAlK";

//     table.insert(test1, 10);
//     table.insert(test2, 20);
//     cout << table.capacity << endl;

//     table.insert(test3, 30); //this insertion makes the load factor = 1

//     cout << table.capacity << endl;


// }
