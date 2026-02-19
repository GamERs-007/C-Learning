/*
 * school.h
 *
 *  Created on: Feb. 4, 2025
 *      Author: umroot
 */

#ifndef SCHOOL_H_
#define SCHOOL_H_

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Student{
public:
	Student(string ls, string fs, int num):fname(fs),lname(ls),id(num){
		cout<< "Student object is constructed!"<<endl;
	}
	Student(const Student& other):fname(other.fname),lname(other.lname),id(other.id){
		cout<< "Student object is copy-constructed!"<<endl;
	}

	~Student(){ cout<< "Student object is destructed!"<<endl;}

	void display(){
		cout<<"Student info: fname "<< fname
			<< " lname "<< lname << " id " << id <<endl;
	}
	string toString()const{
		ostringstream out;
		out << "fname " << fname << "lname " << lname << " id " <<id << "\n";
		return out.str();
	}

//private:
protected:
	std::string fname;
	std::string lname;
	int id;
};

class ugStudent:public Student{
public:
	ugStudent(string ls, string fs, int num, float a, float m, float f):Student(ls, fs, num),assignment(a),midterm(m),finals(f){
		cout<< "ugStudent ojbect is constructed!"<<endl;
	}

	ugStudent(const ugStudent& other): Student(other)/*Undergraduate student is a student*/, assignment(other.assignment),midterm(other.midterm), finals(other.finals){
		cout<< "ugStudent ojbect is copy-constructed!"<<endl;
	}

	~ugStudent(){cout<< "ugStudent ojbect is destructed!"<<endl;}


	void display()  {

		Student::display(); //invoking from the base class version of display();

		//cout<<"Student info: fname "<< fname
		//			<< " lname "<< lname << " id " << id <<endl;

		cout<<"ugStudent info: assignment "<< assignment
		<< " midterm "<< midterm << " finals " << finals <<endl;
	}
	string toString() const{
		stringstream out;
		out << Student::toString() << " assginment " << assignment << " midterm " << midterm << " finals " << finals;
		return out.str();
	}
private:
	float assignment;
	float midterm;
	float finals;
};


#endif /* SCHOOL_H_ */
