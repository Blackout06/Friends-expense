/*
 * Person.hpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Charles
 */

#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <string>

//forward declaration
class Group;

using namespace std;

class Person {
public :
    Person();
    Person(const string& iName,const string& iPhone, float iExpenses);

    void setName(const string& iName);
    void setLink(Group* iLink);
    void setPhone(const string& iPhone);
    void setExpenses(float iExpenses);
    void setPayback(float iPayback);

    const string& getName();
    Group* getLink();
    const string& getPhone();
    float getExpenses() const;
    float getPayback();

    void operatePayback(const float iExpensesPerPerson);

    virtual ~Person();

private :
    string _name;
    string _phone;
    float _expenses;
    float _payback;
    Group* _link;
};

#endif /* PERSON_HPP_ */
