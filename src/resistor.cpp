#include "resistor.h"


resistor::resistor(string id, map<string, string> netList, double min, double max, double def): twoTerminal(id, netList, min, max, def) {
    setType();
}

void resistor::setType() {this->type = "resistor";}