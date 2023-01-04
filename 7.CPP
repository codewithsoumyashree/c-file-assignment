// 7.Given a binary file TELE.DAT, containing records of the following class :
// Write a C++ program to perform the following operations:
// I.Write objects of Directory class to the file TELE.DAT.
// II.Sort the objects according to the area code.
// III.Insert a new entry into the sorted file at appropriate location.
// IV.Delete an object having a given phone no.
// Write a function COPYABC() in C++ that would copy only those records having area code as “123” from TELE.DAT to TELEBACK.DAT.

#include <iostream>
#include <fstream>
using namespace std;

class Directory
{
    char Name[20];
    char Address[30];
    int areacode;
    int phno;

public:
    void Register()
    {
        cout << "Enter Name, Address, areacode and phone number \n";
        cin >> Name >> Address >> areacode >> phno;
    }
    void show()
    {
        cout << "Name : " << Name << endl;
        cout << "Address : " << Address << endl;
        cout << "areacode : " << areacode << endl;
        cout << "phone number : " << phno << endl;
    }
    void SORT(Directory D[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (D[j].areacode > D[j + 1].areacode)
                {
                    Directory temp;
                    temp = D[j];
                    D[j] = D[j + 1];
                    D[j + 1] = temp;
                }
            }
        }
    }
    int checkcode(int AC)
    {
        if (areacode == AC)
            return AC;
        else
            return 0;
    }
    int check_phno(int PHNO)
    {
        if(phno == PHNO)
        return 3;
        else
        return 1;
        
    }
    int COPYABC(int cn)
    {
        if(areacode == cn)
        return 3;
        else
        return 1;
    }
};

int main()
{
    fstream inoutfile,inoutfile2,inoutfile3;
    inoutfile.open("q7tele.txt", ios::in | ios::out | ios::ate | ios::binary);
    inoutfile.seekg(0, ios::beg);
    cout << "Enter the Number of Records \n";
    int n;
    cin >> n;
    Directory S[n],s1;
    cout << "Now Enter the Details of the Records \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Records : " << i + 1 << " ";
        S[i].Register();
        inoutfile.write((char *)&S[i], sizeof(S[i]));
    }
    inoutfile.clear();
    cout<<"Sorting \n";
    s1.SORT(S,n);
    cout<<"Displaying the sorted file \n";
    for (int i = 0; i < n; i++)
    {
            inoutfile.read((char *)&S[i], sizeof(S[i]));
            S[i].show();
    }


    cout<<"Enter a location for inserting new data "<<endl;
    int newdata;
    cin>>newdata;
    S[newdata].Register();
    inoutfile.write((char *)&S[newdata], sizeof(S[newdata]));
    cout<<"Displaying the modified  file \n";
    for (int i = 0; i < n; i++)
    {
            inoutfile.read((char *)&S[i], sizeof(S[i]));
            S[i].show();
    }
    inoutfile.clear();

    cout<<"Enter The Phone Number to delete \n";
    int PHNO;
    cin>>PHNO;
    inoutfile2.open("q7tele2.txt", ios::in | ios::out | ios::ate | ios::binary);
    for (int i = 0; i < n; i++)
    {
            inoutfile.read((char *)&S[i], sizeof(S[i]));
            if(S[i].check_phno(PHNO) == 1)
            inoutfile2.write((char *)&S[i], sizeof(S[i]));           
    }
    remove("q7tele.txt");
    rename("q7tele2.txt","q7tele.txt");
    inoutfile2.clear();
    inoutfile3.open("q7teleback.txt", ios::in | ios::out | ios::ate | ios::binary);
    for (int i = 0; i < n; i++)
    {
        inoutfile.read((char *)&S[i], sizeof(S[i]));
        if (S[i].COPYABC(123) == 3)
        inoutfile3.write((char *)&S[i], sizeof(S[i]));
    }
    cout<<"Files Copied \n";
    return 0;
}
