#include <QDir>
#include <QDebug>
#include "dialog.h"
#include "ui_dialog.h"
#include "define.h"
#include <iostream>


// Constructor
Dialog::Dialog(QWidget *parent): QDialog(parent), ui(new Ui::Dialog){

    // Setup window, FPS, path, RNG
    ui->setupUi(this);
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    this->setWindowState(Qt::WindowFullScreen);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(FRAME_TIME);
    std::srand(std::time(nullptr));

    // Read config file
    config = new Config("D:/info3220 assignment2/Base1E/resources/config.json");
    if(!config->isValid()){
        qCritical() << config->getErrorMsg().c_str();
        QMetaObject::invokeMethod(this, "close", Qt::QueuedConnection);
    }

    // Init world manager and player
    else{
        this->stage2 = this->config->getstage2();
        player = new Player(config);
        worldManager = new WorldManager(config);
        if(stage2 == true){
        this->playerfunc = new moveplayer(player);
        this->ob = new obstacles(config, playerfunc, worldManager);
        bool extend = true;
        this->collide = new collision(worldManager, playerfunc, ob, config, extend);
        }
        //this->ob = nullptr;
    }

}

// Destructor
Dialog::~Dialog(){
    delete ui;
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

// Frame update
void Dialog::nextFrame(){
    if(stage2 == true){
        this->collide->onCollision();
    }
    update();
}
void Dialog::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    worldManager->update(painter);
    if(stage2 == false)
        player->render(painter);
    else{
    playerfunc->render(painter);
    ob->render(painter);
    }
}

// Respond to Key Press
void Dialog::keyPressEvent(QKeyEvent *e){
    // Pause
    if(e->key() == Qt::Key_Tab)
        worldManager->togglePause();
    // Quit
    if(e->key() == Qt::Key_Escape)
        this->reject();
    //jump, first check if we are executing stage 2 code
    if(stage2 == true)
    if(e->key()==Qt::Key_Space){
        this->playerfunc->setyvelocity(30);
        //std::cout << "player jumped" << std::endl;
    }
}
