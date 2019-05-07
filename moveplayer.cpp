#include "moveplayer.h"
#include <iostream>

moveplayer::moveplayer(Player *p)
{
    this->p = p;
    this->yspeed = 0;
    this->gravity = -1;
    this->bottom_limit = RES_Y;
    this->top_limit = 0;
    this->speed_vector = 1;
}

moveplayer::~moveplayer()
{
    delete this->p;
}

void moveplayer::setyvelocity(int val){    this->yspeed = val;}

void moveplayer::render(QPainter &painter)
{
    this->setyvelocity(this->yspeed+this->gravity);
    update_vector();
    this->updateypos(this->yspeed);
    p->render(painter);
}

void moveplayer::updateypos(int val)
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

void moveplayer::setbottom_limit(int val){this->bottom_limit = val;}

void moveplayer::settop_limit(int val){this->top_limit = val;}

void moveplayer::update_vector()
{
    if(this->yspeed>0)
        this->speed_vector = 1;
    else if(this->yspeed < 0)
        this->speed_vector = -1;
    else
        this->speed_vector = 0;
}

int moveplayer::get_vector(){return this->speed_vector;}

