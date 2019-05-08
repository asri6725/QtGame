#include "moveplayer.h"

// constructor
MovePlayer::MovePlayer(Player *p)
{
    this->p = p;
    this->yspeed = 0;
    this->gravity = -1;
    this->bottom_limit = RES_Y;
    this->top_limit = 0;
    this->speed_vector = 1;
}

//destructor
MovePlayer::~MovePlayer()
{
    delete this->p;
}

//set player velocity
void MovePlayer::setyvelocity(int val){    this->yspeed = val;}

//draw player with jump function
void MovePlayer::render(QPainter &painter)
{
    this->setyvelocity(this->yspeed+this->gravity);
    update_vector();
    this->updateypos(this->yspeed);
    p->render(painter);
}

//update yposition based on velocity and gravity and limit it (to screensize or obstacle on collision)
void MovePlayer::updateypos(int val)
{
    if(this->p->pos->getoriginalY() + val > bottom_limit - p->pos->getHeight()){
        p->pos->setY(bottom_limit-p->pos->getHeight());
    }
    else if(this->p->pos->getoriginalY()+val <top_limit){
        p->pos->setY(top_limit);
    }
    else{
        p->pos->moveY(val);
    }
}

//setter method
void MovePlayer::setbottom_limit(int val){this->bottom_limit = val;}

//setter method
void MovePlayer::settop_limit(int val){this->top_limit = val;}

//checks if player is moving upwards or downwards, useful for determining collision and setting limits if player hits obstacle.
void MovePlayer::update_vector()
{
    if(this->yspeed>0)
        this->speed_vector = 1;
    else if(this->yspeed < 0)
        this->speed_vector = -1;
    else
        this->speed_vector = 0;
}
//getter method
int MovePlayer::get_vector(){return this->speed_vector;}

