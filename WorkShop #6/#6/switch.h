//
// Created by 15165 on 2026/1/28.
//

#ifndef _6_SWITCH_H
#define _6_SWITCH_H

#include "panel.h"

class Panel; //pre-declare

class Switch{

    friend void Panel::printSwitchID();
public:

    Switch();
    Switch(bool);
    Switch(const Switch&);
    ~Switch();

    //enable cascading
    //rather than return void
    //return the object itself
    Switch& setState(bool);
    Switch& setId(int);

    //void toggle(){ state = !state; };


    bool getState() const;
    int getId() const;

    Switch clone() const;
    Switch clone(const Switch&) const;

    static int objectCounter;

    //friend void Panel::printSwitchID();

private:
    bool state;
    int* id;

};


#endif //_6_SWITCH_H