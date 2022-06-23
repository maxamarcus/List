#include "ArrayList.h"

template <class t>
class ArrayListSorted : public ArrayList <t> {

public:

    // CONSTRUCTOR
    ArrayListSorted(int);

    // CLASS METHODS
    virtual void Put(t);
    virtual int GetPositionOf(t);
    virtual bool IsInList(t);
    virtual void Remove(t);
};






template <class t>
ArrayListSorted <t> :: ArrayListSorted(int arraySize) : ArrayList <t> (arraySize) {}



template <class t>
void ArrayListSorted <t> :: Put(t putMe) {
    /* Core algorithm uses binary search to determine the insertion location, then iterates linearly to make room for putMe.
    Although the computation time is effectively linear, the binary search still gives a speed boost in most cases, and never causes significant slowdown.
    The insertion location putHere must be set to the index number of the smallest list item that is still larger than putMe. To do this via binary search, putHere is initialized to the last index of the array, and then reassigned whenever the binary search hits a list item that is larger than putHere.
    If the binary search finds putMe in the list, the function exits.
    This binary search algorithm doesnt work if no list items is larger than putMe. So this is treated as a special case. */

    int first = 0;
    int last = this->length - 1;
    int putHere;

    // Special case -- no item in the list is larger than putMe, so binary search cannot determine the location of putHere.
    if (putMe > this->list[last]){
        putHere = this->length;
        // In this case, putHere is necessarily the end of the list.
    }

    // Common case -- at least one item in the list is greater than putMe, so binary search works.
    else {
        int mid;
        putHere = last;
        // putHere starts at the end of the array, and is reassigned whenever binary search hits a list item that is larger than putMe.
        while (first <= last) {
            mid = (first + last) / 2;

            // Condition -- binary search finds putMe already in list, so function exits.
            if (this->list[mid] == putMe) {
                return;
            }

            // Binary search continues otherwise.
            if (this->list[mid] > putMe) {
                last = mid - 1;
                putHere = mid;
            }
            if (this->list[mid] < putMe) {
                first = mid + 1;
            }
        }
    }

    // Before inserting, check IsFull:
    if (this->IsFull()) {
        this->DoubleCapacity();
    }
    // Make room at putHere:
    for (int i = this->length; i > putHere; i --) {
        this->list[i] = this->list[i-1];
    }
    // Put putMe at putHere:
    this->list[putHere] = putMe;
    this->length ++;
}



template <class t>
int ArrayListSorted <t> :: GetPositionOf(t findMe) {
    /* Logarithmic binary search. */
    int position = -1;
    int first = 0;
    int last = this->length - 1;
    int mid;
    while (first <= last) {
        mid = (first + last) / 2;
        if (findMe == this->list[mid]) {
            position = mid;
            break;
        }
        if (findMe < this->list[mid]) {
            last = mid - 1;
        }
        if (findMe > this->list[mid]) {
            first = mid + 1;
        }
    }
    return position;
}



template <class t>
bool ArrayListSorted <t> :: IsInList(t findMe) {
    return (GetPositionOf(findMe) != -1);
}



template <class t>
void ArrayListSorted <t> :: Remove(t removeMe) {
    /* Linear iteration, although the logarithmic sub-process GetPositionOf() gives a speed boost over a fully linear process. */
    int position = GetPositionOf(removeMe);
    if (position != -1) {
        for(int i = position + 1; i < this->length; i ++) {
            this->list[i - 1] = this->list[i];
        }
        this->length --;
    }
}