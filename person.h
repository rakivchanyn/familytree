#ifndef PERSONE_H
#define PERSONE_H

#include <string>
#include <QString>
#include <memory>

struct DateOfBirth
{
	DateOfBirth()
	{
		day = 0;
		month = 0;
		year = 0;
	}

	int day;
	int month;
	int year;
};

struct Name
{
	QString mFirstName;
	QString mMiddleName;
	QString mLastName;
};

class Person
{

	typedef std::shared_ptr<Person> PersonPtr;

public:
	Person();
	~Person(){}

	QString toString();

	unsigned int getID() const;
	void setID(unsigned int aID);

	const Name& getName() const;
	void setName(QString aFirstName, QString aMiddleName, QString aLastName);  const Name& getName();

	const DateOfBirth& getDateOfBirth() const;
	void setDateOfBirth(const DateOfBirth& aDateOfBirth);
	void setDateOfBirth(int aDay, int aMonth, int aYear);

	const QString& getJob() const;
	void setJob(const QString& aJob);

	const QString& getBiography() const;
	void setBiography(const QString &value);

	const PersonPtr getFather() const;
	void setFather(PersonPtr aPersone);

	const PersonPtr getMother() const;
	void setMother(PersonPtr aPersone);

	bool getIsMale() const;
	void setIsMale(bool value);

	static void setNextID(unsigned int iID);
	static unsigned int getNextID();

private:
	Name mName;
	DateOfBirth mDateOfBirth;
	QString mJob;
	QString mBiography;
	PersonPtr mFather;
	PersonPtr mMother;
	bool mIsConnected;
	unsigned int mID;
	bool mIsMale;

private:
	static unsigned int sID;
};

#endif // PERSONE_H
