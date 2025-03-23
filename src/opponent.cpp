#include "opponent.hpp"
#include "ball.hpp"

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

void Opponent::MoveOpponent(const Vector2 ballPosition, const int screenWidth, const int screenHeight)
{
    if(ballPosition.y < opponentBody.y && opponentBody.height / 2 < screenHeight - opponentBody.height)
    {
        opponentBody.y -= opponentYVelocity;
    }
    else{
        opponentBody.y += opponentYVelocity;
    }
}
