#include <iostream>
#include "stack.h"

void menu(Stack& stack) {
    int choice;
    do {
        std::cout << "\nStack Menu\n"
            << "1. Push\n"
            << "2. Pop\n"
            << "3. Peek\n"
            << "4. Display\n"
            << "5. Clear\n"
            << "6. Save to File\n"
            << "7. Read from File\n"
            << "8. Split Stacks\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 0:
            std::cout << "Exiting program..." << std::endl;
            break;
        case 1: {
            int data;
            std::cout << "Enter data to push: ";
            std::cin >> data;
            stack.push(data);
            break;
        }
        case 2:
            stack.pop();
            break;
        case 3:
            std::cout << "Peek: " << stack.peek() << std::endl;
            break;
        case 4:
            std::cout << "Stack: ";
            stack.display();
            break;
        case 5:
            stack.clear();
            std::cout << "Stack cleared" << std::endl;
            break;
        case 6: {
            std::string filename;
            std::cout << "Enter filename: ";
            std::cin >> filename;
            stack.saveToFile(filename);
            break;
        }
        case 7: {
            std::string filename;
            std::cout << "Enter filename: ";
            std::cin >> filename;
            stack.readFromFile(filename);
            std::cout << "Stack read from file" << std::endl;
            break;
        }
        case 8: {
            std::string evenFilename, oddFilename;
            std::cout << "Enter filename for even stack: ";
            std::cin >> evenFilename;
            std::cout << "Enter filename for odd stack: ";
            std::cin >> oddFilename;
            stack.splitStacks(evenFilename, oddFilename);
            std::cout << "Stacks split and saved to files" << std::endl;
            break;
        }
        default:
            std::cout << "Invalid choice, try again" << std::endl;
        }
    } while (choice != 0);
}

int main() {
    Stack stack;
    menu(stack);
    return 0;
}