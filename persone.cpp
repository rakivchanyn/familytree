#include "persone.h"

Persone::Persone() :
    mName(),
    mDateOfBirth(),
    mJob(""),
    mBiography(""),
    mFather(NULL),
    mMother(NULL),
    mIsConnected(false)
{
}

void Persone::setName(std::string aFirstName, std::string aMiddleName, std::string aLastName)
{
    mName.mFirstName = aFirstName;
    mName.mMiddleName = aMiddleName;
    mName.mLastName = aLastName;
}

void Persone::setDateOfBirst(int aDay, int aMonth, int aYear)
{
    mDateOfBirth.mDay = aDay;
    mDateOfBirth.mMonth = aMonth;
    mDateOfBirth.mYear = aYear;
}

void Persone::setJob(std::string aJob)
{
    mJob = aJob;
}

void Persone::setBiography(std::string aBiography)
{
    mBiography = aBiography;
}

QString Persone::toString()
{
    QString s("Ім'я: " + QString::fromStdString(mName.mFirstName));
    s += "\nПо-батькові: " + QString::fromStdString(mName.mMiddleName);
    s += "\nПрізвище: " + QString::fromStdString(mName.mLastName);
    s += "\nДата народження: " + QString::number(mDateOfBirth.mDay) + "." +
            QString::number(mDateOfBirth.mMonth) + "." + QString::number(mDateOfBirth.mYear);
    s += "\nОсновне місце роботи: " + QString::fromStdString(mJob);
    s += "\nБіографія: " + QString::fromStdString(mBiography);
    return s;
}
