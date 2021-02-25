#include<iostream>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

class BST {

private:
	node *root;

public:
    BST() {
		root = NULL;
		
	}

	bool check_left(node *temp) {
		if (temp->left == NULL) {
			return true;
		}
		else return false;
	}

	bool check_right(node *temp) {
		if (temp->right == NULL)
			return true;
		else return false;
	}

	bool is_greater(int val, int val_1) {
		if (val > val_1)
			return true;
		else return false;
	}

	node* Create(int data) {
		node *Node = new node();
		Node->data = data;
		Node->left == NULL;
		Node->right == NULL;
		return Node;
	}

	void Insertion(node *temp, int data) {
		if (root == NULL) {
			root = Create(data);
			return;
		}
		if (is_greater(temp->data, data)) {
			if (check_left(temp)) {
				temp->left = Create(data);
				return;
			}
			else Insertion(temp->left, data);

		}
		else {
			if (check_right(temp)) {
				
				temp->right = Create(data);
				temp->right->left = temp->right->right = NULL;
				return;
			}
			else Insertion(temp->right, data);
		}

	}

	node *Get_Root() {
		return root;
	}

	void print(node *temp) {
		if (temp == NULL)
			return;
		print(temp->left);
		cout << temp->data << " ";
		print(temp->right);
	}

	// ***********Function for Part A**************
    int get_count(node*temp,int count){
    	if(temp==NULL)
    		return 0;
    	if(!check_left(temp))
    		count=get_count(temp->left,count);
    	count++;
    	if(!check_right(temp))
    		 count= get_count(temp->right,count);
    	return count;
    }

    // ***************Part A*******************
    int count_nodes(node* iter, int val, int count=0){	
        //   YOUR CODE HERE /////
        if(iter==NULL)
    		return 0;
    	if(is_greater(iter->data,val))
    		return count_nodes(iter->left,val,count);
    	if(is_greater(val,iter->data))
    		return count_nodes(iter->right,val,count);
    	if(iter->data==val)
    		return get_count(iter,count);

    }
  
	// ***********Function for Part B**************
 	void helper_B(node* temp, bool flag,int height,int *left_most){
    	if (temp==NULL)
    		return;
    	
    	if (!check_left(temp))
    		helper_B(temp->left,true,height+1, left_most);

    	if (flag && is_greater(height,*left_most)){
    		*left_most=height;
    		return;
    	}

    	if (!check_right(temp))
    		helper_B(temp->right,false,height+1, left_most);
    	


    }

    // ****************Part-B********************
    int left_most_node(node *root_iter){
        // YOUR CODE HERE
        int max=0;
        helper_B(root_iter,0,0,&max);
        return max;


    }

    // ***********Function for Part C**************
    void get_sum(node* temp,bool flag, int *sum){
    	if (temp==NULL)
    		return;
    	
    	if(!check_left(temp))
    		get_sum(temp->left,0,sum);
    	
    	if(flag && check_left(temp) && check_right(temp)){
            *sum+=temp->data; 
            return;
        }
    	
    	if(!check_right(temp))
    		get_sum(temp->right,1,sum);


    }


    
    // **********************PART-C********************
    int right_leaves(node* root_iter){
        // YOUR CODE HERE
        int summ=0;
        get_sum(root_iter,0,&summ);
        return summ;
    }


    // ***********Function for Part D**************
    void differ(node* temp, node* &prev, int& ans){  
    
    int sub=ans;
       if (temp == NULL)  
        return;  
       if(prev!=NULL){
        	sub=absolute(temp->data-prev->data);
        	if(ans==0){
    		ans=sub;
    		}
        	if(sub<=ans){
        		ans=sub;
        	}
        }	
    
    prev = temp;

    if(!check_left(temp))
    differ(temp->left, prev, ans);  

	if(!check_right(temp))
    differ(temp->right, prev, ans); 

   

	}  
   // ***********Function for Part D**************
    int absolute(int value){
    	if (value>=0)
    		return value;
    	else if(value<0)
    		return -value;
    }


    // *********************PART-D******************
    int min_diff(node *root_iter,int diff=0){
        // YOUR CODE HERE

        node* prev = NULL;
       differ(root_iter,prev,diff);
       return diff;
        }
        


};

int main() {
	BST bst;

	bst.Insertion(bst.Get_Root(), 10);
    bst.Insertion(bst.Get_Root(), 4);
   bst.Insertion(bst.Get_Root(), 12);
    bst.Insertion(bst.Get_Root(), 1);
    bst.Insertion(bst.Get_Root(),8);
    bst.Insertion(bst.Get_Root(), 24);
    bst.Insertion(bst.Get_Root(), 13);
    bst.Insertion(bst.Get_Root(), 9);
 //   bst.Insertion(bst.Get_Root(), 24);
   // bst.Insertion(bst.Get_Root(), 23);
   // bst.Insertion(bst.Get_Root(), 22);
    bst.print(bst.Get_Root());
    cout<<endl;
   //  cout<<bst.left_most_node(bst.Get_Root());
   //cout<<"Count: "<<bst.count_nodes(bst.Get_Root(),12,0)<<endl;
  //  cout<<bst.right_leaves(bst.Get_Root());
     //cout<<bst.min_diff(bst.Get_Root());
    return 0;
}