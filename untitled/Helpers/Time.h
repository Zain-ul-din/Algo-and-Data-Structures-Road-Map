//
//
//

#ifndef Time_H
#define Time_H

#include <ctime>
#include "./Input.h"

// @ Custom Time Class
class Time {
public:

    /* Constructor */

    Time();
    Time(int year, int month, int day, int hour, int min, const string &monthName, const string &dayName);
    Time (string& time_str);
    /* Getter Setter */

    int getYear() const;
    void setYear(int year);
    int getMonth() const;
    void setMonth(int month);
    int getDay() const;
    void setDay(int day);
    int getHour() const;
    void setHour(int hour);
    int getMin() const;
    void setMin(int min);
    string getDayName() const;
    void setDayName(const string &dayName);
    string getMonthName() const;
    void setMonthName(const string &monthName);
    void setTimeStr();
    string getTimeStr() const;
    /* Helper */
    static Time ParseDate (string&);

    /* Operator Over Loading */

    bool operator==(const Time &rhs) const;
    bool operator!=(const Time &rhs) const;

    friend ostream &operator  << (ostream &os, const Time &time);
    friend ofstream &operator << (ofstream& outFile , const Time& time);

    static string daysName[7]; // to make comparison with std c++ time
    static string fullDaysName [7];

private:

    string timeStr;
    int year , month , day , hour , min;
    string monthName  , dayName;

      void DateInit ();
      static const string  monthsName[12];
      static int GetIdxOfMonth (string&);
};

string Time::daysName[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
string Time::fullDaysName[7] = {"Monday" , "Tuesday" , "Thursday" , "Friday" , "Saturday" , "Sunday"};

/* Constructor */

Time::Time() { this->DateInit(); }
Time::Time(string &time_str) { *this = ParseDate(time_str);}
Time::Time(int year, int month, int day, int hour, int min, const string &monthName, const string &dayName) :
year(year), month(month), day(day), hour(hour), min(min), monthName(monthName), dayName(dayName) {}

/* Getter Setter */

int Time::getYear() const { return year;}
void Time::setYear(int year) { this->year = year; this->setTimeStr();}
int Time::getMonth() const { return month; }
void Time::setMonth(int month) { this->month = month; this->setTimeStr();}
int Time::getDay() const { return day;}
void Time::setDay(int day) { this->day = day; this->setTimeStr();}
int Time::getHour() const { return hour;}
void Time::setHour(int hour) { this->hour = hour; this->setTimeStr();}
int Time::getMin() const { return min;}
void Time::setMin(int min) { this->min = min; this->setTimeStr();}
string Time::getDayName() const { return dayName;}
void Time::setDayName(const string &dayName) { this->dayName = dayName; this->setTimeStr();}
string Time::getMonthName() const { return monthName;}
void Time::setMonthName(const string &monthName) { this->monthName = monthName; this->setTimeStr();}
string Time::getTimeStr() const { return timeStr;}

ostream &operator<<(ostream &os, const Time &time) {
    os << "timeStr: " << time.timeStr << " year: " << time.year << " month: " << time.month << " day: " << time.day
    << " hour: " << time.hour << " min: " << time.min << " monthName: " << time.monthName << " dayName: "
    << time.dayName;
    return os;
}

/* Operator Over Loading */

ofstream &operator << (ofstream& outFile , const Time& time) {
    outFile << Replace(time.timeStr);
    return outFile;
}

const string Time::monthsName[12] =
        {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int Time::GetIdxOfMonth (string& monthName) {
    for (int  i = 0 ; i < 12 ; i += 1)
        if (monthName == monthsName[i]) return i + 1;
    return -1;
}

bool Time::operator==(const Time &rhs) const {
    return year == rhs.year &&
           month == rhs.month &&
           day == rhs.day &&
           hour == rhs.hour &&
           min == rhs.min;
}

bool Time::operator!=(const Time &rhs) const { return !(rhs == *this);}

/* Helper's */

void Time::DateInit () {
    time_t time_now;
    time(&time_now);
    this->timeStr = ctime(&time_now);
    *this = ParseDate(this->timeStr);
}

void Time::setTimeStr() {
     // Thu Jun 02 15:21:52 2022
     this->timeStr = this->dayName + " " + this->monthName + " " + to_string(this->month) + " " +
             to_string(this->hour) + ":" + to_string(this->min) + ":" + to_string(11)
      + " " +  to_string(this->year);
}

Time Time::ParseDate(string& timeStr) {

    string auxiliaryArray[5]; // Thu Jun 02 15:21:52 2022
    string auxiliaryArray1[3];

    {
        const char SEPARATOR = ' ';
        int idx = 0 ;
        for (int  i = 0 ; i < timeStr.length() ; i += 1)
            if (timeStr[i] == SEPARATOR) idx += 1;
            else auxiliaryArray[idx].push_back(timeStr[i]);
    }

    {
        const string auxStr = auxiliaryArray[3];
        const char SEPRATOR = ':';
        int idx = 0;
        for (int  i = 0 ; i < auxStr.length() ; i += 1)
            if (auxStr[i] == SEPRATOR) idx += 1;
            else auxiliaryArray1[idx].push_back(auxStr[i]);
    }

    return Time(
            stoi(auxiliaryArray[4]) ,
            GetIdxOfMonth(auxiliaryArray[1]),
            stoi(auxiliaryArray[2]) ,
            stoi(auxiliaryArray1[0]) ,
            stoi(auxiliaryArray1[1]) ,
            auxiliaryArray[1] ,
            auxiliaryArray[0]
    );
}




#endif //Time_H
