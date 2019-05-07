#ifndef MOVEPLAYER_H
#define MOVEPLAYER_H
#include <player.h>
#include <QDialog>

class moveplayer
{
public:
    moveplayer(Player *p);
    ~moveplayer();

    void setyvelocity(int val);
    // draws the player
    void render(QPainter& painter);
    //changes player position based on velocity. Also implements restricitions to the players velocity
    void updateypos(int val);
    // sets a bottom limit to the pleyer. (Ex if the player is on an obstacle; generally the bottom limit is the screensize)
    void setbottom_limit(int val);
    //sets a top limit for the player
    void settop_limit(int val);

    void update_vector();
    int get_vector();

    Player *p;

private:

    int yspeed, gravity, bottom_limit, top_limit, speed_vector;

};

#endif // MOVEPLAYER_H
