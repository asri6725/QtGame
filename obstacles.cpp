#include "obstacles.h"
#include <iostream>

obstacles::obstacles(Config *config, moveplayer *p, WorldManager *wm)
{
    this->config = config;
    this->wm = wm;
    this->p = p;
    this->speed = wm->getvelocity();
    this->spacing = config->getObstacleSpacing();
    std::vector <std::string> seq = config->getObstacleSequence();
    std::vector <int> obsY = config->getObstacleYpos();
    std::vector <int> size = config->getObstacleSize();

    for(unsigned int i=0; i<seq.size(); i++){
        QPixmap* sprite = nullptr;
        QString type = QString::fromUtf8(seq[i].c_str());
        if(seq[i]=="red")
            sprite = new QPixmap(config->getRed().c_str());
        else if(seq[i] == "blue")
            sprite = new QPixmap(config->getBlue().c_str());
        else
            sprite = new QPixmap(config->getGreen().c_str());
        if(i==0)
            obstacless.push_back(new obstacle(RES_X, obsY[i], 70*size[i], 50*size[i], sprite, type));
        else{
            obstacless.push_back(new obstacle(obstacless[i-1]->pos->getX()+obstacless[i-1]->pos->getWidth()+spacing, obsY[i], 70*size[i], 50*size[i], sprite, type));
        }
    }
}

obstacles::~obstacles()
{
    for(int i=0; i< (int)obstacless.size(); i++)
        delete obstacless[i];
    delete p;
    delete this->config;
    delete this->wm;
}

void obstacles::render(QPainter &painter)
{
    //update obstacle position
    updateObs();


    for(int i=0; i< (int)this->obstacless.size(); i++){
        // draw the obstacles
        obstacless[i]->pos->moveX(this->speed);
        obstacless[i]->render(painter);
    }
}

void obstacles::destroyObs(obstacle* ob)
{
    obstacle* temp = ob;
    Position *tmppos = obstacless.back()->pos;
    temp->pos->moveX(tmppos->getX()+tmppos->getWidth()+spacing);
    obstacless.erase(obstacless.begin());
    obstacless.push_back(temp);
}
void obstacles::updateObs()
{
    if(obstacless[0]->pos->getX()+obstacless[0]->pos->getWidth() < 0){
        destroyObs(obstacless[0]);
    }
}


void obstacles::setvelocity(int velval) {this->speed = velval;}

int obstacles::getvelocity(){return this->speed;}
