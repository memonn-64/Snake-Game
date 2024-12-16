#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"


using namespace std;

class GameMechs
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;

        int boardSizeX;
        int boardSizeY;
        bool newFood = true;

        


    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        // ~GameMechs(); // Deconstructor not needed as new heaped not created in constructor. 
        
        bool getExitFlagStatus() const; 
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();

        char getInput() const;
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX() const;
        int getBoardSizeY() const;
        
        int getScore() const;
        void incrementScore();
        bool getNewFood();
        void setNewFoodTrue();
        void setNewFoodFalse();

        
        // More methods should be added here
};



#endif