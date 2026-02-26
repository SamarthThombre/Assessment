#include <iostream>
using namespace std;
class queue{
	int arr[100];
	int front,rear;
	public:
		queue(){
			front=rear=-1;
		}
		bool is_empty(){
			return front==-1;
		}
		void enqueue(int x){
			if(rear==99){
				cout<<"Queue overflow\n";
			}
			if(front==-1){
				front=0;
			}
			arr[++rear]=x;
		}
		void dequeue(){
			if(is_empty()){
				cout<<"Queue empty\n";
			}
			else{
				cout<<"Front element : "<<arr[front]<<endl;
			}
		}
		void show_front() {
        if (is_empty())
            cout << "Queue Empty\n";
        else
            cout << "Front Element: " << arr[front] << endl;
        }
		void display(){
			if(is_empty()){
				cout<<"Queue Empty\n";
			}
			for(int i=front;i<=rear;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};
int main(){
	queue q;
    int choice, value;

    while (true) {
        cout << "\n1 Enqueue\n2 Dequeue\n3 Front\n4 Display\n5 Exit\n";

		cin >> choice;

        if (choice == 1) {
            cin >> value;
            q.enqueue(value);
        }
        else if (choice == 2)
            q.dequeue();
        else if (choice == 3)
            q.show_front();
        else if (choice == 4)
            q.display();
        else
            break;
    }
    return 0;
}
	


