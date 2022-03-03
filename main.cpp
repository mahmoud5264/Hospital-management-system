#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N =55 , MOD = 1e9+7 , oo = 1e18;


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
    }
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

    string getlname() {
        return lname;
    }

    void setage() {
        cout << "Please enter age: " << endl;
        string s;
        cin >> s;
        if (not_number(s)) {
            cout << "Age must be number!" << endl;
            setage();
        }
        age = str_to_int(s);
        if (age <= 0) {
            cout << "Age must be positive" << endl;
            setage();
        }
    }

    int getage() {
        return age;
    }

    void setphone() {
        cout << "Please enter phone number: " << endl;
        cin >> phoneNumber;
        if (not_number(phoneNumber)) {
            cout << "Phone must be only numbers!" << endl;
            setlname();
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
        if (!yes) {
            cout << "Not valid blood type!" << endl;
            setblood();
        }
        if (blood[0] >= 'a')blood[0] -= 32;
        if (blood.length() == 3 && blood[1] >= 'a') {
            blood[1] -= 32;
        }
    }

    string getblood() {
        return blood;
    }

    void display() {
        cout << "--Patient details--" << endl;
        cout << "First name: " << fname << endl;
        cout << "Last name: " << lname << endl;
        cout << "First name: " << fname << endl;
        cout << "Blood type: " << blood << endl;
        cout << "Phone number: " << phoneNumber << endl;
    }

    patient() {
        system("cls");
        setfname();
        setlname();
        setblood();
        setage();
        setphone();
        display();
        _sleep(1000);
    }

};

queue<patient>general;
queue<patient>heart;
queue<patient>orthopedic;
queue<patient>ophthalmology;
queue<patient>lung;

class clinic {

public:

    static void main(queue<patient> &patients) {
        while (1) {
            system("cls");
            cout << "Please enter your choice" << endl;
            cout << "1 - Add new patient" << endl;
            cout << "2 - Take patient to Doctor" << endl;
            cout << "3 - Display list of patients in the section" << endl;
            cout << "4 - Return to the main menu" << endl;
            string s;
            cin >> s;
            if (s == "1") {
                patient p;
                patients.push(p);
            }
            else if (s == "2") {
                system("cls");
                if (patients.empty()) {
                    cout << "There is already no patients in the clinic!" << endl;
                } else {
                    cout << "Patient who will enter to the Doctor:" << endl;
                    patients.front().display();
                    patients.pop();
                }
                _sleep(1000);
            }
            else if (s == "3") {
                system("cls");
                queue<patient> q;
                while (!patients.empty()) {
                    q.push(patients.front());
                    patients.front().display();
                    patients.pop();
                    cout << endl;
                }
                patients = q;
                cout << "Press any key to continue" << endl;
                string s;
                cin >> s;
            } else if (s == "4") {
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
        cout << "Welcome to our hospital!" << endl;
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
            clinic::main(general);
        }
        else if (s == "2") {
            clinic::main(heart);
        }
        else if (s == "3") {
            clinic::main(orthopedic);
        }
        else if (s == "4") {
            clinic::main(ophthalmology);
        }
        else if (s == "5") {
            clinic::main(lung);
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
