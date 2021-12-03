#include <iostream>
#include <string>

using namespace std;


class Node{
public:
	char data;
	Node *next;

	Node(char data) {
		this->data = data;
		next = NULL;
	}
};

class CircularLinkedList{
private:
	Node *head;

	int getSize(){


		int size = 0;

		if(head == nullptr) return size;

		Node* ptr = head;

		do{
			++size;
			ptr = ptr->next;
		}while(ptr != head);

		return size;		
	}

public:
	CircularLinkedList(){
		head = nullptr;
	}



	void insert(Node *newNode){
		if(head == nullptr){
			head = newNode;
			newNode->next = head;
		}
		else {
			Node *ptr = head;
			while(ptr->next != head){
				ptr = ptr->next;
			}

			ptr->next = newNode;
			newNode->next = head;
		}
	}

	char findOutTheirRelationship(){
		return head->data;
	}

	void printTheirRelationship(string name1, string name2, char relation){

		switch(relation){
			case 'F' : cout << name1 << " and " << name2 << " are friends" << endl; break;
			case 'L' : cout << name1 << " and " << name2 << " are love birds" << endl; break;
			case 'A' : cout << name1 << " has affaction for " << name2 << endl; break;
			case 'M' : cout << name1 << " will marry to " << name2 << endl; break;
			case 'E'	: cout << name1 << " and " << name2 << " are enemy" << endl; break;
			case 'S' : cout << name1 << " and " << name2 << " are sisters" << endl; break;
		}

	}


	void deleteFirst(){
		Node* newHead = head->next;
		Node* nodeToBeDeleted = head;
		Node* temp = head;

		do{
			temp = temp->next;
		}while(temp->next != head);

		delete nodeToBeDeleted;

		temp->next = newHead;
		head = newHead;
	}



	void deleteByPosition(int position){

		if(position%getSize() == 1){
			deleteFirst();
			return;
		}

		
		Node* previousPtr = nullptr;
		Node* nextPtr = head;
		Node* nodeToBeDeleted = nullptr;

		int i = 1;

		while(i != position){
			previousPtr = nextPtr;
			nextPtr = nextPtr->next;
			i++;
		}
	


		previousPtr->next = nextPtr->next;
		head = nextPtr->next;

		nodeToBeDeleted = nextPtr;
		delete nodeToBeDeleted;
		

	}

};


int findUniqueCharCount(string name1, string name2){

	int count = 0;
	for(int i = 0; i < name1.size(); i++){
		for(int j = 0; j < name2.size(); j++){
			if(name1[i] == name2[j]){
				name2.erase(j, 1);
				++count;				
				break;
			}
		}
	}

	return (name1.size() + name2.size())-count;
}



int main(){

	string name1, name2;
	int n = 0;

	do {

			CircularLinkedList list;

			Node *f = new Node('F');
			Node *l = new Node('L');
			Node *a = new Node('A');
			Node *m = new Node('M');
			Node *e = new Node('E');
			Node *s = new Node('S');

			list.insert(f);
			list.insert(l);
			list.insert(a);
			list.insert(m);
			list.insert(e);
			list.insert(s);

			cout << "Enter name 1: ";
			getline(cin, name1);

			cout << "Enter name 2: ";
			getline(cin, name2);

			int differentCharsCount = findUniqueCharCount(name1, name2);

			for(int i = 0; i < 5; i++){
				list.deleteByPosition(differentCharsCount);
			}

			char relation = list.findOutTheirRelationship();

			list.printTheirRelationship(name1, name2, relation);

			cout << "Do you want to continue (enter 1 for yes)? : ";

			cin >> n;

			cin.ignore();

			if(n == 1) continue;
			else break;


	}while(n != 0);

	return 0;

}


