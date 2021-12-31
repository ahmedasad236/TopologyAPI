#include "JsonIO.h"

topology* JsonIO::readJsonTopology(string fileName) {

    try {
        if(fileName.find(".json") == string::npos)
            throw "invalid file name";

        ifstream file;
        file.open(fileName, fstream::in);
        if(!file.is_open())
            throw "File not opened\n";

        json jsonObject = json::parse(file);
        if(jsonObject.empty())
            return nullptr;

        return this->createTopology(jsonObject);

    } catch(string err) {
        cout << "Error: " << err << "\n";
        return nullptr;
    }

}

component* JsonIO::createComponent(const vector<json>& components, int index) {
    component* comp = nullptr;
    double min, max, def;
    string type = components[index]["type"];
    string id = components[index]["id"];

    if(type == "resistor") {
        min = components[index]["resistance"]["min"];
        max = components[index]["resistance"]["max"];
        def = components[index]["resistance"]["default"];
        comp = new resistor(id, components[index]["netlist"], min, max, def);
    }

    else if(type == "nmos") {
        min = components[index]["m(l)"]["min"];
        max = components[index]["m(l)"]["max"];
        def = components[index]["m(l)"]["default"];
        comp = new Nmos(id, components[index]["netlist"], min, max, def);
    }

    // other devices should be handled here (pmos, capacitor, inductor) based on the format of the json file
    return comp;
}

vector<component*> JsonIO::createListOfComponents(json jsonObject) {
    vector<component*> components;
    for(int i = 0, n = jsonObject["components"].size(); i < n; i++)
        components.push_back(this->createComponent(jsonObject["components"], i));

    return components;
}

topology* JsonIO::createTopology(json jsonObject) {
    string id = jsonObject["id"];
    vector<component*> components = createListOfComponents(jsonObject);
    return new topology(id, components);
}

json JsonIO::writeComponent(const component *comp) {
    json jsonFile;

    string devValue;
    string type = comp->getType();
    string id = comp->getID();

    if(type == "resistor") devValue = "resistance";
    else if(type == "nmos") devValue = "m(l)";
    // other cases will be handled here


    json values = {{"default", comp->getDefault()}, {"min", comp->getMin()}, {"max", comp->getMax()}};
    jsonFile = {{"type", type}, {"id", id}, {devValue, values}, {"netlist", comp->getNetList()}};
    return jsonFile;
}

json JsonIO::writeComponents(const vector<component *> &components) {
    json jsonFile;
    vector<json> jsonComponents;
    for(auto comp : components)
        jsonComponents.push_back(this->writeComponent(comp));

    jsonFile = {"components", jsonComponents};
    return jsonFile;
}

json JsonIO::writeTopology(const topology &topo) {
    json jsonFile;
    jsonFile = {{"id", topo.getID()}, this->writeComponents(topo.getComponents())};
    return jsonFile;
}

void JsonIO::writeToJson(const topology &topo, string fileName) {
    ofstream file(fileName);
    if(!file.is_open()) {
        cout << "Error: opening the file failed\n";
        return;
    }

    json jsonFile = this->writeTopology(topo);
    file << setw(4) << jsonFile << endl;
    cout << "Successfully converted to JSON\n";
}