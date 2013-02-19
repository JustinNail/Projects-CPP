/*Justin Nail                                                                 *
 *compiler : Dev-C++                                                          *
 *OS : Windows Vista                                                          *
 *Description : Finds sums and products of various sequences                  */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << setprecision(16);
    double n,total,sign;
    
    //total = 2/3 +3/4 + 4/5 +.....+ 999/1000
    total=0;
    for (n=2;n<=999.0;n++)
    {
        total=total + n/(n+1.0);
    }
    cout<<total<<endl;
    
    //total = 1 - 1/2 + 1/3 - 1/4 + 1/5 - ..... +- 1/1000
    sign=1;
    total=0;
    for (n=1;n<=1000.0;n++)
    {
        total=total + sign*(1/n);
        sign=sign*-1;
    }
    cout<<total<<endl;
    
    //total = 1 - 3^2 + 5^2 - 7^2 +9^2 - ...... +- 101^2
    total=0;
    sign=1;
    for (n=1;n<=101.0;n=n+2)
    {
        total=total + sign*(n*n);
        sign=sign*-1;
    }   
    cout<<total<<endl;
    
    //total = 1/2 + 1/4 + 1/8 + 1/16 + ...... + 1/(2^32) 
    total=0;
    for (n=2;n<=4294967296.0;n=n*2)//4,294,967,296 = 2^32
    {
        total=total + 1/n;
    }
    cout<<total<<endl;
    
    //total = 1 * 1/2 * 2/3 * 3/4 * 4/5 *.....* 50/51
    total=1;
    for (n=1;n<=50.0;n++)
    {
        total=total * (n/(n+1.0));
    }
    cout<<total<<endl;
    
    system("pause");
    return 0;
}
