#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include "persone.h"

#include <vector>

class FamilyTree
{
private:
	FamilyTree()
	{
	}

public:
	~FamilyTree();
	static FamilyTree* getInstance();
	void saveTree();
	void openTree(std::string& aFileName);
	void addNewPersone(Persone* aPersone);

private:
	static FamilyTree* mFamilyTree;
	std::vector<Persone*> mAllFamily;
};
#endif // FAMILYTREE_H
