/*
 * GPUNode.h
 *
 *  Created on: Jan 14, 2026
 *      Author: umroot
 */

#ifndef GPUNODE_H_
#define GPUNODE_H_


#include <string>
#include <iostream>

class GPUNode{
public:

	//constructors;
	GPUNode(); //default constructor;
	GPUNode(double, long, short, long, std::string); //parameter based constructor;
	GPUNode(const GPUNode&); //copy constructor; create an object by an existing object;
	~GPUNode(); //destructor has no overriding form with only one form; placeholder when the lifecycle of an object comes to the end;

	void setModel(double val);  //access functions to data attributes or data members;
	double getModel() const;    //getter /setter

	void setThroughput(long t);
	long getThroughput() const;

	static int instanceCount; // declaration of shared across all the instance,it's just declaration, not initialization, dont occupy space;

private:  //begin with the data
	double model;
	long speed;
	short node;
	long throughput;
	std::string color;
	//position pending;
};


double testGPUNode();
void testStaticCount();
void testPointer();
void testLoopThroughArray();


/*
 * create an array by pointer for the size at least 10;
 * change all the GPUNode throughputs;
 * and display all the GPUNode throughputs;
 * display the staticCount of number of GPUInstance;
 */


#endif /* GPUNODE_H_ */
