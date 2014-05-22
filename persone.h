#ifndef PERSONE_H
#define PERSONE_H

#include <string>
#include <QString>

struct DateOfBirth
{
    DateOfBirth()
    {
        mDay = 0;
        mMonth = 0;
        mYear = 0;
    }

    int mDay;
    int mMonth;
    int mYear;
};

struct Name
{
    std::string mFirstName;
    std::string mMiddleName;
    std::string mLastName;
};

class Persone
{
public:
    Persone();
    ~Persone();
    void setName(std::string aFirstName, std::string aMiddleName, std::string aLastName);
    void setDateOfBirst(int aDay, int aMonth, int aYear);
    void setJob(std::string aJob);
    void setBiography(std::string aBiography);
    QString toString();

private:
    Name mName;
    DateOfBirth mDateOfBirth;
    std::string mJob;
    std::string mBiography;
    Persone* mFather;
    Persone* mMother;
    bool mIsConnected;
};

#endif // PERSONE_H
