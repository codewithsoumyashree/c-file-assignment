// Write a function in C++ to search for a BookNo from a binary file“BOOK.DAT”, assuming the binary file is containing the objects of the following class.


#include<iostream>
#include<fstream>
using namespace std;

class Book
{
    int Bno;
    char Title[30];

public:
    int RBno(int bno)
    {
        if(bno == Bno)
        return Bno;
        else
        return 0;
    }
    void Enter()
    {
        cin >> Bno;
        cin>>Title;
    }
    void Display()
    {
        cout <<"Book Number :"<< Bno <<endl<<"Title :"<< Title << endl;
    }
};
int main()
{
    fstream inoutfile;
    inoutfile.open("q5book.txt", ios::in | ios::out | ios::ate | ios::binary);
    inoutfile.seekg(0, ios::beg);
    cout << "Enter the Number of books \n";
    int n;
    cin >> n;
    Book S[n];
    cout << "Now Enter the Details of the books \n";
    for (int i = 0; i < n; i++)
    {
        cout<<"Book : "<<i+1<<" ";
        S[i].Enter();
        inoutfile.write((char *)&S[i], sizeof(S[i]));
    }
    cout<<"Enter the book number you want to search \n";
    int bno;
    cin>>bno;
    for (int i = 0; i < n; i++)
    {
        inoutfile.read((char *)&S[i], sizeof(S[i]));
        if (S[i].RBno(bno) != 0)
        {
            S[i].Display();
        }
    }
    return 0;
}