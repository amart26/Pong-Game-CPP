#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h> 
#include <iostream>
#include <string>

#include "player.hpp"
#include "opponent.hpp"
#include "ball.hpp"

class Game {

        public: 
            void CreateGame(); 

        private: 

            int screenWidth; 
            int screenHeight; 
            bool isGameOver; 
            int playerScore; 
            int opponentScore;  

            Vector2 playerSize;
            Vector2 playerPosition;
            Color playerColor; 
            float playerYVelocity;
            Rectangle playerBody; 
            Player player;

            Vector2 opponentSize;
            Vector2 opponentPosition;
            Color opponentColor; 
            float opponentYVelocity;
            Rectangle opponentBody; 
            Opponent opponent;

            int ballRadius; 
            Vector2 ballPosition;
            Color ballColor;
            Ball ball;

            void UpdateScore();          
            
}; 

#endif