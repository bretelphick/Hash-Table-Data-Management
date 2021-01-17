/*
* Bret Elphick
* CSC 230
* 12/04/20
* SLL.h- Implementation for singly linked list class,
* consists of constructor, destructor, getHeadPtr, 
* insert, search, remove, getSize, and display functions
*/

#include <iostream>
#include "Node.h"
using  namespace  std;

template <class U>
class SLL {
    
    Node<U> * headPtr;
    int size;
    
    public:
    // default constructor
    SLL(){
        headPtr = nullptr;
        size = 0;
    }

    // destructor    
    ~SLL(){
        Node<U> *temp1 = headPtr;
        while (temp1 != nullptr){
            Node<U> *temp2 = temp1->next;
            delete temp1;
            temp1 = temp2;
        }
    }
    
    Node<U>* getHeadPtr(){
        return headPtr;
    }
    
    // insert (item1, item2) to the list
    void insert(U item1, U item2){
        Node<U> *newNode = new Node<U>;
        newNode->SSN = item1;
        newNode->name = item2;
        newNode->next = nullptr;
    
        // case for an empty linked list
        if (headPtr == nullptr){
            headPtr = newNode;
            size++;
        }
        else{
        // iterates through each node and points the former last node to the new node
        Node<U> *temp = headPtr;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        size++;
        } 
    }
    
    // if find the item1 value, return the pointer to the node
    // otherwise, return nullptr
    Node<U>* search(U item1){
        Node<U> *temp = headPtr;
      
        while (temp != nullptr){
            if (temp->SSN == item1){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
     
    // remove the node with key value: item1
    bool remove(U item1){
        Node<U> *temp1 = headPtr;
        // case that the list is empty
        if (temp1 == nullptr){
            return false;
        }
        // case of removing the first node of the list
        else if (temp1->SSN == item1){
            headPtr = temp1->next;
            delete temp1;
            size--;
            return true;
        }
        else{
            temp1 = headPtr;
            Node<U> *temp2 = headPtr->next;
            while (temp2 != nullptr){
                if(temp2->SSN == item1){
                    break;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            // value was not found in the list
            if (temp2 == nullptr){
                return false;
            }
            else{
                // case for removing the last node of the list
                if (temp2->next == nullptr){
                    temp1->next = nullptr;
                    delete temp2;
                    size--;
                    return true;
                }
                // case of removing a node from the middle of list
                else{
                    temp1->next = temp2->next;
                    delete temp2;
                    size--;
                    return true;
                }
            }
        }
    }
    
    int getSize(){
        
        return size;
    }
    
    // display the SSN values of each node in the linked list
    void display(){
        Node<U>* temp;
        temp = headPtr;
        while (temp!= nullptr) {
            cout << temp->SSN << endl;
            temp = temp->next;
        }
    }
};


