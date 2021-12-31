
#include "component.h"
component::component(string id, map<string, string> netList, double min, double max, double def) {
    this->id = id;
    this->netList = netList;
    this->maxVal = max;
    this->minVal = min;
    this->defaultVal = def;
}

void component::setID(string id) {this->id = id;}
void component::setNetList(map<string, string> netList) {this->netList = netList;}
void component::setMin(double min) {this->minVal = min;}
void component::setMax(double max) {this->maxVal = max;}
void component::setDefault(double def) {this->defaultVal = def;}


string component::getID() const {return this->id;}
string component::getType() const {return this->type;}
map<string, string> component::getNetList() const {return this->netList;}
double component::getMin() const {return this->minVal;}
double component::getMax() const {return this->maxVal;}
double component::getDefault() const {return this->defaultVal;}

