//
// Created by Steven Turner on 9/23/24.
//
#include "assign2Header.h"

//constructor for node, initializes data and sets next to nullptr
template <typename Item_Type>
Node<Item_Type>::Node(const Item_Type& item) : data(item), next(nullptr) {}

//constructor for Single_Linked_List, initializes empty list
template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

//destructor for Single_Linked_List, cleans up all nodes
template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        //continuously pop until list is empty
        pop_front();
    }
}

//add an item to the front of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node<Item_Type>* new_node = new Node<Item_Type>(item); // create a new node
    if (empty()) {
        head = tail = new_node; //if list is empty, set head and tail to new node
    } else {
        new_node->next = head; // link new node to the current head
        head = new_node;       // update head to the new node
    }
    num_items++; // increment number of items
}

// add an item to back of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node<Item_Type>* new_node = new Node<Item_Type>(item); //create a new node
    if (empty()) {
        head = tail = new_node; //if list is empty, set head and tail to new node
    } else {
        tail->next = new_node; //link current tail to the new node
        tail = new_node;       //update tail to the new node
    }
    num_items++; //increment the number of items
}

//remove and return the item at the front of the list
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        throw runtime_error("List is empty"); //check for empty list
    }
    Item_Type popped_item = head->data; //store item that you are returning
    Node<Item_Type>* temp = head;       //temp pointer to the head node
    head = head->next;                  //move head to the next node
    delete temp;                        //delete old head node
    num_items--;                        //decrement the item count
    if (empty()) {
        tail = nullptr; //update tail if the list is empty
    }
    return popped_item;                 //return popped item
}

//remove and return the item at the back of the list
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::pop_back() {
    if (empty()){
        throw runtime_error("List is empty"); //check for empty list
    }
    if (head == tail) { //if only one element
        Item_Type popped_item = head->data; //store item
        delete head; //delete the only node
        head = tail = nullptr; //set head and tail to nullptr
        num_items--; //decrement the item count
        return popped_item; //return popped item
    } else {
        Node<Item_Type>* current = head; //start from head
        while (current->next != tail) { //traverse to the second-to-last node
            current = current->next;
        }
        Item_Type popped_item = tail->data; //store the data of the last node
        delete tail; //delete last node
        tail = current; //update tail to the second-to-last node
        tail->next = nullptr; //set the new tail's next to nullptr
        num_items--; //decrement item count
        return popped_item; //return popped item
    }
}

//get the item at the front of the list
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (empty()) {
        throw runtime_error("List is empty"); //check for empty list
    }
    return head->data; //return the data of the head node
}

//get the item at the back of the list
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (empty()) {
        throw runtime_error("List is empty"); //check for empty list
    }
    return tail->data; //return the data of the tail node
}

// check if the list is empty
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return head == nullptr; // return true if head is nullptr
}

// insert an item at a specified index
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index <= 0) {
        push_front(item); //insert at front if index is 0 or negative
    } else if (index >= num_items) {
        push_back(item); //insert at back if index is greater than or equal to size
    } else {
        Node<Item_Type>* new_node = new Node<Item_Type>(item); //create a new node
        Node<Item_Type>* current = head; //start from head
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next; //traverse to the node before the specified index
        }
        new_node->next = current->next; //link new node to the next node
        current->next = new_node; //link the current node to the new node
        num_items++; //increment the number of items
    }
}

//remove the item at a specified index
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index < 0 || index >= num_items) {
        return false; //return false if index is out of bounds
    }
    if (index == 0) {
        pop_front(); //remove from front if index is 0
    } else {
        Node<Item_Type>* current = head; //start from head
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next; //traverse to the node before the specified index
        }
        Node<Item_Type>* temp = current->next; //node to be deleted
        if (temp == tail) {
            tail = current; //update tail if removing the last element
        }
        current->next = temp->next; //link current to the next node of the node to be deleted
        delete temp; //delete the node
        num_items--; //decrement the number of items
    }
    return true; //successful removal
}

//find the index of the first occurrence of an item
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node<Item_Type>* current = head; //start from head
    size_t index = 0;
    while (current) {
        if (current->data == item) {
            return index; //return index if item is found
        }
        current = current->next; //move to the next node
        index++; //increment index
    }
    return num_items; //return size if item is not found
}

//get the number of items in the list
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    return num_items; //return the count of items
}

//print the contents of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::print() const {
    Node<Item_Type>* current = head; //start from head
    while (current) {
        cout << current->data << " "; //print data of each node
        current = current->next; //move to the next node
    }
    cout << endl;
}

