#ifndef STUDENT_REPORT_H
#define STUDENT_REPORT_H

#include "Input.h"
#include "Array.h"
#include "Utilities.h"
#include "FileSystem.h"

namespace StudentReportManager {
    class Subject;

    class Student;

    class ReportManager;
}

#define SRM StudentReportManager

inline static const char SEPARATOR = '-';
#define $ SEPARATOR

class SRM::Subject : public Interfaces::ISaveAble<Subject> {
public:

    /// default Constructor
    Subject() {
                this->name = "undefined";
                this->totalMarks = 100;
    }

    /// parametrized constructor
    Subject(const string &name, double totalMarks) : name(name), totalMarks(totalMarks) {}

    /// Getter
    const string &getName() const { return name; }

    double getTotalMarks() const { return totalMarks; }

    /// Setter
    void setName(const string &name) { this->name = name; }

    void setTotalMarks(double totalMarks) { this->totalMarks = totalMarks; }

    /// Operator OverLoading
    bool operator==(const Subject &rhs) const { return this->name == rhs.name; }

    bool operator!=(const Subject &rhs) const { return this->name != rhs.name; }

    /// Interface Implementation
    string ToString() override {
                stringstream ss;
                ss << this->name << $ << this->totalMarks;
                return ss.str();
    }

    Subject FromString(string &str) override {
                vector<string> res = Utilities::Split(str, $);
                return Subject{res[0], stod(res[1])};
    }

    /// IO

    void Print() {
                cout << " ~ Name :  " << name << " , " << "Total Marks : " << totalMarks << "  \n";
    }

    void GetInput() {
                this->name = Input::GetLine(" >> Enter Subject Name : ");
                this->totalMarks = Input::GetInput<double>(" >> Enter Total Marks : ");
    }

    template<class CallBack>
    void Update(CallBack callBack, const char *err) {
                bool isEditKey = false;
                Utilities::Menu updateMenu({
                                                     "\n ~ Edit Name          : 0 \n",
                                                     " ~ Edit Total Marks   : 1\n"
                                           });

                const int choice = updateMenu.GetChoice("\n >> Enter Choice : ");
                Subject subject = *this;
                switch (choice) {
                            case 0:
                                        isEditKey = true;
                                        subject.name = Input::GetLine(" >> Enter new Name : ");
                                        break;
                            case 1:
                                        subject.totalMarks = Input::GetInput<double>(" >> Enter new Total Marks : ");
                                        break;
                            default:
                                        Input::Warning("Invalid Choice !");
                }

                if (!callBack(subject) || !isEditKey) *this = subject;
                else Input::Error(err);
    }

private:
    string name;
    double totalMarks;
};

/***
 * Student Class
 ***/
class SRM::Student : public Interfaces::ISaveAble<Student> {
public:

    /// default constructor
    Student() {
                this->studentName = "undefined";
                this->rollNo = 0;
                this->totalMarks = 100;
                this->percentage = 100;
                this->totalSubjects = 5;
                subjectMarks.clear();
    }

    /// parametrized constructor
    Student(const string &studentName, unsigned int rollNo, unsigned int totalSubjects, double totalMarks,
            double percentage) : studentName(studentName), rollNo(rollNo), totalSubjects(totalSubjects),
                                 totalMarks(totalMarks), percentage(percentage) {}

    /// setter
    void setStudentName(const string &studentName) { this->studentName = studentName; }

    void setRollNo(unsigned int rollNo) { this->rollNo = rollNo; }

    void setPercentage(double percentage) { this->percentage = percentage; }

    void setSubjectMarks(const vector<double> &subjectMarks) { this->subjectMarks = subjectMarks; }

    void setTotalSubjects(unsigned int totalSubjects) { this->totalSubjects = totalSubjects; }

    void setTotalMarks(double totalMarks) { this->totalMarks = totalMarks; }

    /// Getter
    unsigned int getRollNo() const { return rollNo; }

    double getPercentage() const { return percentage; }

    vector<double> &getSubjectMarks() { return subjectMarks; }

    const string &getStudentName() const { return studentName; }

    unsigned int getTotalSubjects() const { return totalSubjects; }

    double getTotalMarks() const { return totalMarks; }

    /// Operator OverLoading
    bool operator==(const Student &rhs) const { return this->rollNo == rhs.rollNo; }

