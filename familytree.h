#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include <vector>
#include "persone.h"

class FamilyTree
{
private:
    FamilyTree()
    {
    }
public:
    ~FamilyTree();
    static FamilyTree* getInstance();

    void addNewPersone(Persone* aPersone);
private:
    static FamilyTree* mFamilyTree;
    std::vector<Persone*> mAllFamily;
};
#endif // FAMILYTREE_H
