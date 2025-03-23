#ifndef PLAYER_CPP
#define PLAYER_CPP

#include <raylib.h>

class Player {

    public:
        Rectangle playerBody; 

        Player(Rectangle& playerBody, const Color playerColor, const float& playerYVelocity); 

        Player(); 

        ~Player();

        void MovePlayer(const int& screenWidth, const int& screenHeight); 

        void DrawPlayer();

    private:
        float playerYVelocity;
        Color playerColor;  
};

#endif