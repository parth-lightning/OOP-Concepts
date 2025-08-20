#include <iostream.h>
#include <conio.h>

class Student {
    int roll;
    char name[30];
    int math, eng, phy, chem, cs;
    float percentage;
    char grade[15];

    void copyStr(char dest[], char src[]) {
        int i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

public:
    Student() {
        roll = 0;
        name[0] = '\0';
        math = eng = phy = chem = cs = 0;
        percentage = 0;
        grade[0] = '\0';
    }

    Student(int r, char n[], int m, int e, int p, int c, int s) {
        roll = r;
        copyStr(name, n);
        math = m;
        eng = e;
        phy = p;
        chem = c;
        cs = s;
        calculate();
    }

    ~Student() {
        cout << "\nDestructor called for Roll No: " << roll;
    }

    void input() {
        cout << "\nEnter Roll No: ";
        cin >> roll;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Maths Marks: ";
        cin >> math;

        cout << "Enter English Marks: ";
        cin >> eng;

        cout << "Enter Physics Marks: ";
        cin >> phy;

        cout << "Enter Chemistry Marks: ";
        cin >> chem;

        cout << "Enter CS Marks: ";
        cin >> cs;

        calculate();
    }

    void calculate() {
        int total = math + eng + phy + chem + cs;
        percentage = (total * 100.0) / 500;

        if (percentage >= 60)
            copyStr(grade, "First");
        else if (percentage >= 50)
            copyStr(grade, "Second");
        else if (percentage >= 40)
            copyStr(grade, "Pass");
        else
            copyStr(grade, "Fail");
    }

    void display() {
        cout << "\nRoll No: " << roll;
        cout << "\nName: " << name;
        cout << "\nMarks: Math=" << math << ", Eng=" << eng
             << ", Phy=" << phy << ", Chem=" << chem << ", CS=" << cs;
        cout << "\nPercentage: " << percentage;
        cout << "\nClass: " << grade << "\n";
    }
};

int main() {
    clrscr();

    Student s[20];
    int count = 0;
    int choice;

    do {
        cout << "\n===== Student Management Menu =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                if (count < 20) {
                    s[count].input();
                    count++;
                } else {
                    cout << "\nMaximum student limit reached!";
                }
                break;

            case 2:
                if (count == 0) {
                    cout << "\nNo students added yet!";
                } else {
                    for (int i = 0; i < count; i++) {
                        cout << "\n--- Student " << (i+1) << " ---";
                        s[i].display();
                    }
                }
                break;

            case 3:
                cout << "\nExiting program...";
                break;

            default:
                cout << "\nInvalid choice! Try again.";
        }

    } while(choice != 3);

    getch();
    return 0;
}