    bool operator!=(const Student &rhs) const { return this->rollNo != rhs.rollNo; }

    /// Interface Implementation
    string ToString() override {
                stringstream ss;
                ss << this->studentName << $ << this->rollNo << $ << this->totalSubjects << $
                   << this->totalMarks << $ << this->percentage;

                if (this->subjectMarks.empty())
                            return ss.str();
                ss << $;
                for (double marks : this->subjectMarks)
                            ss << marks << $;
                return ss.str();
    }

    Student FromString(string &str) override {
                vector<string> res = Utilities::Split(str, $);
                Student student;
                student.studentName = res[0];
                student.rollNo = stoi(res[1]);
                student.totalSubjects = stoi(res[2]);
                student.totalMarks = stod(res[3]);
                student.percentage = stod(res[4]);

                if (str.length() > 4) {
                            for (int i = 5; i < res.size(); i++)
                                        student.subjectMarks.push_back(stod(res[i]));
                }

                return student;
    }

    /// IO
    void GetInput() {
                this->studentName = Input::GetLine(" >> Enter Student Name : ");
                this->rollNo = Input::GetInput<unsigned int>(" >> Enter Roll Number : ");
    }

    void Print() { cout << " " << "Name : " << this->studentName << " , " << "RollNo : " << this->rollNo << "\n"; }

    template<class CallBack>
    void Update(CallBack callBack, const char *err) {
                bool isEditKey = false;
                Student student = *this;
                Utilities::Menu studentUpdateMenu({
                                                            "\n ~ Edit Name   : 0\n",
                                                            " ~ Edit RollNo : 1\n",
                                                  });

                const int choice = studentUpdateMenu.GetChoice("\n >> Enter Choice : ");
                switch (choice) {
                            case 0:
                                        student.studentName = Input::GetLine(" >> Enter New Name : ");
                                        break;
                            case 1:
                                        isEditKey = true;
                                        student.rollNo = Input::GetInput<int>(" >> Enter New RollNo : ");
                                        break;
                            default:
                                        Input::Warning("Invalid Choice \n");
                }
                if (!callBack(student) || !isEditKey) *this = student;
                else Input::Error(err);
    }

private:
    string studentName;
    unsigned int rollNo, totalSubjects;
    double totalMarks, percentage;
    vector<double> subjectMarks;
};

/***
 * Report Manager : Singleton
 ***/

class SRM::ReportManager {
public:
    static ReportManager *Instance() {
                if (instance == nullptr) {
                            string fall = Input::GetLine("\t >> Enter Fall : ")
                            , department = Input::GetLine("\t >> Enter Department : ")
                            , semester = Input::GetLine("\t >> Enter Semester : ")
                            , section = Input::GetLine("\t >> Enter Section : ");

                            instance = new ReportManager(fall, department, semester, section);
                }
                return instance;
    }

    void Init() {
                stringstream ss;
                ss << "FM" << this->fall << "_" << this->department << "_" << this->semester;
                string fileName = ss.str();
                this->_fileName = ss.str();

                if (!FileSystem::IsExists(_fileName), true)
                            FileSystem::CreateFile(_fileName);

                // loads subject Data
                Subject subject;
                FileSystem::ReadFile(_fileName, [&](string &str) {
                    subjects.push_back(subject.FromString(str));
                });
                CalculateTotalMarks();

                // loads file records
                this->_secFileName = ss.str() + "_" + "SEC_RECORD";

                if (!FileSystem::IsExists(this->_secFileName))
                            FileSystem::CreateFile(this->_secFileName, true);


                FileSystem::ReadFile(this->_sFileName, [&](string &str) {
                    this->filesRecord.push_back(str);
                });

                // loads student res
                fileName += "_" + this->section;
                this->_sFileName = fileName;

                // Adds Section File Name into fileRecordFile
                if (!any_of(this->filesRecord.begin(), this->filesRecord.end(), [&](string &str) {
                    return str == this->_sFileName;
                })) {
                            this->filesRecord.push_back(this->_sFileName);
                            SaveFileRecords();
                }

                if (!FileSystem::IsExists(fileName), true)
                            FileSystem::CreateFile(fileName);

                Student student;
                FileSystem::ReadFile(fileName, [&](string &str) {
                    studentsReport.push_back(student.FromString(str));
                });

                ClampStudentsMarks();
    }

