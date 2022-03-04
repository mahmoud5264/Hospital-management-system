#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool not_name(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z'))
            return 1;
    }
    return 0;
}

bool not_number(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9')
            return 1;
    }
    return 0;
}

ll str_to_int(string s) {
    ll ret = 0;
    for (int i = 0; i < s.length(); i++) {
        ret = ret * 10 + s[i] - '0';
        if (ret > 100) return 0;
    }
    return ret;
}

string int_to_str(ll num){
    string ret="";
    while(num){
        ret+=(char)(num%10+'0');
        num/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

class patient {
private:
    string fname;
    string lname;
    int age;
    string blood;
    string phoneNumber;

public:
    void setfname() {
        cout << "Please enter first name: " << endl;
        cin >> fname;
        if (not_name(fname)) {
            cout << "Not valid name!" << endl;
            setfname();
        }
    }

    void setfname(string s){
        fname=s;
    }

    string getfname() {
        return fname;
    }

    void setlname() {
        cout << "Please enter last name: " << endl;
        cin >> lname;
        if (not_name(lname)) {
            cout << "Not valid name!" << endl;
            setlname();
        }
    }

    void setlname(string s){
        lname=s;
    }

    string getlname() {
        return lname;
    }

    void setage() {
        cout << "Please enter age: " << endl;
        string s;
        cin >> s;
        if (not_number(s) || str_to_int(s)== 0) {
            cout << "Age must be a positive number between 1 and 100!" << endl;
            setage();
        }
    }

    void setage(int num){
        age=num;
    }

    int getage() {
        return age;
    }

    void setphone() {
        cout << "Please enter phone number: " << endl;
        cin >> phoneNumber;
        if (not_number(phoneNumber)) {
            cout << "Phone must be only numbers!" << endl;
            setphone();
        }
        if (phoneNumber[0] != '0') {
            cout << "Phone number must begin with zero" << endl;
            setphone();
        }
        if (phoneNumber.length() != 11) {
            cout << "Phone number must contain 11 numbers" << endl;
            setphone();
        }
    }

    void setphone(string s){
        phoneNumber=s;
    }

    string getphone() {
        return phoneNumber;
    }

    void setblood() {
        cout << "Please enter blood type: " << endl;
        cin >> blood;
        bool yes = 0;
        yes |= (blood == "b-" || blood == "b+");
        yes |= (blood == "a-" || blood == "a+");
        yes |= (blood == "o-" || blood == "o+");
        yes |= (blood == "ab-" || blood == "ab+");

        yes |= (blood == "B-" || blood == "B+");
        yes |= (blood == "A-" || blood == "A+");
        yes |= (blood == "O-" || blood == "O+");
        yes |= (blood == "AB-" || blood == "AB+");

        yes |= (blood == "Ab-" || blood == "Ab+");
        yes |= (blood == "aB-" || blood == "aB+");

        if (!yes) {
            cout << "Not valid blood type!" << endl;
            setblood();
        }
        if (blood[0] >= 'a')blood[0] -= 32;
        if (blood.length() == 3 && blood[1] >= 'a') {
            blood[1] -= 32;
        }
    }

    void setblood(string s){
        blood=s;
    }

    string getblood() {
        return blood;
    }

    void display() {
        cout << "---- Patient details ----" << endl;
        cout << "First name: " << fname << endl;
        cout << "Last name: " << lname << endl;
        cout << "First name: " << fname << endl;
        cout << "Blood type: " << blood << endl;
        cout << "Phone number: " << phoneNumber << endl;
        cout << endl;
    }


    patient(){}

    patient(bool num) {
        system("cls");
        setfname();
        setlname();
        setblood();
        setage();
        setphone();
        display();
    }

};

string trans(patient p){
    string ret="";
    ret+=p.getfname()+" ";
    ret+=p.getlname()+" ";
    ret+=p.getblood()+" ";
    ret+=int_to_str(p.getage())+" ";
    ret+=p.getphone();
    return ret;
}

patient transrev(string s){
    patient p;
    int i=0;
    string tmp="";
    while(s[i]!=' ') tmp+=s[i++];
    i++;
    p.setfname(tmp);

    tmp="";
    while(s[i]!=' ') tmp+=s[i++];
    i++;
    p.setlname(tmp);

    tmp="";
    while(s[i]!=' ') tmp+=s[i++];
    i++;
    p.setblood(tmp);

    tmp="";
    while(s[i]!=' ') tmp+=s[i++];
    i++;
    p.setage(str_to_int(tmp));

    tmp="";
    while(i<s.length() && s[i]!=' ') tmp+=s[i++];
    p.setphone(tmp);

    return p;
}

class clinic {

public:
    static void pre() {
        cout << "Please enter your choice" << endl << endl;
        cout << "1 - Add new patient" << endl;
        cout << "2 - Take patient to Doctor" << endl;
        cout << "3 - Display list of patients in the section" << endl;
        cout << "4 - Return to the main menu" << endl;
    }

    static void add_patient(ofstream &f){
        patient p(1);
        string s=trans(p);
        f<<s<<endl;
    }

    static void take_to_doctor(ifstream &f){
        string s;
        ofstream tmp;
        tmp.open("tmp.txt");
        if(getline(f,s)){
            patient p=transrev(s);
            cout<<"This patient can enter to the doctor"<<endl;
            p.display();
        }
        else{
            cout<<"There is already no patients waiting in the clinic"<<endl;
            tmp.close();
            return;
        }

        while(getline(f,s)){
            tmp<<s<<endl;
        }
        tmp.close();
        return;
    }

    static void display(ifstream &f){
        string s;
        while(getline(f,s)){
            patient p=transrev(s);
            p.display();
        }
    }

};

class general:public clinic{

public:
    static void child(){
        while (1) {
            system("cls");
            pre();
            string s;
            cin >> s;
            if (s == "1") {
                ofstream f;
                f.open("general.txt",ios::app);
                add_patient(f);
                f.close();
                cout<<"Press any key to continue"<<endl;
                string s;
                cin>>s;
            }
            else if (s == "2") {
                system("cls");
                ifstream f;
                f.open("general.txt");
                take_to_doctor(f);
                f.close();
                remove("general.txt");
                rename("tmp.txt","general.txt");
                cout<<"Press any key to continue"<<endl;
                string s;
                cin>>s;
            }
            else if (s == "3") {
                ifstream f;
                f.open("general.txt");
                display(f);
                f.close();
                cout<<"Press any key to continue"<<endl;
                string s;
                cin>>s;
            }
            else if (s == "4") {
                return;
            }
            else {
                cout << "Invalid entry!" << endl;
                _sleep(1000);
            }
        }
    }
};

class heart:public clinic{

public:
    static void child(){
        while (1) {
            system("cls");
            pre();
            string s;
            cin >> s;
            if (s == "1") {
                ofstream f;
                f.open("heart.txt",ios::app);
                add_patient(f);
                f.close();
                cout<<"Press any key to continue"<<endl;
                string s;
                cin>>s;
            }
            else if (s == "2") {
                system("cls");
                ifstream f;
                f.open("heart.txt");
                take_to_doctor(f);
                f.close();
                remove("heart.txt");
                rename("tmp.txt","heart.txt");
                cout<<"Press any key to continue"<<endl;
                string s;
                cin>>s;
            }
            else if (s == "3") {
                ifstream f;
                f.open("heart.txt");
                display(f);
                f.close();
                cout<<"Press any key to continue"<<endl;
                string s;
                cin>>s;
            }
            else if (s == "4") {
                return;
            }
            else {
                cout << "Invalid entry!" << endl;
                _sleep(1000);
            }
        }
    }
};

class orthopedic:public clinic{

public:
    static void child(){
        while (1) {
            system("cls");
            pre();
            string s;
            cin >> s;
            if (s == "1") {
                ofstream f;
                f.open("orthopedic.txt",ios::app);
                add_patient(f);
                f.close();
                cout<<"Press any key to continue"<<endl;
                string s;
                cin>>s;
            }
            else if (s == "2") {
                system("cls");
                ifstream f;
                f.open("orthopedic.txt");
                take_to_doctor(f);
                f.close();
                remove("orthopedic.txt");
                rename("tmp.txt","orthopedic.txt");
                cout<<"Press any key to continue"<<endl;
                string s;
                cin>>s;
            }
            else if (s == "3") {
                ifstream f;
                f.open("orthopedic.txt");
                display(f);
                f.close();
                cout<<"Press any key to continue"<<endl;
                string s;
                cin>>s;
            }
            else if (s == "4") {
                return;
            }
            else {
                cout << "Invalid entry!" << endl;
                _sleep(1000);
            }
        }
    }
};

class ophthalmology:public clinic{

public:
    static void child(){
        while (1) {
            system("cls");
            pre();
            string s;
            cin >> s;
            if (s == "1") {
                ofstream f;
                f.open("ophthalmology.txt",ios::app);
                add_patient(f);
                f.close();
                cout<<"Press any key to continue"<<endl;
                string s;
                cin>>s;
            }
            else if (s == "2") {
                system("cls");
                ifstream f;
                f.open("ophthalmology.txt");
                take_to_doctor(f);
                f.close();
                remove("ophthalmology.txt");
                rename("tmp.txt","ophthalmology.txt");
                cout<<"Press any key to continue"<<endl;
                string s;
                cin>>s;
            }
            else if (s == "3") {
                ifstream f;
                f.open("ophthalmology.txt");
                display(f);
                f.close();
                cout<<"Press any key to continue"<<endl;
                string s;
                cin>>s;
            }
            else if (s == "4") {
                return;
            }
            else {
                cout << "Invalid entry!" << endl;
                _sleep(1000);
            }
        }
    }
};

class lung:public clinic{

public:
    static void child(){
        while (1) {
            system("cls");
            pre();
            string s;
            cin >> s;
            if (s == "1") {
                ofstream f;
                f.open("lung.txt",ios::app);
                add_patient(f);
                f.close();
                cout<<"Press any key to continue"<<endl;
                string s;
                cin>>s;
            }
            else if (s == "2") {
                system("cls");
                ifstream f;
                f.open("lung.txt");
                take_to_doctor(f);
                f.close();
                remove("lung.txt");
                rename("tmp.txt","lung.txt");
                cout<<"Press any key to continue"<<endl;
                string s;
                cin>>s;
            }
            else if (s == "3") {
                ifstream f;
                f.open("lung.txt");
                display(f);
                f.close();
                cout<<"Press any key to continue"<<endl;
                string s;
                cin>>s;
            }
            else if (s == "4") {
                return;
            }
            else {
                cout << "Invalid entry!" << endl;
                _sleep(1000);
            }
        }
    }
};

//#define endl "\n"
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1) {
        system("cls");
        cout << "---- Welcome to our hospital! ----" << endl << endl;
        cout << "Please enter section" << endl;
        cout << "1 - General clinic" << endl;
        cout << "2 - Heart clinic" << endl;
        cout << "3 - Orthopedic clinic" << endl;
        cout << "4 - Ophthalmology clinic" << endl;
        cout << "5 - Lung clinic" << endl;
        cout << "6 - Exit" << endl;
        string s;
        cin >> s;
        if (s == "1") {
            general::child();
        }
        else if (s == "2") {
            heart::child();
        }
        else if (s == "3") {
            orthopedic::child();;
        }
        else if (s == "4") {
            ophthalmology::child();
        }
        else if (s == "5") {
            lung::child();
        }
        else if (s == "6") {
            break;
        }
        else {
            cout << "Invalid entry!" << endl;
            _sleep(1000);
        }
    }
    return 0;
}
