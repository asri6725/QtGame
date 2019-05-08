#include "test.h"
#include <iostream>

test::test()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(30);
    std::srand(std::time(nullptr));

    // Read config file
    config = new Config("D:/info3220 assignment2/Base1E/resources/config.json");
    if(!config->isValid()){
        std::cout << "Not valid config" << std::endl;
    }

    // Init world manager and player
    else{
        player = new Player(config);
        worldManager = new WorldManager(config);
        this->playerfunc = new moveplayer(player);
        this->ob = new obstacles(config, playerfunc, worldManager);
        //this->ob = nullptr;
        if(this->ob == nullptr)
            this->stage2 = false;
        else
            this->stage2 = true;
    }

}

test::~test()
{
    delete timer;
    if(config->isValid()){
        delete player;
        delete worldManager;
    }
    if(stage2==true){
        delete this->ob;
        delete this->playerfunc;
        delete player;
        delete worldManager;
    }
    delete config;

}


void Dialog::nextFrame(){
    update();
}
