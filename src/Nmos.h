#include "threeTerminal.h"
#ifndef TOPOAPI_NMOS_H
#define TOPOAPI_NMOS_H

class Nmos : public  threeTerminal{

public:
    Nmos(string id, map<string, string> netList, double min, double max, double def);
    void setType();
};


#endif //TOPOAPI_NMOS_H
