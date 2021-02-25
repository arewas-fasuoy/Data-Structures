#include <iostream>
using namespace std;

struct node{
	int data;
	node *left, *right;
};

class BST{
private:
	node *root;
public:
	BST(){
		root = NULL;
	}

	node* Get_Root(){
		return root;
	}
	node* Create(int value){
		node* Node = new node();
		Node->left=NULL;
		Node->right=NULL;
		Node->data=value;
		return Node;
	}

	void Deletion(node *temp, int value){
		node *temp1;
		if (temp->right->data==value){
			if((temp->right->right==NULL) && (temp->right->left==NULL)){

				//case1
				delete temp->right;
				temp->right=NULL;
				return;
			}
			//case2
			else if((temp->right->right!=NULL) && (temp->right->left==NULL)){
				temp1=temp->right;
				temp->right=temp1->right;
				delete temp1;
				return;
			}
			else if((temp->right->right==NULL) && (temp->right->left!=NULL)){
				temp1=temp->right;
				temp->right=temp1->left;
				delete temp1;
				return;
			}
			//case 3
			else if((temp->right->right!=NULL)&&(temp->right->left!=NULL)){
				node* delete_node=find_successor(temp->right->right);
				temp->right=delete_node->left;
				delete delete_node->left;
				delete_node->left==NULL;
			}
		}
		
			//Deletion(temp->left,value);
		if(temp->right->right!=NULL)
			Deletion(temp->right,value);
		
	}
	node* find_successor(node* temp){
		if(temp->left->left!=NULL){
			find_successor(temp->left);
		}
		return temp;
	}

	void Insertion(node *temp,int value){
		
		if(root==NULL){
			root=Create(value);
			return;
		} 

		if (value > temp->data){
			if(temp->right==NULL){
				temp->right=Create(value);
				return;
			}
			else Insertion(temp->right,value);
		}

		else if(value<temp->data){
			if (temp->left==NULL){
				temp->left=Create(value);
				return;
			}
			else Insertion(temp->left,value);
		}
	
	
	}


	void inorder_print(node* temp){
		if (temp==NULL){
			cout<<"Tree is Empty"<<endl;
			return;
		}
		if(temp->left!=NULL)
			inorder_print(temp->left);

		cout<<temp->data<<" ";

		if(temp->right!=NULL)
			inorder_print(temp->right);
	}

};
int main(){
	BST bst;

	bst.Insertion(bst.Get_Root(), 20);
    bst.Insertion(bst.Get_Root(),30);
    bst.Insertion(bst.Get_Root(), 15);
  	bst.Insertion(bst.Get_Root(), 10);
   	bst.Insertion(bst.Get_Root(), 18);
    bst.Insertion(bst.Get_Root(), 29);
    bst.Insertion(bst.Get_Root(), 42);
    bst.Insertion(bst.Get_Root(), 8);
	bst.Insertion(bst.Get_Root(), 16);
    bst.Insertion(bst.Get_Root(), 17);
    bst.Insertion(bst.Get_Root(), 41);
    bst.Insertion(bst.Get_Root(), 45);
   	bst.Insertion(bst.Get_Root(), 39);
	bst.Insertion(bst.Get_Root(), 50);
    bst.inorder_print(bst.Get_Root());
    cout<<endl;
    bst.Deletion(bst.Get_Root(),45);
    cout<<endl;
  	bst.inorder_print(bst.Get_Root());
  	cout<<endl;
   // bst.inorder_print(bst.Get_Root());
}