#include "game.hpp"

void Game::CreateGame()
{
    //Initial Game Settings
    screenWidth = 800; 
    screenHeight = 400; 
    isGameOver = false;
    playerScore = 0;
    opponentScore = 0;

    
    InitWindow(screenWidth, screenHeight, "Pong Game"); 
    SetTargetFPS(60);

    //Intial Player Settings
    playerSize = {20, 80};
    playerPosition = {25, (float)screenHeight /2};
    playerColor = WHITE; 
    playerYVelocity = 4.5;
    playerBody = {playerPosition.x, playerPosition.y, playerSize.x, playerSize.y}; 
    player = Player(playerBody, playerColor, playerYVelocity);

    //Intial Opponent Settings
    opponentSize = {20, 80};
    opponentPosition = {(float)screenWidth - 50, (float)screenHeight /2};
    opponentColor = WHITE; 
    opponentYVelocity = 4.5;
    opponentBody = {opponentPosition.x, opponentPosition.y, opponentSize.x, opponentSize.y}; 
    opponent = Opponent(opponentBody, opponentColor, opponentYVelocity);

    //Intial Ball Settings
    ballRadius = 10; 
    ballPosition = {(float)screenWidth / 2, (float)screenHeight / 2};
    ballColor = RED;
    ball = Ball(ballPosition, ballRadius, ballColor);
    
    while(!WindowShouldClose())
    {
            ball.CheckBallCollision(player, opponent);
            player.MovePlayer(screenWidth, screenHeight);
            ball.MoveBall(screenWidth, screenHeight);
            opponent.MoveOpponent(ball.ballPosition, screenWidth, screenHeight);
            UpdateScore();

            BeginDrawing(); 
                ClearBackground(BLACK);
                DrawText(TextFormat("Player Score: %02i", playerScore), (screenWidth / 2 - 350), 10, 16, WHITE);
                DrawText(TextFormat("Opponent Score: %02i", opponentScore), (screenWidth / 2  + 175), 10, 16, WHITE);
                player.DrawPlayer();
                opponent.DrawOpponent();
                ball.DrawBall();
            EndDrawing(); 
    }

    CloseWindow();
}

void Game::UpdateScore()
{ 
    if(ball.ballPosition.x < 0 && ball.ballPosition.x != float(NULL))
    {
        opponentScore += 1;
        ball.ballPosition = {(float)screenWidth / 2, (float) screenHeight / 2};
    }
    else if(ball.ballPosition.x > screenWidth)
    {
        playerScore += 1; 
        ball.ballPosition = {(float)screenWidth / 2, (float) screenHeight / 2};
    }
}
