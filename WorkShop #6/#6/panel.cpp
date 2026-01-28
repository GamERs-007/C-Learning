//
// Created by 15165 on 2026/1/28.
//

#include "panel.h"
#include "switch.h"
#include <iostream>
#include <span>
using namespace std;

void Panel::assertId(int id){
    if(id>=100+capacity or id<100){
        std::cerr << "switch id "<< id <<" is out of the range!"<<endl;
        exit(EXIT_FAILURE);
    }
}


// Switch& Switch::setState(bool)


Panel::Panel(int numSwitches):capacity(numSwitches), switches(new Switch[capacity]) {

    //capacity = numSwitches;
    //switches = new Switch[capacity];

    for(int i=0;i<capacity;i++){
        switches[i].setState(false).setId(100+i);
    }
}

Panel::Panel(const Panel& other):capacity(other.capacity), switches(new Switch[capacity]){
    for(int i=0;i<capacity;i++){
        switches[i] = other.switches[i]; //copy the objects one by one;
    }
}

Panel::~Panel(){
    delete[] switches;
}


// void Panel::printSwitchID(){
//     //apply span() to refactor to range based for loop
//
//     // for (Switch& item :span(Switch, capacity)) {
//     //     cout << *(item.id) << endl;
//     // }
//
//     for(int i=0;i<capacity;i++){
//         std::cout<< "Switch Id: " << *(switches[i].id) <<std::endl;
//
//     }
//
// }

void Panel::printSwitchID() {
    std::span<Switch> switchSpan(switches, capacity);

    for (Switch& item : switchSpan) {
        std::cout << "Switch Id: " << *(item.id) << std::endl;
    }
}

void Panel::click(int id) {
    assertId(id);  // asserting failure will terminate the program;
    for(int i=0;i<capacity;i++){
        if(switches[i].getId()==id){
            switches[i].setState(!switches[i].getState());
            return;
        }
    }
}

bool Panel::getSwitchState(int id){
    assertId(id);
    for(int i=0;i<capacity;i++){
        if(switches[i].getId()==id){
            return switches[i].getState();
        }
    }
    return false;
}
