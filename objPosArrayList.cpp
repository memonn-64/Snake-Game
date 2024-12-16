#include "objPosArrayList.h"
#include "objPos.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList() //default constructor with new heap memory allocation 
{
    listSize = 0;
    arrayCapacity = 200;
    aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList() // deleting the memory allocation 
{
    delete[] aList;
}

int objPosArrayList::getSize() const // return size of list
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize >= arrayCapacity) // check is list is not full already
    {
        return;
    }   

    listSize++; // increase size of list in order to shift everything towards the tail

    for (int i = listSize; i > 0; i--) // shifting elements towards tail
    {
        aList[i] = aList[i-1];
    }
    
    aList[0] = thisPos;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize >= arrayCapacity) // check is list is not full already
    {
        return;
    }

    aList[listSize++] = thisPos;  // add element to list and increase list size
}

void objPosArrayList::removeHead()
{
    if (listSize <= 0) // Do nothing if list is already empty
    {
        return;
    }
    

    for (int i = 0; i < listSize; i++) // shift everything towards the head
    {
        aList[i] = aList[i+1];
    }
    
    listSize--; //decrease list size
}

void objPosArrayList::removeTail() //
{
    if (listSize > 0) //check is list is big enough to remove tail
    {
        listSize--;
    }

    else // if already too small does nothing
    {
        return;
    }
}

objPos objPosArrayList::getHeadElement() const // simple
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const //simple
{
    return aList[listSize-1];   //listSize to account for the index (0 index).
}

objPos objPosArrayList::getElement(int index) const
{
    if(index >= arrayCapacity) //returns last element if index given is bigger than list size
    {
        return aList[listSize-1];
    }

    else if(index < 0) // returns head element if index given is less than 0.
    {
        return aList[0];
    }
    else // return element @ index given.
    {
    return aList[index];
    }
}