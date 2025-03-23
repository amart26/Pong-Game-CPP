#include "opponent.hpp"

Opponent::Opponent(Rectangle &opponentBody, const Color opponentColor, const float &opponentYVelocity):
opponentBody(opponentBody),
opponentColor(opponentColor), 
opponentYVelocity(opponentYVelocity)
{}

Opponent::Opponent():
opponentBody({0,0,0,0}),
opponentColor(RED), 
opponentYVelocity(0)
{}

Opponent::~Opponent()
{}

void Opponent::DrawOpponent()
{
    DrawRectangleRec(opponentBody, opponentColor);
}

void Opponent::MoveOpponent(const int screenWidth, const int screenHeight)
{
    
    if(IsKeyDown(KEY_UP) && opponentBody.y > 0){opponentBody.y -= opponentYVelocity;}
    else if(IsKeyDown(KEY_DOWN) && opponentBody.y < screenHeight - opponentBody.height){opponentBody.y += opponentYVelocity;}
}