    void PrintResultMenu() {

                Utilities::Menu printResMenu({
                                                       "\n ~ Display All Students Result : 0\n",
                                                       " ~ Check Result By RollNo      : 1\n",
                                                       " ~ EXIT                        : 2\n",
                                             });

                int choice = printResMenu.GetChoice("\n >> Enter Choice : ");
                switch (choice) {
                            case 0:
                                        this->PrintResult();
                                        break;
                            case 1:
                                        do { this->PrintStudentResult(); }
                                        while (Input::GetChoice(" >> Do You Want To Check More Result Y/N _ "));
                                        break;
                            default:
                                        Input::Warning("Invalid Choice \n");
                }
    }

    void AdminMenu() {
                Utilities::Menu adminMenu({
                                                    "\n ~ Add New Subject  : 0 \n",
                                                    " ~ Update Subjects  : 1 \n",
                                                    " ~ Delete Subject   : 2 \n",
                                                    " ~ Display All      : 3 \n",
                                                    " ~ Exit             : 4\n"
                                          });

                const int choice = adminMenu.GetChoice("\n >> Enter Choice : ");
                switch (choice) {
                            case 0:
                                        do { this->AddSubjects(); }
                                        while (Input::GetChoice(" >> Do You Want to Enter more Subjects Data : Y/N "));
                                        break;
                            case 1:
                                        do { this->UpdateSubjects(); }
                                        while (Input::GetChoice(" >> Do You Want to Update more Subjects Data : Y/N "));
                                        break;
                            case 2:
                                        do { this->DeleteSubject(); }
                                        while (Input::GetChoice(" >> Do You Want to Delete more Subjects Data : Y/N "));
                                        break;
                            case 3:
                                        for (Subject &subject : this->subjects)
                                                    subject.Print();
                                        if (this->subjects.empty()) Input::Warning("Empty \n");
                                        break;
                            default:
                                        Input::Warning("Invalid Choice \n");
                }
    }

    void StudentReportMenu() {
                Utilities::Menu reportMenu({
                                                     "\n ~ Display All Students : 0\n",
                                                     " ~ Add Student          : 1\n",
                                                     " ~ Update Student Data  : 2\n",
                                                     " ~ Delete Student       : 3\n",
                                                     " ~ Exit                 : 4\n"
                                           });

                const int choice = reportMenu.GetChoice("\n >> Enter Choice : ");
                switch (choice) {
                            case 0:
                                        for (Student &student : studentsReport)
                                                    student.Print();
                                        if (this->studentsReport.empty()) Input::Warning("Empty \n");
                                        break;
                            case 1:
                                        do { AddStudent(); }
                                        while (Input::GetChoice(" >> Do You Want to Enter more Students : Y/N "));
                                        break;
                            case 2:
                                        do { UpdateStudentData(); }
                                        while (Input::GetChoice(" >> Do You Want To Update More Record : Y/N "));
                                        break;
                            case 3:
                                        do { DeleteStudentData(); }
                                        while (Input::GetChoice(" >> Do You Want to Delete More Record : Y/N "));
                                        break;
                            default:
                                        Input::Warning("Invalid Choice \n");
                }
    }

    void ResultReportMenu() {
                Utilities::Menu resultReportMenu({
                                                           " ~ Fill All Result Cards    : 0\n",
                                                           " ~ Update Result Card       : 1\n",
                                                           " ~ Add Result of individual : 2\n",
                                                           " ~ Apply for Each           : 3\n",
                                                           " ~ Exit                     : 4\n",
                                                 });

                const int choice = resultReportMenu.GetChoice("\n >> Enter Choice : ");

                switch (choice) {
                            case 0:
                                        this->FillResultCards();
                                        break;
                            case 1:
                                        do { this->UpdateResultCard(); }
                                        while (Input::GetChoice(" >> Do You Want to Update More : Y/N "));
                                        break;
                            case 2:
                                        this->UpdateIndividual();
                                        break;
                            case 3:
                                        this->UpdateForEachResult();
                                        break;
                            default:
                                        Input::Warning("Invalid Choice \n");
                }
    }

private:
    static ReportManager *instance;
    string _fileName, _sFileName, _secFileName;
    vector<string> filesRecord;
    string fall, department, semester, section;
    vector<Subject> subjects;
    vector<Student> studentsReport;
    double subjectsTotalMarks;

