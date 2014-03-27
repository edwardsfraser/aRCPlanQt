#-------------------------------------------------
#
# Project created by QtCreator 2014-03-26T13:48:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = aRCPlanQt
TEMPLATE = app


SOURCES += main.cpp\
        guiinput.cpp \
    guioutput.cpp \
    Backfill.cpp \
    BeamModel.cpp \
    computeG.cpp \
    ConfigFile.cpp \
    Constants.cpp \
    Control.cpp \
    Creep.cpp \
    Decompression.cpp \
    FDprofile.cpp \
    Filepath.cpp \
    FracMech.cpp \
    Geometry.cpp \
    Interface.cpp \
    Material.cpp \
    OutflowProcess.cpp \
    Parameters.cpp \
    Plot.cpp \
    Results.cpp \
    Simulation.cpp \
    Solution.cpp \
    SymDoubleMatrix.cpp \
    TestSetup.cpp \

HEADERS  += guiinput.h \
    guioutput.h \
    backFill.h \
    BeamModel.h \
    ConfigFile.h \
    Constants.h \
    Control.h \
    Creep.h \
    Decompression.h \
    FDprofile.h \
    Filepath.h \
    FracMech.h \
    Geometry.h \
    gnuplotHandle.hpp \
    Interface.h \
    Material.h \
    OutflowProcess.h \
    Parameters.h \
    Plot.h \
    Results.h \
    Simulation.h \
    Solution.h \
    SymDoubleMatrix.h \
    TestSetup.h

FORMS    += guiinput.ui \
    guioutput.ui

OTHER_FILES += \
    caseInputData.txt \
    README.md \
    Results.csv \
    aRCPlan.dSYM
