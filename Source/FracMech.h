//     aRCPLan
//     Copyright (c) [2014] [Fraser Edwards][Dr Patrick Leevers]
//     aRCPlan may be freely distributed under the MIT license.
//     For the underlying model, see http://www.sciencedirect.com/science/article/pii/S0013794412003530

#ifndef _FRACHMECH_H
#define _FRACHMECH_H

#include "BeamModel.h"
#include "Parameters.h"

class FracMech
{
public:

	double g0;
    double gs1;
    double gue;
    double gsb;
    double gkb;
    double gtotal;
    double gg0;
    double adotc0;

    //Null constructor
	FracMech();	

    //Constructor
	FracMech(const Parameters parameters);

    //Calculates driving force using strain energy consideration
	void extensionForce(const BeamModel beamModel, const Parameters parameters, const Creep creep);
};

#endif
