#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs() // constructor that sets the game board to 30x15 with 0 score, no input, and exitflag and loseflag equal to false. 
{
    boardSizeX = 30; 
    boardSizeY = 15;
    input = '\0'; 
    exitFlag = false; 
    loseFlag = false; 
    score = 0; 


}

GameMechs::GameMechs(int boardX, int boardY) // setting game board size
{
    boardSizeX = boardX;
    boardSizeY = boardY; 
}



bool GameMechs::getExitFlagStatus() const // simple
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const // simple
{
    return loseFlag; 
}
    

char GameMechs::getInput() const // simple 
{
    return input;
}

int GameMechs::getScore() const // simple
{
    return score;
}

void GameMechs::incrementScore() // simple
{
    score++;
}

int GameMechs::getBoardSizeX() const // simple
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const // simple
{
    return boardSizeY;
}


void GameMechs::setExitTrue() // simple
{
    exitFlag = true; 
}

void GameMechs::setLoseFlag() // simple
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input) // set a input
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    
    
}

void GameMechs::clearInput() // simple.
{
    input = '\0'; 

}


bool GameMechs::getNewFood()
{
    return newFood;
}

void GameMechs::setNewFoodTrue() // function to set bool when needed to spawn new food. 
{
    newFood = true;
}
void GameMechs::setNewFoodFalse() // function to set bool when not needed to spawn new food. 
{
    newFood = false;
}

// More methods should be added here