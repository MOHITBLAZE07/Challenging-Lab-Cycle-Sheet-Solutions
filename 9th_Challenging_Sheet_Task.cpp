#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;


class Faculty {
private:
	string name;
	int id;
	string subject;

public:
	Faculty(){}

	Faculty(int id, string name, string subject){
		this->id = id;
		this->name = name;
		this->subject = subject;
	}

	int getId(){
		return id;
	}

	void print(){
		
		cout << "  |" << setw(13) << id << "|" <<
			setw(14) << name << "|" << 
			setw(12) << subject << "|" << endl;
			cout << "  |-------------|--------------|------------|" << endl;
	}
};



class FacultyList{
private:
	const static int MAX = 1000;
	Faculty faculties[MAX];
	int size;
	int countSwap = 0;


	Faculty findMax(Faculty facultyList[], int size){
		Faculty maxEle = facultyList[0];

		for (int i = 1; i < size; ++i){
			if((maxEle.getId() < facultyList[i].getId())){
				maxEle = facultyList[i];
			}
		}

		return maxEle;
	}

	int findDigits(Faculty faculty){
		if(faculty.getId() == 0) return 1;
		return floor(log10(faculty.getId())+1);
	}


public:
	FacultyList(){
		this->size = 0;
	}

	void addFaculty(Faculty faculty){
		faculties[size++] = faculty;
	}

	int getSwapCount(){
		return countSwap;
	}


	void radixSort(){

		Faculty maxE = findMax(faculties, size);
		int passes = findDigits(maxE);


		Faculty facultyBucket[10][10];
		int facultyBucketIdx[10];
		int div = 1;

		for (int i = 0; i < passes; ++i)
		{
			for (int j = 0; j < 10; ++j){
				facultyBucketIdx[j] = 0;
			}

			for(int k = 0; k < size; k++){
				++countSwap;
				int digit = (faculties[k].getId() / div) % 10;
				facultyBucket[digit][facultyBucketIdx[digit]] = faculties[k];
				facultyBucketIdx[digit] += 1;
			}

			
			int pos = 0;
			for(int l = 0; l < 10; l++){
				for(int m = 0; m < facultyBucketIdx[l]; m++){
					faculties[pos++] = facultyBucket[l][m];
				}
			}

			div = div*10;
				
		}


	}

	void print(){
		cout << "  |-------------|--------------|------------|" << endl;
		cout << "  | Faculty ID  | Faculty Name |   Subject  | " << endl;
		cout << "  |-------------|--------------|------------|" << endl;
		for (int i = 0; i < size; ++i)
		{
			faculties[i].print();
		}
	}
};


FacultyList initializeFacultyList(){
	FacultyList list;

	list.addFaculty(Faculty(121, "Chandan Kumar", "Maths"));
	list.addFaculty(Faculty(101, "Ravi Kumar", "Computer"));
	list.addFaculty(Faculty(701, "Aman Kumar", "Physics"));	
	list.addFaculty(Faculty(800, "Abhi Kumar", "Maths"));

	return list;
}



void showMenu(){
	cout << "Enter 1 to add new faculty" << endl;
	cout << "Enter 2 to show faculties" << endl;
	cout << "Enter 3 to show faculties sorted by id" << endl;
	cout << "Enter 4 to show swap count" << endl;
	cout << "Enter 5 to exit" << endl;

}

Faculty createFaculty(){
	int id;
	string name, subject;

	cout << "Enter id (Only Numbers): ";
	cin >> id;


	cin.ignore();
	cout << "Enter name: ";
	getline(cin, name);

	cout << "Enter subject: ";
	cin >> subject;

	return Faculty(id, name, subject);
}



int main(){

	showMenu();	
	FacultyList list = initializeFacultyList();

	int choice;

	do{
		cout << "Enter your choice: ";
		cin >> choice;

		switch(choice){
			case 1: {
				list.addFaculty(createFaculty());
				break;
			}

			case 2: {
				list.print();
				break;
			}

			case 3: {
				list.radixSort();
				list.print();
				break;
			}

			case 4: {
				cout << "Swap Count: " <<  list.getSwapCount() << endl;
			}

			case 5: {
				return 0;
			}
		}
	}while(choice != 5);


	return 0;
}


