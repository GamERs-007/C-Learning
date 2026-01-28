//
// Created by 15165 on 2026/1/28.
//

#ifndef _6_PANEL_H
#define _6_PANEL_H

#include <cstdlib>
using namespace std;


class Switch; //pre-declaration

class Panel {
private:
    Switch* switches; // store a number of Switch objects;
    int capacity;

protected:
    void assertId(int id); // mainly for usage by the Panel class itself as a utility;

public:
    Panel(int numSwitches);
    ~Panel();
    Panel(const Panel & other);

    void printSwitchID();

    void click(int id) ;

    bool getSwitchState(int id);

};

#endif //_6_PANEL_H