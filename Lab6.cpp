/*Justin Nail                                                                 *
 *compiler : Dev-C++                                                          *
 *OS : Windows Vista                                                          *
 *Description : splits a program into two files, one with the comments and one*
                with the actual code                                          */
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    char ch;
    //declare file input and output variables
    ifstream indata;
    ofstream commentout;
    ofstream sourceout;
    
    //opens files
    indata.open("g:\\lab5.cpp");
    commentout.open("g:\\comment.dat");
    sourceout.open("g:\\source.dat");
    
    indata.get(ch);//get first character
    while(!indata.eof())//goes until there is no more data
    {
        if((ch=='/')&&(indata.peek()=='*'))//checks for /*
        {
            while(!((ch=='*')&&(indata.peek()=='/')))//goes until next */
            {
                commentout<<ch;//print to comment.dat
                indata.get(ch);//get next character
            }
            //prints the */ to comment.dat
            commentout<<ch;
            indata.get(ch);
            commentout<<ch;
            indata.get(ch);
            
            commentout<<endl;
        }
        if((ch=='/')&&(indata.peek()=='/'))//checks for //
        {
            while(ch!='\n')//goes until newline
            {
                commentout<<ch;//prints to comment.dat
                indata.get(ch);//get next character
            }
            commentout<<endl;//prints newline
        }
        
        sourceout<<ch;//if not a comment, prints to source.dat
        indata.get(ch);//gets next character
    }
    
    return 0;
}
