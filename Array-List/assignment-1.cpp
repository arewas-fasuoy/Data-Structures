#include <iostream>
#include <string>
using namespace std;
class Array_Operation{
private:
	int *ptr1;
	int *ptr2;
	int length;
	int *array;
	int arr[8]={2,3,2,3,3,4,5,6};
public:
 Array_Operation(){
 	ptr1=NULL;
 	ptr2=NULL;
 	length=0;
 	array= new int[15];
 }
 int * MostFrequentElementInSubArray(int left, int right, int frequency){
 	ptr1 = arr;
 	length=sizeof(arr)/sizeof(arr[0]); //finding length of array
 		if (left>=0 && right>=left && right<length){ //constraint 1
 			if (2*frequency>=right-left+1){	//constraint 2
 				for (int i =0; i<right; i++){
 					int count=1;
 					ptr2=arr+i+1;
 					for (int j= 0; j<right; j++){
 						if (*ptr1==*ptr2){
 							count++;
 							ptr2++;
 						}
 						else {
 							ptr2++;
 						}
 					}
 					ptr1++;
 					if(count>=frequency){
 						*(array+i)=*ptr1; //apending elements into array whose frequency is greater of equal to the given freqeuncy
 						cout<<endl<<"Elements whose Frequency is greater or equal to the given Frequency are: "<<*(array+i)<<endl;
 					}

 				}

 			}
 			else{
 				cout<<"Please Enter a valid Frequency that is greater than 1"<<endl;
 			}
 		}
 		else {
 			cout<<"Error: Invalid Indexes. Kindly Enter a valid index range "<<endl;
 		}
 		return array; //returning the address of array of matched frequency elements
	}
};
int main(){
	Array_Operation obj;
	int *arr;
 	arr=obj.MostFrequentElementInSubArray(1,4,3);
 	cout<<endl<<"Elements whose Frequency is greater or equal to the given Frequency are: "<<endl;
 	int length1=sizeof(arr)/sizeof(arr[0]);
 	for (int i=0; i<length1; i++){ //printing the elements of array returned by function; 
 		cout<<*(arr+i)<<endl;
 	}

 return 0;
}