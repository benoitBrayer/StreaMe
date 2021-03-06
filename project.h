/**
 *
 *  StreaMe is a cross-platform live streaming broadcasting client, written in C++, using QT and FFMPEG library.
 *  Copyright (C) 2013, Benoit Brayer, Nans Plancher, Romaric Delaunoy.
 *  This program is free software: you can redistribute it and/or modify it under the terms of
 *  the GNU General Public License as published by the Free Software Foundation,
 *  either version 3 of the License, or (at your option) any later version.
 *  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *  You should have received a copy of the GNU General Public License along with this program.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 **/

#ifndef PROJECT_H
#define PROJECT_H

#include "source.h"
#include "live.h"
#include <vector>
#include <string.h>
#include <QString>
#include <controller.h>

class Controller;
class Source;
class Live;

class Project
{
public:
    Project(Controller* controller);
    ~Project();
    bool save(std::string fileUrl); // return true if successfull
    bool load(std::string fileUrl); // return true if successfull
    std::vector<Source*> getUsedSources();
    void setUsedSources(std::vector<Source*> usedSources);
    void addUsedSource(Source* source);
    void removeUsedSource(std::string sourceName);
    void test_displayUsedSources();
    void setName(std::string name);

    // Streaming platform attributes acessors and mutators
    int getPlatformIndex();
    QString getPlatformIndexQstring();
    void setPlatformIndex(int index);
    void setPlatformIndex(QString index);

    QString getStreamingKeyQstring();
    void setStreamingKey(QString key);

    // Streaming configuration attributes acessors and mutators
    int getVideoSizeIndex();
    QString getVideoSizeIndexQstring();
    void setVideoSizeIndex(int index);
    void setVideoSizeIndex(QString index);

    int getVideoFormatIndex();
    QString getVideoFormatIndexQstring();
    void setVideoFormatIndex(int index);
    void setVideoFormatIndex(QString index);

    bool getAutoConfiguration();
    QString getAutoConfigurationQstring();
    void setAutoConfiguration(bool value);
    void setAutoConfiguration(QString value);

    int getUploadSpeed();
    QString getUploadSpeedQstring();
    void setUploadSpeed(int uploadSpeed);
    void setUploadSpeed(QString uploadSpeed);

    int getVideoBitrate();
    QString getVideoBitrateQstring();
    void setVideoBitrate(int videoBitrate);
    void setVideoBitrate(QString videoBitrate);

    int getAudioBitrateIndex();
    QString getAudioBitrateIndexQstring();
    void setAudioBitrateIndex(int index);
    void setAudioBitrateIndex(QString index);

    bool getStereoConfiguration();
    QString getStereoConfigurationQstring();
    void setStereoConfiguration(bool value);
    void setStereoConfiguration(QString value);

    bool isSource(std::string sourceName);

    std::string getName();

private:
    Controller* controller;
    std::vector<Source*> usedSources;
    Controller* getController();
    std::string name;

    // platform attributes
    int platformIndex;
    QString streamingKey;

    // streaming configuration attributes
    int videoSizeIndex;
    int videoFormatIndex;
    bool autoConfiguration;
    int uploadSpeed;
    int videoBitrate;
    int audioBitrateIndex;
    bool stereoConfiguration;
};

#endif // PROJECT_H
