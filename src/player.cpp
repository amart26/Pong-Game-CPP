#include "player.hpp"

Player::Player(Rectangle& playerBody, const Color playerColor, const float& playerYVelocity):
playerBody(playerBody),
playerColor(playerColor),
playerYVelocity(playerYVelocity)
{}

Player::Player():
playerBody({0, 0, 0, 0}),
playerColor(RED),
playerYVelocity(0)
{}

Player::~Player()
{}

void Player::MovePlayer(const int& screenWidth, const int& screenHeight)
{
    if(IsKeyDown(KEY_W) && playerBody.y > 0){playerBody.y -= playerYVelocity;}
    else if(IsKeyDown(KEY_S) && playerBody.y < screenHeight - playerBody.height){playerBody.y += playerYVelocity;}
}

void Player::DrawPlayer()
{
    DrawRectangleRec(playerBody, playerColor);
}
