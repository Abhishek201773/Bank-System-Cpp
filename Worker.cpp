#include<bits/stdc++.h>
using namespace std;
const int LEN = 25;

class Person {
    string name;
    int age;
public:
    void readperson();
    void displayperson() {
        cout << "Name: " << name << "\tAge: " << age << endl;
    }
};

void Person::readperson() {
    cout << "Enter Name of Person: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
}

class Student : public Person {
    int rollno;
    float average;
public:
    void readstudent() {
        readperson();
        cout << "Enter Roll no: ";
        cin >> rollno;
        cout << "Enter Average Marks: ";
        cin >> average;
    }
    void disp_rollno() {
        cout << "Roll no: " << rollno << "\n";
    }
    float getaverage() {
        return average;
    }
};

class GradStudent : public Student {
    string subject;
    char working;
public:
    void readit();
    void display() {
        displayperson();
        cout << "Subject: " << subject << endl;
        cout << "Working: " << working << endl;
    }
    char workstatus() {
        return working;
    }
};

void GradStudent::readit() {
    readstudent();
    cout << "Enter Main Subject: ";
    cin.ignore();
    getline(cin, subject);
    cout << "Working (Y/N): ";
    cin >> working;
}

int main() {
    const int size = 5;
    GradStudent grad[size];
    int year, num_working = 0, non_working = 0, div1 = 0, total = 0;
    float topscore s= 0, score;
    int number = -1;

    cout << "Enter Year: ";
    cin >> year;

    for (int i = 0; i < size; i++) {
        cout << "Enter Details for Graduate " << i + 1 << " \n";
        grad[i].readit();
        total++;
        if (grad[i].workstatus() == 'Y' || grad[i].workstatus() == 'y') {
            num_working++;
        } else {
            non_working++;
        }
        score = grad[i].getaverage();
        if (score > topscore) {
            topscore = score;
            number = i;
        }
        if (score > 60.0) {
            div1++;
        }
    }

    cout << "\n\tReport for the Year " << year << endl;
    cout << "\t-------------------\n";
    cout << "Working Grad: " << num_working;
    cout << "\t Non-working: " << non_working << endl;
    
    if (number != -1) {
        cout << "Detail of the Top Scorer:\n";
        grad[number].display();
        cout << "\t Average Marks: " << grad[number].getaverage() << " \n";
    }

    float nwperc = ((float)non_working / (float)total) * 100;
    float wperc = ((float)div1 / (float)total) * 100;
    
    cout << "\t " << nwperc << "% of the graduates this year are non-working and \n";
    cout << wperc << "% are first division\n";

    return 0;
}
