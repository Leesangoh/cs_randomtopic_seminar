#ifndef SEPARATE_CHAINING_H
#define SEPARATE_CHAINING_H

#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

int hash2(const char *key);
int hash2(const string &key);
int hash2(int key);

int nextPrime(int n);

// SeparateChaining Hash table class
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
    explicit HashTable(int size = 101)
        : currentSize(0)
    {
        theLists.resize(101);
    }

    bool contains(const HashedObj &x) const
    {
        const list<HashedObj> &whichList = theLists[myhash(x)];
        return find(whichList.begin(), whichList.end(), x) != whichList.end();
    }

    void makeEmpty()
    {
        for (int i = 0; i < theLists.size(); i++)
            theLists[i].clear();
    }

    bool insert(const HashedObj &x)
    {
        // FILL THIS

        list<HashedObj> &temp = theLists[myhash(x)];

        if (find(temp.begin(), temp.end(), x) != temp.end())
            return false; // Already contained

        temp.push_front(x);

        if (currentSize + 1 > theLists.size())
        {
            currentSize += 1;
            rehash();
        }

        currentSize += 1;

        return true;
    }

    bool remove(const HashedObj &x)
    {
        // FILL THIS
        list<HashedObj> &temp = theLists[myhash(x)];

        auto pos = find(temp.begin(), temp.end(), x);

        if (pos == temp.end())
            return false; // Doesn't exist

        temp.erase(pos);
        currentSize = currentSize - 1;

        return true;
    }

private:
    vector<list<HashedObj>> theLists; // The array of Lists
    int currentSize;

    void rehash()
    {
        vector<list<HashedObj>> oldLists = theLists;

        // Create new double-sized, empty table
        theLists.resize(nextPrime(2 * theLists.size()));
        for (int j = 0; j < theLists.size(); j++)
            theLists[j].clear();

        // Copy table over
        currentSize = 0;
        for (int i = 0; i < oldLists.size(); i++)
        {
            typename list<HashedObj>::iterator itr = oldLists[i].begin();
            while (itr != oldLists[i].end())
                insert(*itr++);
        }
    }

    int myhash(const HashedObj &x) const
    {
        int hashVal = hash2(x);

        hashVal %= theLists.size();
        if (hashVal < 0)
            hashVal += theLists.size();

        return hashVal;
    }
};

#endif
