#include "obstacles.h"
#include <iostream>

obstacles::obstacles(Config *config, moveplayer *p)
{
    this->p = p;
    this->speed = config->getVelocity();
    this->spacing = config->getObstacleSpacing();
    std::vector <std::string> seq = config->getObstacleSequence();
  //  std::vector <int> obsY = config->getObstacleYpos();
    for(unsigned int i=0; i<seq.size(); i++){
        QPixmap* sprite = nullptr;
        if(seq[i]=="red")
            sprite = new QPixmap(config->getRed().c_str());
        else if(seq[i] == "blue")
            sprite = new QPixmap(config->getBlue().c_str());
        else
            sprite = new QPixmap(config->getGreen().c_str());
        if(i==0)
            obstacless.push_back(new obstacle(RES_X, 100, 70, 50, sprite));
        else{
            Position *p = obstacless[i-1]->pos;
            p->moveX(spacing);
            obstacless.push_back(new obstacle(p, sprite));
        }
    }
}

obstacles::~obstacles()
{
    for(int i=0; i< (int)obstacless.size(); i++)
        delete obstacless[i];
    delete p;
}

void obstacles::render(QPainter &painter)
{
    //update obstacle position

    helper();

    // check for collision
    bool collide = collision(obstacless[0]);

    for(int i=0; i< (int)this->obstacless.size(); i++){
        collide = collide || collision(obstacless[i]);
        if(collide)
            this->speed = 0;
        else
            this->speed = -3;

        // draw the obstacles
        obstacless[i]->pos->setX(obstacless[i]->pos->getX()+this->speed);
        obstacless[i]->render(painter);
    }
}
bool obstacles::collision(obstacle *ob)
{
    int x1 = this->p->p->pos->getX(), y1= this->p->p->pos->getoriginalY(), w1 = this->p->p->pos->getWidth(), h1 = p->p->pos->getHeight();
    int x2 = ob->pos->getX(), y2 = ob->pos->getoriginalY(), w2 = ob->pos->getWidth(), h2 = ob->pos->getHeight();
    bool check = false;

    //Actually checks for collision

    if(x1 <= (x2+w2))
        if(x2 <= x1+w1)
            if(y1 <= y2+h2)
                if(y2 <= y1+h1)
                    check = true;

    //If it is a collision from top or bottom, prevents the player from going through the obstacle.

    if(check == true){
        if(x2+2 < x1+w1){
            if(this->p->get_vector()>0)
                this->p->setbottom_limit(y2);

            if(this->p->get_vector()<0)
                this->p->settop_limit(y2+h2);            
        }
    }
    else{
            p->setbottom_limit(RES_Y);
            p->settop_limit(0);
         }

    return check;

}

void obstacles::helper()
{
    obstacle* check = obstacless[0];
    if(check->pos->getX()+check->pos->getWidth() < 0){
        Position *p2 = obstacless[obstacless.size()-1]->pos;
        if(p2->getX()+spacing > RES_X)
            check->pos->moveX(p2->getX()+spacing);
        else
            check->pos->moveX(p2->getX()+spacing+RES_X);
        obstacless.erase(obstacless.begin());
        obstacless.push_back(check);
    }
}


void obstacles::setvelocity(int velval) {this->speed = velval;}

int obstacles::getvelocity(){return this->speed;}
