#include <iostream>
using namespace std;

#include "Parameters.h"
#include "ConfigFile.h"

void Parameters::collect(ConfigFile config)
{
    Material material(4,config);
	
    Geometry geometry(4, config);

    TestSetup testSetup(4, config);
	
    Control control(4,config);

	copy(material, geometry, testSetup, control);
	conditionToTemperature();
		
}

void Parameters::copy(Material material, Geometry geometry, TestSetup testSetup, Control control)
{

	outflowModelOn = control.outflowModelOn;
	lambda = control.lambda;
	analyticalSolutionMode = control.analyticalSolutionMode;
	numberOfSpeedValues = control.numberOfSpeedValues;
    aDotc0 = control.aDotc0;
	elementsInL = control.elementsInL;

	methodID = testSetup.methodID;
	fullScale = testSetup.fullScale;
	tempDegC = testSetup.tempDegC;
	p0bar = testSetup.p0bar;
	isBackfilled = testSetup.isBackfilled;
	backfillDepth = testSetup.backfillDepth;
	backfillDensity = testSetup.backfillDensity;
	solidInsidePipe = testSetup.solidInsidePipe;
	waterInsidePipe = testSetup.waterInsidePipe;

	pipeID = geometry.pipeID;
	diameter = geometry.diameter;
	sdr = geometry.sdr;
	notchDepth = geometry.notchDepth;
	diameterCreepRatio = geometry.diameterCreepRatio;
    h =  geometry.h;
	crackWidth = geometry.crackWidth;
	hOverR = geometry.hOverR;
	radius = geometry.radius;


	matID = material.matID;
	density = material.density;
	eDyn0degC = material.eDyn0degC;
	dEdyndT = material.dEdyndT;
	creepModulus = material.creepModulus;
	poisson = material.poisson;

}

void Parameters::conditionToTemperature()
{
	dynamicModulus = eDyn0degC + tempDegC * dEdyndT;
} 