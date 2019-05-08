#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>

class Config {

public:

    // Constructors + Destructors
    Config();
    Config(std::string file);
    ~Config();

    // Load config file
    bool loadFile(std::string filename);

    // Getters
    bool isValid();
    std::string getErrorMsg();
    std::string getSize();
    int getInitX();
    int getInitY();
    int getVelocity();
    std::string getBackgroundTexture();
    std::string getPlayerTexture();
    std::string getPauseTexture();
    std::vector<std::string> getAirCandyTextures();
    std::vector<std::string> getGroundCandyTextures();
    int getAirPos();
    int getGroundPos();

    // obstacles
    std::string getRed();
    std::string getGreen();
    std::string getBlue();
    std::vector<std::string> getObstacleSequence();
    int getObstacleSpacing();
    std::vector<int> getObstacleYpos();
    std::vector <int> getObstacleSize();
    bool getstage2();
private:

    // Attributes
    bool valid = false;
    std::string errorMsg = "";
    std::string size;
    int initX;
    int initY;
    int velocity;
    std::string backgroundTexture;
    std::string playerTexture;
    std::string pauseTexture;
    std::vector<std::string> airCandyTextures;
    std::vector<std::string> groundCandyTextures;
    int groundPos;
    int airPos;

    //obstacles
    std::string red;
    std::string blue;
    std::string green;
    std::vector<std::string> obstacleSequence;
    int obstacleSpacing;
    std::vector <int> obstacleYpos;
    std::vector <int> obstacleSize;
    bool stage2;
    // Helper function
    bool fileExists(std::string path);
    bool fileNotFoundError(std::string file);
    bool paramNotFoundError(std::string param);
};

#endif // CONFIG_H
