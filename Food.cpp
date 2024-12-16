#include "MacUILib.h"
#include "Food.h"
#include <cstdlib> 
#include <ctime>   
#include "Player.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"



Food::Food(GameMechs* thisGMRef):gameMechsRef(thisGMRef) 
{
    // seed random generator
    srand(static_cast<unsigned>(time(0))); 
    foodPos = objPos(0, 0, 'x'); 
}

Food::~Food() // deconstructor
{

}

void Food::generateFood(objPosArrayList* playerPosList) {
    int boardX = gameMechsRef->getBoardSizeX()-2; //board width without borders.
    int boardY = gameMechsRef->getBoardSizeY()-2; // board height without borders.

    bool isOnSnake; // bool to check if food generated is on snake.

    int newX, newY;
    do {
        newX = (rand() % boardX) + 1; //generate random X and Y from 1-29 and 1-14 (without borders)
        newY = (rand() % boardY) + 1; 


        isOnSnake = false; // resets to false to allow for loop to generate till its not on snake.

        for (int i = 0; i < playerPosList->getSize(); i++) {
            if (newX == playerPosList->getElement(i).getX()
            && newY == playerPosList->getElement(i).getY()) // check if snake body is on the food generated
            {
                isOnSnake = true; // set true if generated on snake
                break; 
            } 
        }
    }
    while (isOnSnake); // Continue until position that doesnt overlap is generated 
    
    

    gameMechsRef->setNewFoodFalse(); //shows new food item doesnt need to be generated as of now

    foodPos = objPos(newX, newY, 'x'); //update pos of food with coordinates. 
}

objPos Food::getFoodPos() const // getter function to return objpos object of food position.
{
    return foodPos;
}
