#include <iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class stack{
	node *top;
	public:
		stack(){
			top=NULL;
		}
		bool is_empty(){
			return top==NULL;
		}
		void push(int x){
			node *n=new node();
			n->data=x;
			n->next=top;
			top=n;
		}
		void pop(){
			if(is_empty()){
				cout<<"Stack Underflow\n";
			}
			node *temp=top;
			cout<<"Popped : "<<top->data<<endl;
			top=top->next;
			delete temp;
		}
		void peek(){
			if(is_empty()){
				cout<<"Stack is empty\n";
			}
			cout<<"Top element : "<<top->data<<endl;
		}
		void display(){
			if(is_empty()){
				cout<<"Stack Empty\n";
			}
			node *temp=top;
			cout<<"Stack : ";
			while(temp){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
};
int main(){
	stack s;
    int choice, value;
    while (true) {
        cout << "\n1 Push\n2 Pop\n3 Peek\n4 Display\n5 Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid Choice\n";
        }
    }
	return 0;
}
