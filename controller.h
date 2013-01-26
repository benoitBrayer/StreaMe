#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "mainwindow.h"
#include "project.h"
#include "streamtools.h"


class MainWindow;
class Project;
class StreamTools;

class Controller
{
public:
    Controller();
    ~Controller();
    void ShowMainWindow();
    void displayVideoSources();
    void displayAudioSources();
    void captureFileTest();

private:
    MainWindow * mainwindow;
    Project *project;
    StreamTools *streamTools;
};

#endif // CONTROLLER_H
