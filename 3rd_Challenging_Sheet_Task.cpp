#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//defining the max size for stacks.
#define MAX 20

using namespace std;
//global declaration
int e_stack[MAX];   // expression stack.
char stack[MAX];    // operator stack
int top, e_top=-1;  // top and e_top for operator and expression stack respectively

//method for insertion into the operator stack. 
void push( char ch ) {
    if( top >=MAX ) {
        cout<<"Stack Overflow."<<endl;
    }
    else {
        stack[++top] = ch;
    }
}
//method to pop from operator stack.
char pop() {
    char ch;
        if( top == -1 ) {
            cout<<"Stack Underflow"<<endl;
            getchar();
            exit(1);
        }
        else {
            ch = stack[top];
            top = top - 1;
            return(ch);
        }
}

// method to push into the expression stack.
void e_push( int item ) {
    if( e_top >=MAX ) {
        cout<<"Stack Overflow."<<endl;
    }
    else {
        e_stack[++e_top] = item;
    }
}
//method to pop from expression stack.
int e_pop() {
    int item;
        if( e_top == -1 ) {
            cout<<"Stack Underflow"<<endl;
            getchar();
            exit(1);
        }
        else {
            item = e_stack[e_top];
            e_top = e_top - 1;
            return(item);
        }
}
//method to check whether the character is operator or not.
int is_operator( char ch ) {
    if( ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}
//method to check for precedence.
int precedence( char ch ) {
    if( ch == '^' ) {
        return(3);
    }
    else if ( ch == '*' || ch == '/' ) {
        return(2);
    }
    else if ( ch == '+' || ch == '-' ) {
        return(1);
    }
    else {
        return(0);
    }
}

//method to convert infix expression to postfix expression.
void infix_to_postfix( char infix_exp[], char postfix_exp[] ) {
    int i = 0, j = 0;
    top = -1;
    char ch, x;  
    
    push('(');
    strcat( infix_exp, ")" );
    
    ch = infix_exp[i];
    
        while( ch != '\0' ) {
            if( ch == '(' ) {
                push(ch);
            }
            else if( isdigit(ch) || isalpha(ch) ) {
                postfix_exp[j] = ch;
                j++;    
            }
            else if( is_operator(ch) == 1 ) {
                x = pop();

                while( is_operator(x) == 1 && precedence(x) >= precedence(ch) ) {
                    postfix_exp[j] = x;
                    j++;
                    x = pop();
                }
                push(x);
                push(ch); 
            }
            else if( ch == ')' ) {
                x = pop();
                while( x != '(' ) {
                    postfix_exp[j] = x;
                    j++;
                    x = pop();
                }
            }
            else {
                cout<<"Invalid Infix Expression!"<<endl;
                getchar();
                exit(1);
            }
                i++;
                ch = infix_exp[i];

        }
        if( top > 0 ) {
            cout<<"Invalid Infix Expression!"<<endl;
                getchar();
                exit(1);
        }
        postfix_exp[j] = '\0';

}

//method to convert infix expression to prefix expression
void infix_to_prefix( char infix_exp[], char prefix_exp[] ) {

    int i = 0, j = 0;
    top = -1;
    char ch, x;  
    
    
    strrev(infix_exp);
    push(')');
    strcat( infix_exp, "(" );
    ch = infix_exp[i];
    
        while( ch != '\0' ) {
            if( ch == ')' ) {
                push(ch);
            }
            else if( isdigit(ch) || isalpha(ch) ) {
                prefix_exp[j] = ch;
                j++;    
            }
            else if( is_operator(ch) == 1 ) {
                x = pop();

                while( is_operator(x) == 1 && precedence(x) > precedence(ch) ) {
                    prefix_exp[j] = x;
                    j++;
                    x = pop();
                }
                push(x);
                push(ch); 
            }
            else if( ch == '(' ) {
                x = pop();
                while( x != ')' ) {
                    prefix_exp[j] = x;
                    j++;
                    x = pop();
                }
            }
            else {
                cout<<"Invalid Infix Expression!"<<endl;
                getchar();
                exit(1);
            }
                i++;
                ch = infix_exp[i];

        }
        if( top > 0 ) {
            cout<<"Invalid Infix Expression!"<<endl;
                getchar();
                exit(1);
        }
        prefix_exp[j] = '\0';
}
//method to evaluate postfix expression.
void eval_postfix( char postfix_expr[] ) {
    e_top = -1;
    char ch;
    int A, B, val;

        for( int i = 0; postfix_expr[i] != ')'; i++ ) {
            ch = postfix_expr[i];
                if( isdigit(ch) ) {
                    e_push(ch - '0');
                }
                else if( ch == '+' || ch == '-' || ch == '*' || ch == '/' ) {
                    A = e_pop();
                    B = e_pop();

                    switch(ch) {
                        case '*': 
                                    val = B*A;
                                    break;
                        case '/': 
                                    val = B/A;
                                    break;
                        
                        case '+': 
                                    val = B+A;
                                    break;
                        
                        case '-': 
                                    val = B-A;
                                    break;
                    }
                    e_push(val);
                }
        }
        cout<<"Result of expression after evaluation is: "<<e_pop()<<"\n\n"<<endl;

}
//method to evaluate prefix expression.
void eval_prefix( char prefix_exp[] ) {
    int A,B,val;
    char ch;  
            
        for( int i = strlen(prefix_exp)-1; i>=0; i-- ) {
           
            ch = prefix_exp[i];

            if( isdigit(ch) ) {
               e_push(ch - '0');
            }
            else if( ch == '+' || ch == '-' || ch == '*' || ch == '/' ) {
                    A = e_pop();
                    B = e_pop();

                    switch(prefix_exp[i]) {
                        case '*': 
                                    val = B*A;
                                    break;
                        case '/': 
                                    val = B/A;
                                    break;
                        
                        case '+': 
                                    val = B+A;
                                    break;
                        
                        case '-': 
                                    val = B-A;
                                    break;
                    }
                    e_push(val);

            }
        }

        cout<<"Result of expression after evaluation is: "<<e_pop()<<"\n\n"<<endl;
}


int main() {
 
 char infix[MAX], postfix[MAX], prefix[MAX]; // strings for storing infix, postfix, prefix expressions.
 
    int choice;

    while(1) {
        cout<<"\n---------------------APPLICATIONS OF STACK----------------\n";
                cout<<"|\t\t\t\t\t\t\t |\n|\t\t1.Infix to PostFix Conversion.           |\n";
                cout<<"|\t\t2.Infix to PreFix Conversion.            |\n";
                cout<<"|\t\t3.Evaluation of Postfix Expression.      |\n";
                cout<<"|\t\t4.Evaluation of PreFix Expression.       |\n";
                cout<<"|\t\t5. Exit                                  |\n";
                cout<<"|\t\t\t\t\t\t\t |\n|\t\t\t\t\tBy- MOHITBLAZE07 |\n----------------------------------------------------------"<<endl;

        cout<<"Enter you choice: "<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
                cout<<"Enter the expression: ";
                cin>>infix;
                infix_to_postfix(infix,postfix);
                cout<<"Equivalent postfix expression is: "<<postfix<<"\n\n"<<endl;
                break;
        case 2:
                cout<<"Enter the expression: ";
                cin>>infix;
                infix_to_prefix(infix, prefix);
                cout<<"Equivalent prefix expression is: "<<strrev(prefix)<<"\n\n"<<endl;
                break;

        case 3:
                cout<<"Enter the PostFix Expression: ";
                cin>>postfix;
                eval_postfix(postfix);
                break;

        case 4: 
                cout<<"Enter the PostFix Expression: ";
                cin>>prefix;
                eval_prefix(prefix);
                break;
        case 5:
            exit(0);
                break;
        
        default:
                cout<<"Invalid Choice!"<<endl;
                break;
        }
    }
  return 0;
}