#include<iostream>
using namespace std;

#define MAX 200

    int front = -1;
    int rear = -1;
    int queue[MAX];

void delete_prev_people(){
    int i = 0;
    while( i < 20 ) {
        front++;
        i++;
    }
}

int get_length() {
    int temp;
    int length = 0;
    temp = front;

    while( temp <= rear ) {
        length++;
        temp++;
    }
 return length;
}
void enqueue( int val ) {
    if( rear == MAX-1 ) {
        cout<<"QUEUE OVERFLOW"<<endl;
    }
    else {
        if ( front == -1 ){
            front = 0;
        }
            queue[rear+1]= val;
            rear += 1;
    }
}
void dequeue() {
    if ( front == -1 || front > rear ) {
        cout<<"QUEUE UNDERFLOW"<<endl;
    }
    else {
        cout<<"VALUE DELETED "<<queue[front]<<endl;
        front += 1;
    }
}
void display() {
    if ( front == -1 ) {
        cout<<"Empty queue"<<endl;
    }
    else {
        int temp = front;
        while ( temp <= rear ) {
            cout<<queue[temp]<<" ";
            temp += 1;
        }
        cout<<endl;
    }
}
void check_stat() {
    int adult = 0;
    int child = 0;
    int temp = front;
    while ( temp <= rear ) {
        if( temp == -1 ) {
            temp++;
        }
        else if( queue[temp] < 18 ) {
            child++;
        }
        else {
            adult++;
        }
            temp++;
    }
    cout<<"TOTAL CHILDREN: "<<child<<endl;
    cout<<"TOTAL ADULTS: "<<adult<<endl;
}
int main() {
    int choice;
    int length;
          cout<<"\n--------------------Roller Coaster QUEUE------------------\n";
          cout<<"|\t\t\t\t\t\t\t |\n|\t\t1. ENQUEUE                               |\n";
          cout<<"|\t\t2. DEQUEUE                               |\n";
          cout<<"|\t\t3. DISPLAY ALL PERSONS IN QUEUE          |\n";
          cout<<"|\t\t4. DISPLAY ADULTS AND CHILDREN           |\n";
          cout<<"|\t\t5. DELETE PREVIOUS PEOPLE                |\n";
          cout<<"|\t\t6. EXIT                                  |\n";
          cout<<"|\t\t\t\t\t\t\t |\n|\t\t\t\t\tBy- MOHITBLAZE07 |\n----------------------------------------------------------"<<endl;
        while(1) {
        //     cout<<"\n--------------------Roller Coaster QUEUE------------------\n";
        //   cout<<"|\t\t\t\t\t\t\t |\n|\t\t1. ENQUEUE                               |\n";
        //   cout<<"|\t\t2. DEQUEUE                               |\n";
        //   cout<<"|\t\t3. DISPLAY ALL PERSONS IN QUEUE          |\n";
        //   cout<<"|\t\t4. DISPLAY ADULTS AND CHILDREN           |\n";
        //   cout<<"|\t\t5. DELETE PREVIOUS PEOPLE                |\n";
        //   cout<<"|\t\t6. EXIT                                  |\n";
        //   cout<<"|\t\t\t\t\t\t\t |\n|\t\t\t\t\tBy- MOHITBLAZE07 |\n----------------------------------------------------------"<<endl;

            cout<<"Enter your choice : ";
            cin>>choice;
            switch(choice){
                case 1:
                        length = get_length();
                        if ( length >= 20 ) {
                            cout<<"CANNOT BE INSERTED! Queue Limit full MAX 20 People can stand in queue!"<<endl;
                        }
                        else {
                            int age;
                            cout<<"ENTER PERSON's AGE: "<<endl;
                            cin>>age;
                            enqueue(age);
                        }
                        break;
                case 2:
                        dequeue();
                        break;
                case 3:
                        display();
                        break;
                case 4:
                        check_stat();
                        break;
                case 5:
                        delete_prev_people();
                        break;
                case 6:
                        exit(0);

                default: cout<<"Invalid choice!"<<endl;
                         break;
            }
        }
return 0;
}