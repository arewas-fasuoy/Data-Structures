#include <iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class Queue{
private:
	node* front;
	node* rear;
	int limit;
	int i;
public:
	Queue(int size){

		front = rear = NULL;
		limit=size;
		i=0;
	}
	void Enqueue(int value){

		if(i==limit){
			cout<<"OverFlow"<<endl;
			return;
		}

		if (front==NULL){
			node* temp=new node;
			temp->data=value;
			front = temp;
			rear = temp;
			temp->next=NULL;
			i++;
			return;
		}
		node *temp = new node;
		temp->data = value;
		rear->next=temp;
		rear= temp;
		rear->next=NULL;
		i++;
		return;
	}

	void Dequeue(){
		if(front==NULL){
			cout<<"UnderFlow"<<endl;
			return;
		}
		node* temp;
		temp=front;
		if(front==rear){
			rear = front->next;
		}
		front=front->next;
		delete temp;
		temp=NULL;
		i--;
		return;

	}

	void Print(){
		if(front==NULL){
			cout<<"Queue is Empty"<<endl;
			return;
		}
		node* temp;
		temp=front;
		while(temp!=NULL){
			cout<<temp->data<<"|";
			temp=temp->next;
		}
		cout<<endl;
		return;
	}
};
int main(){
	int size;
	cout<<"Enter the limit for Queue"<<endl;
	cin>>size;
	Queue Q1(size);
	//Q1.Print();
	//Q1.Dequeue();
	Q1.Enqueue(1);
	Q1.Enqueue(2);
	Q1.Enqueue(3);
	Q1.Print();
	Q1.Dequeue();
	Q1.Enqueue(6);
	Q1.Print();
	return 0;
}
