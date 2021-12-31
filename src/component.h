#include <iostream>
#include <string>
#include <map>
#ifndef TOPOAPI_COMPONENT_H
#define TOPOAPI_COMPONENT_H
using namespace std;

class component {

protected:
    string id;
    map<string, string> netList;
    double minVal;
    double maxVal;
    double defaultVal;
    string type;

public:
    component(string id, map<string, string> netList, double min, double max, double def);

    virtual void setID(string id);
    virtual void setNetList(map<string, string> netList);
    virtual void setMin(double min);
    virtual void setMax(double max);
    virtual void setDefault(double def);
    virtual void setType() = 0;

    virtual  string getID() const;
    virtual string getType() const;
    map<string, string> getNetList() const;
    virtual double getMin() const;
    virtual double getMax() const;
    virtual double getDefault() const;
};


#endif //TOPOAPI_COMPONENT_H
