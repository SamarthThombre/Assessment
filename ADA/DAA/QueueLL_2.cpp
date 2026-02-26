#include <iostream>
using namespace std;

class CircularQueue {
    int arr[10];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool is_empty() {
        return front == -1;
    }

    bool is_full() {
        return (rear + 1) % 10 == front;
    }

    void enqueue(int x) {
        if (is_full()) {
            cout << "Queue is Full\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear = (rear + 1) % 10;
        arr[rear] = x;

        cout << x << " inserted\n";
    }

    void dequeue() {
        if (is_empty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Removed: " << arr[front] << endl;

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % 10;
    }

    void display() {
        if (is_empty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % 10;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    while (true) {
        cout << "\n1 Enqueue\n2 Dequeue\n3 Display\n4 Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            q.display();
        }
        else if (choice == 4) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

