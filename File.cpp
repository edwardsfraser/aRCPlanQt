#include "File.h"
#include <iostream>
#include <sys/stat.h>

File::File()
{
   initialise();
}

void File::initialise()
{
    aDotc0 = 0.0;
    densityratio = 0.0;

    dStarMinus1 = 0.0;
    dStarMinus2 = 0.0;
    baffleLeakageArea = 0.0;
    fdArraySize = 0;
    decompression = 0.0;

    zetaClosure = 0.0;
    printOpeningProfile = 0;

    l = 0;
    maxIterations = 0;
    hOverR = 0.0;
    lambdaLast = 0.0;
    zetaBackfilledLast = 0.0;
    notConverged = 0;
    iterations = 0;
    noCrackOpening = 0;
    wStar2 = 0.0;
    wStarMax = 0.0;
    wStar2dash = 0.0;
    wStar2dash2 = 0.0;
    integral_wStar2 = 0.0;
    zetaBackfillEject = 0.0;
    p1p0r = 0.0;
    dynamicShearModulus = 0.0;
    nodeResolution = 0.0;
    v0 = 0.0;
    factor = 0.0;
    p1bar = 0.0;
    vStarRes = 0.0;
    nodeAtClosure = 0;
    aDotOverCL = 0.0;
    aDotCLfactor = 0.0;
    aDotCLfactor_backfilled = 0.0;
    lambdaPow4 = 0;
    sdrMinus1 = 0.0;
    sdrMinus2 = 0.0;
    zetaBackfilled = 0.0;
    outflowLength = 0.0;
    v00 = 0.0;
    error = 0.0;
    availableInternalVolume = 0.0;
    vStarDashBackfillEject = 0.0;

    m[0] = 0.0;
    m[1] = 0.0;
    alpha[0] = 0.0;
    alpha[1] = 0.0;
}

void File::correct()
{

    found = directory.find("aRCPlanQt.app");

    if (found != string::npos)
    {
         directory.resize(found);
    }

}

int File::check()
{
    struct stat st;

    if(stat(directory.c_str(), &st) == 0)
    {

        if (st.st_mode & S_IFDIR != 0)
        {
            subfolder = directory + "Results/";

            if(stat(subfolder.c_str(), &st) == 0)
            {
                if (st.st_mode &S_IFDIR != 0)
                {
                    checkstate = 0;
                }
            }
            else
            {
                mkdir(subfolder.c_str(), 0777);
                return checkstate = 1;
            }

            subfolder = directory + "Profiles/";

            if(stat(subfolder.c_str(), &st) == 0)
            {
                if (st.st_mode &S_IFDIR != 0)
                {
                    checkstate = 0;
                }
            }
            else
            {
                mkdir(subfolder.c_str(), 0777);
                return checkstate = 2;
            }

            subfolder = directory + "Log/";

            if(stat(subfolder.c_str(), &st) == 0)
            {
                if (st.st_mode &S_IFDIR != 0)
                {
                    checkstate = 0;
                }
            }
            else
            {
                mkdir(subfolder.c_str(), 0777);
                return checkstate = 3;
            }
        }
    }
    else
    {
        return checkstate = 4;
    }

    return checkstate;

}

int File::loadcheck(string name)
{

    struct stat st;

    if(stat((directory + name).c_str(), &st) == 0)
    {
        return 0;
    }

    return 1;
}

int File::casehandler(Parameters temp, string filename)
{
    if(filename.find(".txt",0)<100)
    {
        writepartxt(temp, filename);
        return 0;
    }
    else
    {
        return 1;
    }
}

void File::writeresults()
{
    extern File file;
    extern Solution solution;

    filename = "Results.csv";

    out.open((file.directory + "Results/" + filename).c_str(), std::fstream::in | std::fstream::out | std::fstream::trunc);

    out << "Normalised Crack Speed,Decomp. factor,Speed factor,Support factor,Outflow length,Flaring,Irwin Corten force,Crack driving force,Normalised total,\n";

    for(i=1; i<solution.soln+1;i++)
    {

        out << solution.aDotc0[i] << "," << solution.decompression[i] << "," << solution.alpha[i] << ","
                << solution.m[i] << "," << solution.outflowLength[i] << ", ," << solution.g0[i] << ","
                << solution.gG0[i] << "," << solution.gTotal[i] << "\n";

    }

    out.close();

}

