#include "component.h"
#ifndef TOPOAPI_TWOTERMINAL_H
#define TOPOAPI_TWOTERMINAL_H

class twoTerminal : public component{
public:
    twoTerminal(string id, map<string, string> netList, double min, double max, double def);
    string getT1();
    string getT2();
    void setT1(string t1);
    void setT2(string t2);
};
#endif //TOPOAPI_TWOTERMINAL_H
