#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include "person.h"

#include <vector>
#include <memory>

typedef std::shared_ptr<Person> PersonPtr;

class FamilyTree
{
private:
	FamilyTree()
	{
	}

public:
	~FamilyTree();
	static FamilyTree* getInstance();
	void saveTree(const QString &iSaveFileName);
	void openTree(std::string& aFileName);
	void addNewPersone(PersonPtr aPersone);
	std::vector<PersonPtr>& getAllFamily();
	PersonPtr findPersonById(unsigned int iId);

private:
	static FamilyTree* mFamilyTree;
	std::vector<PersonPtr> mAllFamily;
};
#endif // FAMILYTREE_H
