#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyList {
    Node* head;

public:
    SinglyList() {
        head = NULL;
    }

    void insert_at_head(int x) {
        Node* n = new Node();
        n->data = x;
        n->next = head;
        head = n;
    }

    void insert_at_tail(int x) {
        Node* n = new Node();
        n->data = x;
        n->next = NULL;

        if (head == NULL) {
            head = n;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = n;
    }

    void delete_node(int x) {
        if (head == NULL) return;

        if (head->data == x) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != x)
            temp = temp->next;

        if (temp->next) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }

    bool search(int x) {
        Node* temp = head;
        while (temp) {
            if (temp->data == x)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyList s;

    s.insert_at_head(3);
    s.insert_at_head(2);
    s.insert_at_head(1);
    
    s.insert_at_tail(4);
    s.insert_at_tail(5);
    s.insert_at_tail(6);

    cout << "Singly List: ";
    s.display();

    s.delete_node(3);

    cout << "After Deletion: ";
    s.display();

    return 0;
}