    /// constructor's :-)
    ReportManager(const string &fall, const string &department, const string &semester, const string &section) : fall(
              fall), department(department), semester(semester), section(section) {}

    ReportManager() {}


    /// FileSystem Write
    void SaveSubjects() { FileSystem::WriteData(this->_fileName, subjects); }

    void SaveStudentReports() { FileSystem::WriteData(this->_sFileName, studentsReport); }

    void SaveFileRecords() { FileSystem::WriteData(this->_secFileName, filesRecord, true); }

    void AddResultRecord(string &fileName) {
                vector<Student> students;
                Student aux;
                FileSystem::ReadFile(fileName, [&](string &str) {
                    students.push_back(aux.FromString(str));
                });
                for (Student &student : students) {
                            student.getSubjectMarks().push_back(0);
                            *(student.getSubjectMarks().end()) = 0;
                            CalculateResult(student);
                }
                FileSystem::WriteData(fileName, students);
    }

    void UpdateResultRecord(string &fileName, int &idx, double &newMarks) {
                vector<Student> students;
                Student aux;
                FileSystem::ReadFile(fileName, [&](string &str) {
                    students.push_back(aux.FromString(str));
                });
                for (Student &student : students) {
                            student.getSubjectMarks()[idx] = newMarks;
                            CalculateResult(student);
                }
                FileSystem::WriteData(fileName, students);
    }

    void DeleteResultRecord(string &fileName, int idx) {
                vector<Student> students;
                Student aux;
                FileSystem::ReadFile(fileName, [&](string &str) {
                    students.push_back(aux.FromString(str));
                });
                for (Student &student : students)
                            if (Utilities::IsValidIdx(student.getSubjectMarks(), idx)) {
                                        student.getSubjectMarks().erase(student.getSubjectMarks().begin() + idx);
                                        CalculateResult(student);
                            }
                FileSystem::WriteData(fileName, students);
    }

    void CalculateResult(Student &student) {
                student.setTotalMarks(Utilities::GetSumOf(student.getSubjectMarks()));
                student.setPercentage(Utilities::GetPercentage(this->subjectsTotalMarks, student.getTotalMarks()));
                student.setTotalSubjects(this->subjects.size());
    }

    /// Helper
    void CalculateTotalMarks() {
                this->subjectsTotalMarks = 0;
                for (Subject &sub : subjects)
                            this->subjectsTotalMarks += sub.getTotalMarks();
    }

    void PrintResult_Helper_Header() {
                Input::PrintStr(" Name ", 20);
                Input::PrintStr(" Roll No ", 20);
                for (Subject &subject : this->subjects)
                            Input::PrintStr(subject.getName().c_str(), 20);
                Input::Print("\n");
    }

    void PrintResult_Helper_Data(vector<Student> students) {
                if (students.empty()) {
                            Input::Warning("\n\t\tEmpty\t\n");
                            return;
                }
                for (Student &student : students) {
                            Input::PrintStr(student.getStudentName().c_str(), 20);
                            Input::PrintStr(to_string(student.getRollNo()).c_str(), 20);
                            for (int i = 0; i < student.getSubjectMarks().size(); i++)
                                        Input::PrintStr(
                                                  Utilities::DoubleToString(student.getSubjectMarks()[i]).c_str(), 20,
                                                  '|',
                                                  Utilities::GetGradeColor(this->subjects[i].getTotalMarks(),
                                                                           student.getSubjectMarks()[i])
                                        );
                            Input::Print("\n");
                }
    }

    /// CRUD Helper
    template<class T>
    static bool CheckValidIdx(vector<T> vec, int &idx, const char *msg) {
                Input::Print(msg);

                if (vec.empty()) {
                            Input::Warning("Empty\n");
                            return false;
                }

                for (int i = 0; i < vec.size(); i++) {
                            Input::Print(string(" idx : " + to_string(i)).c_str());
                            vec[i].Print();
                }

                idx = Input::GetInput<int>(" >> Enter Idx Of Data You Want To Select _ ");

                if (!Utilities::IsValidIdx(vec, idx)) {
                            Input::Warning("Invalid Idx \n");
                            return false;
                }

                return true;
    }

protected:

    /*** Admin CURD ***/

