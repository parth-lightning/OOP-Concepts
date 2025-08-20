#include <iostream.h>
#include <conio.h>
#include <string.h>

class companies{
 char comp_name[10];
 char founder[20];
 int avg_sal;
 static int turnover;

 public:
  void get_data(char a[], char b[], int avg_sal, int turn);

  void display_data(){
   cout << comp_name <<", "<< founder <<", "<< avg_sal <<", "<< turnover<<endl;
  }
  void copy_fun(companies cop){
   this->avg_sal = cop.avg_sal;
  }
  companies dupli(){
   companies obj;
   obj.avg_sal = avg_sal;
   return obj;
  }
  companies(){
   comp_name[0] = '\0';
   founder[0] = '\0';
   turnover = 0;
   cout << "Constructor used" << endl;
  }
  companies(int a){
   a=0;
   this->avg_sal = a;
  }
  ~companies(){
   cout << "Destructor used!" << endl;
  }
  void change_sal(int new_sal);
};

int companies::turnover;
void companies::change_sal(int new_sal){
 avg_sal = new_sal;
 cout << "Average salary update to " << avg_sal << endl;
}
void companies::get_data(char a[], char b[], int avg_sal, int turn){
  int i;
  for (i = 0; a[i] != '\0'; i++) {
      comp_name[i] = a[i];
  }
  comp_name[i] = '\0';

  for (i = 0; b[i] != '\0'; i++) {
      founder[i] = b[i];
  }
  founder[i] = '\0';

  this->avg_sal = avg_sal;
  turnover = turn;
}

int main(){
 clrscr();
 companies c1,c2,c3;
 char name[20];
 char found[20];
 int av_sa,turni;
 cout << "Enter the turnover: ";
 cin >> turni;
 cout << "Enter the average salary: ";
 cin >> av_sa;
 cout << "Enter the company name: ";
 cin >> name;
 cout << "Enter the founder name: ";
 cin >> found;

 c1.get_data(name,found,av_sa,turni);
 c1.display_data();
 c2.copy_fun(c1);
 c2.display_data();
 c3 = c1.dupli();
 c3.display_data();
 c1.change_sal(600);
 c1.display_data();
 getch();
 return 0;
}
