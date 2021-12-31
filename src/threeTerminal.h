#include "component.h"
#ifndef TOPOAPI_THREETERMINAL_H
#define TOPOAPI_THREETERMINAL_H


class threeTerminal : public component{

public:
    threeTerminal(string id, map<string, string> netList, double min, double max, double def);
    string getSrc();
    string getDrain();
    string getGate();
    void setSrc(string src);
    void setGate(string gate);
    void setDrain(string drain);
};


#endif //TOPOAPI_THREETERMINAL_H
