#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include<sstream>
#include<iterator>
#include<algorithm>
using namespace std;

void frontpage()
{
    cout<<"==============================================================================="<<endl;
    cout<<"|                                                                             |"<<endl;
    cout<<"|                     WELCOME TO OUR CONTACT MANAGER                          |"<<endl;
    cout<<"|                                                                             |"<<endl;
    cout<<"==============================================================================="<<endl;

    cout<<"\n\n      CREATED BY:           BSCS (E)"<<endl<<endl;
    cout<<"                         M. Fahad Hassan (482)"<<endl;
    cout<<"                         Zain Ul Din     (147)"<<endl;
    cout<<"                         Hassan Raza     (238)"<<endl;
    cout<<"                         Umer Mahmood    (170)"<<endl;
    cout<<"                         Raheel Arshad   (159)"<<endl;

}

class Userid
{
public:
    char id[15];
    char name[10];
    char pass[8];

    Userid() = default;


    bool checkID()
    {
        if(id==id){
            cout<<"ID ALREADY EXISTS..."<<endl;
            return false;
        }
        else{
            return true;
        }
    }

    void Signup()
    {
        cout<<"Enter Your Front Name : ";cin>>name;
        cout<<"Enter Your ID (14 Char): ";cin>>id;
        cout<<"Enter Your Password (7 Char): ";cin>>pass;
    }

    void Displayid()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"User Name: "<<name<<endl;
        cout<<"Pass: "<<pass<<endl;

    }
};

string nametofname(char c[],int count)
{
    string fileName;
    for(int i=0;i<count;i++)
    {
        fileName+= c[i];
    }
    fileName=fileName.c_str();
    fileName+=".txt";
    return fileName;
}
void saving(Userid &e)
{
    string nwfile;
    fstream file;
    fstream ax;
    file.open("Accounts.txt",ios::app);
    e.Signup();
    file.write( reinterpret_cast<char*>(&e), sizeof(e) );
    nwfile=nametofname(e.id,15);
    ax.open (nwfile.c_str(),ios::out);
    file.close();
    ax.close();
}

void display(Userid &e)
{
    fstream file;
    file.open("Accounts.txt",ios::in);
    while (true)
    {
        file.read(reinterpret_cast<char*>(&e), sizeof(e));
        if(file.eof())
        {
            break;

        }
        e.Displayid();
    }
    file.close();
}

char* login(Userid &e)
{
    fstream file;
    string user;
    string pass;
    int k;
    char j;
    do
    {
        k=0;
        file.open("Accounts.txt",ios::in);
        cout<<"\n\nEnter Your ID: ";
        cin>>user;
        file.seekg(0);
        file.read( reinterpret_cast<char*>(&e), sizeof(e) );
        while(!file.eof())
        {
            if(e.id==user)
            {
                cout<<"Enter Password: ";cin>>pass;
                if(e.pass==pass)
                {
                    j='N';
                    file.close();
                    system("cls");

                    cout<<"WELCOME... "<<e.name<<" to YOUR CONTACTS!!!!!!!"<<endl;
                    system("pause");
                    return e.id;
                }
                else
                {
                    cout<<"\nWrong Password...."<<endl;
                    j='Y';
                    cout<<"Try Again..."<<endl;
                    break;
                }
            }
            else
            {
                //if id don't matches
                k++;
            }

            file.read( reinterpret_cast<char*>(&e), sizeof(e) );
        }

        if(k!=0)
        {
            cout<<"\nWrong ID...."<<endl;
            j='Y';
            cout<<"Try Again..."<<endl;
        }
        file.close();
    }
    while(j=='Y');
    file.close();
}

