//
// Created by Steven Turner on 9/23/24.
//

#include "stackHeader.h"
#include <iostream>
using namespace std;

//check if the stack is empty
template <typename Item_Type>
bool Stack<Item_Type>::isEmpty() const {
    return stack.empty();
}

//push an integer onto the stack
template <typename Item_Type>
void Stack<Item_Type>::push(Item_Type value) {
    stack.push_back(value);
}

//pop an integer from the stack
template <typename Item_Type>
void Stack<Item_Type>::pop() {
    if (!isEmpty()) {
        stack.pop_back();
    } else {
        cout << "Stack is empty. Cannot pop." << endl;
    }
}

//get the top element of the stack
template <typename Item_Type>
Item_Type Stack<Item_Type>::top() const {
    if (!isEmpty()) {
        return stack.back();
    } else {
        cerr << "Stack is empty. No top element." << endl;
        return -1; //return an error value
    }
}

//calculate the average of the stack elements
template <typename Item_Type>
double Stack<Item_Type>::average() const {
    if (isEmpty()) {
        cerr << "Stack is empty. Cannot calculate average." << endl;
        return 0.0; //return 0 for empty stack
    }

    double sum = 0;
    for (int value : stack) {
        sum += value;
    }
    return sum / stack.size();
}
