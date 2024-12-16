#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"



class Food{
    private:
        objPos foodPos; //ObjPos of food         
        GameMechs* gameMechsRef; //pointer reference to gamemechs class


    public:
        Food(GameMechs* thisGMRef); //Constructor
        ~Food(); // decontructor                    
        void generateFood(objPosArrayList* playerPosList); //function generating food @ random location.
        objPos getFoodPos() const; // Getter function return objpos of food. 


};

#endif
