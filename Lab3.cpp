/*Justin Nail                                                                 *
 *compiler : Dev-C++                                                          *
 *OS : Windows Vista                                                          *
 *Description :sums of the first 5 Billion numbers                            * 
 *          prints the current number and sum after every 250,000,000 numbers */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double number=0, sum=0;
    cout << setprecision(16);
    int count=1;
    //adds together every 250,000,000 numbers 20 times
    //to get the sum of the first 5 billion numbers
    while (count<=20)
    {
        double check=0;
        while (check<250000000)
        {
           number++;
           sum += number;
           check++;
        }
        //prints out in 3 columns, using c++ and c methods respectively
        cout <<setw(2)<<count<<setw(11)<<number<<setw(24)<<sum<<endl;
        printf("%2d%11.0f%24.15e\n", count, number, sum);
        
        count++;
    }
    system("pause");
    return 0;
    
}
