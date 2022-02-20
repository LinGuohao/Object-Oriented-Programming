#ifndef SIMULATION_H
#define SIMULATION_H
#include <vector>
#include <iostream>
#include <cstdlib>
#include "gaslayer.h"
#include "atmosphericvariable.h"
#include <fstream>
class Simulation
{
    public:
        enum FILE{FILEERROR};
        enum INPUT{WRONG_INPUT};

        Simulation(std::string &fname);

        int searchUpperGasLayers(GasLayer *newlyTransformed, int startPosition);
        void simulate();

        void first(){this->simulate();}
        std::vector<GasLayer*> current(){return _gasLayers;}
        void next(){this->simulate();}
        bool end(){return _end==true;}

        virtual ~Simulation();

    protected:

    private:
        bool _end;
        std::vector<GasLayer*> _gasLayers;
        std::vector<AtmosphericVariable*> _variables;
};

#endif // SIMULATION_H
