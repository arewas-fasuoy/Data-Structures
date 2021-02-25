#include <iostream>
using namespace std;

struct node{
	int data;
	node *left, *right;
	bool LTH, RTH;
};

class TH{
private:
	node *root;
	node *dummy;
public:
	TH(){
		root = NULL;
		dummy = NULL;
	}

	node* Get_Root(){
		return root;
	}
	node* Get_Dummy(){
		return dummy;
	}

	void Insertion(node *temp,int value){
	
		if(root==NULL){
	
			node *Node = new node;
			Node->data=value;
			root=Node;
			dummy->left= Node;
			dummy->right=dummy;
			Node->right= dummy;
			Node->left=dummy;
			Node->LTH=1;
			Node->RTH=1;
			return;
		} 

		if (value > temp->data){
			if(temp->RTH){
				node* Node = new node;
				Node->data=value;
				Node->right=temp->right;
				Node->left=temp;
				temp->right=Node;
				temp->RTH=0;
				Node->RTH=1;
				Node->LTH=1;

				return;
			}
			else Insertion(temp->right,value);
		}

		else if(value<temp->data){
			if (temp->LTH){
				node* Node = new node;
				Node->data=value;
				Node->left=temp->left;
				Node->right=temp;
				temp->left=Node;
				temp->LTH=0;
				Node->RTH=1;
				Node->LTH=1;
				return;
			}
			else Insertion(temp->left,value);
		}
	
	
	}

	node* find_successor(node* temp){
		if(temp->RTH){
			return (temp->right);
		}
		else{
			temp=temp->right;
			while(!temp->LTH)
				temp=temp->left;
			return temp;
		}
	}

	void fast_inorder(node* temp){
		if (root==NULL){
			cout<<"Tree is Empty"<<endl;
			return;
		}
		while((temp=find_successor(temp))!=dummy)
			cout<<temp->data<<"->";
		cout<<endl;
		return;	
	}

};
int main(){
	TH tree;

	tree.Insertion(tree.Get_Root(), 20);
    tree.Insertion(tree.Get_Root(),30);
    tree.Insertion(tree.Get_Root(), 15);
  	tree.Insertion(tree.Get_Root(), 10);
   	tree.Insertion(tree.Get_Root(), 18);
    tree.Insertion(tree.Get_Root(), 29);
 
    tree.fast_inorder(tree.Get_Dummy());
    cout<<endl;
    
 // 	bst.Insertion(bst.Get_Root(), 55);
    cout<<endl;

}