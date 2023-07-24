#include <iostream>
using namespace std;

estruct Queue {
    char data[MAX_SIZE];
    int front, rear;
};

// Функция для проверки, является ли очередь пустой
bool isQueueEmpty(Queue q) {
    return q.front == -1;
}


bool isQueueFull(Queue q) {
    return q.rear == MAX_SIZE - 1;
}

void enqueue(Queue& q, char item) {
    if (isQueueFull(q)) {
        cout << "Queue overflow" << endl;
    }
    else {
        if (q.front == -1) {
            q.front = 0;
        }
        q.rear++;
        q.data[q.rear] = item;
    }
}

char dequeue(Queue& q) {
    char item;
    if (isQueueEmpty(q)) {
        cout << "Queue underflow" << endl;
        item = ' ';
    }
    else {
        item = q.data[q.front];
        if (q.front == q.rear) {
            q.front = -1;
            q.rear = -1;
        }
        else {
            q.front++;
        }
    }
    return item;
}

// Функция для вывода элементов очереди на экран
void display(Queue q) {
    if (isQueueEmpty(q)) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "Queue elements are: ";
        for (int i = q.front; i <= q.rear; i++) {
            cout << q.data[i] << " ";
        }
        cout << endl;
    }
}

// Функция для определения размера очереди
int size(Queue q) {
    if (isQueueEmpty(q)) {
        return 0;
    }
    else {
        return q.rear - q.front + 1;
    }
}

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;
    int maxSize;
    char symbol;

    cout << "Enter maximum size of the queue: ";
    cin >> maxSize;

    for (int i = 1; i <= maxSize; i++) {
        cout << "Enter element " << i << " to enqueue: ";
        cin >> symbol;
        enqueue(q, symbol);
    }

    cout << "Enter a symbol to check if it matches the first element: ";
    cin >> symbol;

    if (!isQueueEmpty(q) && q.data[q.front] == symbol) {
        cout << "Queue elements: ";
        display(q);
        cout << "Queue size: " << size(q) << endl;
    }
    else {
        cout << "Symbol does not match the first element of the queue" << endl;
    }

    return 0;
}
