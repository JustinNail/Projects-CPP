/*Justin Nail                                                                 *
 *compiler : Dev-C++                                                          *
 *OS : Windows Vista                                                          *
 *Description : selection sort function           */
#include <iostream>
#include <iomanip>
void selectionSort (int[],bool,int);
void printArray(int[],int);
using namespace std;

int main()
{
    int arrayA[10]={376,1186,12,75,82,10,10,88,5,223};//the array
    bool flag = true;//true=ascending order
    int n = 10;//size of array
    
    printArray(arrayA,n);//prints
    cout<<endl;
    
    selectionSort(arrayA,flag,n);//sorts
    
    printArray(arrayA,n);//prints sorted
    
    system("pause");
    return 0;
}

void selectionSort (int array[],bool ascend,int n)
{
    int i,j,s,t;
    if(ascend)//checks to see what order to put it in
    {
        for (i = 0;(i < n); i++) 
        {
            s = i;//points to current smallest
            for (j = i + 1; j < n; j++) 
            {
                if (array[j] < array[s]) //checks to see if it is smaller than s
                {
                    s = j;//if so, s point to new smallest
                }
            }
            t = array[i];
            array[i] = array[s];//swaps
            array[s] = t;
        }
    }
    else
    {
        for (i = 0; i < n; i++) 
        {
            s = i;//points to current largest
            for (j = i + 1; j < n; j++) 
            {
                if (array[j] > array[s]) //checks to see if it is larger than s
                {
                    s = j;//if so, s point to new largest
                }
            }
            t = array[i];
            array[i] = array[s];//swaps
            array[s] = t;
        }
    }

    
    
}
void printArray (int array[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<array[i]<<endl;
    }
    
}
