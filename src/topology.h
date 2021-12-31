#include "resistor.h"
#include "Pmos.h"
#include "Nmos.h"
#include "vector"
#ifndef TOPOAPI_TOPOLOGY_H
#define TOPOAPI_TOPOLOGY_H


class topology {
private:
    string id;
    vector<component*> components;
    bool connectedNetList(string netListNodeID, map<string, string> netList) const;
public:
    topology(string id);
    topology(string id, const vector<component *>& components);
    void setComponents(const vector<component *>& components);
    void setId(string id);
    string getID() const;
    vector<component*> getComponents() const;
    vector<component*> getConnectedComponents(string netListNodeID) const;
    ~topology();

};


#endif //TOPOAPI_TOPOLOGY_H
