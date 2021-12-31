#include "topoController.h"

int topoController::findTopology(string topologyID) const {
    for(int i = 0, n = topologyList.size(); i < n; i++)
        if(topologyList[i]->getID() == topologyID)
            return i;

    cout << "Invalid Topology ID\n";
    return -1;
}

void topoController::choices() const{
    cout << "--------------------------------------------\n";
    cout << "1) Read Json file\n";
    cout << "2) Write Json file\n";
    cout << "3) Print Topologies\n";
    cout << "4) Delete Topology\n";
    cout << "5) Get Divces in Topology\n";
    cout << "6) Get Devices connected in a net list\n";
    cout << "7) Exit\n";
    cout << "--------------------------------------------\n";
}

bool topoController::validateInput(string choice) const{
    for(int i = 0; i < 7; i++)
        if(valid[i] == choice)
            return 1;
    return 0;
}

vector<topology *> topoController::getTopologies() const {return topologyList;}

void topoController::deleteTopology(string id) {
    int index = findTopology(id);
    if(index != -1) {
        auto it = topologyList.begin();
        advance(it, index);
        topologyList.erase(it);
        cout << "Succesfully Deleted\n";
        return;
    }
    cout << "Failde Deletion\n";
}

vector<component*> topoController::getDevices(string topID) const {
    int index = this->findTopology(topID);

    if(index != -1)
        return topologyList[index]->getComponents();

    vector<component*> empty;
    return empty;
}

vector<component*> topoController::getConnectedDevices(string topID, string netListNodeID) {

    int index = this->findTopology(topID);

    if(index != -1)
        return topologyList[index]->getConnectedComponents(netListNodeID);

    vector<component*> empty;
    return empty;
}


void topoController::writeTopology(string filename, string topologyID) {
    int index = this->findTopology(topologyID);

    if(index != -1)
        ioJson.writeToJson(*topologyList[index], filename);
}


topology* topoController::readTopology(string filename) {
    return ioJson.readJsonTopology(filename);
}

void topoController::insertTopology(topology *Topology) {
    topologyList.push_back(Topology);
}

void topoController::mainProgram() {
    string choice;
    string fileName;
    string topID;
    string nodeID;
    do {
        choices();
        cout << "Choice: ";
        getline(cin, choice);
        if(!validateInput(choice)){
            cout << "Invalid Choice, try again\n";
            continue;
        }

        if(choice == "1") {
            cout << "Enter input file (.json extension): ";
            getline(cin, fileName);
            topology* Topology = this->readTopology(fileName);

            if(!Topology)
                cout << "Failde to read a topology\n";


            else {
                cout << "Succesfully read\n";
                this->insertTopology(Topology);
            }
        }

        else if(choice == "2") {
            cout << "Enter output file (.json extension): ";
            getline(cin, fileName);
            cout << "Enter Topology ID: ";
            getline(cin, topID);
            this->writeTopology(fileName, topID);
        }

        else if(choice == "3") {

            vector<topology*> topologies = this->getTopologies();
            int count = topologies.size();
            cout << "Existed Topologies: " << count << "\n";

            for(int i = 0; i < count; i++)
                cout << "Topology ID: " << topologies[i]->getID() << "\n";
        }

        else if(choice == "4") {
            cout << "Enter Topology ID: ";
            getline(cin, topID);
            this->deleteTopology(topID);
        }

        else if(choice == "5") {
            cout << "Enter Topology ID: ";
            getline(cin, topID);
            vector<component*> components = this->getDevices(topID);
            if(components.size() > 0) {
                int count = components.size();
                cout << "Devices in given topology: " << count << '\n';
                for(auto com : components)
                    cout << "Device ID: " << com->getID() << '\n';
            }
        }

        else if (choice == "6") {
            cout << "Enter Topology ID: ";
            getline(cin, topID);
            cout << "Enter Node ID: ";
            getline(cin, nodeID);
            vector<component*> components = this->getConnectedDevices(topID, nodeID);
            if(components.size() > 0) {
                int count = components.size();
                cout << "Connected devices : " << count << '\n';
                for(auto com : components)
                    cout << "Device ID: " << com->getID() << '\n';
            }
        }

    } while (choice != "7");
    cout << "****************** Thank You ***************************\n";
}