#ifndef TOPOAPI_JSONTOPOLOGYREADER_H
#define TOPOAPI_JSONTOPOLOGYREADER_H
#include "json.hpp"
#include "topology.h"
#include <fstream>
#include <iomanip>

using json = nlohmann::json;

class JsonIO {

private:
    topology* createTopology(json jsonObject);
    component* createComponent(const vector<json>& components, int index);
    vector<component*> createListOfComponents(json jsonObject);
    json writeComponent(const component* comp);
    json writeComponents(const vector<component*>& components);
    json writeTopology(const topology& topo);

public:
    topology* readJsonTopology(string fileName);
    void writeToJson(const topology& topo, string fileName);
};


#endif //TOPOAPI_JSONTOPOLOGYREADER_H
