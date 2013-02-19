/*Justin Nail                                                                 *
 *compiler : Dev-C++                                                          *
 *OS : Windows Vista                                                          *
 *Description : read data from a file into a structure, sorts the structure,  *
 *              and prints the structure                                      */
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
struct studentType
{
    char LastName[15];
    char FirstName[10];
    char MI;
    char ClassID[7][4];
    char ClassGrade[7];
    float GPA;    
    studentType *next;
};

void read(studentType[]);
float GPA(studentType[]);
void print(studentType[],float);


int main()
{  
    cout << setprecision(2);
    studentType students[200];//an array of students
    int i,j,k;
    float totalGPA;
    
    for(i=0;i<200;i++)//initializes the array
    {
        for(j=0;j<15;j++)
        {
            students[i].LastName[j]=' ';//fills LastName w/ spaces
        }

        
        for(j=0;j<10;j++)
        {
            students[i].FirstName[j]=' ';//fills FirstName w/ spaces
        }

        
        students[i].MI=' ';
        
        for(k=0;k<7;k++)
        {
            for(j=0;j<4;j++)
            {
                students[i].ClassID[k][j]=' ';//fills ClassIDs w/ spaces
            }
            students[i].ClassGrade[k]=' ';//fills ClassGrade w/ spaces
        }
        students[i].GPA=0;
    } 

 
    read(students);//reads the student info from a file
    totalGPA=GPA(students);//calculates and sorts by GPA, return total GPA
    print(students,totalGPA);//prints structure
         
    system("pause");
    return 0;
}


void read(studentType students[])
{
    int i,j,k;
    char ch;
    //declare variable and open file
    ifstream indata;
    indata.open("g:\\ClassGPA.txt");
    
    for(i=0;((i<200)&&(!indata.eof()));i++)
    //goes until there is no more data or reaches max number of students
    {         
        indata.get(ch);//get first character
        for(j=0;j<15;j++)
        {
            students[i].LastName[j]=ch;//insert into LastName
            indata.get(ch);//get next char
        }

        for(j=0;j<10;j++)
        {
            students[i].FirstName[j]=ch;//insert into FirstName
            indata.get(ch);//get next char
        }
        
        students[i].MI=ch;//insert into MI
        indata.get(ch);//get next char
        
        for(k=0;k<7&&ch!='\n';k++)
        {
            for(j=0;j<4;j++)
            {
                students[i].ClassID[k][j]=ch;//insert into ClassID
                indata.get(ch);//get next char
            }
            students[i].ClassGrade[k]=ch;//insert into ClassGrade
            indata.get(ch);//get next char
        } 

    }
    
}



float GPA(studentType students[])
{
    int i,j,s,nClasses,total=0;
    float totalGPA=0;
    studentType temp;
    for(i=0;i<200;i++)
    {
        nClasses=0;
        for(j=0;j<7;j++)
        { 

            switch(students[i].ClassGrade[j])
            {
                case 'A':case 'B':case 'C': case 'D': case 'F':
                    nClasses++;//find the number of classes the student took
                    break;
                default:break;
            }
        }

        for(j=0;j<nClasses;j++)
        {
            switch(students[i].ClassGrade[j])
            {
                case 'A':students[i].GPA+=4.0;//A=4                   
                    break;
                case 'B':students[i].GPA+=3.0;//B=3 
                    break;
                case 'C':students[i].GPA+=2.0;//C=2 
                    break; 
                case 'D':students[i].GPA+=1.0;//E=1 
                    break;
                case 'F':students[i].GPA+=0.0;//F=0 
                    break;
                default:break;
            }
       }
        students[i].GPA=students[i].GPA/nClasses;//calculate GPA
    }
    for (i = 0;i <200; i++)//sorts by GPA 
    {
        s = i;//points to current largest
        for (j = i + 1; j < 200; j++) 
        {
            if (students[j].GPA > students[s].GPA) //checks to see if it is largerer than s
            {
                s = j;//if so, s point to new largest
            }
        }
        temp = students[i];
        students[i] = students[s];//swaps
        students[s] = temp;
    }
    
    for (i = 0;i <200; i++) 
    {
        switch(students[i].ClassGrade[0])
            {
                case 'A':case 'B':case 'C': case 'D': case 'F':
                totalGPA+=students[i].GPA;//add all the GPAs together
                total++;//actual number of students
                break;
                default:break;
            }
    }
    return totalGPA/total;//returns totalGPA(the GPAs together/actual number of students)
}


void print(studentType students[],float totalGPA)
{
    int i,j,k;
    
    cout<<totalGPA<<endl;
    
    for(i=0;i<10;i++)
    {
        for(j=0;j<15;j++)
        {
            cout<<students[i].LastName[j];//prints LastName

        }
   
        for(j=0;j<10;j++)
        {
            cout<<students[i].FirstName[j];//prints FirstName
        }        
        cout<<students[i].MI;//prints MI
        for(k=0;k<7;k++)
        {
            for(j=0;j<4;j++)
            {
                cout<<students[i].ClassID[k][j];//prints ID
            }
            cout<<' ';
            cout<<students[i].ClassGrade[k];//prints Grade
            cout<<' ';
        }
        cout<<endl; 
        cout<<students[i].GPA;//prints GPA
        cout<<endl;     
    } 
}





















