#include<iostream>
#include<string.h>

  // Max strength of students submitting assignments.
#define MAX 65

using namespace std;
 

class Table {
    private:
              string table[MAX]; // Teacher's table representing stack.
              int top; //Declaring top for keeping track of top assignment's roll no.

    public:
          //constructor for initialization
              Table() {
                top = -1; // initializing top = -1; initialized empty Table.
              }

      // push operation method defination
              void push( string roll_number) {
                //check for overflow condition.
                  if( top == MAX-1 ) {
                      cout<<"Table is full, no space for keeping new assignment!"<<endl;
                  }
                  else {
                      table[++top] = roll_number; //keep the assignment on top of previous submitted assignment.
                  }
              }

          // pop operation method defination
              int pop() {
                string roll_number;
                //check for underflow condition.
                  if( top == -1 ) {
                      cout<<"Table is already empty, no assignents to pop out!"<<endl;
                  }
                  else {
                      roll_number = table[top];
                      top -= 1;// decrement the top to update the latest top assignment
                      cout<<"Popped Assignment's Roll number is: "<<roll_number<<endl;
                  }
              }

              void display() {
                // if table have no assignments.
                  if( top == -1 ) {
                      cout<<"Table is empty, No assignment to display!"<<endl;
                  }
                //if table is having less or equal to 10 assignments.
                  else if( top <= 9 ) {
                    cout<<"Assignment's submitted by Roll numbers on table are:"<<endl;
                      for( int i = top; i>=0; i-- ) {
                          cout<<table[i]<<endl;
                      }
                  }
           //MIDDLE LEVEL SOLUTION

           //if table is having more than 10 assignments, then display first 10 assignments only
                  else if ( top > 9 ) {
                    int temp = top; //using temp variable to keep all assignments safe.
                      while( temp != 9 ) {
                        temp--; // pop until 10th assignment is encountered.
                      }
                      cout<<"First 10 submitted Assignment's Roll numbers in LIFO order are: "<<endl;
                      for( int i = temp; i>=0; i-- ) {
                          cout<<table[i]<<endl; // display first 10 assignments.
                      }
                  }
              }
            
            // LOW LEVEL SOLUTION

    // method for checking the last submitted assignment's roll number.

              void get_top() {
                // if table has no assignment.
                  if( top == -1 ) {
                      cout<<"Table is empty, No assignment to display!"<<endl;
                  }
                  else {
                      string roll_number = table[top];
                      cout<<"Roll number of Last Submitted Assignment is: "<<roll_number<<endl; //display the last submitted assignment's roll number.
                  }
              }

                  //HIGH LEVEL SOLUTION

        // search method checks whether the particular roll number has submitted the assignment or not.
              void search( string s ) {
                //if the table has no assignment.
                  if( top == -1 ) {
                    cout<<"Table is empty, Search not possible!"<<endl;
                  }
                  else {
                      for( int i = top; i>=0; i--) {
                        // if the roll number has submitted.
                          if(strcasecmp(table[i].c_str(),s.c_str()) == 0 ) {
                                cout<<"Assignment Submitted for Roll number: "<<s<<endl;
                                return;
                          }
                      }
                      // if the roll number has not submitted.
                        cout<<"Assignment not submitted by Roll number: "<<s<<endl;
                  }
              }

};




int main() {
 
  Table t; // object instantiation.
  string roll_number, search_roll_no; // roll number for submitting assignment.
  //search_roll_no for search the particular roll number on table.

  int choice;

  
  while(1) {
      cout<<"\n------------------------STACK MENU------------------------\n";
      cout<<"|\t\t\t\t\t\t\t |\n|\t\t1. PUSH ASSIGNMENT                       |\n";
      cout<<"|\t\t2. POP ASSIGNMENT                        |\n";
      cout<<"|\t\t3. LAST SUBMITTED ASSIGNMENT             |\n";
      cout<<"|\t\t4. DISPLAY FIRST 10 ASSIGNMENT           |\n";
      cout<<"|\t\t5. SEARCH FOR SUBMISSION                 |\n";
      cout<<"|\t\t6. Exit                                  |\n";
      cout<<"|\t\t\t\t\t\t\t |\n|\t\t\t\t\tBy- MOHITBLAZE07 |\n----------------------------------------------------------"<<endl;

      cout<<"\nEnter your choice: "; // get choice from menu
        cin>>choice;
        
            switch(choice) {

                case 1: 
                        cout<<"\n Enter Roll number: ";
                        cin>>roll_number;
                        t.push(roll_number);  // invoke push() method from class Table
                        break;
                case 2: t.pop();  // invoke pop() method from class Table
                        break;

                        //LOW LEVEL SOLUTION
                case 3: t.get_top();  // invoke get_top() method from class Table
                        break;

                        //MIDDLE LEVEL SOLUTION
                case 4: t.display(); //invoke display() method from class Table
                        break; 

                        //HIGH LEVEL SOLUTION
                case 5: cout<<"Enter Roll number to check: "; //invoke search method from class Table
                        cin>>search_roll_no;
                        t.search(search_roll_no);
                        break;
                case 6: exit(0); // exit the loop
                        break;
                default: cout<<"Invalid choice!"<<endl; // for invalid choices.
                        break;
            }
        }

  return 0;
}