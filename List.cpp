#include "List.h"       // used to reference header file. Must be in quotes since we created it
#include <cstdlib>
#include <iostream>

using namespace std;

List::List()        //define private data members
{
    //ctor
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void List::AddNode(int addData){
    nodePtr n = new node;       // n points to the new node
    n->next = NULL;      // points to nothing
    n->data = addData;   // fills node with data. Whatever we pass to addData gets added to the node

    if(head != NULL){   // head is a private pointer of our class. If head points to an object, then our list exists.
        curr = head;    // current pointer points to the front of the list
        while(curr->next != NULL){   // while we are not at the end of the list
            curr = curr->next;       // current pointer points to the next node in the list
        }
        curr->next = n;      // the next element will point to n (the new node we filled with data)
    }
    else{                   // if we don't have at least one element in the list
        head = n;           // we tell the new node that it will be the front of the list
    }
}

void List::DeleteNode(int delData){
    nodePtr delPtr = NULL;
    temp = head;                                    // temp trails the current pointer one step behind as current pointer advances (in case we delete the current pointer)
    curr = head;                                    // if the current node is what we want to delete, we delete it.
    while(curr != NULL && curr->data != delData){    // make sure the data in the current pointer is not equal to the delData that we're passing in the function
        temp = curr;
        curr = curr->next;       // traverses the list
    }
    if(curr == NULL){           // if the current pointer is not pointing to anything, we've passed through the entire list and didn't find the value we were looking for
        cout << delData << " was not in the list.\n";
        delete delPtr;          // We don't have a garbage collector in C++ like Java, so we must manually delete delPtr
    }
    else{       // if this else statement executes, that means we found the node we're looking for, we delete that node, and output that we've deleted it. Then we patch our list.
        delPtr = curr;          // the deletion pointer is pointing to the node we want to delete
        curr = curr->next;
        temp->next = curr;       // both lines patch the hole in the list
        if(delPtr == head){     // if the deletion pointer points to the front of the list
            head = head->next;
            temp = NULL;
        }
        delete delPtr;
        cout << "The value " << delData << " was deleted.\n";
    }
}

void List::PrintList(){
    curr = head;
    while(curr != NULL){
        cout << curr->data << endl;  // prints one bit of data per line
        curr = curr->next;           // iterates through the list
    }
}
