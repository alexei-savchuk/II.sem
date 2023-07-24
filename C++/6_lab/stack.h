#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack();
    ~Stack();
    bool isEmpty();
    void push(int data);
    void pop();
    int peek();
    void display();
    void clear();
    void saveToFile(std::string filename);
    void readFromFile(std::string filename);
    void splitStacks(std::string evenFilename, std::string oddFilename);
};

#endif // STACK_H
