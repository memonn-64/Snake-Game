#include "objPos.h"

objPos::objPos() //default constructor 
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; 
}

objPos::objPos(int xPos, int yPos, char sym) // special constructor with specific x y and symbol
{
    pos = new Pos; // allocate pos Object
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule


objPos::~objPos() //deconstruct to delete heap memory . 
{
    delete pos; //free the memory
}

objPos::objPos(const objPos& other)
{
    if (other.pos)
    {
        pos = new Pos{*other.pos}; 
    }
    else
    {
        pos = nullptr;
    }
    symbol = other.symbol;
}


objPos& objPos::operator=(const objPos& other) //copy constructor
{
    if (this == &other) // check for self assigment
        return *this; 
    delete pos; // deleter current pos Object
    if (other.pos) // Deep copy of Pos object
    {
        pos = new Pos{*other.pos};
    }
    else
    {
        pos = nullptr; // set pos to null if no valid pos
    }
    symbol = other.symbol; // copy symbol

    return *this; // return object
}


void objPos::setObjPos(objPos o) // setting object position using another objpos object
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym) // setting position using specific x, y and symbol
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const // getter for objpos object
{
    objPos returnPos; // returns copy of objpos
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const // getter for symbol
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const 
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y); // checks if objpos (x,y coordinate)is equal referenced objectpos (input) 
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos)) // if x,y coordinate is equal to reference objpos then returns symbol
        return symbol;
    else
        return 0;
}