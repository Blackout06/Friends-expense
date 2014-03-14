//============================================================================
// Name        : main.cpp
// Author      : Charles
// Version     : 1.2
// Copyright   : Your copyright notice
// Description : Application to manage friends expenses
//============================================================================

#include "Person.hpp"
#include "Group.hpp"

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    unsigned int aNb,bNb = 0;
    string name;

    /*
     *  Register the input
     */

    cout << "How many group are there?" << endl;
    cin >> bNb;

    vector<Group> Groups;


    for (unsigned int i=0; i < bNb; i++)
    {

    cout << "What is the Name of the group?" << i+1 << endl;
    cin >> name;

    cout << "How many people are you?" << endl;
    cin >> aNb;

    Group aGroup(aNb,name);


		for (unsigned int i=0; i < aNb; i++) {
			string nameP,phone;
			float expen;

			cout << "What is the name of person " << i+1 << " ?" << endl;
			cin >> nameP;

			cout << "What is the phone number of person " << i+1 << " ?" << endl;
			cin >> phone;

			cout << "What is the expenses of person " << i+1 << " ?" << endl;
			cin >> expen;


			Person aPerson(nameP,phone,expen);
			aGroup.push_back(aPerson);
			aGroup[i].setLink(&aGroup);
		}

		Groups.push_back(aGroup);
    }

    /*
     *  Prepare the output
     */

    for (vector<Group>::iterator it = Groups.begin() ; it != Groups.end(); ++it)
    {
			cout << endl;
			cout << "Group " << it->getName() << endl;
			cout << "Total expenses:\t\t" << it->totalExpenses() << endl;
			cout << "Expenses per person:\t" << it->expensesPerPerson() << endl;
			cout << endl;

			cout << "Name\t\t" << "Phone Number\t" << "Expenses\t"
				<< "Payback\t\t" << "Group" << endl;
			cout << "--------------------------------------------------------------------------"
			<< endl;

			Group tmpGroup = *it;

			for (size_t i=0; i < tmpGroup.size(); ++i) {
				// operate the payback first
				tmpGroup[i].operatePayback(tmpGroup.expensesPerPerson());
				// display the values
				cout << tmpGroup[i].getName() << "\t\t" << tmpGroup[i].getPhone()
					<< "\t\t" << tmpGroup[i].getExpenses() << "\t\t"
					<< tmpGroup[i].getPayback() << "\t\t" << tmpGroup[i].getLink()->getName() << endl;
			}
			cout << endl;

    }

    return 0;
}
