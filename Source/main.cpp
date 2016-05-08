//     aRCPLan
//     Copyright (c) [2014] [Fraser Edwards][Dr Patrick Leevers]
//     aRCPlan may be freely distributed under the MIT license.
//     For the underlying model, see http://www.sciencedirect.com/science/article/pii/S0013794412003530

//     Main function
//     Sets up GUI and displays it before waiting for signals to execture other commands

#include <QApplication>
#include <iostream>
using namespace std;

#include "guimain.h"
#include "ui_guimain.h"
#include "Simulation.h"
#include "File.h"
#include "Solution.h"

File file;
Solution solution;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //Find application directory
    file.directory = a.applicationDirPath().toStdString();

    //Alters directory to outside the application bundle
    file.correct();

    //Create initial parameters to populate the GUI
    Parameters initial;

    //Create main form guimain
    guimain b;
    b.setnames(initial,0);
    b.setWindowTitle("aRCPlan");

    //Shown window
    b.show();

    //Wait for signals from GUI
    return a.exec();

}
