/*
 * Group.hpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Charles
 */

#ifndef GROUP_HPP_
#define GROUP_HPP_

#include "Person.hpp"

#include <vector>
#include <string>

using namespace std;

class Group : public vector<Person> {
public :
	Group();
	Group(int iNbPerson,const string& iNameg);

	void setName(const string& iNameg);

	const string&  getName();

	float totalExpenses() const;
	float expensesPerPerson() const;

    virtual ~Group();

private :
    string _name;
    int _nbPerson;

};

#endif /* GROUP_HPP_ */
