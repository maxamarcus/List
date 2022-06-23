#include "List.h"

template <class t>
class ArrayList : public List <t> {

public:

    // CONSTRUCTOR
    ArrayList(int);

    // CLASS METHODS
    virtual void Put(t);
    virtual int GetPositionOf(t);
    virtual bool IsInList(t);
    virtual void Remove(t);
    virtual int GetLength();
    virtual void ClearList();

    // ITERATORS
    virtual void ResetList();
    virtual t GetNext();

protected:

    // MEMBER VARIABLES:
    t * list;
    int length;
    int capacity;
    int current;

    // HELPER FUNCTIONS:
    bool IsFull() {return length == capacity;}
    void DoubleCapacity();
};








template <class t>
ArrayList <t> :: ArrayList(int arraySize) {
    this->capacity = arraySize;
    this->list = new t [arraySize];
    this->length = 0;
}



template <class t>
void ArrayList <t> :: Put(t putMe) {
    /* Iterate linearly to determine that putMe is not already in list. If list is full, then iterate linearly again to increase the capacity. */
    if ( IsInList(putMe) ) {
        return;
    }
    if ( IsFull() ) {
        DoubleCapacity();
    }
    this->list[this->length] = putMe;
    this->length ++;
}



template <class t>
int ArrayList <t> :: GetPositionOf(t findMe) {
    /* Linear iteration. */
    int position = -1;
    for (int i = 0; i < this->length; i ++) {
        if (this->list[i] == findMe) {
            position = i;
            break;
        }
    }
    return position;
}



template <class t>
bool ArrayList <t> :: IsInList(t findMe) {
    return (GetPositionOf(findMe) != -1);
}



template <class t>
void ArrayList <t> :: Remove(t removeMe) {
    /* Linear iteration. See GetPositionOf(). */
    int position = GetPositionOf(removeMe);
    if (position != -1) {
        this->list[position] = this->list[length - 1];
        length --;
    }
}



template <class t>
int ArrayList <t> :: GetLength() {
    return this->length;
}



template <class t>
void ArrayList <t> :: ClearList() {
    this->length = 0;
}



template <class t>
void ArrayList <t> :: ResetList() {
    this->current = -1;
}



template <class t>
t ArrayList <t> :: GetNext() {
    if (current < length - 1) {
        current ++;
        return this->list[current];
    }
    else {
        ResetList();
        return GetNext();
    }
}



template <class t>
void ArrayList <t> :: DoubleCapacity() {
    /* Linear iteration. */
    t * newList = new t [capacity * 2];
    for (int i = 0; i < capacity; i ++) {
        newList[i] = this->list[i];
    }
    delete this->list;
    this->list = newList;
    capacity *= 2;
}