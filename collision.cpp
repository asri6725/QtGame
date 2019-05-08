#include "collision.h"

collision::collision(WorldManager *bg, moveplayer* p, obstacles *ob, Config *config, bool extend)
{
    this->bg = bg;
    this->p = p;
    this->obs = ob;
    this->config = config;
    this->extend = extend;
}

bool collision::iscolliding()
{
    int x1 = this->p->p->pos->getX(), y1= this->p->p->pos->getoriginalY(), w1 = this->p->p->pos->getWidth(), h1 = p->p->pos->getHeight();
    int x2 = obs->obstacless[0]->pos->getX(), y2 = obs->obstacless[0]->pos->getoriginalY(), w2 = obs->obstacless[0]->pos->getWidth(), h2 = obs->obstacless[0]->pos->getHeight();
    bool check = false;


    if(x1 <= (x2+w2))
        if(x2 <= x1+w1)
            if(y1 <= y2+h2)
                if(y2 <= y1+h1)
                    check = true;

    return check;
}

void collision::onCollision()
{
    int x1 = this->p->p->pos->getX(), y1= this->p->p->pos->getoriginalY(), w1 = this->p->p->pos->getWidth(), h1 = p->p->pos->getHeight();
    int x2 = obs->obstacless[0]->pos->getX(), y2 = obs->obstacless[0]->pos->getoriginalY(), w2 = obs->obstacless[0]->pos->getWidth(), h2 = obs->obstacless[0]->pos->getHeight();

    if(iscolliding()==true){
        if(x2+2 < x1+w1){
            if(this->p->get_vector()>0)
                this->p->setbottom_limit(y2);

            if(this->p->get_vector()<0)
                this->p->settop_limit(y2+h2);
            difficultDestroy();
        }
        this->obs->setvelocity(0);
        this->bg->setvelocity(0);
    }
    else{
            p->setbottom_limit(RES_Y);
            p->settop_limit(0);
            this->obs->setvelocity(-(config->getVelocity()));
            this->bg->setvelocity(config->getVelocity());
    }
}

void collision::difficultDestroy()
{

    if(this->extend == true){
        if(this->obs->obstacless[0]->obsType() == "blue" && this->p->get_vector()<0){
            this->obs->destroyObs(obs->obstacless[0]);
            this->p->setyvelocity(15);
        }
        else if(this->obs->obstacless[0]->obsType() == "red" && this->p->get_vector()>0){
            this->obs->destroyObs(obs->obstacless[0]);
            this->p->setyvelocity(-15);
        }
    }
}
