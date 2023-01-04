#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class DRINKS
{
int DCODE;
char DNAME[15];
int DSIZE;
float DPRICE;
public:
void getdrinks()
{
cout<<"Enter drink code : ";
cin>>DCODE;
cout<<"Enter drink name : ";
cin>>DNAME;
cout<<"Enter drink size : ";
cin>>DSIZE;
cout<<"Enter drink price : ";
cin>>DPRICE;
}
void showdrinks()
{
cout<<"Drink code : "<<DCODE<<endl;
cout<<"Drink name : "<<DNAME<<endl;
cout<<"Drink size : "<<DSIZE<<endl;
cout<<"Drink price : "<<DPRICE<<endl;
}
char *getchar()
{
return DNAME;
}
};
int main()
{
DRINKS d[4];
fstream f1;
f1.open("drink.dat", ios::in | ios::out);
int i;
for(i=0; i<4; i++)
{
d[i].getdrinks();
f1.write((char *)&d[i], sizeof(d[i]));
}
f1.seekg(0);
for(i=0; i<4; i++)
{
f1.read((char *)&d[i], sizeof(d[i]));
if(strcmp(d[i].getchar(), "COCA-COLA")==0)
d[i].showdrinks();
}
f1.close();
return 0;
}