void File::writepartxt(Parameters temp, string filename)
{

    out.open((directory + filename).c_str());

    writelinetxt("Input Data", out,1);

    writelinetxt("Material Data", out, 1);

    writelinetxt("matID = ", temp.matID, out, 0);
    writelinetxt("density = ", temp.density, out, 0);
    writelinetxt("eDyn0degC = ", temp.eDyn0degC, out, 0);
    writelinetxt("dEdyndT = ", temp.dEdyndT, out, 0);
    writelinetxt("creepModulus = ", temp.creepModulus, out, 0);
    writelinetxt("poisson = ", temp.poisson, out, 1);

    writelinetxt("Pipe Data", out,1);

    writelinetxt("pipeID = ", temp.pipeID, out, 0);
    writelinetxt("diameter = ", temp.diameter, out, 0);
    writelinetxt("sdr = ", temp.sdr, out, 0);
    writelinetxt("notchDepth = ", temp.notchDepth, out, 0);
    writelinetxt("diameterCreepRatio = ", temp.diameterCreepRatio, out, 1);

    writelinetxt("Test Setup Data", out, 1);

    writelinetxt("fullScale = ", temp.fullScale, out, 0);
    writelinetxt("tempDegC = ", temp.tempDegC, out, 0);
    writelinetxt("p0bar = ", temp.p0bar, out, 0);
    writelinetxt("isBackfilled = ", temp.isBackfilled, out, 0);
    writelinetxt("backfillDepth = ", temp.backfillDepth, out, 0);
    writelinetxt("backfillDensity = ", temp.backfillDensity, out, 0);
    writelinetxt("solidInsidePipe = ", temp.solidInsidePipe, out, 0);
    writelinetxt("waterInsidePipe = ", temp.waterInsidePipe, out, 1);

    writelinetxt("Program Control Data", out, 1);

    writelinetxt("outflowModelOn = ", temp.outflowModelOn, out, 0);
    writelinetxt("lambda = ", temp.lambda, out, 0);
    writelinetxt("solutionmethod = ", temp.solutionmethod, out, 0);
    writelinetxt("numberOfSpeedValues = ", temp.rangenumber, out, 0);
    writelinetxt("elementsInL = ", temp.elementsinl, out, 0);

    out.close();

}

void File::writeparcsv(Parameters temp, string filename)
{

    out.open((directory + filename).c_str());

    writelinestringcsv("Input Data", out);
    writelinestringcsv("\n", out);

    writelinestringcsv("Material Data", out);
    writelinestringcsv("\n", out);

    writelinestringcsv("matID", temp.matID, out);
    writelinedoublecsv("density", temp.density, out);
    writelinedoublecsv("eDyn0degC", temp.eDyn0degC, out);
    writelinedoublecsv("dEdyndT", temp.dEdyndT, out);
    writelinedoublecsv("creepModulus", temp.creepModulus, out);
    writelinedoublecsv("poisson", temp.poisson, out);
    writelinestringcsv("\n", out);

    writelinestringcsv("Pipe Data", out);
    writelinestringcsv("\n", out);

    writelinestringcsv("pipeID", temp.pipeID, out);
    writelinedoublecsv("diameter", temp.diameter, out);
    writelinedoublecsv("sdr", temp.sdr, out);
    writelinedoublecsv("notchDepth", temp.notchDepth, out);
    writelinedoublecsv("diameterCreepRatio", temp.diameterCreepRatio, out);

    writelinestringcsv("\n", out);
    writelinestringcsv("Test Setup Data", out);
    writelinestringcsv("\n", out);

    writelinedoublecsv("fullScale", temp.fullScale, out);
    writelinedoublecsv("tempDegC", temp.tempDegC, out);
    writelinedoublecsv("p0bar", temp.p0bar, out);
    writelinedoublecsv("isBackfilled", temp.isBackfilled, out);
    writelinedoublecsv("backfillDepth", temp.backfillDepth, out);
    writelinedoublecsv("backfillDensity", temp.backfillDensity, out);
    writelinedoublecsv("solidInsidePipe", temp.solidInsidePipe, out);
    writelinedoublecsv("waterInsidePipe", temp.waterInsidePipe, out);

    writelinestringcsv("\n", out);
    writelinestringcsv("Program Control Data", out);
    writelinestringcsv("\n", out);

    writelinedoublecsv("outflowModelOn", temp.outflowModelOn, out);
    writelinedoublecsv("lambda", temp.lambda, out);
    writelinedoublecsv("solutionmethod", temp.solutionmethod, out);
    writelinedoublecsv("numberOfSpeedValues", temp.rangenumber, out);
    writelinedoublecsv("elementsInL", temp.elementsinl, out);

    out.close();
}

