#ifndef PERSONE_H
#define PERSONE_H

#include <string>

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

class Persone
{
public:
    Persone();
    ~Persone();

    void setDateOfBirst(int aDay, int aMonth, int aYear);
    void setJob(std::string& aJob);
    void setBiography(std::string& aBiography);

private:
    DateOfBirth mDateOfBirth;
    std::string mJob;
    std::string mBiorgaphy;
    Persone* mMother;
    Persone* mFather;
    bool mIsConnected;
};

#endif // PERSONE_H
