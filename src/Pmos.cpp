#include "Pmos.h"
Pmos::Pmos(string id, map<string, string> netList, double min, double max, double def) : threeTerminal(id, netList, min, max, def){
    setType();
}

void Pmos::setType() {type = "pmos";}
