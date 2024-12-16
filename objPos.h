#ifndef OBJPOS_H
#define OBJPOS_H
//Nabils Comment
// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos;        
        char symbol;

        objPos(); // constructor 
        objPos(int xPos, int yPos, char sym); // speical constructor 
        
        // Respect the rule of six / minimum four
        // [TODO] Implement the missing special member functions to meet the minimum four rule

        ~objPos(); // deconstructor 
        objPos(const objPos& other);
        objPos& operator=(const objPos& other);

        //setters
        void setObjPos(objPos o);   
        void setObjPos(int xPos, int yPos, char sym);  

        //getters
        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        //bool
        bool isPosEqual(const objPos* refPos) const;

        //getters
        int getX() const { return pos->x; }
        int getY() const { return pos->y; }
};

#endif