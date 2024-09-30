//
// Created by Steven Turner on 9/23/24.
//

#ifndef ASSIGN2ST_ASSIGN2HEADER_H
#define ASSIGN2ST_ASSIGN2HEADER_H



#include <iostream>
#include <stdexcept>
using namespace std;

//node class definition
template <typename Item_Type>
class Node {
public:
    Item_Type data;
    Node* next;

    //initializes node with data
    Node(const Item_Type& item);
};

//single linked list class definition
template <typename Item_Type>
class Single_Linked_List {
private:
    //pointer to head node
    Node<Item_Type>* head;

    //pointer to tail node
    Node<Item_Type>* tail;

    //number of items in list
    size_t num_items;
public:
    //constructor
    Single_Linked_List();

    //destructor
    ~Single_Linked_List();

    //add item to front of list
    void push_front(const Item_Type& item);

    //add item to back of list
    void push_back (const Item_Type& item);

    //remove and return item at front of list
    Item_Type pop_front();

    //remove and return item at back of list
    Item_Type pop_back();

    //get item at front of list
    Item_Type front() const;

    //get item at back of list
    Item_Type back() const;

    //check to see if list is empty
    bool empty() const;

    //insert item at specific index
    void insert(size_t index, const Item_Type& item);

    //remove item at specific index
    bool remove(size_t index);

    //find index of first occurrence of item
    size_t find(const Item_Type& item) const;

    //get number of item in list
    size_t size() const;

    //print contents of list
    void print() const;
};
#endif //ASSIGN2ST_ASSIGN2HEADER_H


