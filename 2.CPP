#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class student
{
int addno;
char name[90];
float totalmarks;
public:
void getinfo()
{
cout<<"Enter admission number : ";
cin>>addno;
cout<<"Enter name : ";
cin>>name;
cout<<"Enter total marks : ";
cin>>totalmarks;
}
void showinfo()
{
cout<<"Admission number : "<<addno<<endl;
cout<<"Name : "<<name<<endl;
cout<<"Total marks : "<<totalmarks<<endl;
}
float rettotmarks ()
{
return totalmarks;
}
};
int main()
{
student s[4];
fstream f2;
f2.open("student.dat", ios::in | ios::out);
int i;
for(i=0; i<4; i++)
{
s[i].getinfo();
f2.write((char *)&s[i], sizeof(s[i]));
}
for(i=0; i<4; i++)
{
f2.read((char *)&s[i], sizeof(s[i]));
if(s[i].rettotmarks()>=456 && s[i].rettotmarks()<=498)
s[i].showinfo();
}
f2.close();
return 0;
}