#include <stdio.h>
#include "MacUILib.h"

// PPA2 GOAL: 
//       Construct the game backbone where the player can control an object 
//       to move freely in the game board area with border wraparound behaviour.

// Watch Briefing Video and Read Lab Manual before starting on the activity!



// PREPROCESSOR CONSTANTS DEFINITION HERE
/////////////////////////////////////////



// GLOBAL VARIABLE DEFINITION HERE
/////////////////////////////////////////

int exitFlag; // Program Exiting Flag - old stuff
int R, C, i, v;

// For storing the user input - from PPA1
char input;
    

// [TODO] : Define objPos structure here as described in the lab document

    struct objPos 
    {
        int x; 
        int y; 
        char symbol;
    };
    struct objPos start;

// [TODO] : Define the Direction enumeration here as described in the lab document
//          This will be the key ingredient to construct a simple Finite State Machine
//          For our console game backbone.

enum Direction {

    UP,   // 0
    DOWN, // 1
    LEFT, // 2
    RIGHT, // 3
    STOP, //4
    
} direction;
    


// FUNCTION PROTOTYPING DEFINITION HERE
/////////////////////////////////////////

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

// You may insert additional helper function prototypes below.
// 
// As a good practice, always insert prototype before main() and implementation after main()
// For ease of code management.



// MAIN PROGRAM LOOP
/////////////////////////////////////////
// This part should be intuitive by now.
// DO NOT TOUCH

int main(void)
{

    Initialize();

    while(!exitFlag)  
    {
        GetInput();

        RunLogic();

        DrawScreen();

        LoopDelay();
    }

    CleanUp();

}


// INITIALIZATION ROUTINE
/////////////////////////////////////////
void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();



   i = 500000;
   v = 1;

    input = 0; // NULL
    exitFlag = 0;  // not exiting    
   
    // [TODO] : Initialize more variables here as seen needed.
    //          PARTICULARLY for the structs!!

    start.x=9;
    start.y=4;
    start.symbol = '@';

    direction = STOP;

    // direction = LEFT;

}


// INPUT PROCESSING ROUTINE
/////////////////////////////////////////
void GetInput(void)
{
    // [TODO] : Implement Asynchronous Input - non blocking character read-in    
    //          (Same as PPA1)

    if (MacUILib_hasChar()) {

        input = MacUILib_getChar();
        

    }


    

    }



// PROGRAM LOGIC ROUTINE
/////////////////////////////////////////
void RunLogic(void)
{
    // [TODO] : First, process the input by mapping
    //          WASD to the corresponding change in player object movement direction

 

    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case '`':  // exit
                exitFlag = 1;
                break;
            case 'w':
                if(direction !=DOWN) {direction = UP;}
                break; 
            case 'a':
                if(direction !=RIGHT) {direction = LEFT;}
                break;
            case 's': 
                if(direction !=UP) {direction = DOWN;}
                break;
            case 'd': 
                if(direction !=LEFT) {direction = RIGHT;}
                break;

            // Add more key processing here
            // Add more key processing here
            // Add more key processing here    
            
            case '1':
                i = 500000;
                v = 1;
                break;
            case '2':
                i = 400000;
                v = 2;
                break;
            case '3':
                i = 300000;
                v = 3;
                break;
            case '4':
                i = 200000;
                v = 4;
                break;
            case '5':
                i = 100000;
                v = 5;
                break;
            
            
            
            
            
            default:
                break;
        }
        input = 0;
    

    
   
    }    



    // [TODO] : Next, you need to update the player location by 1 unit 
    //          in the direction stored in the program
    
   switch(direction) {

        case LEFT:
            start.x--;
            if (start.x == 0) {start.x = 18;}
            break;
        case RIGHT:
            start.x++; 
            if (start.x == 19) {start.x = 1;}
            break;
        case UP:
            start.y--; 
            if (start.y == 0) {start.y = 8;}
            break;
       case DOWN: 
            start.y++;
            if (start.y == 9) {start.y = 1;}
            break;
        case STOP:
        default:
            start.y = 4;
            start.x = 9;
            break;
    }


    // [TODO] : Heed the border wraparound!!!

    

}



// SCREEN DRAWING ROUTINE
/////////////////////////////////////////
void DrawScreen(void)
{
MacUILib_clearScreen();
for (R=0; R<10; R++) {
    if (R==0||R==9){MacUILib_printf("####################\n");}   
    else {
        for(C=0; C<20; C++) {
            if(C==0) {MacUILib_printf("#");}
            else if(C==19) {MacUILib_printf("#\n");}
            else if(R==start.y && C==start.x) {MacUILib_printf("%c",start.symbol);}
            else {MacUILib_printf(" ");}

        }
    }
}

MacUILib_printf("Choose a speed from 1-5\nPress ` to Quit.\nSpeed:%d", v);


    

    // [TODO] : Implement the latest drawing logic as described in the lab manual
    //
    //  1. clear the current screen contents

    //  2. Iterate through each character location on the game board
    //     using the nested for-loop row-scanning setup.

    //  3. For every visited character location on the game board
    //          If on border on the game board, print a special character
    //          If at the player object position, print the player symbol
    //          Otherwise, print the space character
    //     Think about how you can format the screen contents to achieve the
    //     same layout as presented in the lab manual

    //  4. Print any debugging messages as seen needed below the game board.
    //     As discussed in class, leave these debugging messages in the program
    //     throughout your dev process, and only remove them when you are ready to release
    //     your code. 

   


}



// PROGRAM LOOOP DELAYER ROUTINE
/////////////////////////////////////////
void LoopDelay(void)
{
    // Change the delaying constant to vary the movement speed.
    MacUILib_Delay(i);    
}



// PROGRAM CLEANUP ROUTINE
/////////////////////////////////////////
// Recall from PPA1 - this is run only once at the end of the program
// for garbage collection and exit messages.
void CleanUp(void)
{
    MacUILib_uninit();
}


