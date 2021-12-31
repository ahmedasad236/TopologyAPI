cmake_minimum_required(VERSION 3.20)
project(TopologyAPI)

set(CMAKE_CXX_STANDARD 14)

add_executable(TopologyAPI main.cpp component.cpp component.h JsonIO.cpp JsonIO.h Nmos.cpp Nmos.h Pmos.cpp Pmos.h resistor.cpp resistor.h threeTerminal.cpp threeTerminal.h topoController.cpp topoController.h topology.cpp topology.h twoTerminal.cpp twoTerminal.h)
