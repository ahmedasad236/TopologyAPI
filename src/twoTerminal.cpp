#include "twoTerminal.h"
twoTerminal::twoTerminal(string id, map<string, string> netList, double min, double max, double def):component(id, netList, min, max, def) {

}

string twoTerminal::getT1() {return netList["t1"];}
string twoTerminal::getT2() {return netList["t2"];}
void twoTerminal::setT1(string t1) {netList["t1"] = t1;}
void twoTerminal::setT2(string t2) {netList["t2"] = t2;}
