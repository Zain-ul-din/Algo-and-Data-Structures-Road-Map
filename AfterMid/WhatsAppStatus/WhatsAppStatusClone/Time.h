//
// Custom Time Class
//

#ifndef CUSTOM_TIME_H
#define CUSTOM_TIME_H


#if __cplusplus < 201103L
#error  "You need to install c++ 11 to run this Program __ embarcadero.com/free-tools/dev-cpp"
#endif

#include<iostream>
#include<string>
#include<vector>
#include<ctime>


using namespace std;


#define STD_TIME_INTERVAL 12

class Time{
public:
    Time(){
        string cTime;
        time_t timeNow;
        time(&timeNow); // set time to Now
        cTime = ctime(&timeNow);
        StrToTime(cTime);
    }

    string day , month , interval;
    int date{} , hour{} , min{} , sec{} , year{};
    const int PROPSCOUNT = 7;

    friend ostream& operator << (ostream& out , const Time& time){
        out <<time.hour<<"H"<<" : "<<time.min<<"min"<<" - "<<time.interval<<"  ''"<<time.sec<<"sec"<<endl;
        out<<time.day<<","<<time.month<<endl;
        out <<time.month<<"/"<<time.date<<"/"<<time.year<<endl;
        return out;
    }

private:
    void StrToTime(string &ss){
        vector<string> vec = Split(ss,' ');

        if(vec.size() < PROPSCOUNT){
            cout << "Can't Convert string to time .. Some thing went wrong " <<endl;
            return;
        }

        day   = vec[TimeFormat::Day_Str];
        month = vec[TimeFormat::Month_Str];
        date  = stoi(vec[TimeFormat::Date]);
        interval = stoi(vec[TimeFormat::Hour]) > STD_TIME_INTERVAL ? "PM" : "AM";
        hour  = (  stoi(vec[TimeFormat::Hour])   > STD_TIME_INTERVAL) ?
                stoi(vec[TimeFormat::Hour])- STD_TIME_INTERVAL: stoi(vec[TimeFormat::Hour]) ;
        min   = stoi(vec[TimeFormat::Min]);
        sec   = stoi(vec[TimeFormat::Sec]);
        year  = stoi(vec[TimeFormat::Year]);
    }

    static vector<string> Split(string& ss,const char separator = ' '){
        vector<string> vec;
        string str;
        const char COLON = ':';

        for(char s : ss){
            if(s != separator && s != COLON)
                str.push_back(s);
            if(s == separator || s == COLON){
                vec.push_back(str);
                str = "";
            }
        }

        if(!str.empty())
            vec.push_back(str);

        return vec;
    }

    // Wed Jan 12 17:26:55 2022
    enum  TimeFormat{
        Day_Str ,
        Month_Str,
        Date , Hour , Min , Sec ,
        Year
    };
};


#endif //CUSTOM_TIME_H