    void AddSubjects() {
                Input::Print("\n ! Total Subjects Added So Far , : ", blue);
                Input::Print(string(to_string(subjects.size()) + "\n").c_str());

                Subject subject;
                subject.GetInput();
                if (any_of(subjects.begin(), subjects.end(), [&](Subject &sub) {
                    return sub == subject;
                })) {
                            Input::Error("Subject Name Already Exists !");
                } else {
                            this->subjects.push_back(subject);
                            this->subjectsTotalMarks = 0;
                            for (Subject &marks : this->subjects) this->subjectsTotalMarks += marks.getTotalMarks();
                            this->SaveSubjects();
                            for (string &fileName : this->filesRecord) AddResultRecord(fileName);
                            for (Student &student : this->studentsReport) student.getSubjectMarks().push_back(0);
                }
    }

    void UpdateSubjects() {
                int idx;
                if (!CheckValidIdx(this->subjects, idx, "\n \t** All Subjects Record ** \n"))
                            return;
                do {
                            subjects[abs(idx)].Update([&](Subject &sub) {
                                return any_of(subjects.begin(), subjects.end(), [&](Subject &subject) {
                                    return sub == subject;
                                });
                            }, "Subject Name Already Exists !");
                            subjects[abs(idx)].Print();
                            Input::Print("Record Has been Updated \n");
                            this->subjectsTotalMarks = 0;
                            for (Subject &marks : this->subjects)
                                        this->subjectsTotalMarks += marks.getTotalMarks();
                            SaveSubjects();
                            ClampStudentsMarks();
                            for (Student &student : this->studentsReport) CalculateResult(student);
                            SaveStudentReports();
                } while (Input::GetChoice(" >> Do You Want to Edit More Y/N : "));
    }

    void DeleteSubject() {
                int idx;
                if (!CheckValidIdx(this->subjects, idx, "\n \t** All Subjects Record ** \n"))
                            return;
                subjects.erase(subjects.begin() + idx);
                this->subjectsTotalMarks = 0;
                for (Subject &marks : this->subjects)
                            this->subjectsTotalMarks += marks.getTotalMarks();
                SaveSubjects();

                for (string &fileName : this->filesRecord) DeleteResultRecord(fileName, idx);
                for (Student &student : this->studentsReport)
                            if (Utilities::IsValidIdx(student.getSubjectMarks(), idx)) {
                                        student.getSubjectMarks().erase(student.getSubjectMarks().begin() + idx);
                                        CalculateResult(student);
                            }

                Input::Print("Subject Has Been Removed\n", green);
    }


    /*** Student Report CURD ***/

    void AddStudent() {
                Student student;
                student.GetInput();
                if (any_of(studentsReport.begin(), studentsReport.end(), [&](Student &stud) {
                    return student == stud;
                })) {
                            Input::Error("Student Roll Number Already Exists");
                            return;
                }

                student.setTotalSubjects(subjects.size());

                /// Post Result
                vector<double> *vec = &student.getSubjectMarks();

                for (int i = 0; i < subjects.size(); i += 1) {
                            cout << "Enter " << subjects[i].getName() << " Marks / " << subjects[i].getTotalMarks()
                                 << " _ ";
                            double marks = abs(Input::GetInput<double>(" "));
                            if (marks > subjects[i].getTotalMarks())
                                        marks = subjects[i].getTotalMarks();
                            vec->push_back(marks);
                }

                this->CalculateResult(student);
                studentsReport.push_back(student);
                SaveStudentReports();
    }

    void UpdateStudentData() {
                int idx;
                if (!CheckValidIdx(this->studentsReport, idx, "\n \t** All Students Record ** \n"))
                            return;
                this->studentsReport[idx].Update([&](Student &student) {
                    return any_of(this->studentsReport.begin(), this->studentsReport.end(), [&](Student &stud) {
                        return student == stud;
                    });
                }, "Can't Add Duplicate Roll Number \n");
    }

    void DeleteStudentData() {
                int idx;
                if (!CheckValidIdx(this->studentsReport, idx, "\n \t** All Students Record ** \n"))
                            return;
                this->studentsReport.erase(this->studentsReport.begin() + idx);
                Input::Print("Data Has Been Deleted \n", green);
                SaveStudentReports();
    }

    /***  Result Card Curd    ***/

