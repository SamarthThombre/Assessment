#include <iostream>
using namespace std;
class stack{
	int arr[100];
	int top;
	public:
		stack(){
			top=-1;
		}
		bool is_empty(){
			return (top==-1);
		}
		void push(int x){
			if(top == 99){
				cout<<"Stack Overflow\n";
				return;
			}
			arr[++top]=x;
		}
		int pop(){
			if(is_empty()){
				cout<<"Stack Underflow\n";
			}
			cout<<"Popped : "<<arr[top--]<<endl;
		}
		int peek(){
			if(is_empty()){
				cout<<"Stack Empty\n";
			}
			cout<<"Top element : "<<arr[top]<<endl;
		}
		void display(){
			if (is_empty()) {
			    cout << "Stack is Empty\n";
                return;
           }
           cout<<"Stack\n";
			for(int i=0;i<=top;i++){
				cout<<arr[i]<<" ";
			cout<<endl;
			}
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

