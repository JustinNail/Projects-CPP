/*Justin Nail                                                                 *
 *compiler : Dev-C++                                                          *
 *OS : Windows Vista                                                          *
 *Description : gets a number and checks to see if it meets certain criteria  *
 *              if it does it is multiplied by two and printed to screen      *
 *Errors: Requires another end-line character and returns 'Bad Data' if       *
 *           there are spaces after first number                              */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char ch;
    bool end=false,badData=false;

    
    while(!end)//repeats until user inputs crtl + z
    {
        int n=0,count=0;
        badData=false;//reset badData
        
        //gets number
        cout<<"Enter an Integer: ";
        cin.get(ch);
        end=cin.eof();
        
        //clears leading zeros
        while(ch==' ')
            cin.get(ch);
        
        while(ch!='\n')//go's until end of line
        {
            badData=false;//reset badData
            
            if((ch<'0'||ch>'9') && ch!=' ')//prints Bad Data if a digit is not a number
            {
                cout<<"Bad Data"<<endl;
                cin.clear();
                cin.ignore(100, '\n');
                badData=true;
                break;
            }

            count++;
            if (count > 9)//prints Bad Data if there are more than 9 digits
            {
                cout<<"Bad Data"<<endl;
                cin.clear();
                cin.ignore(100, '\n');
                badData=true;
                break;
            }
            
            while(ch==' ')//prints Bad Data if there is more than one number per line
            {
                cin.get(ch);
                if(ch!=' '||ch!='\n')
                {
                    cout<<"Bad Data"<<endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                    badData=true;
                    break;
                }
            }
            
            if(count==1)
                n=int(ch)-48;//converts first digit from ascii and puts in n
            else
                n=(n*10)+(int(ch)-48);//converts other digits from ascii and puts in correct slot in n
            
            cin.get(ch);
        }
        if(!badData)//doesn't print the number multiplied by 2 if there is bad data
        {  
            n=n*2;
            cout<<n<<endl;
        }
    }

    return 0;
}
