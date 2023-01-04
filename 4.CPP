// Given a binary file APPLY.DAT containing records of the following class Applicant type.
// Write a function in C++ that would read contents of file APPLY.DAT and display the details of those students whose A_score is above 70.

#include <iostream>
#include <fstream>
using namespace std;

class Applicant
{
    char Rno[10];
    char name[30];
    int A_score;

public:
    void enroll()
    {
        cin>>Rno;
        cin>>name;
        cin>>A_score;
    }

    void Status()
    {
        cout <<"ROLL NUMBER : "<< Rno <<endl<<"NAME :" << name <<endl<<"A_score :"<<endl<< A_score<< endl;
    }
    int ReturnScore()
    {
        if(A_score >= 70)
        return 3;
        else 
        return 0;
    }
};

int main()
{
    fstream inoutfile;
    inoutfile.open("q4apply.txt", ios::in | ios::out | ios::ate | ios::binary);
    inoutfile.seekg(0, ios::beg);
    cout << "Enter the Number of students \n";
    int n;
    cin >> n;
    Applicant S[n];
    cout << "Now Enter the Details of the students \n";
    for (int i = 0; i < n; i++)
    {
        cout<<"Student : "<<i+1<<" ";
        S[i].enroll();
        inoutfile.write((char *)&S[i], sizeof(S[i]));
    }
    for (int i = 0; i < n; i++)
    {
        inoutfile.read((char *)&S[i], sizeof(S[i]));
        if (S[i].ReturnScore() != 0)
        {
            S[i].Status();
        }
    }
    return 0;
}