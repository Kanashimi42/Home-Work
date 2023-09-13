#include "PhoneBook.h"

#include <iostream>
using namespace std;

int main() {

	int numOfSubscribers = 0;
	int numOfDeletions = 0;
	int userChoice = 0;
	int searchKey = 0;
	int minMenuItem = 1, maxMenuItem = 7;

	bool flag = false;

	char inputBuffer[100];

	char* firstName;
	char* lastName;
	char* middleName;

	PhoneBook* contactList = nullptr;

	cout << "Menu: " << endl;
	cout << "1. Add Subscribers" << endl;
	cout << "2. Add Subscriber" << endl;
	cout << "3. Search for a Subscriber by Full Name" << endl;
	cout << "4. Show All Subscribers" << endl;
	cout << "5. Save Subscribers to File" << endl;
	cout << "6. Load Subscribers from File" << endl;
	cout << "7. Delete Subscriber" << endl;
	cout << "0. Exit" << endl;

	do {
		cout << "Input: ";
		cin >> userChoice;

		if (userChoice == 0) {
			cout << "Goodbye!" << endl;
			break;
		}
		else if (userChoice < minMenuItem || userChoice > maxMenuItem) {
			cout << "You entered an invalid menu item!" << endl << endl;
		}
		else {
			if (userChoice == 1) {
				cout << "Enter the number of subscribers: ";
				cin >> numOfSubscribers;

				contactList = new PhoneBook[numOfSubscribers];

				for (int i = 0; i < numOfSubscribers; i++) {
					contactList[i].Input();
					cout << endl;
				}

				flag = true;
			}
			else if (userChoice == 2) {
				numOfSubscribers = contactList->ResizeArray(contactList, numOfSubscribers);
				for (int i = numOfSubscribers - 1; i < numOfSubscribers; i++) {
					contactList[i].Input();
					cout << endl;
				}

				flag = true;
			}

			if (!flag)
				cout << "Select 1 or 2 first!" << endl << endl;
			else {
				if (userChoice == 3) {
					cout << "Search by Full Name: " << endl;
					cout << "Enter last name: ";
					cin >> inputBuffer;
					lastName = new char[strlen(inputBuffer) + 1];
					strcpy_s(lastName, strlen(inputBuffer) + 1, inputBuffer);

					cout << "Enter first name: ";
					cin >> inputBuffer;
					firstName = new char[strlen(inputBuffer) + 1];
					strcpy_s(firstName, strlen(inputBuffer) + 1, inputBuffer);

					cout << "Enter middle name: ";
					cin >> inputBuffer;
					middleName = new char[strlen(inputBuffer) + 1];
					strcpy_s(middleName, strlen(inputBuffer) + 1, inputBuffer);

					searchKey = contactList->SearchByFullName(contactList, numOfSubscribers, firstName, lastName, middleName);

					cout << "KEY: " << searchKey << endl;

					if (searchKey == -1)
						cout << "Key not found!" << endl;
					else
						contactList[searchKey].Print();
				}

				else if (userChoice == 4) {
					if (numOfSubscribers == 0) {
						cout << "No subscribers to display!" << endl << endl;
					}
					else {
						for (int i = 0; i < numOfSubscribers; i++) {
							contactList[i].Print();
							cout << endl;
						}
					}
				}
				else if (userChoice == 5) {
					contactList->SaveToFile(contactList, numOfSubscribers);
					cout << "Data saved to file" << endl << endl;
				}
				else if (userChoice == 6) {
					contactList->LoadFromFile();
				}
				else if (userChoice == 7) {
					cout << "Number of subscribers: " << numOfSubscribers << endl;

					do {
						cout << "Enter the subscriber to delete: ";
						cin >> numOfDeletions;

						if (numOfDeletions > numOfSubscribers || numOfDeletions <= 0)
							cout << "You entered an invalid range!" << endl << endl;
					} while (numOfDeletions > numOfSubscribers || numOfDeletions <= 0);
					numOfDeletions--;

					numOfSubscribers = contactList->DeleteSubscriber(contactList, numOfSubscribers, numOfDeletions);
					cout << "User deleted" << endl << endl;
				}
			}
		}
	} while (userChoice != 0 || userChoice < minMenuItem || userChoice > maxMenuItem);

	return 0;
}
