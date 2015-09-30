#ifndef PERSONE_H
#define PERSONE_H

#include <string>
#include <QString>

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

class Persone
{
public:
	Persone();
	~Persone();

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

	const Persone* getFather() const;
	void setFather(Persone* aPersone);

	const Persone *getMother() const;
	void setMother(Persone *aPersone);

private:
	Name mName;
	DateOfBirth mDateOfBirth;
	QString mJob;
	QString mBiography;
	Persone* mFather;
	Persone* mMother;
	bool mIsConnected;
	unsigned int mID;

private:
	static unsigned int ID;
};

#endif // PERSONE_H
