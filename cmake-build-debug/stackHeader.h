//
// Created by Steven Turner on 9/23/24.
//

#ifndef ASSIGN2ST_STACKHEADER_H
#define ASSIGN2ST_STACKHEADER_H

#include <iostream>
#include <vector>
using namespace std;

template <typename Item_Type>
class Stack {
private:
    vector<Item_Type> stack;
public:
    bool isEmpty() const;
    void push(Item_Type value);
    void pop();
    Item_Type top() const;
    double average() const;
};


#endif //ASSIGN2ST_STACKHEADER_H
