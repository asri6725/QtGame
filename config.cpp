#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFileInfo>
#include "config.h"
#include <iostream>

// Constructors + Destructors
Config::Config(){}
Config::Config(std::string file){
    loadFile(file);
}
Config::~Config(){}

// Load config file
bool Config::loadFile(std::string filename){

    // Init to invalid
    valid = false;

    // Read JSON file
    QString content;
    QFile file;
    file.setFileName(QString(filename.c_str()));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!file.exists()) return fileNotFoundError("config.json");
    content = file.readAll();
    file.close();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(content.toUtf8());
    if(jsonDoc.isNull()){
        errorMsg = "Invalid JSON format";
        return false;
    }
    QJsonObject json = jsonDoc.object();

    // Load size and verify valid option
    if(json.contains("size")){
        size = json.value("size").toString().toStdString();
        if(size != "tiny" && size != "normal" && size != "large" && size != "giant") {
            errorMsg = "Invalid size value";
            return false;
        }
    }
    else return paramNotFoundError("size");

    // Load other options
    if(json.contains("initX"))
        initX = json.value("initX").toInt();
    else return paramNotFoundError("initX");
    if(json.contains("initY"))
        initY = json.value("initY").toInt();
    else return paramNotFoundError("initY");
    if(json.contains("velocity"))
        velocity = json.value("velocity").toInt();
    else return paramNotFoundError("velocity");
    if(json.contains("airCandyPosition"))
        airPos = json.value("airCandyPosition").toInt();
    else return paramNotFoundError("airCandyPosition");
    if(json.contains("groundCandyPosition"))
        groundPos = json.value("groundCandyPosition").toInt();
    else return paramNotFoundError("groundCandyPosition");

    // Load textures
    if(json.contains("backgroundTexture"))
        backgroundTexture = json.value("backgroundTexture").toString().toStdString();
    else return paramNotFoundError("backgroundTexture");
    if(json.contains("playerTexture"))
        playerTexture = json.value("playerTexture").toString().toStdString();
    else return paramNotFoundError("playerTexture");
    if(json.contains("pauseTexture"))
        pauseTexture = json.value("pauseTexture").toString().toStdString();
    else return paramNotFoundError("pauseTexture");
    if(json.contains("airCandyTextures")){
        QJsonArray values = json.value("airCandyTextures").toArray();
        for(int i = 0; i < values.count(); i++)
            airCandyTextures.push_back(values.at(i).toString().toStdString());
    }
    else return paramNotFoundError("airCandyTextures");
    if(json.contains("groundCandyTextures")){
        QJsonArray values = json.value("groundCandyTextures").toArray();
        for(int i = 0; i < values.count(); i++)
            groundCandyTextures.push_back(values.at(i).toString().toStdString());
    }
    else return paramNotFoundError("groundCandyTextures");

    //Read about obstacles

    if(json.contains("red"))
        red = json.value("red").toString().toStdString();
    else return paramNotFoundError("red texture - obstacle");


    if(json.contains("blue"))
        blue = json.value("blue").toString().toStdString();
    else return paramNotFoundError("blue texture - obstacle");

    if(json.contains("green"))
        green = json.value("green").toString().toStdString();
    else return paramNotFoundError("green texture - obstacle");

    if(json.contains("obstacleSequence")){
        QJsonArray values = json.value("obstacleSequence").toArray();
        for(int i = 0; i < values.count(); i++)
            obstacleSequence.push_back(values.at(i).toString().toStdString());
    }
    else return paramNotFoundError("obstacleSequence");

    if(json.contains("spacing"))
        obstacleSpacing = json.value("spacing").toInt();
    else return paramNotFoundError("spacing");

/*
    if(json.contains("ypositions")){
        QJsonArray values = json.value("ypositions").toArray();
        for(int i = 0; i < values.count(); i++)
            obstacleYpos.push_back(values.at(i).toInt());
    }
    else return paramNotFoundError("obstacles Y positions");
*/
    // Check textures exist
    if(!fileExists(backgroundTexture)) return fileNotFoundError(backgroundTexture);
    if(!fileExists(playerTexture)) return fileNotFoundError(playerTexture);
    if(!fileExists(pauseTexture)) return fileNotFoundError(pauseTexture);
    for(unsigned int i = 0; i < airCandyTextures.size(); i++)
        if(!fileExists(airCandyTextures[i])) return fileNotFoundError(airCandyTextures[i]);
    for(unsigned int i = 0; i < groundCandyTextures.size(); i++)
        if(!fileExists(groundCandyTextures[i])) return fileNotFoundError(groundCandyTextures[i]);

    // obstacle files
    if(!fileExists(blue)) return fileNotFoundError(blue);
    if(!fileExists(red)) return fileNotFoundError(red);
    if(!fileExists(green)) return fileNotFoundError(green);
/*    for(unsigned int i = 0; i < obstacleSequence.size(); i++)
        if(!fileExists(obstacleSequence[i])) return fileNotFoundError(obstacleSequence[i]);

    if(obstacleSequence.size() != obstacleYpos.size())
        return paramNotFoundError("Check the ypositions and sequences for obstacles");
*/
    // Everything successfully parsed so set valid
    valid = true;
    return valid;

}

// Helper functions
bool Config::fileExists(std::string path){
    return QFileInfo::exists(path.c_str()) && QFileInfo(path.c_str()).isFile();
}
bool Config::fileNotFoundError(std::string file){
    errorMsg = "File not found: " + file;
    return false;
}
bool Config::paramNotFoundError(std::string param){
    errorMsg = "Parameter not found: " + param;
    return false;
}

// Getters
bool Config::isValid(){return valid;}
std::string Config::getErrorMsg(){return errorMsg;}
std::string Config::getSize(){return size;}
int Config::getInitX(){return initX;}
int Config::getInitY(){return initY;}
int Config::getVelocity(){return velocity;}
std::string Config::getBackgroundTexture(){return backgroundTexture;}
std::string Config::getPlayerTexture(){return playerTexture;}
std::string Config::getPauseTexture(){return pauseTexture;}
std::vector<std::string> Config::getAirCandyTextures(){return airCandyTextures;}
std::vector<std::string> Config::getGroundCandyTextures(){return groundCandyTextures;}
int Config::getAirPos(){return airPos;}
int Config::getGroundPos(){return groundPos;}

std::string Config::getRed(){return red;}
std::string Config::getBlue(){return blue;}
std::string Config::getGreen(){return green;}
std::vector<std::string> Config::getObstacleSequence(){return obstacleSequence;}

int Config::getObstacleSpacing(){return obstacleSpacing;}

std::vector<int> Config::getObstacleYpos(){return obstacleYpos;}
