#include "topology.h"
#include "JsonIO.h"
#ifndef TOPOAPI_TOPOCONTROLLER_H
#define TOPOAPI_TOPOCONTROLLER_H


class topoController {
private:
    vector<topology*> topologyList;
    JsonIO ioJson;
    const string valid[7] = {"1", "2", "3", "4", "5", "6", "7"};
    int findTopology(string topologyID) const;
    void choices() const;
    bool validateInput(string choice) const;
public:
    void writeTopology(string filename, string topologyID);
    topology* readTopology(string filename);
    vector<topology*> getTopologies() const;
    void deleteTopology(string id);
    void insertTopology(topology* Topology);
    vector<component*> getDevices(string topID) const;
    vector<component*> getConnectedDevices(string topID, string netListNodeID);
    void mainProgram();
};

#endif //TOPOAPI_TOPOCONTROLLER_H
