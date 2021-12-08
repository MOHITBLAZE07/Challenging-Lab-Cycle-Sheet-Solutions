#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <chrono>
#include <thread>


using namespace std;

class DVDPlayer {

private:
	const static int MAX = 1000;
	char dvdData[MAX];
	int front;
	int rear;

	bool isEmpty(){
		return front == -1 && rear == -1;
	}

	bool isFull(){
		return (rear + 1) % MAX == front;
	}

public:	
	DVDPlayer(){
		front = rear = -1;
	}

	void writeData(char data){

		if(isEmpty()){
			front = rear = 0;
			dvdData[rear] = data;
		} else if(isFull()){
			cout << "Error: DVD overflow!" << endl;
		}
		else {
			rear = (rear+1) % MAX;
			dvdData[rear] = data;
		}
	}

	char deleteData(){
		if(isEmpty()){
			cout << "Error: DVD is empty!" << endl;
			return '\0';
		}
		else if(front == rear){
			int temp = front;
			front = rear = -1;
			return dvdData[temp];			
		}
		else {
			int temp = front;
			front = (front+1) % MAX;
			return dvdData[temp];
		}
	}

	void play(){
		if(isEmpty()){
			cout << "DVD is empty" << endl;
			return;
		}

		for(int i = front; i <= rear; i = (i+1)%MAX){
			cout << dvdData[i];
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		cout << endl;
	}
 
	int getFront(){
		return front;
	}

	int getRear(){
		return rear;
	}
};


void showMenu(){
	cout << "Enter 1 to write data to dvd" << endl;
	cout << "Enter 2 to play dvd" << endl;
	cout << "Enter 3 to print front and rear index" << endl;
	cout << "Enter 4 to exit" << endl;
}


int main(){
	
	DVDPlayer dvdPlayer;
	string data;
	int choice; 

	showMenu();

	do{
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();

		switch(choice){
			case 1: {
				cout << "Enter data to be written to dvd: ";
				getline(cin, data);

				for(int i = 0; i < data.size(); i++){
					dvdPlayer.writeData(data[i]);
				}
				break;
			}

			case 2: {
				dvdPlayer.play();
				break;
			}

			case 3: {
				cout << "Front index: " << dvdPlayer.getFront() << endl;
				cout << "Rear index: " << dvdPlayer.getRear() << endl;
				break;
			}

			case 4: {
				return 0;
			}
		}



	}while(choice != 4);


	return 0;
}

