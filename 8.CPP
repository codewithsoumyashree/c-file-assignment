// 8.Write a C++ program to implement the GRADING system of KIIT University. The system will maintain the marks of a student in various subjects using the following class:

// Include appropriate member functions :

// I.To calculate the sgpa based on the marks received.
// II.To re-calculate the sgpa after new marks received after improvement examination, for a particular roll no student.
// III.To delete an object for a particular roll no student, after he/she quits from the course.
// IV.Sort the file according to batch.

#include <iostream>
#include <fstream>
using namespace std;

class student
{
    int Rollno;
    int marks[3];
    float sgpa;
    int semester;
    char branch[15];
    int batch;

public:
    void Details()
    {
        cout << "Enter Roll Number :";
        cin >> Rollno;
        cout << "Enter marks in 3 subjects \n";
        cin >> marks[0] >> marks[1] >> marks[2];
        sgpa = (marks[0] >> marks[1] >> marks[2]) / 3.0;
        cout << "Enter The Semester \n";
        cin >> semester;
        cout << "Enter The Branch \n";
        cin >> branch;
        cout << "Enter the batch \n";
        cin >> batch;
    }
    void Display()
    {
        cout << "Roll Number : " << Rollno << endl;
        cout << "SGPA : " << sgpa << endl;
        cout << "Semester : " << semester << endl;
        cout << "Branch : " << branch << endl;
        cout << "Batch : " << batch << endl;
    }
    void recalculate(student S[], int i)
    {
        cout << "Enter the new marks : " << endl;
        cin >> S[i].marks[0] >> S[i].marks[1] >> S[i].marks[2];
        S[i].sgpa = (S[i].marks[0] >> S[i].marks[1] >> S[i].marks[2]) / 3.0;
    }
    int remove_stud(int r)
    {
        if (Rollno == r)
            return 3;
        else
            return 1;
    }
    void SORT(student D[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (D[j]. batch > D[j + 1].batch)
                {
                    student temp;
                    temp = D[j];
                    D[j] = D[j + 1];
                    D[j + 1] = temp;
                }
            }
        }
    }
};
int main()
{
    fstream inoutfile, inoutfile2;
    inoutfile.open("q5book.txt", ios::in | ios::out | ios::ate | ios::binary);
    inoutfile.seekg(0, ios::beg);
    cout << "Enter the Number of Students \n";
    int n;
    cin >> n;
    student S[n], S1;
    cout << "Now Enter the Details of the Students \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Student : " << i + 1 << " ";
        S[i].Details();
        inoutfile.write((char *)&S[i], sizeof(S[i]));
    }
    inoutfile.seekg(0, ios::beg);
    cout << "Displaying Records of students \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Student : " << i + 1 << " ";
        S[i].Display();
    }
    int i;
    cout << "Enter the Number of the student who went for improvement exam \n";
    cin >> i;
    S1.recalculate(S, i);
    inoutfile.clear();
    inoutfile2.open("q8stud2.txt", ios::in | ios::out | ios::ate | ios::binary);
    cout << "Enter the Roll number of the student who left \n";
    int rno;
    cin >> rno;
    for (int i = 0; i < n; i++)
    {
        inoutfile.read((char *)&S[i], sizeof(S[i]));
        if (S[i].remove_stud(rno) != 0)
            inoutfile2.write((char *)&S[i], sizeof(S[i]));
    }
    remove("q8stud.txt");
    rename("q8stud2.txt", "q8stud.txt");
    cout<<"Sorting \n";
    S1.SORT(S,n);

    cout << "Displaying Modified Records of students \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Student : " << i + 1 << " ";
        S[i].Display();
    }
    return 0;
}
