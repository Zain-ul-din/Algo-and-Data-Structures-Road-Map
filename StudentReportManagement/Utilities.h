
#ifndef UTILITIES_H
#define UTILITIES_H

#include "Input.h"
#include "Array.h"
#include <cmath>

/// Interface
namespace Interfaces {
    /***
     * Implement `ISaveAble` to Save Object In Text File
     * @tparam T
    */
    template<class T>
    class ISaveAble {
    public:
        virtual string ToString() = 0;

        virtual T FromString(string &) = 0;
    };
}

/// Utilities
namespace Utilities {

    vector<string> Split(string str, const char separator) {
        vector<string> vec;
        string aux("");
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == separator) {
                vec.push_back(aux);
                aux = "";
            } else aux.push_back(str[i]);
        }
        if (!aux.empty()) vec.push_back(aux);
        return vec;
    }

    class Menu {
    public:
        /// Single-argument constructors must be marked explicit to avoid unintentional implicit conversions
        explicit Menu(vector<const char *> menu) { this->menu = menu; }

        int GetChoice(const char *msg) {
            for (auto choice : menu)
                cout << choice;
            int choice = Input::GetInput<int>(msg);
            return choice;
        }

    private:
        vector<const char *> menu;
    };

    template<class T>
    bool IsValidIdx(vector<T> vec, int idx) { return abs(idx) < vec.size(); }

    string DoubleToString(double number, const int precision = 2) {
        std::stringstream stream;
        stream << fixed << setprecision(precision) << number;
        return stream.str();
    }


    double GetSumOf(vector<double> &vec) {
        double auxiliary = 0;
        for (double &i : vec)
            auxiliary += i;
        return auxiliary;
    }

    /*** Result Calculator Helper ***/

    double GetPercentage(const double max, const double obtained) { return (obtained / max) * 100; }

    /// Grade Color Flag Helper
    string GetGradeColor(const double max, const double obtained) {
        double percentage = GetPercentage(max, obtained);
        if (percentage > 80) return "green"; // Good
        if (percentage > 60) return "white"; // Average
        if (percentage > 40) return "yellow"; // Need Improvement
        return "red"; // not good
    }

    string GetGrade(const double max, const double obtained) {
        double score = GetPercentage(max, obtained);
        if (score >= 85) return "A";
        if (score >= 75) return "B";
        if (score >= 65) return "C";
        if (score >= 40) return "D";
        else return "F";
    }
}

#endif