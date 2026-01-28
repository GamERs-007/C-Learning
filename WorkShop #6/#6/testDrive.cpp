#include "switch.h"
#include "panel.h"
#include <iostream>
using namespace std;
#include <string>

void monitor(){
	std::cout << Switch::objectCounter <<  std::endl;
}

void testSwitch(){

		Switch s1; // Default constructor

	    s1.setState(true); // parameter based constructor is invoked;
	    s1.setId(101);

	    Switch s2(true); // Parameterized constructor

	    Switch s3(s2); // Copy constructor
	    //Switch s3 = s2; // copy constructor;

	    std::cout << "s1 state: " << s1.getState() << ", id: " << s1.getId() << "\n";
	    std::cout << "s2 state: " << s2.getState() << ", id: " << s2.getId() << "\n";
	    std::cout << "s3 state: " << s3.getState() << ", id: " << s3.getId() << "\n";

	    string result = (s2.getId()==s3.getId())?"Pass!":"Fail!";
	    std::cout << result  << std::endl;

}


void testPointerOfSwitch(){
	Switch* sPoint = new Switch(true);
	sPoint->setId(100);
	std::cout << sPoint->getId()<<std::endl;

	const string result = (sPoint->getId()==100)?"Pass!":"Fail!";
    std::cout <<result  << std::endl;

	delete sPoint;
}

void testClone(){

		Switch oldSwitch;
		oldSwitch.setState(true);
		oldSwitch.setId(200);

   	    Switch firstSwitch = oldSwitch.clone();

   	    oldSwitch.setId(500);
   	    Switch secondSwitch(oldSwitch);

   	    Switch thirdSwitch = oldSwitch.clone(secondSwitch);

   	    //Question: this line has compilation error, how to fix it?
   	    //string result = ( *(thirdSwitch.id)== *(secondSwitch.id))?"Pass!":"Fail!";

   	    string result = (thirdSwitch.getId()== secondSwitch.getId())?"Pass!":"Fail!";
   	    std::cout <<result  << std::endl;

}

void testArray(){

	  Switch aotherArray[10];

	  for(int i=0;i<10;i++){
		  aotherArray[i].setState(true);
		  aotherArray[i].setId(i);
	  }

	  string result="Pass!";

	  for(Switch item:aotherArray){
	  	 if(item.getState()!=true){
	  		 result = "Fail!";
	  		 break;
	  	 }

	  }
	  std::cout <<result  << std::endl;

}

void testCascadingCall(){
	Switch switchOne;
	string result =
			(switchOne.setId(1000).setState(true).getId()==1000)?"Pass!":"Fail!";
	std::cout <<result  << std::endl;
}

void testStaticCounting(){
	Switch* switchArray[3];

	for(int k=0;k<3;k++){
		switchArray[k] = new Switch[10];
		std::cout << " [new] The loop shows switch counts : ";
		monitor();
	}

	for(int k=0;k<3;k++){
		delete[] switchArray[k];
		std::cout << " [delete] The loop shows switch counts : ";
		monitor();
	}

}

void testPanelClick(){

	Panel switchPannel(5); //all states are false
	int switchId = 100;  // to check the switch id valid range;
	switchPannel.click(switchId); // switch with id switchId is toggled to true;

	string result = (switchPannel.getSwitchState(switchId)==true)?"Pass!":"Fail!";
	std::cout <<result  << std::endl;

	switchPannel.click(switchId);  // switch with id switchId is toggled to false;
	result = (switchPannel.getSwitchState(switchId)==false)?"Pass!":"Fail!";
	std::cout <<result  << std::endl;
}

void testFriend(){
	Panel switchPannel(5); //all states are false
	switchPannel.printSwitchID();
}

int main() {
	std::cout << "----------------- testSwitch-----------------------"<<endl;
	testSwitch();

	std::cout << "----------------- testPointerofSwitch-----------------------"<<endl;
	testPointerOfSwitch();

	std::cout << "----------------- testClone-----------------------"<<endl;
	testClone();

	std::cout << "----------------- testArray-----------------------"<<endl;
	testArray();

	std::cout << "----------------- testCascadingCall-----------------------"<<endl;
	testCascadingCall();

	std::cout << "----------------- testStaticCounting-----------------------"<<endl;
	testStaticCounting();

	std::cout << "------------------testPanelClick -------------------------"<<endl;
	testPanelClick();

	std::cout << "------------------testFriend -------------------------"<<endl;
	testFriend();
    return 0;
}
