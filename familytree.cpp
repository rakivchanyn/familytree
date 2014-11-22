#include <sstream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include "familytree.h"
#include "rapidxml_1_13/rapidxml.hpp"

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

void FamilyTree::openTree(std::string& aFileName)
{
    std::ifstream inf;
    inf.open(aFileName.c_str());
    if (!inf.is_open())
    {
        //QMessageBox::information(this, "Info", "No such file to read");
        return;
    }
    std::stringstream buffer;
    buffer << inf.rdbuf();
    inf.close();
    std::string content = std::string(buffer.str());
    rapidxml::xml_document<> doc;
    doc.parse<0>(&content[0]);

    xml_node<>* pRoot = doc.first_node();
//    xml_node<>* pNode1 = pRoot->first_node();
//    for(xml_node<>* pNode = pNode1->first_node(); pNode; pNode=pNode->next_sibling())
//    {
//        mHeaderNames.push_back(pNode->name());
//    }
//    std::vector<std::string> cd;
//    cd.reserve(mHeaderNames.size());
//    xml_node<>* pRoot = mDoc.first_node();
//    xml_node<>* tempNode = NULL;
//    for(xml_node<>* pNode= pRoot->first_node(mCDTagName.c_str()); pNode; pNode=pNode->next_sibling())
//    {
//        for(auto it : mHeaderNames)
//        {
//            tempNode = pNode->first_node(it.c_str());
//            if (tempNode != NULL)
//            {
//                cd.push_back(tempNode->value());
//            }
//        }
//        std::lock_guard<std::mutex> lk(mMutex);
//        mCDInfo.push(cd);
//        cd.clear();
//        mCond.notify_one();
//    }
//    std::lock_guard<std::mutex> lk(mMutex);
//    mIsFileEnded = true;
//    mCond.notify_one();
}

void FamilyTree::addNewPersone(Persone *aPersone)
{
    mAllFamily.push_back(aPersone);
}
