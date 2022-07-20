#include "LinkedList.h"

template <class t>
class LinkedListSorted : public LinkedList <t> {

public:

    // CONSTRUCTOR
    LinkedListSorted();

    // CLASS METHODS
    virtual void Put(t);
    virtual int GetPositionOf(t);
    virtual bool IsInList(t);
    virtual void Remove(t);
};



template <class t>
LinkedListSorted <t> :: LinkedListSorted() : LinkedList <t>() {}



template <class t>
void LinkedListSorted <t> :: Put(t putMe) {
    /* Core algorithm iterates linearly through the linked list until the node after the current node is larger than putMe, then inserts putMe between the current node and the next.
    If the node after the current matches putMe, then putMe is already in the list, so the function exits.
    If the node after the current is null, then the iteration has reached the end of the list without finding a node with a value larger than putMe, and so putMe is placed at the end of the list. 
    Because iteration focuses on the node after current, the first node of the list is processed as a special case. */

    node <t> * toPut = new node <t>;
    toPut->info = putMe;
    toPut->next = nullptr;

    node <t> * current = this->list;

    // Special case -- list is empty, or first list item is greater than putMe.
    if (current == nullptr or current->info > putMe) {
        toPut->next = this->list;
        this->list = toPut;
        this->length ++;
        return;
    }

    // Special case -- first node matches putMe.
    if (current->info == putMe) {
        delete toPut;
        return;
    }

    // Common case -- linear iteration.
    while (current != nullptr) {

        // Condition -- Next node is null, so there is no list element larger than putMe, so putMe goes at the end of the list.
        if (current->next == nullptr) {
            current->next = toPut;
            this->length ++;
            return;
        }

        // Condition -- Next node's value is larger than putMe, so putMe goes between current and next nodes.
        if (current->next->info > putMe) {
            toPut->next = current->next;
            current->next = toPut;
            this->length ++;
            return;
        }

        // Condition -- Next node matches putMe, so function exits.
        if (current->next->info == putMe) {
            delete toPut;
            return;
        }

        current = current->next;
    }
}



template <class t>
int LinkedListSorted <t> :: GetPositionOf(t findMe) {
    /* Iterate linearly until hitting findMe. If findMe is not in list, position value stays at default -1.
    This implementation is different from the standard (unsorted) LinkedList because it can determine that findMe is not in the list if iteration hits a value larger than findMe, and then exit the function without iterating through the entire list. */
    int position = -1;
    node <t> * scanner = this->list;
    int counter = 0;
    while (scanner != nullptr) {
        if (scanner->info > findMe) {
            break;
        }
        if (scanner->info == findMe) {
            position = counter;
            break;
        }
        scanner = scanner->next;
        counter ++;
    }
    return position;
}



template <class t>
bool LinkedListSorted <t> :: IsInList(t findMe) {
    return (GetPositionOf(findMe) != -1);
}



template <class t>
void LinkedListSorted <t> :: Remove(t removeMe) {
    /* Core algorithm iterates linearly through the linked list until the node after the current node matches removeMe.
    If the node after current is null or its value is larger than removeMe, then removeMe is not in the list, and so the function exits.
    Because the iteration focuses on the node after current, the first node is processed as a special case. */

    node <t> * current = this->list;

    // Special case -- first node indicates that removeMe is not in list.
    if (current == nullptr or current->info > removeMe) {
        return;
    }

    // Special case -- first node matches removeMe.
    if (current->info == removeMe) {
        this->list = this->list->next;
        delete current;
        this->length --;
        return;
    }

    // Common case.
    while (current != nullptr) {

        // Condition -- next node indicates that removeMe is not in list.
        if (current->next == nullptr or current->next->info > removeMe) {
            return;
        }

        // Condition -- next node matches removeMe.
        if (current->next->info == removeMe) {
            node <t> * toRemove = current->next;
            node <t> * before = current;
            node <t> * after = toRemove->next;
            delete toRemove;
            before->next = after;
            this->length --;
            return;
        }

        current = current->next;
    }
}