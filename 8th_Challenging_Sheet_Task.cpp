#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <thread>

using namespace std;


class Date{
private:
	int day;
	int month;
	int year;

public:
	Date(){}

	Date(int day, int month, int year){
		this->day = day;
		this->month = month;
		this->year = year;
	}

	string getStringDate(){
		string date = to_string(day) + "-" + to_string(month) + "-" + to_string(year);
		return date;
	}

	int getDay(){
		return day;
	}

	int getMonth(){
		return month;
	}

	int getYear(){
		return year;
	}

	bool compareTo(Date date){
		if(date.getYear() != year)
			return year > date.getYear();
		else if (date.getMonth() != month)
			return month > date.getMonth();
		else if(date.getDay() != day)
			return day > date.getDay();
		else 
			return false;
	}
};


class Passport{
private:
	int id;
	string name;
	Date lastRenewedDate;

public:

	Passport(){
	}


	Passport(int id, string name){
		this->id = id;
		this->name = name;
	}

	Passport(int id, string name, Date lastRenewedDate){
		this->id = id;
		this->name = name;
		this->lastRenewedDate = lastRenewedDate;
	}

	int getId(){
		return id;
	}

	string getName(){
		return name;
	}

	Date getRenewedDate(){
		return lastRenewedDate;
	}
};



class PassportList {
private:
	const static int MAX = 1000;
	Passport passports[MAX];
	int size;

	void swap(Passport &passport1, Passport &passport2){
		Passport temp = passport1;
		passport1 = passport2;
		passport2 = temp;
	}


public:
	PassportList(){
		this->size = 0;
	}

	void addPassport(Passport passport){
		passports[size++] = passport;
	}

	void sortById(){
		for(int i = 0; i < size; i++){
			int minIdx = i;
			for(int j = i+1; j < size; j++){
				if(passports[j].getId() < passports[minIdx].getId()){
					minIdx = j;
				}
			}

			swap(passports[minIdx], passports[i]);
		}
	}

	void sortByDate(){
		Passport key;
		int j;

		for(int i = 1; i < size; i++){
			key = passports[i];
			j = i-1;


			while(j >= 0 && passports[j].getRenewedDate().compareTo(key.getRenewedDate())){
				passports[j+1] = passports[j];
				j = j - 1;
			}

			passports[j+1] = key;

		}
	}

	void print(){
		cout << "  |Passport Id|Applicant Name|Renewed Date|" << endl;
		cout << "  |-----------|--------------|------------|" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(150));

		for (int i = 0; i < size; ++i){

			cout << "  |" << setw(11) <<  passports[i].getId() << "|" <<
			setw(14) << passports[i].getName() << "|" << 
			setw(12) << passports[i].getRenewedDate().getStringDate() << "|" << endl;
			cout << "  |-----------|--------------|------------|" << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
	}

};

void showMenu(){
	cout << "  =============== Air India Passport System ===============" << endl;
	cout << "  Enter 1 to create passport" << endl;
	cout << "  Enter 2 to show passport list sorted by Passport Id" << endl;
	cout << "  Enter 3 to show passport list sorted by Date" << endl;
	cout << "  Enter 4 to exit" << endl;
	cout << "  =============== XXXXXXXXXXXXXXXXXXXXXXXXX ================" << endl;
}

Date getDateObject(string date){
	istringstream ss(date);
	string token;

	int arr[3];
	int i = 0;

	while(getline(ss, token, '/')) {
    	arr[i++] = stoi(token);
	}

	return Date(arr[0], arr[1], arr[2]);
}

Passport createPassport(){
	int id;
	string date;
	string name;

	cout << "  Enter passport id: ";
	cin >> id;

	cin.ignore();
	cout << "  Enter your name: ";
	getline(cin, name);

	cout << "  Enter renewal date (DD/MM/YYYY): ";
	cin >> date;

	Date renewalDate = getDateObject(date);

	return Passport(id, name, renewalDate);
}

PassportList initializePassportList(){
	Passport p1(2, "Chandan",  Date(4, 7, 2021));
	std::this_thread::sleep_for(std::chrono::milliseconds(150));
	Passport p2(3, "Rahul", Date(30, 12, 2021));
	std::this_thread::sleep_for(std::chrono::milliseconds(150));
	Passport p3(4, "Aman", Date(1, 11, 2010));
	std::this_thread::sleep_for(std::chrono::milliseconds(150));
	Passport p4(1, "Ravi",  Date(2, 12, 2015));
	std::this_thread::sleep_for(std::chrono::milliseconds(150));

	PassportList list;
	
	list.addPassport(p1);
	list.addPassport(p2);
	list.addPassport(p3);
	list.addPassport(p4);

	return list;
}

int main(){

	showMenu();

	PassportList passportList = initializePassportList();

	int choice;

	do {
			cout << "  Enter your choice: ";
			cin >> choice;

		switch(choice){
			case 1: {
					Passport passport = createPassport();
					passportList.addPassport(passport);
					break;	
				}

			case 2: {
				passportList.sortById();
				passportList.print();
				break;
			}

			case 3: {
				passportList.sortByDate();
				passportList.print();
				break;
			}

			case 4: {
				cout << "  Good bye" << endl;
				return 0;
			}

			default: cout << "  Wrong choice" << endl;

		} 

	} while(choice != 4);



	return 0;
}

