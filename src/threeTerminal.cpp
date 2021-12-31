#include "threeTerminal.h"
threeTerminal::threeTerminal(string id, map<string, string> netList, double min, double max, double def):component(id, netList, min, max, def) {

}

string threeTerminal::getSrc() {return netList["source"];}

string threeTerminal::getGate() {return netList["gate"];}

string threeTerminal::getDrain() {return netList["drain"];}

void threeTerminal::setSrc(string src) {netList["source"] = src;}

void threeTerminal::setDrain(string drain) {netList["drain"] = drain;}

void threeTerminal::setGate(string gate) {netList["gate"] = gate;}