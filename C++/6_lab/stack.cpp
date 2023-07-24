#include "stack.h"

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    clear();
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::push(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

int Stack::peek() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        return -1;
    }
    return top->data;
}

void Stack::display() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    Node* temp = top;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::saveToFile(std::string filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cout << "Error opening file" << std::endl;
        return;
    }
    Node* temp = top;
    while (temp != nullptr) {
        file << temp->data << std::endl;
        temp = temp->next;
    }
    file.close();
}

void Stack::readFromFile(std::string filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file" << std::endl;
        return;
    }
    clear();
    int data;
    while (file >> data) {
        push(data);
    }
    file.close();
}

void Stack::splitStacks(std::string evenFilename, std::string oddFilename) {
    Stack stack1, stack2;
    Node* temp = top;
    while (temp != nullptr) {
        if (temp->data % 2 == 0) {
            stack1.push(temp->data);
        }
        else {
            stack2.push(temp->data);
        }
        temp = temp->next;
    }
    stack1.saveToFile(evenFilename);
    stack2.saveToFile(oddFilename);
}
