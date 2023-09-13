#include <iostream>
#include <fstream>
#include "PhoneBook.h"
using namespace std;

PhoneBook::PhoneBook() {
	firstName = nullptr;
	lastName = nullptr;
	middleName = nullptr;
	homePhone = nullptr;
	workPhone = nullptr;
}

PhoneBook::PhoneBook(const char* fn, const char* ln, const char* mn, const char* hp, const char* wp) {
	firstName = new char[strlen(fn) + 1];
	strcpy_s(firstName, strlen(fn) + 1, fn);

	lastName = new char[strlen(ln) + 1];
	strcpy_s(lastName, strlen(ln) + 1, ln);

	middleName = new char[strlen(mn) + 1];
	strcpy_s(middleName, strlen(mn) + 1, mn);

	homePhone = new char[strlen(hp) + 1];
	strcpy_s(homePhone, strlen(hp) + 1, hp);

	workPhone = new char[strlen(wp) + 1];
	strcpy_s(workPhone, strlen(wp) + 1, wp);
}

PhoneBook::~PhoneBook() {
	delete[] lastName;
	delete[] firstName;
	delete[] middleName;
	delete[] homePhone;
	delete[] workPhone;
}

void PhoneBook::Input() {
	char buff[100];

	cout << "Enter first name: ";
	cin >> buff;
	if (firstName != nullptr) {
		delete[] firstName;
	}
	firstName = new char[strlen(buff) + 1];
	strcpy_s(firstName, strlen(buff) + 1, buff);

	cout << "Enter last name: ";
	cin >> buff;
	if (lastName != nullptr) {
		delete[] lastName;
	}
	lastName = new char[strlen(buff) + 1];
	strcpy_s(lastName, strlen(buff) + 1, buff);

	cout << "Enter middle name: ";
	cin >> buff;
	if (middleName != nullptr) {
		delete[] middleName;
	}
	middleName = new char[strlen(buff) + 1];
	strcpy_s(middleName, strlen(buff) + 1, buff);

	cout << "Enter home phone: ";
	cin >> buff;
	if (homePhone != nullptr) {
		delete[] homePhone;
	}
	homePhone = new char[strlen(buff) + 1];
	strcpy_s(homePhone, strlen(buff) + 1, buff);

	cout << "Enter work phone: ";
	cin >> buff;
	if (workPhone != nullptr) {
		delete[] workPhone;
	}
	workPhone = new char[strlen(buff) + 1];
	strcpy_s(workPhone, strlen(buff) + 1, buff);
}

void PhoneBook::Print() {
	cout << "Last Name: " << lastName << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Middle Name: " << middleName << endl;
	cout << "Home Phone: " << homePhone << endl;
	cout << "Work Phone: " << workPhone << endl;
}

int PhoneBook::ResizeArray(PhoneBook*& array, int oldSize) {
	int newSize = oldSize + 1;
	PhoneBook* newArray = new PhoneBook[newSize];

	for (int i = 0; i < oldSize; i++) {
		newArray[i] = array[i];
	}

	array = newArray;

	return newSize;
}

int PhoneBook::DeleteSubscriber(PhoneBook*& array, int oldSize, int numberDelete) {
	int newSize = oldSize - 1;
	PhoneBook* newArray = new PhoneBook[newSize];

	for (int i = 0, j = 0; i < oldSize; i++) {
		if (i != numberDelete) {
			newArray[j] = array[i];
			j++;
		}
	}

	array = newArray;

	return newSize;
}

int PhoneBook::SearchByFullName(PhoneBook* array, int size, const char* fn, const char* ln, const char* mn) {
	if (!array) {
		return -2;
	}

	for (int i = 0; i < size; i++) {
		if (strcmp(array[i].lastName, ln) == 0 && strcmp(array[i].firstName, fn) == 0 && strcmp(array[i].middleName, mn) == 0) {
			return i;
		}
	}

	return -1;
}

void PhoneBook::SaveToFile(PhoneBook* array, int size) {
	if (!array) {
		return;
	}

	ofstream text("subscribersInfo.txt");

	for (int i = 0; i < size; i++) {
		text << "First Name: " << array[i].firstName << ";" << endl;
		text << "Last Name: " << array[i].lastName << ";" << endl;
		text << "Middle Name: " << array[i].middleName << ";" << endl;
		text << "Home Phone: " << array[i].homePhone << ";" << endl;
		text << "Work Phone: " << array[i].workPhone << ";" << endl << endl;
	}
}

void PhoneBook::LoadFromFile() {
	int n = 256;
	char* buffer = new char[n] {};
	ifstream binary1("Employee.txt", ios::binary);

	binary1.read(buffer, n);
	cout << buffer << endl;

	delete[] buffer;

	binary1.close();
}

char* PhoneBook::GetFirstName() {
	return this->firstName;
}

char* PhoneBook::GetLastName() {
	return this->lastName;
}

char* PhoneBook::GetMiddleName() {
	return this->middleName;
}

char* PhoneBook::GetHomePhone() {
	return this->homePhone;
}

char* PhoneBook::GetWorkPhone() {
	return this->workPhone;
}

void PhoneBook::SetFirstName(const char* fn) {
	if (firstName != nullptr) {
		delete[] firstName;
	}

	firstName = new char[strlen(fn) + 1];
	strcpy_s(firstName, strlen(fn) + 1, fn);
}

void PhoneBook::SetLastName(const char* ln) {
	if (lastName != nullptr) {
		delete[] lastName;
	}

	lastName = new char[strlen(ln) + 1];
	strcpy_s(lastName, strlen(ln) + 1, ln);
}

void PhoneBook::SetMiddleName(const char* mn) {
	if (middleName != nullptr) {
		delete[] middleName;
	}

	middleName = new char[strlen(mn) + 1];
	strcpy_s(middleName, strlen(mn) + 1, mn);
}

void PhoneBook::SetHomePhone(const char* hp) {
	if (homePhone != nullptr) {
		delete[] homePhone;
	}

	homePhone = new char[strlen(hp) + 1];
	strcpy_s(homePhone, strlen(hp) + 1, hp);
}

void PhoneBook::SetWorkPhone(const char* wp)
{
	if (workPhone != nullptr) {
		delete[] workPhone;
	}

	workPhone = new char[strlen(wp) + 1];
	strcpy_s(workPhone, strlen(wp) + 1, wp);
}
