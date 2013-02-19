/*Justin Nail                                                                 *
 *compiler : Dev-C++                                                          *
 *OS : Windows Vista                                                          *
 *Description : read data from a file into a structure, sorts the structure,  *
 *              and prints the structure, uses dynamic memory                 
 
 */
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

void read();
void GPA(studentType);
void print(studentType,float);


int main()
{  
    int i,j,k;
    float totalGPA=0;
//initializes the array
    cout<<"reading"<<endl;        
    read();//reads and sorts the student info from a file
    cout<<"read"<<endl;
    
         
    system("pause");
    return 0;
}


void read()
{
    int i,j,k;
    char ch;
    studentType *newNode,*current,*first=NULL,*last=NULL;
    
    
    //declare variable and open file
    ifstream indata;
    indata.open("g:\\ClassGPA.txt");
    
    while(!indata.eof())//until end of file
    {
        newNode=new studentType;
        indata.get(ch);//get first character
        while(ch!='\n')
        //goes until end of line
        {         
            
            for(j=0;j<15;j++)
            {
                newNode->LastName[j]=ch;//insert into LastName
                indata.get(ch);//get next char
            }

            for(j=0;j<10;j++)
            {
                newNode->FirstName[j]=ch;//insert into FirstName
                indata.get(ch);//get next char
            }
        
            newNode->MI=ch;//insert into MI
            indata.get(ch);//get next char
        
            for(k=0;k<7&&ch!='\n';k++)
            {
                for(j=0;j<4;j++)
                {
                    newNode->ClassID[k][j]=ch;//insert into ClassID
                    indata.get(ch);//get next char
                }
                newNode->ClassGrade[k]=ch;//insert into ClassGrade
                indata.get(ch);//get next char
            } 
            GPA(*newNode);
            current=first;
            if(first==NULL)
            {
                first=newNode;
                last=newNode;
            }
        
            else if(newNode->GPA > first->GPA)
            {
                newNode->next=first;
                first=newNode;
            }
            else
            {
                while((current!=NULL)&&(newNode->GPA < current->next->GPA))
                {
                    cout<<"stuck"<<endl;
                    current=current->next;
                }
                newNode->next=current->next;
                current->next=newNode;
            }
            cout<<"inner"<<endl;
            system("pause");
        }
        cout<<"outer"<<endl;
        system("pause");       
    }
    cout<<"printing"<<endl;
    print(*first,0);//prints structure to file
    cout<<"done"<<endl;
    
}



void GPA(studentType students)
{
    int i,j,s,nClasses,total=0;
    float totalGPA=0;
    studentType temp;
    for(i=0;i<200;i++)
    {
        nClasses=0;
        for(j=0;j<7;j++)
        { 

            switch(students.ClassGrade[j])
            {
                case 'A':case 'B':case 'C': case 'D': case 'F':
                    nClasses++;//find the number of classes the student took
                    break;
                default:break;
            }
        }

        for(j=0;j<nClasses;j++)
        {
            switch(students.ClassGrade[j])
            {
                case 'A':students.GPA+=4.0;//A=4                   
                    break;
                case 'B':students.GPA+=3.0;//B=3 
                    break;
                case 'C':students.GPA+=2.0;//C=2 
                    break; 
                case 'D':students.GPA+=1.0;//E=1 
                    break;
                case 'F':students.GPA+=0.0;//F=0 
                    break;
                default:break;
            }
       }
        students.GPA=students.GPA/nClasses;//calculate GPA
    }
    for (i = 0;i <200; i++) 
    {
        switch(students.ClassGrade[0])
            {
                case 'A':case 'B':case 'C': case 'D': case 'F':
                totalGPA+=students.GPA;//add all the GPAs together
                total++;//actual number of students
                break;
                default:break;
            }
    }
    return; //totalGPA/total;//returns totalGPA(the GPAs together/actual number of students)
}


void print(studentType students,float totalGPA)
{
    int i,j,k;
    ofstream outdata;
    outdata.open("g:\\sortedGPA.txt");
    outdata<<totalGPA<<endl;
    
    for(i=0;i<10;i++)
    {
        for(j=0;j<15;j++)
        {
            outdata<<students.LastName[j];//prints LastName

        }
   
        for(j=0;j<10;j++)
        {
            outdata<<students.FirstName[j];//prints FirstName
        }        
        cout<<students.MI;//prints MI
        for(k=0;k<7;k++)
        {
            for(j=0;j<4;j++)
            {
                outdata<<students.ClassID[k][j];//prints ID
            }
            outdata<<' ';
            outdata<<students.ClassGrade[k];//prints Grade
            outdata<<' ';
        }
        outdata<<endl; 
        outdata<<students.GPA;//prints GPA
        outdata<<endl;     
    } 
}





