void deleteid(Userid &e)
{
    char j;
    int k;
    fstream ax;
    fstream file;
    fstream temp;
    string user;
    string pass;
    cout<<"\nTo Remove Account...."<<endl;
    do
    {
        k=0;
        file.open("Accounts.txt",ios::in);
        cout<<"\n\nEnter Your ID: ";
        cin>>user;
        file.seekg(0);
        file.read( reinterpret_cast<char*>(&e), sizeof(e) );
        while(!file.eof())
        {
            j='Y';
            if(e.id==user)
            {
                cout<<"Enter Password: ";cin>>pass;
                if(e.pass==pass)
                {
                    j='N';
                    file.close();

                    break;
                }
                else
                {
                    cout<<"\nWrong Password...."<<endl;
                    j='Y';
                    cout<<"Try Again..."<<endl;
                    break;
                }
            }
            else
            {
                //if id don't matches
                k++;
            }

            file.read( reinterpret_cast<char*>(&e), sizeof(e) );
        }

        if(k!=0)
        {
            cout<<"\nWrong ID...."<<endl;
            j='Y';
            cout<<"Try Again..."<<endl;
        }
        file.close();
    }
    while(j=='Y');

    file.close();
    file.open("Accounts.txt",ios::in);
    temp.open("Fah.txt",ios::out);
    file.seekg(0);

    while (true)
    {
        file.read( reinterpret_cast<char*>(&e), sizeof(e) );
        if(file.eof()){
            break;
        }
        if(e.id!=user)
        {
            temp.write( reinterpret_cast<char*>(&e), sizeof(e) );
        }
    }
    file.close();
    temp.close();
    user=user+".txt";
    remove(user.c_str());
    remove("Accounts.txt");
    rename("Fah.txt","Accounts.txt");
    cout<<"\n\nRecord Deleted .."<<endl;
}

//ZAIN PROGRAMS

// Doubly Linked List in c++


#define ll long long
class Contact {
public:
    Contact() {
        userName = "UNSET";
        userContactNumber = 00000000000;
    }

    Contact(const string& userName, ll& userContactNumber) :
            userName(userName),
            userContactNumber(userContactNumber) {}




    // Getter Setter

    const string& getUserName() const { return userName; }
    const ll& getUserContactNumber() const { return userContactNumber; }

    void setUserName(const string& userName) { this->userName = userName; }
    void setUserContactNumber(ll userContactNumber) { this->userContactNumber = userContactNumber; }



    // operator over loading
    friend ostream& operator << (ostream& out, Contact& contact) {

        out << "\n\t------------------------------------------------\n";
        cout << "\tName : " << contact.userName << "\n";
        cout << "\tContact Number : " << "0"<<contact.userContactNumber << "\n";
        out << "\t------------------------------------------------\n";
        return out;
    }

    friend istream& operator >>(istream& in, Contact& contact) {
        cout << "Enter Name : ";
        in.sync();
        in >> contact.userName;
        in.clear();
        cout << "Enter Contact Number : ";
        in >> contact.userContactNumber;
        return in;
    }

    //  compare

    // obj is Equal
    bool operator == (Contact& contact) {
        return userName == contact.userName && userContactNumber == contact.userContactNumber;
    }

    // Obj_l is greater or equal to Obj_r
    bool operator >= (Contact& contact) {
        if (this->userName == contact.userName)return true;
        // Compares 1st char
        cout << " " << userName[0] << " " << contact.userName[0];
        if (IsLunderR(userName[0], contact.userName[0])) return false;

        unsigned int minLength = (contact.userName.length() < userName.length()) ? contact.userName.length() : userName.length();

        for (int i = 0; i < minLength; i++)
            if (IsLunderR(userName[i], contact.userName[i])) return false;

        return true;
    }

    bool operator <= (Contact& contact) {
        if (this->userName == contact.userName) return true;
        // Compares 1st char
        if (userName[0] != contact.userName[0]) return IsLunderR(userName[0], contact.userName[0]); // if not equal


       unsigned int minLength = (contact.userName.length() < userName.length()) ? contact.userName.length() : userName.length();
        // 1 str
        for (int i = 0; i < minLength; i++)
            if (userName[i] == contact.userName[i]) continue;
            else {
                // if (IsLunderR(userName[i], contact.userName[i])) {
                // cout << " " << userName[i] << " < " << contact.userName[i] << endl;
                // }
                //else cout << " " << userName[i] << " > " << contact.userName[i] << endl;
                return IsLunderR(userName[i], contact.userName[i]);
            }

        //  if(!IsLunderR(userName[i] , contact.userName[i])) return false;

        return true;
    }

    string ToString(){
        replace(userName.begin() , userName.end() , ' ', '`' );
        stringstream ss;
        ss << userName<<"$"<< userContactNumber;
        return ss.str();
    }


