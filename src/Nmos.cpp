#include "Nmos.h"
Nmos::Nmos(string id, map<string, string> netList, double min, double max, double def) : threeTerminal(id, netList, min, max, def){
    setType();
}

void Nmos::setType() {type = "nmos";}
