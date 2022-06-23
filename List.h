// List ABC

// Members do not repeat. All list items have distinct key values.

template <class t>
class List {
public:

    // CLASS METHODS
    virtual void Put(t) = 0;
    // Implementation must not allow adding more than one of an item.
    virtual int GetPositionOf(t) = 0;
    // Return -1 (invalid value) if argument is not in list.
    virtual bool IsInList(t) = 0;
    virtual void Remove(t) = 0;
    virtual int GetLength() = 0;
    virtual void ClearList() = 0;

    // ITERATORS
    virtual void ResetList() = 0;
    // Set current position before first item.
    virtual t GetNext() = 0; 
    // Advance current position, return the item.
};