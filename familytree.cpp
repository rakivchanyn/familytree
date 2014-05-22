#include "familytree.h"

FamilyTree* FamilyTree::mFamilyTree = NULL;
FamilyTree* FamilyTree::getInstance()
{
    if (mFamilyTree == NULL)
    {
        mFamilyTree = new FamilyTree();
    }
    return mFamilyTree;
}

void FamilyTree::addNewPersone(Persone *aPersone)
{
    mAllFamily.push_back(aPersone);
}