    void FillResultCards() {
                this->PrintResult_Helper_Header();
                for (int i = 0; i < this->studentsReport.size(); i += 1) {
                            PrintResult_Helper_Data({this->studentsReport[i]});
                            int idx = FindNullIdx(this->studentsReport[i].getSubjectMarks());
                            bool isContainsNull = false;
                            if (idx != -1) FillResultCards_Helper(idx, this->studentsReport[i], isContainsNull);
                            if (isContainsNull)
                                        if (!Input::GetChoice(" >> Do You Want to Enter More Records Y/N_ ")) return;
                            Input::Print("\n");
                }

                Input::Print("All Set !!\n", green);
    }

    void UpdateIndividual() {
                this->PrintResult();
                Input::Print("\n");
                int rollNo = abs(Input::GetInput<int>(" >> Enter Roll No of Student _ "));
                Student student;
                student.setRollNo(rollNo);
                auto val = find(this->studentsReport.begin(), this->studentsReport.end(), student);
                if (val == this->studentsReport.end()) {
                            Input::Error("Invalid RollNo \n");
                            return;
                }
                PrintResult_Helper_Data({*val});
                bool aux = false;
                int idx = this->FindNullIdx(val->getSubjectMarks());
                if (idx == -1) {
                            Input::Print("All Set !\n", green);
                            return;
                }
                FillResultCards_Helper(idx, *val, aux);
    }

    void UpdateResultCard() {
                this->PrintResult();
                Input::Print("\n");
                int rollNo = abs(Input::GetInput<int>(" >> Enter Roll No of Student _ "));
                Student student;
                student.setRollNo(rollNo);
                auto val = find(this->studentsReport.begin(), this->studentsReport.end(), student);
                if (val == this->studentsReport.end()) {
                            Input::Error("Invalid RollNo \n");
                            return;
                }

                PrintResult_Helper_Data({*val});
                Input::Print("\n");

                // Do Update Logic Here
                int idx;
                Input::Print("\n");
                if (!CheckValidIdx(this->subjects, idx, "\n \t** All Students Record ** \n"))
                            return;

                double marks = abs(
                          Input::GetInput<double>(
                                    stringstream("Enter New Marks for" + this->subjects[idx].getName() + " / " +
                                                 to_string(this->subjects[idx].getTotalMarks()) +
                                                 " ").str().c_str()));

                if (marks > this->subjects[idx].getTotalMarks()) marks = this->subjects[idx].getTotalMarks();

                if (Utilities::IsValidIdx(val->getSubjectMarks(), idx))
                            val->getSubjectMarks()[idx] = marks;

                Input::Print("Marks Has Been Updated \n\n", green);
    }

    void UpdateForEachResult() {
                Input::Warning("\n\t!!! Note : These Changes will Apply for All Students\n");
                Utilities::Menu menu({
                                               " ~ Apply for this Section - 0\n",
                                               " ~ Apply For All Sections - 1\n"
                                     });

                int choice = menu.GetChoice("\n >> Enter Choice _ ");
                switch (choice) {
                            case 0 :
                                        UpdateForEachResult_Helper_Section();
                                        break;
                            case 1 :
                                        UpdateForEachResult_Helper_UpdateAll();
                                        break;
                            default:
                                        Input::Warning("Invalid Choice : ");
                }
    }

    /*** UpdateForEachResult helper ***/

    void UpdateForEachResult_Helper_Section() {
                int idx;
                if (!CheckValidIdx(this->subjects, idx, "\n \t** All Subjects Record ** \n"))
                            return;
                double marks = abs(Input::GetInput<double>(
                          stringstream(" >> Enter New Marks for All Students " + this->subjects[idx].getName() + " / " +
                                       to_string(this->subjects[idx].getTotalMarks()) + " ").str().c_str()));
                if (marks > this->subjects[idx].getTotalMarks())
                            marks = this->subjects[idx].getTotalMarks();
                if (!Input::GetChoice(" >> Apply For All Y/N : "))
                            return;
                for_each(this->studentsReport.begin(), this->studentsReport.end(), [&](Student &student) {
                    student.getSubjectMarks()[idx] = marks;
                });
                SaveStudentReports();
                Input::Print("Data Has Been Updated\n", green);
    }

