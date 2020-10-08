#include <iostream>
using namespace std;
class arrayList{
private:
	int array[100], length;
public:
	arrayList(){
		length = 0;
	}
	int Length(){
		return length;
	}

	void addatend(int data){
		*(array+length)=data;
		length++;
	}
	int get_next(int position){
		if(position==100){
			cout<<"You are at the end of your List. There is no next available"<<endl;
		}
		else
			return *(array+(position+1));
	}
	int get_prev(int position){
		if(position==0){
			cout<<"You are at the beggining of your List. There is no previous available"<<endl;
		}
		else
			return *(array+(position-1));
	}
	int get_start(){
		return *array;
	}
	int get_end(){
		return *(array+(length-1));
	}
	int search(int key){
		current = array;
		for(int i= 0; i<length; i++){
			if (*current==key){
				return *current;
			}
			current++;
		}
		cout<<"Key Not Found"<<endl;
		return 0;
	}

	void insertAtPosition(int data, int position){
		int j;
		if (position<0 || position>100){
			cout<<"The Position is out of Range"<<endl;
			return;
		}
		for (int i = length-1 ; i>=position; i--){
			j=i+1;
			*(array+j)=*(array+i);
		}
		*(array+position)=data;
		length++;

	}
	void delete_item(int position){
		if(length==0){
			cout<<"The List is empty"<<endl;
			return;
		}
		if (position<0 || position>=length){
			cout<<"The Position is out of Range"<<endl;
			return;
		}
		int j;
		for (int i=position; i<length; i++){
			j=i+1;
			*(array+i)=*(array+j);
		}
		length--;
	}
	void Print(){
		if (length==0){
			cout<<"The List is Empty"<<endl;
			return;
		}
		for (int i = 0; i<length; i++){
		cout<<*(array+i)<<" " ;
	}
	cout<<endl;
	}

};
int main(){
	arrayList arr;
	arr.addatend(1);
	arr.addatend(2);
	arr.addatend(3);
	//cout<<arr.search(2)<<endl;
	arr.insertAtPosition(4,1);
	// arr.Print();
	
	cout<<arr.get_end()<<endl;
	arr.insertAtPosition(19,0);
	cout<<arr.get_start()<<endl;
	cout<<arr.get_prev(2)<<endl;
	arr.delete_item(-5);
	// cout<<arr.get_next(1)<<endl;
	arr.Print();
}