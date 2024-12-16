#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // direction states

        Player(GameMechs* thisGMRef, Food* foodref); // constructor with reference to gamemechs class and food class
        ~Player(); // deconstructor

        objPosArrayList* getPlayerPos() const; // Getter returning Array list of snakes position      
        void updatePlayerDir();
        void movePlayer();
        bool checkSelfCollision();

        // More methods to be added here

    private:
        objPosArrayList *playerPosList; // Reference to Snake Body (List )       
        enum Dir myDir;

        
        GameMechs* mainGameMechsRef; // Need a reference to the Main Game Mechanisms
        Food* mainFoodRef;

};

#endif