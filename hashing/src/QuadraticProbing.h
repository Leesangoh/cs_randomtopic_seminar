#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <vector>
#include <string>
using namespace std;

int nextPrime(int n);

int hash2(const char *key);
int hash2(const string &key);
int hash2(int key);

// QuadraticProbing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hash2( string str ) --> Global method to hash strings

template <typename HashedObj>
class HashTable
{
public:
    explicit HashTable(int size = 101) : array(nextPrime(size))
    {
        makeEmpty();
    }

    bool contains(const HashedObj &x) const
    {
        return isActive(findPos(x));
    }

    void makeEmpty()
    {
        currentSize = 0;
        for (int i = 0; i < array.size(); i++)
            array[i].info = EMPTY;
    }

    bool insert(const HashedObj &x)
    {
        // FILL THIS
        //

        int pos = myhash(x);
        int initial_pos = pos;

        for (int i = 1; array[pos].info == ACTIVE && array[pos].element != x; i++) // "deleted" flag를 만나도 거기엔 insert 할 수 있도록 해야한다.
        {
            pos = pos + i * i;
            if (pos > array.size() - 1)
                pos = pos - array.size();

            if (pos == initial_pos) // infinite loop 방지.. 그럴일은 없나? rehash덕분에 없을 것 같기도 하고
                break;
        }

        if (isActive(pos)) // the same key entered
            return false;

        array[pos].info = ACTIVE;
        array[pos].element = x;

        if (currentSize + 1 > array.size() / 2) // 늘어난 사이즈가 절반보다 커진다면 rehash
            rehash();
        else
            currentSize++;

        return true;
    }

    bool remove(const HashedObj &x)
    {
        // FILL THIS
        //

        int pos = findPos(x);

        if (!isActive(pos)) // delete하려는데 delete 되어있음
            return false;

        array[pos].info == DELETED;
        return true;
    }

    enum EntryType
    {
        ACTIVE,
        EMPTY,
        DELETED
    };

private:
    struct HashEntry
    {
        HashedObj element;
        EntryType info;

        HashEntry(const HashedObj &e = HashedObj(), EntryType i = EMPTY)
            : element(e), info(i) {}
    };

    vector<HashEntry> array;
    int currentSize;

    bool isActive(int currentPos) const
    {
        return array[currentPos].info == ACTIVE;
    }

    int findPos(const HashedObj &x) const // need quadratic probing, but skips "deleted" flag (so we can't use this function in "insert" function)
    {
        int pos = myhash(x);
        int initial_pos = pos;

        for (int i = 1; array[pos].info != EMPTY && array[pos].element != x; i++)
        {
            pos = pos + i * i;
            if (pos > array.size() - 1)
                pos = pos - array.size();

            if (pos == initial_pos) // infinite loop 방지.. 그럴일은 없나? rehash덕분에 없을 것 같기도 하고
                break;
        }

        return pos;
    }

    void rehash()
    {
        vector<HashEntry> oldArray = array;

        // Create new double-sized, empty table
        array.resize(nextPrime(2 * oldArray.size()));
        for (int j = 0; j < array.size(); j++)
            array[j].info = EMPTY;

        // Copy table over
        currentSize = 0;
        for (int i = 0; i < oldArray.size(); i++)
            if (oldArray[i].info == ACTIVE)
                insert(oldArray[i].element);
    }
    int myhash(const HashedObj &x) const
    {
        int hashVal = hash2(x);

        hashVal %= array.size();
        if (hashVal < 0)
            hashVal += array.size();

        return hashVal;
    }
};

#endif
