#include "assign2Header.h"
#include "stackHeader.h"
#include "stackCPP.cpp"
#include "assign2CPP.cpp"


using namespace std;


int main() {
    Single_Linked_List<int> list;

    //lines 12-31 deal with Stacks
    Stack<int> myStack; //creating stack object

    //inserting test values into stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);


    cout << "Top element: " << myStack.top() << endl; //outputting top element from stack
    cout << "Average: " << myStack.average() << endl; //outputting the average of elements in stack

    myStack.pop();
    cout << "Top element after pop: " << myStack.top() << endl;
    bool stack_status = myStack.isEmpty();
    if (stack_status == true) {
        cout <<"Your stack is empty." << endl;
    }
    else {
        cout <<"Your stack is NOT empty" << endl;
    }

    //creating space between stack and list outputs
    cout << " " << endl;

    //remaining code deals with Single Linked Lists

    //adding elements to front and back of list
    list.push_front(10);
    list.push_front(5);
    list.push_back(20);
    list.push_back(30);

    //printing list, should be : 5 10 20 30
    cout << "List: " ;
    list.print();

    cout << "Front element: " << list.front() << endl;  //should be: 5
    cout << "Back element: " << list.back() << endl; //should be: 30

    list.pop_front();
    cout << "List after pop_front: ";
    list.print();  // should be: 10 20 30

    list.pop_back();
    cout << "List after pop_back: ";
    list.print();  //should be: 10 20

    list.insert(1, 15);
    cout << "List after insert at index 1: ";
    list.print();  //should be: 10 15 20

    list.remove(1);
    cout << "List after remove at index 1: ";
    list.print();  //should be: 10 20

    size_t index = list.find(20);
    if (index != list.size()) {
        cout << "Element 20 found at index: " << index << endl;  //should be: Element 20 found at index 1
    } else {
        cout << "Element 20 not found in the list." << endl;
    }

    //get the size of the list
    cout << "List size: " << list.size() << endl;

    if (list.empty()) {
        cout << "The list is empty." << endl;  //output this if list is empty
    } else {
        cout << "The list is not empty." << endl;  //output this if list has elements
    }





}