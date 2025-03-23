#include <raylib.h>
#include <iostream>

#include "player.hpp"
#include "opponent.hpp"


#pragma once

class Ball {

    public:
        Vector2 ballPosition;

        Ball (Vector2 &ballPosition, const int& ballRadius, const Color& ballColor); 
        
        Ball(); 

        ~Ball();

        void DrawBall(); 

        void MoveBall(const int& screenWdith, const int& screenHeight);

        void CheckBallCollision(const Player& player, const Opponent& opponent);

    private:

        int ballRadius; 
        float xVelocity;
        float yVelocity;
        Color ballColor;
};