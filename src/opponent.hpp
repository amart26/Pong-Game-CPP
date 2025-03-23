#include <raylib.h>


#pragma once

class Opponent {

    public: 
        
        Rectangle opponentBody; 

        Opponent(Rectangle& opponentBody, const Color opponentColor, const float& opponentYVelocity); 

        Opponent(); 

        ~Opponent();

        void DrawOpponent();

        void MoveOpponent(const int screenWidth, const int screenHeight);

    private:

        float opponentYVelocity;
        Color opponentColor;  

}; 