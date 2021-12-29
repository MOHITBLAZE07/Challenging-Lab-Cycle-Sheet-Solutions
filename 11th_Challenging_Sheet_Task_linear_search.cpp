#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef struct Student{
string name;
int id;
Student(){}
Student(int sId, string sName){
name = sName;
id = sId;
}
}Student;
void LinearSearch(Student students[], int size, int id){
for(int i = 0; i < size; i++){
if(students[i].id == id){
cout << "Student Name: " << students[i].name << "\t" <<
"Id: " << students[i].id << endl;
return;
}
}
cout << "Student not found" << endl;
}
Student takeInput(){
int id;
string name;
cout << "Enter id: ";
cin >> id;
cout << "Enter first name only: ";
cin >> name;
return Student(id, name);
}
int askWhichStudentToSearch(){
int id;
cout << "Enter id of students that you want to search: ";
cin >> id;
return id;
}
void showMessage(){
cout << "Enter 1 to search" << endl;
cout << "Enter 2 to exit" << endl;
}
int main(){
Student s[100];

int n, choice;
cout << "Enter no. of students: ";
cin >> n;
for(int i = 0; i < n; i++){
s[i] = takeInput();
}
showMessage();
do {
cout << "Enter your choice: ";
cin >> choice;
if(choice == 1){
LinearSearch(s, n, askWhichStudentToSearch());
}
else if (choice ==2){
return 0;
}
else {
cout << "Invalid input" << endl;
}
}while(choice !=2);
return 0;
}