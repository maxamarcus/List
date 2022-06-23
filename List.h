// List ABC

/* Every list element has a unique key value. This is enforced in the implementations. */

template <class t>
class List {
public:

    // CLASS METHODS
    virtual void Put(t) = 0;
    /* Implementation must not allow adding more than one of an item. */
    virtual int GetPositionOf(t) = 0;
    /* Return -1 (invalid value) if argument is not in list. */
    virtual bool IsInList(t) = 0;
    virtual void Remove(t) = 0;
    virtual int GetLength() = 0;
    virtual void ClearList() = 0;

    // ITERATORS
    virtual void ResetList() = 0;
    /* Set current position before first item. Use this before iterating, so that GetNext() returns the first item. */
    virtual t GetNext() = 0; 
    /* The "next" list item after the last list item is the first list item -- ie, list can iterate circularly. */
};
