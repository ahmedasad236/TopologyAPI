#include "threeTerminal.h"
#ifndef TOPOAPI_PMOS_H
#define TOPOAPI_PMOS_H


class Pmos : public threeTerminal{

public:
    Pmos(string id, map<string, string> netList, double min, double max, double def);
    void setType();
};


#endif //TOPOAPI_PMOS_H
