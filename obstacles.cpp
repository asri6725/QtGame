#include "obstacles.h"

//constructor
Obstacles::Obstacles(Config *config)
{
    //read from config and store directly in class objects.For vectors, store them in temporary variables so I can use them easier
    this->config = config;
    this->speed = config->getVelocity();
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
            obstacless.push_back(new Obstacle(RES_X, obsY[i], 70*size[i], 50*size[i], sprite, type));       //create the first object at the end of the screen
        else
            obstacless.push_back(new Obstacle(obstacless[i-1]->pos->getX()+obstacless[i-1]->pos->getWidth()+spacing, obsY[i], 70*size[i], 50*size[i], sprite, type)); //create all other objects with a space before their previos object
    }
}

Obstacles::~Obstacles()
{
    for(int i=0; i< (int)obstacless.size(); i++)
        delete obstacless[i];
    delete this->config;
}

void Obstacles::render(QPainter &painter)
{
    //update obstacle position
    updateObs();


    for(int i=0; i< (int)this->obstacless.size(); i++){
        // draw the obstacles
        obstacless[i]->pos->moveX(this->speed);
        obstacless[i]->render(painter);
    }
}

// destroy obstacles- push the obstacle back at the end of the sequence
void Obstacles::destroyObs(Obstacle* ob)
{
    Obstacle* temp = ob;
    Position *tmppos = obstacless.back()->pos;
    temp->pos->moveX(tmppos->getX()+tmppos->getWidth()+spacing);
    obstacless.erase(obstacless.begin());
    obstacless.push_back(temp);
}

//destroy obstacles if they are no longer on screen
void Obstacles::updateObs()
{
    if(obstacless[0]->pos->getX()+obstacless[0]->pos->getWidth() < 0){
        destroyObs(obstacless[0]);
    }
}

//getter and setter methods
void Obstacles::setvelocity(int velval) {this->speed = velval;}

int Obstacles::getvelocity(){return this->speed;}
