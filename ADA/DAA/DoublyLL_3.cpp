#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyList {
    Node* head;

public:
    DoublyList() {
        head = NULL;
    }

    void insert_at_head(int x) {
        Node* n = new Node();
        n->data = x;
        n->prev = NULL;
        n->next = head;

        if (head)
            head->prev = n;

        head = n;
    }

    void insert_at_tail(int x) {
        Node* n = new Node();
        n->data = x;
        n->next = NULL;

        if (head == NULL) {
            n->prev = NULL;
            head = n;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = n;
        n->prev = temp;
    }

    void delete_node(int x) {
        Node* temp = head;

        while (temp && temp->data != x)
            temp = temp->next;

        if (!temp) return;

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;

        delete temp;
    }

    void display_forward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void display_backward() {
        Node* temp = head;
        while (temp && temp->next)
            temp = temp->next;

        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyList d;

    d.insert_at_head(3);
    d.insert_at_head(2);
    d.insert_at_head(1);

    d.insert_at_tail(4);
    d.insert_at_tail(5);
    d.insert_at_tail(6);

    cout << "Forward: ";
    d.display_forward();

    cout << "Backward: ";
    d.display_backward();

    d.delete_node(3);

    cout << "After Deletion Forward: ";
    d.display_forward();

    cout << "After Deletion Backward: ";
    d.display_backward();

    return 0;
}