void File::writelinetxt(string title, double value, ofstream &out, int format)
{
    out << "\t" << title << value << endl;
    if(format == 1)
    {
        out << endl;
    }
}

void File::writelinetxt(string title, string value, ofstream &out, int format)
{
    out << "\t" << title << value << endl;
    if(format == 1)
    {
        out << endl;
    }
}

void File::writelinetxt(string title, ofstream &out, int format)
{
    out << title << endl;
    if(format == 1)
    {
        out << endl;
    }
}

void File::writelinedoublecsv(string title, double value, ofstream &out)
{
    out << title << "," << value << "\n";
}

void File::writelinestringcsv(string title, string value, ofstream &out)
{
     out << title << "," << value << "\n";
}

void File::writelinestringcsv(string title, ofstream &out)
{

    out << title << "," << "\n";

}

void File::writeheaders(string temp)
{
    filename = temp;
    out.open((directory + filename).c_str(), std::fstream::in | std::fstream::out | std::fstream::app);

    writelinestringcsv("\n", out);

    out << "aDotc0" << "," << "Irwin Corten Force" << "," << "diameterRes0" << "," << "residualCrackClosure" << ","
        << "densityratio" << "," << "zetaclosure" << "," << "nodeAtClosure" << "," << "outflowLength" << ","
        << "p1bar" << "," << "v0" << "," << "vStarRes" << "," << "aDotCLfactor" << "," << "aDotcClfactor_backfilled"
        << "," << "maxIterations" << "," << "iterations" << "," << "m[0]" << "," << "m[1]" << ","
        << "alpha[0]" << "," << "alpha[1]" << "," << "error" << "," << "notConverged" << "," << "arraySize";

    writelinestringcsv("\n", out);
    out.close();
}

void File::logprepare(Parameters temp)
{
    initialise();
    filename = "Log/Log.csv";
    writeparcsv(temp, filename);
    writeheaders(filename);
}

void File::writelogline(int newline)
{
    out.open((directory + filename).c_str(), std::fstream::in | std::fstream::out | std::fstream::app);

    if(newline)
    {
    out << " \n";
    }

    out << aDotc0 << ","
        << g0 << ","
        << diameterRes0 << "," << residualCrackClosure << ","
        << densityratio << ","
        << zetaClosure << "," << nodeAtClosure << "," << outflowLength << ","
        << p1bar << "," << v0 << ","
        << vStarRes << "," << aDotCLfactor << "," << aDotCLfactor_backfilled << ","
        << maxIterations << "," << iterations << "," << m[0] << "," << m[1] << ","
        << alpha[0] << "," << alpha[1] << "," << error << "," << notConverged << "\n";

    out.close();
}

void File::collect(FracMech fracmech)
{
    g0 = fracmech.g0;
    writelogline(0);
}

void File::collect(Creep creep)
{
    diameterRes0 = creep.diameterRes0;
    residualCrackClosure = creep.residualCrackClosure;
    writelogline(0);
}

void File::collect(Backfill backfill)
{
    densityratio =  backfill.densityratio;
    writelogline(0);
}

void File::collect(BeamModel *beamModel, int newline)
{
    zetaClosure = beamModel ->zetaClosure;
    nodeAtClosure = beamModel->nodeAtClosure;
    outflowLength = beamModel -> outflowLength;
    p1bar = beamModel -> p1bar;
    v0 = beamModel ->v0;
    vStarRes = beamModel -> vStarRes;
    aDotCLfactor = beamModel -> aDotCLfactor;
    aDotCLfactor_backfilled = beamModel -> aDotCLfactor_backfilled;
    maxIterations = beamModel -> maxIterations;
    iterations = beamModel -> iterations;
    m[0] = beamModel -> m[0];
    m[1] = beamModel -> m[1];
    alpha[0] = beamModel -> alpha[0];
    alpha[1] = beamModel -> alpha[1];
    error = beamModel -> error;
    notConverged = beamModel -> notConverged;
    writelogline(newline);
}



