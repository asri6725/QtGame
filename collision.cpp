#include "collision.h"

//constructor
Collision::Collision(WorldManager *bg, MovePlayer* p, Obstacles *ob, Config *config, bool extend)
{
    this->bg = bg;
    this->p = p;
    this->obs = ob;
    this->config = config;
    this->extend = extend;
}

//destructor
Collision::~Collision()
{
    delete this->bg;
    delete this->config;
    delete this->obs;
    delete this->p;
}

//checks for collision
bool Collision::iscolliding()
{
    int x1 = this->p->p->pos->getX(), y1= this->p->p->pos->getoriginalY(), w1 = this->p->p->pos->getWidth(), h1 = p->p->pos->getHeight();
    int x2 = obs->obstacless[0]->pos->getX(), y2 = obs->obstacless[0]->pos->getoriginalY(), w2 = obs->obstacless[0]->pos->getWidth(), h2 = obs->obstacless[0]->pos->getHeight();
    bool check = false;
    /*
     * Rectangle 1, formed by player represented by (x1, y1, w1, h1), rectangle 2 formed by obstacle represented by (x2, y2, w2, h2)
     * The code below checks if there is any overlap between rectangle1 and rectangle2.
     **/

    if(x1 <= (x2+w2))
        if(x2 <= x1+w1)
            if(y1 <= y2+h2)
                if(y2 <= y1+h1)
                    check = true;

    return check;
}

//modifies player and background as needed when collision occurs
void Collision::onCollision()
{
    int x1 = this->p->p->pos->getX(), y1= this->p->p->pos->getoriginalY(), w1 = this->p->p->pos->getWidth(), h1 = p->p->pos->getHeight();
    int x2 = obs->obstacless[0]->pos->getX(), y2 = obs->obstacless[0]->pos->getoriginalY(), w2 = obs->obstacless[0]->pos->getWidth(), h2 = obs->obstacless[0]->pos->getHeight();
    /*
     * (x1,y1,w1,h1) and (x2,y2,w2,h2) represent the same thing as the collision checking function.
     * This function checks if the player is colliding with the obstacle by jumping above it or hitting it from below.
     * In this case, the player's movement is limited to the obstacle's size.
     * This function also applies the extension and the extension function (difficultDestroy) checks if we actually want the extension or not.
     * */
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

//simple extension
void Collision::difficultDestroy()
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