     friend ofstream& operator << (ofstream& fileOut , Contact& contact){
        fileOut << contact.ToString() << "\n";
        return fileOut;
     }

    static Contact StrToContact(string ss){
        string arr[2];
        int index = 0;

        // split string to array
        for(int i=0;i<ss.length() ;i++) {
            if (ss[i] != '$') arr[index] += ss[i];
            else
                index++;
        }

        string t_userName = arr[0];
        int long long t_contactNumber = stoll(arr[1]);

        replace(t_userName.begin() , t_userName.end() , '`' , ' ');

        Contact contact(t_userName , t_contactNumber);
        return contact;
    }

private:
    string userName;
    ll userContactNumber;

    const char alphabet[26] = {
            'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' ,'p' ,
            'q' , 'r'  , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' ,'z'
    };

    const char Alphabet[26] = {
            'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' ,'P' ,
            'Q' , 'R'  , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' ,'Z'
    };

    bool IsLunderR(char l, char r) const {
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] == l || Alphabet[i] == l) return true;
            if (alphabet[i] == r || Alphabet[i] == r) return false;
        }
        return l < r;
    }
};

void start()
{
    frontpage();
    //sndPlaySound("D:/PROJECT/1.wav",SND_FILENAME);

    system("PAUSE");

    Userid u;
    int n;

    do
    {
        system("cls");
        cout<<"CHOOSE AN OPTION: "<<endl;
        cout<<"1. LOGIN"<<endl;
        cout<<"2. SIGNUP"<<endl;
        cout<<"3. DELETE AN ID"<<endl;
        cout<<"4. DEBUG IDs"<<endl;
        cout<<"0. EXIT"<<endl;
        cin>>n;
        switch(n)
        {
            case 1:
                login(u);
                n=0;
                break;
            case 2:
                saving(u);
                break;
            case 3:
                deleteid(u);
                break;
            case 4:
                display(u);
                system("pause");
                break;
            case 0:
                break;
            default:
                cout<<"Wrong input..."<<endl;
                break;
        }

    }while(n!=0);

}

int main() {
    /* cout << "This Program will check string c1 is less then c2" << endl;
     Contact c1, c2;
     cout << "Enter Input For _ C1 : " << endl;
     cin >> c1;
     cout << "Enter Input For _ C2 : " << endl;
     cin >> c2;

     if (c1 <= c2) {
         cout << "TRUE" << endl;
     }
     else {
         cout << "False" << endl;
     }*/


    ///STATING FROM SOUND AND LOGIN
    start();
    int n;
    do
    {
        system("cls");

        cout<<"MENU: "<<endl;
        cout<<"1. ADD NUMBER"<<endl;
        cout<<"2. FIND NUMBER"<<endl;
        cout<<"3. FAKE CALL"<<endl;
        cout<<"4. RECENTS"<<endl;
        cout<<"5. FAVORITES"<<endl;
        cout<<"6. DELETE CONTACT"<<endl;
        cout<<"7. MANAGE CONTACT"<<endl;
        cout<<"8. SHOW ALL CONTACTS"<<endl;
        cout<<"0. EXIT"<<endl;
        cin>>n;
        switch(n)
        {
            case 1:
                ////ADD NUMBER USING FILEHANDLING
                break;
            case 2:
                ////SEARCH FOR NUMBER BY TAKING INPUT FOR NAME

                break;
            case 3:
                ////FAKE CALL FUNCTION WITH SOUND
                break;
            case 4:
                ////AFTER FAKE CALL NUMBER WILL BE IN RECENT
                break;
            case 5:
                ////FAVOURITES
                break;
            case 6:
                ////DELETE NUMBER
                break;
            case 7:
                ////MANAGE CONTACT
                break;
            case 8:
                ////DISPLAY ALL CONTACTS IN SORTING FORM
                break;
            case 0:
                cout<<"THANKS FOR USING OUR PROGRAM...."<<endl;
                cout<<"       SEE YOU AGAIN..."<<endl;
                break;
            default:
                cout<<"Wrong input..."<<endl;
                break;
        }

    }while(n!=0);

}
