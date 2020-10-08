#include <iostream>
using namespace std;
struct node{
	int info;
	node* next;
};
class SinglyLinkedList{
private:
	node *head, *current;

public:

	SinglyLinkedList(){
		head = current = NULL;
	}
	node* createnode(int data){
		node* linknode = new node;
		linknode->info = data;
		linknode->next = NULL;
		return linknode;
	}
	void insert(int data){
		int choice;
		if (head == NULL){
			head = createnode(data);
			return;
		}
		cout<<"Press 1 to insert at head"<<endl;
		cout<<"Press 2 to insert at tail"<<endl;
		cin>>choice;
		node* linknode = createnode(data);
		if(choice == 1){
			node* linknode = createnode(data);
			linknode->next = head;
			head = linknode;
			return;
		}
		else if (choice == 2){
			//cout<<"hello";
			current = gettail(); 
			current->next = linknode;
			linknode->next = NULL;
			return;
		}

	}

	node* getPrevious(node* random_node){

	}
	node* gettail(){
		current = head;
		while (current != NULL){
			current = current->next;
			if (current->next == NULL){
				return current;
			}
		}
	}

	node* searchNode(int key){
		current = head;
		while(current != NULL){
			if (current->info == key){
				return current;
			}
			current = current->next;
		}
		return current;
	}
	void insertAtPosition(int data, int key){
		node* keynode = searchNode(key);
		node *linknode = createnode(data);
		linknode->next = keynode->next;
		keynode->next = linknode;

	}

	void remove(int key){
		if (head == NULL){
			cout<<"The List is Empty"<<endl;
			return;
		}
		//remove head
		if(head->info==key){
			node* temp = head;
			head = temp->next;
			delete temp;
			return;
		}

		current = head;
		while(current != NULL){
			if(current->next->info == key){
				node* temp = current->next;
				current->next = temp->next;
				delete temp;
				return;
			}
			current = current->next; 
		}
		//node* tail= gettail();
		//if (tail->info == key){

		//}
		/*current = head;
		while(current != NULL){
			if(current->next->info == key){
				node* linknode = current->next;
				current->next = linknode->next;
				delete linknode;
				linknode = NULL;
				return;
			}
			current = current->next; 
		}*/
	}

	void print(){
		if (head == NULL){
			cout<<"The List is Empty"<<endl;
			return;
		}
		current = head;
		cout<<"Your List is: ";
		while(current != NULL){
			cout<<current->info<<" ";
			current = current->next;
		}
		cout<<endl;

	}
};
int main(){
	SinglyLinkedList l1;
	l1.insert(2);
	l1.print();
	l1.insert(1);
	l1.print();
	l1.insert(4);
	l1.print();
	l1.insertAtPosition(3,2);
	l1.print();
	l1.remove(1);
	l1.print();
	l1.remove(3);
	l1.print();
	return 0;

}