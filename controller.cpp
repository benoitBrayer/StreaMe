#include "controller.h"
using namespace std;

Controller::Controller()
{
    this->mainwindow = new MainWindow(this);
    this->streamTools = new StreamTools(this);
    this->project = new Project(this);

}

Controller::~Controller(){
    delete this->streamTools;
}

void Controller::ShowMainWindow(){
    this->mainwindow->show();
}

void Controller::displayVideoSources(){

    vector<Source*> videoDevices = streamTools->getVideoSources();

    for(unsigned int i(0); i < videoDevices.size(); i++){
        cout << videoDevices[i]->getName() << endl;
    }
}

void Controller::displayAudioSources(){

    vector<Source*> audioDevices = streamTools->getAudioSources();

    for(unsigned int i(0); i < audioDevices.size(); i++){
        cout << audioDevices[i]->getName() << endl;
    }
}

void Controller::stream(){

    string url, size, videoBitrate, audioBitrate;

    //Switching to define the streaming platform
    switch(project->getPlatformIndex())
    {
    case 0: //Platform == Justin.tv
        url = "rtmp://live.twitch.tv/app/";
        url += project->getStreamingKeyQstring().toStdString();
        break;
    case 1: // Platform == Ustream
        url = "rtmp://1.13181675.fme.ustream.tv/ustreamVideo/13181675/";
        url += project->getStreamingKeyQstring().toStdString();
        url += " flashver=FMLE/3.0\20(compatible;\20FMSc/1.0)";
        break;
    default:
        break;
    }

    //Switching to define the streaming video size ("480x360" for example)
    switch(project->getVideoSizeIndex())
    {
    case 0: // size = 360p
        if(project->getVideoFormatIndex() == 0)// if format == 16/9
            size = "640x360";
        else // else if format == 4/3
            size = "480x360";
        break;
    case 1: // size = 480p
        if(project->getVideoFormatIndex() == 0)// if format == 16/9
            size = "720x480";
        else // else if format == 4/3
            size = "640×480";
        break;
    case 2: // size = 720p
        size = "1280×720";
        break;
    default:
        break;
    }



    //Construct the video bitrate string
    stringstream stringVBitrate(videoBitrate);
    stringVBitrate << project->getVideoBitrate();
    videoBitrate = stringVBitrate.str() + "k";

    switch(project->getAudioBitrateIndex())
    {
    case 0:
        audioBitrate = "56k";
        break;
    case 1:
        audioBitrate = "128k";
        break;
    case 2:
        audioBitrate = "256k";
        break;
    case 3:
        audioBitrate = "320k";
        break;
    default:
        break;
    }

    cout << url << endl;
    cout << size << endl;
    cout << videoBitrate << endl;
    cout << audioBitrate << endl;
    streamTools->startStream(url,size,videoBitrate,audioBitrate);
}

void Controller::stopStream(){
    streamTools->stopStream();
}

void Controller::displayFreeSources(){
    vector<Source*> allSources(streamTools->getAllSources()), usedSources(project->getUsedSources());
    //usedSources.push_back(new Source("Microphone (Realtek High Definition Audio)","audio"));
    bool used(false);
    unsigned int j(0);
    QStringList listFSources;

    for(unsigned int i(0); i < allSources.size(); i++){

        while( (j < usedSources.size()) && !used){ // browse the used vector to check if the source is used
            if(allSources[i]->getName() == usedSources[j]->getName())
                used = true;
            else
                j++;
        }

        if(!used) //if not used, the source is free, so we add it on the list
            listFSources.push_back(QString::fromStdString((allSources[i]->getName())));

        used = false; // used = false to enter in the next iteration
        j = 0; // same thing
    }
    mainwindow->setFreeSources(listFSources);
}

void Controller::displayUsedSources(){
    QStringList listUSources;
    for(unsigned int i(0); i < project->getUsedSources().size(); i++){
        listUSources.push_back(QString::fromStdString((project->getUsedSources()[i]->getName())));
    }
    mainwindow->setUsedSources(listUSources);
}

Project* Controller::getProject(){
    return this->project;
}

void Controller::setProject(Project* newProject){
    this->project = newProject;
}

void Controller::useSource(string sourceName){

    Source *selectedSource(0);

    for(unsigned int i(0); i < streamTools->getAllSources().size(); i++){
        if(streamTools->getAllSources()[i]->getName() == sourceName)
            selectedSource = streamTools->getAllSources()[i];
    }

    if(selectedSource != 0){
        project->addUsedSource(selectedSource);
        displayFreeSources();
        displayUsedSources();
    }
}

void Controller::notUseSource(string sourceName){

    project->removeUsedSource(sourceName);
    displayFreeSources();
    displayUsedSources();
}

vector<Source*> Controller::getProjectUsedSouces(){
    return project->getUsedSources();
}

void Controller::streamStarted(){
    Sleep(7000);
    mainwindow->startVideo();
}
