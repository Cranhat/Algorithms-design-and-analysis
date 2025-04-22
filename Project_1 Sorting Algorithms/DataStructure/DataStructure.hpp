#pragma once

class DataStructure{
    public:

    DataStructure();

    virtual void printElements();

    virtual void addFront(int value); 

    virtual void addBack(int value);

    virtual void addIndex(int value, int index);

    virtual void deleteIndex(int index);

    virtual void deleteFront();

    virtual void deleteBack();

    virtual bool contains(int value);
    
    virtual int getSize();

    virtual int firstElement();
    
    virtual int lastElement();

    virtual void clear();

    virtual void sort();

};