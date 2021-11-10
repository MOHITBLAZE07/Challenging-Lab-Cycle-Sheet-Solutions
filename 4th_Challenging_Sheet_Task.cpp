#include<iostream>
using namespace std;

//MAX is defined as 9
#define MAX 9

//stack of size 9
int stack[MAX];
//top1 initialized with value -1 (Facing Left Side)
int top1 = -1;
//top2 is initialized from MAX (Facing Right Side)
int top2 = MAX;
//m denotes the slot of every individual stacks
int m = MAX/3;
//top3 is initialized from Max - slot for each individual stack (Facing Right Side)
int top3 = MAX - m;

//push method accepting the stack number as argument
void push( int stack_number ) {
    int data;
    cout<<"Enter data: ";
    cin>>data; //taking the input data to push into respective stack number
    //if the stack operation is on 1st stack
    if( stack_number == 1 ) {
        //check for overflow condition
        if( top1 == m - 1 ) {
            cout<<"Stack 1 is FULL!"<<endl;
        }
        //if not overflowing, then just push the data into stack1
        else {
            stack[++top1] = data;
        }
    }
    //if the stack operation is on 2nd stack
    else if( stack_number == 2 ) {
        //check for overflow condition
        if( top2 == MAX-m ) {
            cout<<"Stack 2 is FULL!"<<endl;
        }
        //if not overflowing, then just push the data into stack2
        else {
            stack[--top2] = data;
        }
    }
    //if the stack operation is on 3rd stack
    else if( stack_number == 3 ) {
        //check for overflow condition
        if( top3 == m ) {
            cout<<"Stack 3 is FULL!"<<endl;
        }
        //if not overflowing, then just push the data into stack3
        else {
            stack[--top3] = data;
        }
    }
}

void pop( int stack_number ) {
    int data;
    //if the stack operation is on 1st stack
    if( stack_number == 1 ) {
        if( top1 == -1 ) {
            cout<<"Stack1 is Empty!"<<endl;
        }
        else {
            data = stack[top1];
            top1--;
            cout<<"Popped Item is "<<data<<endl;
        }
    }
    //if the stack operation is on 2nd stack
    else if( stack_number == 2 ) {
        if( top2 == MAX ) {
            cout<<"Stack2 is Empty!"<<endl;
        }
        else {
            data = stack[top2];
            top2--;
            cout<<"Popped Item is "<<data<<endl;
        }
    }
    //if the stack operation is on 3rd stack
    else if( stack_number == 3 ) {
        if( top3 == MAX - m ) {
            cout<<"Stack3 is Empty!"<<endl;
        }
        else {
            data = stack[top3];
            top3--;
            cout<<"Popped Item is "<<data<<endl;
        }
    }
}

void isEmpty( int stack_number ) {
    //if the stack operation is on 1st stack
    if( stack_number == 1 ) {
        //check for empty condition
        if( top1 == -1 ) {
            cout<<"Stack1 is Empty!"<<endl;
        }
        else {
            cout<<"Stack1 is not Empty!"<<endl;
        }
    }
    //if the stack operation is on 2nd stack
    else if( stack_number == 2 ) {
        //check for empty condition
        if( top2 == MAX ) {
            cout<<"Stack2 is Empty!"<<endl;
        }
        else {
            cout<<"Stack2 is not Empty!"<<endl;
        }
    }
    //if the stack operation is on 3rd stack
    else if( stack_number == 3 ) {
        //check for empty condition
        if( top3 == MAX - m ) {
            cout<<"Stack3 is Empty!"<<endl;
        }
        else {
            cout<<"Stack3 is not Empty!"<<endl;
        }
    }
}

void isFull( int stack_number ) {
    //if the stack operation is on 1st stack
    if( stack_number == 1 ) {
        //check for full condition
        if( top1 == m - 1 ) {
            cout<<"Stack 1 is FULL!"<<endl;
        }
        else {
            cout<<"Stack1 is not FULL!"<<endl;
        }
    }
    //if the stack operation is on 2nd stack
    else if( stack_number == 2 ) {
        //check for full condition
        if( top2 == MAX-m ) {
            cout<<"Stack 2 is FULL!"<<endl;
        }
        else {
            cout<<"Stack2 is not FULL!"<<endl;
        }
    }
    //if the stack operation is on 3rd stack
    else if( stack_number == 3 ) {
        //check for full condition
        if( top3 == m ) {
            cout<<"Stack 3 is FULL!"<<endl;
        }
        else {
            cout<<"Stack3 is not FULL!"<<endl;
        }
    }
}

