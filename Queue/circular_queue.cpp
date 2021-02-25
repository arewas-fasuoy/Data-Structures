#include <iostream>
using namespace std;
class CircularQueue{
private:
	int *arr;
	int *front;
	int *rear;
	int size;
public:
	CircularQueue(){
		front = rear = NULL;
		arr = new int[5];
		size=5;
	}
	void Enqueue(int value){
		if(front == NULL){
			*arr=value;
			front = arr;
			rear = arr; 
			return;
		}
		if(rear == arr+(size-1) && front == arr){
			cout<<"Overflow"<<endl;
			return;
		}
		if(rear+1 == front){
			cout<<"OverFlow"<<endl;
			return;
		}
		if(rear == arr+(size-1) && front != arr){
			rear = arr;
			*rear = value;
			return;
		}
		rear++;
		*rear= value;
		return;
	}

	void Dequeue(){
		if(front == NULL){
			cout<<"UnderFlow"<<endl;
			return;
		}
		if(front==arr+(size-1)){
			front= arr;
			return;
		}
		if(front == rear){
			front=NULL;
			rear = NULL;
			return;
		}
		front++;
		return;
	}
	void print(){
		if(front==NULL){
			cout<<"Queue is Empty"<<endl;
			return;
		}
		int* temp = front;
		while(temp!= rear+1){
			cout<<*temp<<"|";
			temp++;
		}
		cout<<endl;
	}
};
int main(){
	CircularQueue Q1;
	Q1.Enqueue(1);
	Q1.Enqueue(2);
	Q1.Enqueue(3);
	Q1.Enqueue(4);
	Q1.Enqueue(5);
	Q1.print();
	Q1.Dequeue();
	Q1.print();
	Q1.Enqueue(5);
	Q1.print();
	return 0;
}