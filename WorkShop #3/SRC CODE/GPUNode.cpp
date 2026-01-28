/*
 * GPUNode.cpp
 *
 *  Created on: Jan 14, 2026
 *      Author: umroot
 */

#include "GPUNode.h"
#include <iostream>
#include <string>



int GPUNode::instanceCount = 0; //initialized once and only once;

//member initialization list
GPUNode::GPUNode()
:model(0),
speed(0),
node(-1),
throughput(-1),
color("")
{
	++instanceCount;
	std::cout << "default constructor invoked" <<std::endl;
}

GPUNode::GPUNode(double m, long s, short n, long t, std::string col)
:model(m),
speed(s),
node(n),
throughput(t),
color(col)
{
	++instanceCount;
	std::cout << "parameter-based constructor invoked" <<std::endl;
}

GPUNode::GPUNode(const GPUNode& other)
:model(other.model),
speed(other.speed),
node(other.node),
throughput(other.throughput),
color(other.color)
{
	++instanceCount;
	std::cout << "copy constructor invoked" <<std::endl;
}

GPUNode::~GPUNode()
{
	--instanceCount;
	std::cout << "destructor invoked" <<std::endl;
}



//setter and getter
void GPUNode::setModel(double val){
	model = val;
}

double GPUNode::getModel() const{
	return model;
}

//setter and getter
void GPUNode::setThroughput(long t){
	throughput = t;
}

long GPUNode::getThroughput() const{
	return throughput;
}



//test
double testGPUNode(){ //outside the scope of class definition, can only access to public segments
	GPUNode item;  //item is an object instance; //calling construction by the compiler;
	item.setModel(37.5);
	//item.model = 5; model is private and not accessible outside the class GPUNode;
	std::cout << item.getModel() << std::endl;

	GPUNode item2;
	item2.setModel(40);

	GPUNode cloneGPU(item);

	return cloneGPU.getModel();

}

void testStaticCount(){
	std::cout << "Before the for loop " << GPUNode::instanceCount << std::endl;
	for(int i=0; i<3; i++){
		GPUNode item;
		item.setModel(30+i);
		std::cout << GPUNode::instanceCount << std::endl;
	}
	std::cout << "After the for loop " << GPUNode::instanceCount << std::endl;

}

void testPointer(){

	std::cout<< "before the array creation: " << GPUNode::instanceCount <<std::endl;
	GPUNode* ptr = new GPUNode[3]; //creating an array of 3 elements;
	std::cout<< "after the array creation: " << GPUNode::instanceCount <<std::endl;

	ptr[0].setModel(100);

	GPUNode item0(ptr[0]);
	std::string result = (item0.getModel()==100) ? "pass":"fail";
	std::cout << "test copy constructor " << result << std::endl;

	GPUNode item1(*(ptr+1));

//  GPUNode item1(ptr[1]);

	delete[] ptr;

//	GPUNode item1;
//	item1.setModel(35);
//	GPUNode item2;
//	item2.setModel(50);
//
//
//	ptr[1] = item1;
//	ptr[2] = item2;
}

void testLoopThroughArray() {
	std::cout<< "before the array creation: " << GPUNode::instanceCount << std::endl;
	// 1. create an array by pointer (size 10)
	int size = 10;
	GPUNode* arr = new GPUNode[size];
	std::cout << "After array creation: " << GPUNode::instanceCount << std::endl;

	// 2. change all GPUNode throughputs
	for(int i = 0; i < size; i++){
		arr[i].setThroughput(100 + i * 10);
	}

	// 3. display all GPUNode throughputs
	std::cout << "Displaying throughputs:" << std::endl;
	for(int i = 0; i < size; i++){
		std::cout << "GPUNode " << i << " throughput = " << arr[i].getThroughput() << std::endl;
	}
	// 4. delete array
	delete[] arr;
	std::cout << "After deleting array: " << GPUNode::instanceCount << std::endl;
}
