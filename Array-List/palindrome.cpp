#include <iostream>
using namespace std;
int main(){
	char *arr;
	int size;
	cout<<"Enter size: ";
	cin>>size;
	arr=new char[size];
	cout<<"Enter the Word"<<endl;
	for (int i=0;i<size;i++){
		cin>>arr[i];
	}
	int j;
	j=5-1;
	for (int i=0;i<=5/2;i++){
		if(*(arr+i)==*(arr+j)){
			j--;
		}
		else {
			cout<<"not a palindrome"<<endl;
			return 0;
		}
		

	}
	cout<<"Is a palindrome"<<endl;
}
