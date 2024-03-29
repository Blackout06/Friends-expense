/*
 * Group.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Charles
 */

#include "Group.hpp"


Group::Group() {

}


Group::Group(int iNbPerson, const string& iNameg) :
		_name(iNameg),
		_nbPerson(iNbPerson)
{

}

void Group::setName(const string& iNameg){
	_name = iNameg;
}

const string& Group::getName(){
	return _name;
}


float Group::totalExpenses() const {
    float aTotal = 0;
    for (size_t i=0; i < this->size(); i++) {
        aTotal += this->at(i).getExpenses();
    }
    return aTotal;
}

float Group::expensesPerPerson() const {
    float aExpense = this->totalExpenses() / this->size();
    return aExpense;
}


Group::~Group() {

}
