#include "persone.h"

unsigned int Persone::ID = 0;

Persone::Persone() :
    mName(),
    mDateOfBirth(),
    mJob(""),
    mBiography(""),
    mFather(NULL),
    mMother(NULL),
    mIsConnected(false),
    mID(ID++)
{
}

QString Persone::toString()
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

const Name& Persone::getName()
{
    return mName;
}

void Persone::setName(QString aFirstName, QString aMiddleName, QString aLastName)
{
    mName.mFirstName = aFirstName;
    mName.mMiddleName = aMiddleName;
    mName.mLastName = aLastName;
}

unsigned int Persone::getID() const
{
    return mID;
}

const Name& Persone::getName() const
{
    return mName;
}

const DateOfBirth& Persone::getDateOfBirth() const
{
    return mDateOfBirth;
}

void Persone::setDateOfBirth(const DateOfBirth& aDateOfBirth)
{
    mDateOfBirth = aDateOfBirth;
}

void Persone::setDateOfBirth(int aDay, int aMonth, int aYear)
{
    mDateOfBirth.day = aDay;
    mDateOfBirth.month = aMonth;
    mDateOfBirth.year = aYear;
}

const QString& Persone::getJob() const
{
    return mJob;
}

void Persone::setJob(const QString& aJob)
{
    mJob = aJob;
}

const QString& Persone::getBiography() const
{
    return mBiography;
}

void Persone::setBiography(const QString& aBiography)
{
    mBiography = aBiography;
}

const Persone* Persone::getFather() const
{
    return mFather;
}

void Persone::setFather(Persone* aPersone)
{
    mFather = aPersone;
}

const Persone* Persone::getMother() const
{
    return mMother;
}

void Persone::setMother(Persone* aPersone)
{
    mMother = aPersone;
}
