#include <iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class stack{
private:
	node *top;
	int limit;
	int i;
public:
	stack(int val){
		top = NULL;
		limit=val;
		i=0;
	}
	void push(int value){

		if(i==limit){
			cout<<"Stack OverFlow"<<endl;
			return;
		}
		if (top == NULL){
			cout<<"Pushing "<<value<<endl;
			top= new node;
			top->data = value;
			top->next=NULL;
			i++;
			return;
		}
		cout<<"Pushing "<<value<<endl;
		node* linknode = new node;
		linknode->data=value;
		linknode->next=top;
		top=linknode;
		i++;
		return;
	}
	void pop(){
		if(isEmpty()){
			cout<<"Stack UnderFlow";
			return;
		}
		node* temp;
		temp = top;
		top=temp->next;
		delete temp;
		temp=NULL;
		return;
	}
	bool isEmpty(){
		if(top == NULL){
			return true;
		}
		else 
			return false;
	}
	void print(){
		if(isEmpty()){
			cout<<"Stack is Empty"<<endl;
			return;
		}
		node * temp;
		temp = top;
		while(temp != NULL){
			cout<<temp->data<<"|";
			temp=temp->next;
		} 
		cout<<endl;
		return;
	} 
};
int main(){
	int value;
	cout<<"Enter the Limit for stack"<<endl;
	cin>>value;
	stack S1(value);
	S1.print();
	S1.push(1);
	S1.push(2);
	S1.push(3);
	S1.print();
	S1.pop();
	cout<<"Stack after popping: "<<endl;
	S1.print();
	return 0;
}