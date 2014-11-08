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
    QFile file("tree.xml");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    Persone* p = mAllFamily.front();
    p->getName().mFirstName;
    out << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n";
    for (auto persone : mAllFamily)
    {
        out << "<persone>\n";
        out << "\t" << "<personeID>" << persone->getID() << "</personeID>" << "\n";
        out << "\t" << "<name>\n";
        out << "\t\t" << "<firstname>" << persone->getName().mFirstName << "</firstname>" << "\n";
        out << "\t\t" << "<middlename>" << persone->getName().mMiddleName << "</middlename>" << "\n";
        out << "\t\t" << "<lastname>" << persone->getName().mLastName << "</lastname>" << "\n";
        out << "\t" << "</name>\n";
        out << "\t" << "<dateofbirth>\n";
        out << "\t\t"<< "<day>" << QString::number(persone->getDateOfBirth().day) << "</day>" << "\n";
        out << "\t\t"<< "<month>" << QString::number(persone->getDateOfBirth().month) << "</month>" << "\n";
        out << "\t\t"<< "<year>" << QString::number(persone->getDateOfBirth().year) << "</year>" << "\n";
        out << "\t" << "</dateofbirth>\n";
        out << "\t" << "<job>" << persone->getJob() << "</job>" << "\n";
        out << "\t" << "<biography>" << persone->getBiography() << "</biography>" << "\n";
        out << "</persone>\n";



        //out << persone->toString() << "\n\n";
    }
    file.close();
}

void FamilyTree::addNewPersone(Persone *aPersone)
{
    mAllFamily.push_back(aPersone);
}
