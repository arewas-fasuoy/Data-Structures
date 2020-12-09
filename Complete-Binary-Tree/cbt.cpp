#include <iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
};

class CBT{
private:
    node *root;
public:
    CBT(){
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
    
    int count_nodes(node* temp, int count=0){
        if(temp==NULL)
            return 0;
        if(temp->left!=NULL){
            count=count_nodes(temp->left,count);
        }

        count++;

        if (temp->right!=NULL){
            count=count_nodes(temp->right,count);
        }
        return count;


    }

    int  get_height(node *temp){
    if(temp == NULL)
        return 0;

    int lh = get_height(temp->left)+1;
    int rh = get_height(temp->right)+1;

    if (lh > rh) 
        return lh;
    else return rh;

    }

    int pow(int num, int exp){
        int result=1;
        for (int i=0;i<exp;i++){
            result=result*num;
        }
        return result;
    }

    void Insertion(node *temp,int value){
        
        if(root==NULL){
            root=Create(value);
            return;
        }
    
        int height = get_height(temp->left);
        int expected_nodes = pow(2,height)-1;
        int left_tree_node_count = count_nodes(temp->left);
        int right_tree_node_count = count_nodes(temp->right);

        if (left_tree_node_count == right_tree_node_count){
            if (temp->left == NULL){
                temp->left = Create(value);
                return;
            }
            Insertion(temp->left,value);
        }

        else if (left_tree_node_count != expected_nodes){
            if (temp->left == NULL){
                temp->left = Create(value);
                return;
            }
            Insertion(temp->left,value);
        }

        else if (right_tree_node_count != expected_nodes){
            if (temp->right == NULL){
                temp->right = Create(value);
                return;
            }
            Insertion(temp->right,value);
        }
    }

    void delet(node*temp,int val,node*del_node, bool flag){
        if (temp == NULL){
            return;
        }

        if(temp->left != NULL)
            delet(temp->left,val,del_node,flag);

        if(temp->right != NULL)
            delet(temp->right,val,del_node,flag);


        if(temp->data == val){
            cout<<"Deleting: "<<temp->data;
            if (flag == 1){
                temp->data = del_node->right->data;
                del_node->right = NULL;
                delete del_node->right;
                return;
            }
            else if( flag == 0){
                temp->data = del_node->left->data;
                del_node->left = NULL;
                delete del_node->left;
                return;
            }
            
        }
    
    }

    void delete_node(node* temp,int value){

        int right_height = get_height(temp->right);
        int left_height = get_height(temp->left);
        int expected_nodes = pow(2,left_height)-1;
        int left_tree_node_count = count_nodes(temp->left);
        int right_tree_node_count = count_nodes(temp->right);

        if (left_height == right_height){
            if(left_tree_node_count == right_tree_node_count){
                if(temp->right->right == NULL){
                    delet(root,value,temp,1);
                    return;
                }
            }

            delete_node(temp->right,value);
        }

        else{
            if(temp->left->left == NULL){
                delet(root,value,temp,0);
                return;
            }
            else delete_node(temp->left,value);
        }
    }

    void inorder_print(node* temp){
        if (temp == NULL){
            cout<<"Tree is Empty"<<endl;
            return;
        }
        if(temp->left != NULL)
            inorder_print(temp->left);

        cout<<temp->data<<" ";

        if(temp->right != NULL)
            inorder_print(temp->right);
    }

};
int main(){
    CBT cbt;

    cbt.Insertion(cbt.Get_Root(), 10);
    cbt.Insertion(cbt.Get_Root(), 4);
    cbt.Insertion(cbt.Get_Root(), 12);
    cbt.Insertion(cbt.Get_Root(), 1);
    cbt.Insertion(cbt.Get_Root(), 8);
    cbt.Insertion(cbt.Get_Root(), 24);
    cbt.Insertion(cbt.Get_Root(), 13);
    cbt.Insertion(cbt.Get_Root(), 9);
    cbt.Insertion(cbt.Get_Root(), 3);
    cbt.Insertion(cbt.Get_Root(), 6);
    cbt.Insertion(cbt.Get_Root(), 5);
    cbt.Insertion(cbt.Get_Root(), 20);
    cbt.Insertion(cbt.Get_Root(), 30);
    cbt.Insertion(cbt.Get_Root(), 40);
    cbt.Insertion(cbt.Get_Root(), 50);
    cbt.inorder_print(cbt.Get_Root());
    cout<<endl;
    cbt.delete_node(cbt.Get_Root(),12);
    cout<<endl;
    cbt.inorder_print(cbt.Get_Root());
    cout<<endl;
}