#ifndef OPPONENT_HPP
#define OPPONENT_HPP

#include <raylib.h>

class Ball; 

class Opponent {

    public: 
        
        Rectangle opponentBody; 

        Opponent(Rectangle& opponentBody, const Color opponentColor, const float& opponentYVelocity); 

        Opponent(); 

        ~Opponent();

        void DrawOpponent();

        void MoveOpponent(const Vector2 ballPosition, const int screenWidth, const int screenHeight);

    private:

        float opponentYVelocity;
        Color opponentColor;  

}; 

#endif