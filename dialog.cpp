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
        player = new Player(config);
        worldManager = new WorldManager(config);
        this->playerfunc = new moveplayer(player);
        this->ob = new obstacles(6, -3, playerfunc);
        //this->ob = nullptr;
        if(this->ob == nullptr)
            this->stage2 = false;
        else
            this->stage2 = true;
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
    worldManager->setvelocity(-(ob->getvelocity()));

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
    //jump
    if(stage2 == true)
    if(e->key()==Qt::Key_Space)
        this->playerfunc->setyvelocity(30);
}