    void UpdateForEachResult_Helper_UpdateAll() {
                int idx;
                if (!CheckValidIdx(this->subjects, idx, "\n \t** All Subjects Record ** \n"))
                            return;
                double marks = abs(Input::GetInput<double>(
                          stringstream(" >> Enter New Marks for All Sections " + this->subjects[idx].getName() + " / " +
                                       to_string(this->subjects[idx].getTotalMarks()) + " ").str().c_str()));
                if (marks > this->subjects[idx].getTotalMarks())
                            marks = this->subjects[idx].getTotalMarks();
                if (!Input::GetChoice(" >> Apply For All Y/N : "))
                            return;
                for_each(this->studentsReport.begin(), this->studentsReport.end(), [&](Student &student) {
                    student.getSubjectMarks()[idx] = marks;
                });
                for (string &fileName : this->filesRecord) UpdateResultRecord(fileName, idx, marks);
                Input::Print("Data Has Been Updated\n", green);
    }

    /*** Result Card Curd !! helper ***/

    static int FindNullIdx(vector<double> &vec) {
                for (int i = 0; i < vec.size(); i++)
                            if (vec[i] == 0) return i;
                return -1;
    }

    void FillResultCards_Helper(int &idx, Student &student, bool &isContainsNull) {
                if (idx == -1) return;
                do {
                            isContainsNull = true;
                            idx = FindNullIdx(student.getSubjectMarks());
                            const int totalMarks = this->subjects[idx].getTotalMarks();
                            cout << "\n >> Enter Marks of " << this->subjects[idx].getName() << " / " << totalMarks
                                 << " _ ";
                            double marks = abs(Input::GetInput<double>(" "));
                            if (marks > totalMarks) marks = totalMarks;
                            student.getSubjectMarks()[idx] = marks;
                            this->CalculateTotalMarks();
                            const double totalSubjectsMarks = Utilities::GetSumOf(student.getSubjectMarks());
                            student.setTotalMarks(totalSubjectsMarks);
                            student.setPercentage(
                                      Utilities::GetPercentage(this->subjectsTotalMarks, totalSubjectsMarks));
                            student.setTotalSubjects(this->subjects.size());
                } while (FindNullIdx(student.getSubjectMarks()) != -1);
                this->SaveStudentReports();
    }

    /*** Print Result Helper ***/

    void PrintResult() {
                this->PrintResult_Helper_Header();
                this->PrintResult_Helper_Data(this->studentsReport);
    }

    void PrintStudentResult() {
                int rollNo = abs(Input::GetInput<int>("\n >> Enter Roll No of Student _ "));
                Student student;
                student.setRollNo(rollNo);
                auto val = find(this->studentsReport.begin(), this->studentsReport.end(), student);
                if (val == this->studentsReport.end()) {
                            Input::Error("Invalid RollNo \n");
                            return;
                }

                this->PrintResult_Helper_Header();
                PrintResult_Helper_Data({*val});
                Input::Print("\n");
                string gradeFlag = Utilities::GetGradeColor(this->subjectsTotalMarks, val->getTotalMarks());
                cout << "\t Total Subjects : " << val->getTotalSubjects() << "\n";
                cout << "\t Total Marks : " << this->subjectsTotalMarks << "\n";
                cout << "\t Obtained Marks : " << val->getTotalMarks() << "\n";
                cout << "\t Percentage : ";
                Input::PrintStr(
                          to_string(Utilities::GetPercentage(this->subjectsTotalMarks, val->getTotalMarks())).c_str(),
                          0,
                          ' ', gradeFlag);
                cout << "\n\t Grade : ";
                string grade = Utilities::GetGrade(this->subjectsTotalMarks, val->getTotalMarks());
                Input::PrintStr(grade.c_str(), 0, ' ', gradeFlag);
                Input::Print("\n\t BETTER LUCK FOR NEXT TIME :-) \n", magenta);
    }

    /// init Helper

    /// Clamps Students Marks
    void ClampStudentsMarks() {
                for (Student &student : this->studentsReport) {
                            for (int i = 0; i < this->subjects.size(); i++)
                                        if (student.getSubjectMarks()[i] > this->subjects[i].getTotalMarks())
                                                    student.getSubjectMarks()[i] = this->subjects[i].getTotalMarks();
                            double totalMarks = Utilities::GetSumOf(student.getSubjectMarks());
                            student.setTotalMarks(totalMarks);
                            student.setPercentage(Utilities::GetPercentage(this->subjectsTotalMarks, totalMarks));
                            student.setTotalSubjects(this->subjects.size());
                }
                this->SaveStudentReports();
    }

};

SRM::ReportManager *SRM::ReportManager::instance = nullptr;
#endif


