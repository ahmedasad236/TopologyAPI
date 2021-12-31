#include "topology.h"

//utility function to search for connected netLists
bool topology::connectedNetList(string netListNodeID, map<string, string> netList) const{
    for(auto node : netList)
        if(node.second == netListNodeID)
            return 1;

    return 0;
}

topology::topology(string id) {this->id = id;}
topology::topology(string id, const vector<component *>& components) {
    this->id = id;
    setComponents(components);
}

void topology::setId(string id) {this->id = id;}

void topology::setComponents(const vector<component *>& components) {
    // Copy the components to this topology components, deep copy is used
    string id;
    map<string , string> netList;
    int min, max, def;

    for(int i = 0, n = components.size(); i < n; i++) {
        id = components[i]->getID();
        netList = components[i]->getNetList();
        min = components[i]->getMin();
        max = components[i]->getMax();
        def = components[i]->getDefault();
        if(dynamic_cast<resistor*>(components[i]))
            this->components.push_back(new resistor(id, netList, min, max, def));




        else if(dynamic_cast<Pmos*>(components[i]))
            this->components.push_back(new Pmos(id, netList, min, max, def));
        else
            this->components.push_back(new Nmos(id, netList, min, max, def));
    }
}

string topology::getID() const {return this->id;}

vector<component*>topology::getComponents() const {return this->components;}

vector<component*> topology::getConnectedComponents(string netListNodeID) const {
    vector<component*> result;
    for(auto component : components) {
        map<string, string> netList = component->getNetList();
        if(this->connectedNetList(netListNodeID, netList))
            result.push_back(component);
    }
    return result;
}

topology::~topology() {
    for(auto &comp : this->components)
    {
        delete comp;
        comp = nullptr;
    }

    this->components.clear();
}
