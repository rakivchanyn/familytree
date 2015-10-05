#include "person.h"

typedef std::shared_ptr<Person> PersonPtr;

unsigned int Person::ID = 0;

Person::Person() :
	mName(),
	mDateOfBirth(),
	mJob(""),
	mBiography(""),
	mFather(NULL),
	mMother(NULL),
	mIsConnected(false),
	mID(ID++),
	mIsMale(true)
{
}

QString Person::toString()
{
	QString s("Ім'я: " + mName.mFirstName);
	s += "\nПо-батькові: " + mName.mMiddleName;
	s += "\nПрізвище: " + mName.mLastName;
	s += "\nДата народження: " + QString::number(mDateOfBirth.day) + "." +
			QString::number(mDateOfBirth.month) + "." + QString::number(mDateOfBirth.year);
	s += "\nОсновне місце роботи: " + mJob;
	s += "\nБіографія: " + mBiography;
	return s;
}

const Name& Person::getName()
{
	return mName;
}

void Person::setName(QString aFirstName, QString aMiddleName, QString aLastName)
{
	mName.mFirstName = aFirstName;
	mName.mMiddleName = aMiddleName;
	mName.mLastName = aLastName;
}

unsigned int Person::getID() const
{
	return mID;
}

void Person::setID(unsigned int aID)
{
	mID = aID;
}

const Name& Person::getName() const
{
	return mName;
}

const DateOfBirth& Person::getDateOfBirth() const
{
	return mDateOfBirth;
}

void Person::setDateOfBirth(const DateOfBirth& aDateOfBirth)
{
	mDateOfBirth = aDateOfBirth;
}

void Person::setDateOfBirth(int aDay, int aMonth, int aYear)
{
	mDateOfBirth.day = aDay;
	mDateOfBirth.month = aMonth;
	mDateOfBirth.year = aYear;
}

const QString& Person::getJob() const
{
	return mJob;
}

void Person::setJob(const QString& aJob)
{
	mJob = aJob;
}

const QString& Person::getBiography() const
{
	return mBiography;
}

void Person::setBiography(const QString& aBiography)
{
	mBiography = aBiography;
}

const PersonPtr Person::getFather() const
{
	return mFather;
}

void Person::setFather(PersonPtr aPersone)
{
	mFather = aPersone;
}

const PersonPtr Person::getMother() const
{
	return mMother;
}

void Person::setMother(PersonPtr aPersone)
{
	mMother = aPersone;
}
bool Person::getIsMale() const
{
	return mIsMale;
}

void Person::setIsMale(bool value)
{
	mIsMale = value;
}

