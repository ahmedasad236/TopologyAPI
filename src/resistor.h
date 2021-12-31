#include "twoTerminal.h"
#ifndef TOPOAPI_RESISTOR_H
#define TOPOAPI_RESISTOR_H


class resistor : public twoTerminal{
public:
    resistor(string id, map<string, string> netList, double min, double max, double def);
    void setType();
};


#endif //TOPOAPI_RESISTOR_H
