#include <QFile>
#include <QTextStream>

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

void FamilyTree::saveTree()
{
    QFile file("tree.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    for (auto persone : mAllFamily)
    {
        out << persone->toString() << "\n\n";
    }
    file.close();
}

void FamilyTree::addNewPersone(Persone *aPersone)
{
    mAllFamily.push_back(aPersone);
}
