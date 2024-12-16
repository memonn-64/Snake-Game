#include "Player.h"
#include "objPosArrayList.h"
#include "Food.h"
#include "GameMechs.h"


Player::Player(GameMechs* thisGMRef, Food* foodref)
{
    mainGameMechsRef = thisGMRef; // pointer to reference game mechanics class
    myDir = LEFT; // default direction
    mainFoodRef = foodref; // pointer to reference food class
    
    // more actions to be included

    playerPosList = new objPosArrayList[20]; //allocate new heap memory 
    objPos start =  {7, 15, 'o'}; // starting object position
    playerPosList->insertHead(start); // add starting head @ start of game

}


Player::~Player()
{
    delete[] playerPosList;     // delete any heap members here
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList; // simple.
}

void Player::updatePlayerDir()
{

    char input = mainGameMechsRef->getInput();
        // PPA3 input processing logic       
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit
                mainGameMechsRef->setExitTrue();
                break;
            case 'W': 
            case 'w':
                if (myDir == LEFT || myDir == RIGHT)
                {
                    myDir = UP;
                }
                break;
            
            case 'a':
            case 'A':
                if (myDir == UP || myDir == DOWN)
                {
                    myDir = LEFT;
                }    
                break;

            case 's':
            case 'S':
                if (myDir == LEFT || myDir == RIGHT)
                {
                    myDir = DOWN;
                }
                break;
            
            case 'd':
            case 'D':
                if (myDir == UP || myDir == DOWN)
                {
                    myDir = RIGHT;
                }
                break;

            default:
                break;
        }
        mainGameMechsRef->clearInput();
    }

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    int newX = playerPosList->getHeadElement().getX(); // X coordinate of head
    int newY = playerPosList->getHeadElement().getY(); // Y coordinate of head

    switch (myDir)
    {
    case UP:
        newY -= 1;
        break;
    case DOWN:
        newY +=1;
        break;

    case LEFT:
        newX -= 1;
        break;

    case RIGHT:
        newX += 1;
        break;

    default:
        break;
    }    
        
    // wrap around logic
    if (newX < 1) newX = mainGameMechsRef->getBoardSizeX() - 2;     
    else if (newX > mainGameMechsRef->getBoardSizeX() - 2) newX = 1;    
    else if (newY < 1) newY = mainGameMechsRef->getBoardSizeY() - 2;    
    else if (newY > mainGameMechsRef->getBoardSizeY() - 2) newY = 1;

    objPos newPos = objPos(newX, newY, 'o'); // setting new position of head into a object position

    




    if (newX == mainFoodRef->getFoodPos().getX() && newY == mainFoodRef->getFoodPos().getY()) //checks if XY coordinate touches XY coordinate of food.
    {
        objPos newHead = objPos(mainFoodRef->getFoodPos().getX(), mainFoodRef->getFoodPos().getY(), 'o'); // Setting new position of head into object postion of food. AKA food becomes the new head
        playerPosList->insertHead(newHead); // actually adding food position to the head
        mainGameMechsRef->setNewFoodTrue(); // function to allow spawn of new food.
        mainGameMechsRef->incrementScore(); // increase score

    }
    else
    {
        //List based movement 
        playerPosList->insertHead(newPos); // add head to new position in the list
        playerPosList->removeTail(); // remove tail to make it look like entire list is moving
    }
    

}

bool Player::checkSelfCollision()
{
    
    for (int i = 1; i < playerPosList->getSize(); i++) // check through all element in list size (all part of snake body) except head.
    {
        
        if (playerPosList->getHeadElement().getX() == playerPosList->getElement(i).getX()
        && playerPosList->getHeadElement().getY() == playerPosList->getElement(i).getY() ) // check if head hits any part of the list (snake body)
        {
            return true; // true if collision happens. 
        }
        
    }
    return false; // false if collision doesnt happen.
    
}

// More methods to be added