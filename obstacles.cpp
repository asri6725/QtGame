#include "obstacles.h"
#include <iostream>

obstacles::obstacles(int number, int speed, moveplayer *p)
{
    this->speed = speed; this->number = number; this->p = p;
    obstacless.push_back(new obstacle(RES_X, 70, 50, 70));
    for(int i=1; i<number; i++){
        int x = obstacless[i-1]->pos->getX(), y = obstacless[i-1]->pos->getY(), w = obstacless[i-1]->pos->getWidth(), h = obstacless[i-1]->pos->getHeight();
        obstacless.push_back(new obstacle(x+300, y, w, h));
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
        obstacless.erase(obstacless.begin());
        obstacless.push_back(new obstacle(RES_X,500, 50, 70));
    }
}


void obstacles::setvelocity(int velval) {this->speed = velval;}

int obstacles::getvelocity(){return this->speed;}
