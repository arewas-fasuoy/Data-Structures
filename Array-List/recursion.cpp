#include<iostream>
#include<string>
using namespace std;

// ############# PART-A #######################
////////  DO NOT CHANGE FUNCTION NAME AND PARAMTERS ///////
string leave_2nd_print_reverse(string str, int leave, int index=0){
     
       // YOUR CODE HERE
	if(index>str.length()-1 || str.length()==0)
		return "";
	
	else{
		if(index+leave<=str.length()-1)
		return (leave_2nd_print_reverse(str,leave,index+leave)+str[index+leave]);
		return "";
	}
}


////////  DO NOT CHANGE FUNCTION NAME AND PARAMTERS ///////
// ############# PART-B #######################

   // UNCOMMENT WHEN YOU DONE WITH PART A BECAUSE TEST CASES WILL SHOW YOU FAIL
int count_after_specific(string str, int num1,int num2, int index=0){
    // YOUR CODE HERE
    	if(index>str.size()-1)
		return 0;
	else{
	if (str[index]-'0'==num1 && str[index+1]-'0'==num2)
		{
		return count_after_specific(str,num1,num2,index+1)+1;}
	else 
		{
		return count_after_specific(str,num1,num2,index+1);}
	}
}

int main(){


 
    // PART A SAMPLE
 /*  if (leave_2nd_print_reverse("aabdfb",2,0) == "fb")
        cout<<"Match"<<endl;
    
    else
     cout<<"MissMatch"<<endl;*/
   cout<<"Output:"<<leave_2nd_print_reverse("",2,0)<<endl;

    // PART B SAMPLE
    //cout<<"Output:"<<count_after_specific("111123112322311232000230",2,5,0)<<endl;

}
