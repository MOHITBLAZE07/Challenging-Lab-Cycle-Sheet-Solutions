#include<iostream>
#include<string.h>
using namespace std;

//defining the Max size for the stack.
#define MAX 30

//global declaration stack container and the two top variables storing respective forward and backward values.
string forward_backward_stack[MAX];
int top_f = -1;
int top_b = MAX;

//push method for pushing the input url from user-> into the forward_backward_stack.
void push( string url ) {
  // overflow condition.
    if( top_f + 1 == top_b ) {
      cout<<"stack overflow!"<<endl;
    }
  //otherwise insert into stack.
    else {
      forward_backward_stack[++top_f] = url;
    }
}

// display method when backward button is pressed by user.
void display_url_backward_button() {

    string url;
  //if you are on the home page.
      if( top_f == -1 ) {
        cout<<"You're on homepage now, there's no other website window opened."<<endl;
      }
    // if you are on webpage other than the homepage
      else {
        // copy the url and store it in url variable and then decrement the top
        url = forward_backward_stack[top_f--];
        //then store the url into the forward stack using top_b. and decrement the top
        forward_backward_stack[--top_b] = url;
  //if you reach to home page then let user know that its the homepage
          if( top_f == -1 ) {
            cout<<"You're on homepage now, there's no other website window opened."<<endl;
          }
    // otherwise display the home page name to user after pressing the backward button.
          else {
              cout<<"After Pressing Back Button, you are now on: "<<forward_backward_stack[top_f]<<" url."<<endl;
          }
        
      }
}

//method to display webpage url when forward button is pressed.
void display_url_forward_button() {
  //check condition for initial, when stack is empty
  if( top_b == MAX && top_f == -1 ) {
    cout<<"You're on homepage now, there's no other website window opened."<<endl;
  }
  // if forward stack is empty means user is on the last webpage.
  else if( top_b == MAX ) {
    cout<<"You're on the last page, Front navigation not possible."<<endl;
  }
  //otherwise, insert the top of forward stack into the backward stack in same array using top_b. and increment it, so that top points to the previous url or MAX.
  else {
    push(forward_backward_stack[top_b++]);
    cout<<"After Pressing Forward Button, you are now on: "<<forward_backward_stack[top_f]<<" url."<<endl;
  }
  
}


int main() {
 
    string url_name;
    int choice;
    
      while( 1 ) {
        cout<<"\n------------------------BROWSER MENU----------------------\n";
      cout<<"|\t\t\t\t\t\t\t |\n|\t\t1. ENTER NEW WEBSITE's URL               |\n";
      cout<<"|\t\t2. PRESS BACKWARD BUTTON                 |\n";
      cout<<"|\t\t3. PRESS FORWARD BUTTON                  |\n";
      cout<<"|\t\t4. Exit                                  |\n";
      cout<<"|\t\t\t\t\t\t\t |\n|\t\t\t\t\tBy- MOHITBLAZE07 |\n----------------------------------------------------------"<<endl;
        cout<<"\nEnter your choice: ";
        cin>>choice;
          switch (choice) {
          case 1:
                  cout<<"\n Enter the Url: ";
                  cin>>url_name;
                  push(url_name);
                  break;

          case 2:
                  display_url_backward_button();
                  break;

          case 3:
                  display_url_forward_button();
                  break;

          case 4: exit(0);
                  break;
          
          default:
                  cout<<"\n Invalid Choice!"<<endl;
                  break;
          }
      }


  return 0;
}