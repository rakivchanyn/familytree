
#include "familytree.h"
#include "rapidxml_1_13/rapidxml.hpp"

#include <sstream>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
FamilyTree* FamilyTree::mFamilyTree = NULL;

FamilyTree* FamilyTree::getInstance()
{
	if (mFamilyTree == NULL)
	{
		mFamilyTree = new FamilyTree();
	}
	return mFamilyTree;
}

void FamilyTree::saveTree(QString const & iSaveFileName)
{
	if (mAllFamily.empty())
		return;
	QFile file(iSaveFileName);
	file.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream out(&file);
	out.setCodec("UTF-8");

	PersonPtr p = mAllFamily.front();
	p->getName().mFirstName;
	out << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n";
	out << "<latestId>" << Person::getNextID() << "</latestId>\n";
	out << "<FAMILY>\n";
	for (auto person : mAllFamily)
	{
		out << "<persone>\n";
		out << "\t" << "<personeID>" << person->getID() << "</personeID>\n";
		out << "\t" << "<name>\n";
		out << "\t\t" << "<firstname>" << person->getName().mFirstName << "</firstname>\n";
		out << "\t\t" << "<middlename>" << person->getName().mMiddleName << "</middlename>\n";
		out << "\t\t" << "<lastname>" << person->getName().mLastName << "</lastname>\n";
		out << "\t" << "</name>\n";
		out << "\t" << "<dateofbirth>\n";
		out << "\t\t"<< "<day>" << QString::number(person->getDateOfBirth().day) << "</day>\n";
		out << "\t\t"<< "<month>" << QString::number(person->getDateOfBirth().month) << "</month>\n";
		out << "\t\t"<< "<year>" << QString::number(person->getDateOfBirth().year) << "</year>\n";
		out << "\t" << "</dateofbirth>\n";
		QString sex = person->getIsMale() ? "чоловік" : "жінка";
		out << "\t" << "<sex>" << sex << "</sex>\n";
		out << "\t" << "<job>" << person->getJob() << "</job>\n";
		out << "\t" << "<biography>" << person->getBiography() << "</biography>\n";
		out << "</persone>\n";



		//out << persone->toString() << "\n\n";
	}
	out << "</FAMILY>\n";
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

	rapidxml::xml_node<>* pRoot = doc.first_node();
//	pRoot->first_node("")
	rapidxml::xml_node<>* tempNode = NULL;
	for(rapidxml::xml_node<>* pNode = pRoot->first_node("persone"); pNode; pNode = pNode->next_sibling())
	{
		//TODO: make loop for automaticaly getting nodes and assine to persone
		tempNode = pNode->next_sibling();
		PersonPtr pers(new Person());
		if (tempNode != NULL)
		{
			pers->setID((unsigned int)(tempNode->value()));
		}
		mAllFamily.push_back(pers);
		pers = NULL;
	}
}

void FamilyTree::addNewPersone(PersonPtr aPersone)
{
	mAllFamily.push_back(aPersone);
}

std::vector<PersonPtr> &FamilyTree::getAllFamily()
{
	return mAllFamily;
}

PersonPtr FamilyTree::findPersonById(unsigned int iId)
{
	for (auto it : mAllFamily)
	{
		if (it->getID() == iId)
			return it;
	}
	return nullptr;
}
