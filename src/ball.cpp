#include "ball.hpp"

Ball::Ball(Vector2 &ballPosition, const int& ballRadius, const Color& ballColor):
ballPosition(ballPosition),
ballRadius(ballRadius),
ballColor(ballColor),
yVelocity(5),
xVelocity(6)
{}

Ball::Ball():
ballPosition({0, 0}), 
ballRadius(0),
ballColor(RED)
{}

Ball::~Ball()
{
    std::cout << "Ball Deleted";
}


void Ball::DrawBall()
{
    DrawCircleV(ballPosition, ballRadius, ballColor);
}

void Ball::MoveBall(const int& screenWdith, const int& screenHeight)
{
    if(ballPosition.y < 0 + ballRadius)
    {
        yVelocity = -yVelocity;
        ballPosition.y += yVelocity; 
    }
    if (ballPosition.y > screenHeight - ballRadius)
    {
        yVelocity = -yVelocity;
        ballPosition.y += yVelocity;
    }
    else 
    {
        ballPosition.y += yVelocity;
        ballPosition.x += xVelocity;
    }  
}

void Ball::CheckBallCollision(const Player &player, const Opponent &opponent)
{
    if(CheckCollisionCircleRec(ballPosition, ballRadius, player.playerBody))
    {
        xVelocity = -xVelocity; 
        ballPosition.x += xVelocity;
    }
    if(CheckCollisionCircleRec(ballPosition, ballRadius, opponent.opponentBody))
    {
        xVelocity = -xVelocity; 
        ballPosition.x += xVelocity;
    }
}

