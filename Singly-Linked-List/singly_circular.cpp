#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class SinglyRingList
{
private:
	node *head;
public:
	SinglyRingList():head(NULL){}
	node* create_node(int val){
		//This function will create a node in the memory wuth the given value
		node* link_node = new node();
		link_node->data = val;
		link_node->next = NULL;
		return link_node;
	}

	node* get_tail(){
		node* iter = head;
		while(iter->next != head){
			iter = iter->next;
		}
		return iter;
	}

	void add_node_to_tail(int val){
		//this function will add node to tail of single circular list
		if (head == NULL){
			head = create_node(val);
			head->next = head;
			return;
		}
		node* tail = get_tail();
		node* link_node = create_node(val);
		link_node->next = tail->next;
		tail->next = link_node;

	}

	node* search_node(int key){
		node *iter = head;
		while (iter->data != key){
			iter = iter->next;
			if (iter == head){
				return NULL;
			}
		}
		return iter;
	}

	void add_node_at_val(int val, int key){
		node* key_node = search_node(key);
		node* link_node = create_node(val);

		link_node->next = key_node->next;
		key_node->next = link_node;
	}

        node* get_prev(node* random_node){
            node* temp_iter = head;
            if (random_node==NULL)
                    return NULL;
            if (random_node==head)return head;
            while(temp_iter->next!=random_node){
                temp_iter=temp_iter->next;
            }
            return temp_iter;
        }

	void delete_node(int key){
		//Case Head
		node* tail = get_tail();
		node* del_node = search_node(key);
		node* prev = get_prev(del_node);
		if (head->data == del_node->data){
			tail->next = head->next;
			node *del = head;
			head = head->next;
			delete del;
			del = NULL;
		}
		//Case Tail
		else if(del_node->next==head){
			prev->next=del_node->next;
			delete del_node;
			del_node=NULL;
		}
		//Random Case
		else{
			prev->next=del_node->next;
			delete del_node;
			del_node=NULL;
		}
		

	}
	void Print(){
		node* iter = head;
		do{
			cout<<iter->data<<" ";
			iter = iter->next;
		}while(iter != head);
		cout<<endl;
	}
};
int main(){
	SinglyRingList Ring;
	Ring.add_node_to_tail(1);
	Ring.add_node_to_tail(2);
	Ring.add_node_to_tail(4);
	Ring.add_node_at_val(3,2);
	Ring.delete_node(2);
	Ring.Print();
	return 0;
}