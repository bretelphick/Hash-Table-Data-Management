/*
* Bret Elphick
* CSC 230
* 12/04/20
* Project 4 - Read data from file that contains leading char, SSN, and name,
* throughout program keep track of time, # of inserts, # of deletions, # of retreivals, and # of entries in hash table
* when get to the end of the file close the fstream and display the values
*/

#include <iostream>
#include <fstream>
#include "hashTable.h"
#include <string>
#include <time.h>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]){
  clock_t start, end;
  double duration;

  start = clock();

  int insertionCount; 
  int deletionCount;
  int retrievalCount;
  string ssn; 
  string name;
  string tempName;
  char firstChar; 
  fstream input(argv[1]);
  HashTable<string> hashTable(10007);

  insertionCount = 0;
  deletionCount = 0;
  retrievalCount = 0;

  // Read in data from one of the files
  while(!input.eof()){
      input >> firstChar;
      input >> ssn;
      input >> name;
      input >> tempName;
      
      tempName = name + " " + tempName;
      
      if (firstChar == 'i'){
          if (hashTable.insert(ssn, name) == true){
              insertionCount++;
          }
      }
      else if (firstChar == 'd'){
          if (hashTable.erase(ssn) == true){
              deletionCount++;
          }
      }
      else{
          if (hashTable.find(ssn) == true){
              retrievalCount++;
          }
      }
  }
  input.close();

  cout << "The Number of Valid Insertion: " << insertionCount << endl;
  cout << "The Number of Valid Deletion: " << deletionCount << endl;
  cout << "The Number of Valid Retrieval: " << retrievalCount << endl;
  cout << "Item numbers in the list: " << hashTable.getSize() << endl;

  end = clock();
  duration = ( end - start ) / (double) CLOCKS_PER_SEC;

  cout<<"Time elapsed: "<< duration <<'\n';
}
