#include<iostream>
using namespace std;
//FUNCTION FOR LENGTH
int find_length(char *arr){
	int count=0;
	while(*arr!='\0'){
		count++;
		arr++;
	}
	return count;

}
//FUNCTION FOR INDEX
int find_index(char *arr){
	int index=0;
	for (int i=0; i<find_length(arr); i++){
		while (*arr!='.'){
			index++;
			arr++;
		}
}
	return index;
}


int main(){
    char *ch = (char*)"1232333.3422324234";
    //// YOUR CODE*/
    cout<<"The length of the string is: "<<find_length(ch)<<endl;
    cout<<"The index of decimal is: "<<find_index(ch)<<endl;
    return 0;
}
