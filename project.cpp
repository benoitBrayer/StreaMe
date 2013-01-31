#include "project.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <QString>
#include <source.h>
#include <iostream>

using namespace std;

Project::Project(Controller* controller)
{
    this->controller=controller;
}

Controller* Project::getController(){
    return this->controller;
}

vector<Source*> Project::getUsedSources(){
    return this->usedSources;
}

void Project::setUsedSources(vector<Source*> sources){
    this->usedSources=sources;
}

void Project::addUsedSource(Source* source){
    this->usedSources.push_back(source);
}

void Project::removeUsedSource(string sourceName){
    //remove the item by finding his position in the usedSource vector, and remove the item on this position

    unsigned int i(0);
    bool found(false);
    while(i < usedSources.size() && !found){
        if(usedSources[i]->getName() == sourceName)
            found=true;
        i++;
    }
    usedSources.erase(usedSources.begin() + --i); // remove on the position 'i'
}

void Project::test_displayUsedSources(){
    for(unsigned int i(0); i<usedSources.size();i++)
        cout << usedSources[i]->getName() <<" (" << usedSources[i]->getType() << ")" << endl;
    cout << "---" <<endl;
}

void Project::setLive(Live* live){
    this->live=live;
}

bool Project::save(string fileUrl){

    QString fileName = fileUrl.c_str();
    QFile file(fileName);

    // Openning file in writting only mode
    file.open(QFile::WriteOnly | QFile::Text);
    QXmlStreamWriter writer(&file);

    // Allow Xml indentation
    writer.setAutoFormatting(true);

    // Writing XML Header : <?xml version="1.0" encoding="UTF-8" ?>
    writer.writeStartDocument();

    // Writing root XML element
    // <project>
    //      ...
    writer.writeStartElement("project");

    // Adding sources element
    // <project>
    //      <sources>
    //          ...
    writer.writeStartElement("sources");

    //for (vector<Source>::iterator i = sources.begin(); i != sources.end(); ++i)
    //@todo : test avec boucle
    //{
    // Adding source element
    // <project>
    //      <sources>
    //          <source>
    //              ...
    writer.writeStartElement("source");

    // Adding name element and calling this element with the source name
    // <project>
    //      <sources>
    //          <source>
    //              <name>sourceName</name>
    cout << "plantepas" << endl;
    //writer.writeTextElement("name", (*i).getName().c_str());
    writer.writeTextElement("name", "NAMETEST");
    cout << "plantepas" << endl;
    // Adding type element and calling this element with the source type
    // <project>
    //      <sources>
    //          <source>
    //              <name>sourceName</name>
    //              <type>sourceType</type>
    cout << "plantepas" << endl;
    //writer.writeTextElement("type", (*i).getType().c_str());
    writer.writeTextElement("type", "TYPETEST");
    cout << "plantepas" << endl;

    // Closing source element
    // <project>
    //      <sources>
    //          <source>
    //              <name>sourceName</name>
    //              <type>sourceType</type>
    //          </source>
    cout << "plantepas" << endl;
    writer.writeEndElement();
    cout << "plantepas" << endl;
    //i++;
    //}

    // Closing sources element
    // <project>
    //      <sources>
    //          <source>
    //              <name>sourceName</name>
    //              <type>sourceType</type>
    //          </source>
    //      </sources>
    writer.writeEndElement();

    // Closing project element
    // <project>
    //      <sources>
    //          <source>
    //              <name>sourceName</name>
    //              <type>sourceType</type>
    //          </source>
    //      </sources>
    //  </project
    writer.writeEndElement();

    // Ending XML document
    writer.writeEndDocument();

    // Closing file
    file.close();
    return true;
}

bool Project::load(string fileUrl){

    QXmlStreamReader reader;
    QString fileName = fileUrl.c_str();
    QFile file(fileName);
    cout << fileName.toStdString() << endl;
    file.open(QFile::ReadOnly | QFile::Text); // Openning the XML file in text mode
    reader.setDevice(&file); // Initialising the reader object on the xml file
    while (!reader.atEnd()){
        if(reader.readNextStartElement()){
            if(reader.name().toString().toStdString() == "source"){
                if(reader.readNextStartElement()){
                    if(reader.name().toString().toStdString() == "name"){
                        cout << reader.readElementText().toStdString() << endl;
                        if(reader.readNextStartElement()){
                            if(reader.name().toString().toStdString() == "type")
                                cout << reader.readElementText().toStdString() << endl;
                        }
                    }
                }
            }
        }
    }
    file.close();
    return true;
}
