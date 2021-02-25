#include <iostream>
using namespace std;
class stack{
private:
	int size=3;
	int *arr = new int[size];
	int *top;
	int i;
public:
	stack(){
		top=NULL;
		i=0;
	}
	void push(int value){
		if(i>=size){
			cout<<"Stack OverFlow"<<endl;
			return;
		}
		if(top==NULL){
			cout<<"Pushing "<<value<<endl;
			*(arr+i)=value;
			top = arr+i;
			i++;
			return;

		}
		cout<<"Pushing "<<value<<endl;
		*(arr+i)=value;
		top=arr+i;
		i++;
		return;
	}
	void pop(){
		if(isEmpty()){
			cout<<"Stack UnderFlow"<<endl;
			return;
		}
		i--;
		top=arr+i;
	}
	void print(){
		if(isEmpty()){
			cout<<"Array is empty"<<endl;
			return;
		}
		for (int j=i-1; j>=0; j--){
			cout<<*(arr+j)<<"|";
		}
		cout<<endl;
		return;
	}
	bool isEmpty(){
		if(top==NULL)
			return true;
		else 
			return false;
	}
};
int main(){
	stack S1;
	//S1.print();
	//S1.pop();
	S1.push(1);
	S1.push(2);
	S1.push(3);
	S1.push(4);
	S1.print();
	S1.pop();
	cout<<"Stack after popping: "<<endl;
	S1.print();
	return 0;
}