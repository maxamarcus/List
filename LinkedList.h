#include "List.h"

// DEFINITIONS
template <class t>
struct node {
    t info;
    node * next;
};

template <class t>
class LinkedList : public List <t> {

public:

    // CONSTRUCTOR
    LinkedList();
    ~LinkedList();

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

    // MEMBER VARIABLES
    node <t> * list;
    node <t> * current;
    int length;
};



template <class t>
LinkedList <t> :: LinkedList() {
    this->list = nullptr;
    this->current = nullptr;
    this->length = 0;
}



template <class t>
LinkedList <t> :: ~LinkedList() {
    node <t> * ptr;
    while (this->list != nullptr) {
        ptr = this->list;
        this->list = this->list->next;
        delete ptr;
    }
}



template <class t>
void LinkedList <t> :: Put(t putMe) {
    /* Must first iterate linearly to determine that putMe is not already in list. After that, insertion time is constant. */
    if ( IsInList(putMe) ) {
        return;
    }
    node <t> * toAdd = new node <t>;
    toAdd->info = putMe;
    toAdd->next = this->list;
    this->list = toAdd;
    this->length ++;
}



template <class t>
int LinkedList <t> :: GetPositionOf(t findMe) {
    /* Linear iteration. */
    int position = -1;
    node <t> * scanner = this->list;
    for (int i = 0; i < this->length; i ++) {
        if (scanner->info == findMe) {
            position = i;
            break;
        }
        scanner = scanner->next;
    }
    return position;
}



template <class t>
bool LinkedList <t> :: IsInList(t findMe) {
    return (GetPositionOf(findMe) != -1);
}



template <class t>
void LinkedList <t> :: Remove(t removeMe) {
    /* Iterate linearly until the node after the current node matches removeMe. Because iteration focuses on the node after the current, the first list item is processed as a special case. */

    if (this->length == 0) {
        return;
    }

    node <t> * current = this->list;

    // Special case -- first item matches removeMe.
    if (current->info == removeMe) {
        node <t> * toDelete = this->list;
        this->list = this->list->next;
        delete toDelete;
        length --;
        return;
    }

    // Common case.
    while (current->next != nullptr) {

        // Condition -- node after current matches removeMe.
        if (current->next->info == removeMe) {
            node <t> * before = current;
            node <t> * toDelete = current->next;
            node <t> * after = toDelete->next;
            before->next = after;
            delete toDelete;
            length --;
            break;
        }
        
        current = current->next;
    }
}



template <class t>
int LinkedList <t> :: GetLength() {
    return this->length;
}



template <class t>
void LinkedList <t> :: ClearList() {
    /* Linear iteration. */
    node <t> * deleteMe = this->list;
    node <t> * deleteNext;
    while (deleteMe != nullptr) {
        deleteNext = deleteMe->next;
        delete deleteMe;
        deleteMe = deleteNext;
    }
    this->list = nullptr;
    this->length = 0;
}



template <class t>
void LinkedList <t> :: ResetList() {
    this->current = this->list;
}



template <class t>
t LinkedList <t> :: GetNext() {
    if (current == nullptr) {
        ResetList();
    }
    t output = current->info;
    current = current->next;
    return output;
}