// Following is the structure of each object in a data file named“PRODUCT.DAT”.
// Write a function in C++ to update the file with a new value of stock. The value of stock and the PCODE , whose stock to be updated are read during the execution of the program.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class PROD
{
    char PCODE[100];
    char DESC[100];
    int stock;

public:
    void Enter_Market()
    {
        cout << "Enter the code of product \n";
        cin >> PCODE;
        cout << "Enter the Description of product \n";
        cin >> DESC;
        cout << "Enter the value of stock \n";
        cin >> stock;
    }
    void Display()
    {
        cout << "The code of product : " << PCODE << endl;
        cout << "The Description of product : " << DESC << endl;
        cout << "The Number of stock : " << stock << endl;
    }
    int Update_Value(PROD p[], int i, int stock1, char *PCODE1)
    {
        if (p[i].stock == stock1 && (strcmp(PCODE, PCODE1)) == 0)
            return 3;
        else
            return 0;
    }
};

int main()
{
    fstream inoutfile;
    inoutfile.open("q6product.txt", ios::in | ios::out | ios::ate | ios::binary);
    inoutfile.seekg(0, ios::beg);
    cout << "Enter the Number of stocks \n";
    int n;
    cin >> n;
    PROD S[n];
    cout << "Now Enter the Details of the stocks \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Book : " << i + 1 << " ";
        S[i].Enter_Market();
        inoutfile.write((char *)&S[i], sizeof(S[i]));
    }
    for (int i = 0; i < n; i++)
    {
        S[i].Display();
    }
    cout << "Enter the value of the stock and product code to update \n";
    int stock1;
    char PCODE1[100];
    cin >> stock1 >> PCODE1;
    for (int i = 0; i < n; i++)
    {
        inoutfile.read((char *)&S[i], sizeof(S[i]));
        if (S[i].Update_Value(S, i, stock1, PCODE1) != 0)
            inoutfile.write((char *)&S[i], sizeof(S[i]));
    }
    cout << "Displaying Modified File \n";
    for (int i = 0; i < n; i++)
    {
        S[i].Display();
    }
    return 0;
}