void display( int stack_number ) {
    //if the stack operation is on 1st stack
    if( stack_number == 1 ) {
        //check for empty condition
        if( top1 == -1 ) {
            cout<<"Stack1 is Empty!"<<endl;
        }
        //other wise just print the contents in the stack1
        else {
            for( int i = top1; i>=0; i-- ) {
                cout<<stack[i]<<endl;
            }
        }
    }
    //if the stack operation is on 2nd stack
    else if( stack_number == 2 ) {
        //check for empty condition
        if( top2 == MAX ) {
            cout<<"Stack2 is Empty!"<<endl;
        }
        //other wise just print the contents in the stack2
        else {
            for( int i = top2; i<= MAX-1; i++ ) {
                cout<<stack[i]<<endl;
            }
        }
    }
    //if the stack operation is on 3rd stack
    else if( stack_number == 3 ) {
        //check for empty condition
        if( top3 == MAX - m ) {
            cout<<"Stack3 is Empty!"<<endl;
        }
        //other wise just print the contents in the stack3
        else {
            for( int i = top3; i<=MAX-m-1; i++ ) {
                cout<<stack[i]<<endl;
            }
        }
    }
}




int main() {
    int stack_number;

 int choice;
 
      while( 1 ) {
          cout<<"\n------------------------3 Stack MENU----------------------\n";
          cout<<"|\t\t\t\t\t\t\t |\n|\t\t1. PUSH                                  |\n";
          cout<<"|\t\t2. POP                                   |\n";
          cout<<"|\t\t3. IsEmpty                               |\n";
          cout<<"|\t\t4. IsFull                                |\n";
          cout<<"|\t\t5. DISPLAY                               |\n";
          cout<<"|\t\t6. EXIT                                  |\n";
          cout<<"|\t\t\t\t\t\t\t |\n|\t\t\t\t\tBy- MOHITBLAZE07 |\n----------------------------------------------------------"<<endl;
        
        cout<<"\nEnter your choice: ";
        cin>>choice;

          switch (choice) {
          case 1:
                  cout<<"\n Enter the stack number: ";
                  cin>>stack_number;
                  if( stack_number <= 0 || stack_number > 3 ) {
                      cout<<"Please Enter stack number 1, 2 or 3 only!"<<endl;
                      break;
                  }
                  push(stack_number);
                  break;

          case 2:
                  cout<<"\n Enter the stack number: ";
                  cin>>stack_number;
                  if( stack_number <= 0 || stack_number > 3 ) {
                      cout<<"Please Enter stack number 1, 2 or 3 only!"<<endl;
                      break;
                  }
                  pop(stack_number);
                  break;

          case 3:
                  cout<<"\n Enter the stack number: ";
                  cin>>stack_number;
                  if( stack_number <= 0 || stack_number > 3 ) {
                      cout<<"Please Enter stack number 1, 2 or 3 only!"<<endl;
                      break;
                  }
                  isEmpty(stack_number);
                  break;

          case 4: 
                  cout<<"\n Enter the stack number: ";
                  cin>>stack_number;
                  if( stack_number <= 0 || stack_number > 3 ) {
                      cout<<"Please Enter stack number 1, 2 or 3 only!"<<endl;
                      break;
                  }
                  isFull(stack_number);
                  break;

          case 5: 
                  cout<<"\n Enter the stack number: ";
                  cin>>stack_number;
                  if( stack_number <= 0 || stack_number > 3 ) {
                      cout<<"Please Enter stack number 1, 2 or 3 only!"<<endl;
                      break;
                  }
                  display(stack_number);
                  break;

          case 6: 
                  exit(0);
                  break;
          
          default:
                  cout<<"\n Invalid Choice!"<<endl;
                  break;
          }
      }
 
  return 0;
}