/*Justin Nail                                                                 *
 *compiler : Dev-C++                                                          *
 *OS : Windows Vista                                                          *
 *Description :                                                               *
 *simulates a drunk wandering an island to determine if he drowns or survives */
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void initial(int[][20],int,int);
void print(int[][20],int,int);
bool drunk(int[][20],int,int);
void search(int[][20],int,int,int&,int&);


int main()
{
    bool drown;
    int row=20,col=20;
    int island[20][20];
    
    initial(island,row,col);//calls initialization function
    print(island,row,col);//prints
    drown=drunk(island,row,col);//calls drunk function returns true if drowned
    print(island,row,col);//prints
    if(drown)
        cout<<"the drunk drowned"<<endl;
    if(!drown)
        cout<<"the drunk made it off the island"<<endl;
       
    system("pause");
    return 0;
}
void initial(int island[][20],int row,int col)
{
    int i,j,brow=0,bcol=0,srow,scol,wrow=0,wcol=0;
    
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            island[i][j]=0;//sets every space to 0
    
    for(j=0;j<col;j++)//makes the sides -1
    {
        island[0][j]=-1;
        island[row-1][j]=-1;
    }
    for(i=0;i<row;i++)//makes the top and bottom -1
    {
        island[i][0]=-1;
        island[i][col-1]=-1;
    }
    
    while(!(wrow==20 && wcol==20))//gets additional water spaces from user
    {
        cout<<"input coordinates(0-19) (0-19)of additional water";
        cout<<",input \"20 20\" to stop: ";
        cin>>wrow>>wcol;
        island[wrow][wcol]=-1;//set water locations to -1
    }
    
    while(!(brow==20 && bcol==20))//gets bridge locations from user
    {
        cout<<"input the bridges coordinates(0-19) (0-19)";
        cout<<",input \"20 20\" to stop: ";
        cin>>brow>>bcol;
        island[brow][bcol]=-8;//set bridge loactions to -8
    }
    //gets drunks starting location from the user
    cout<<"input the starting coordinates for the drunk: ";
    cin>>srow>>scol;
    island[srow][scol]=1;//set starting location to 1
    
}
void search(int island[][20],int row,int col,int &srow,int &scol)
{
    int i,j;
    //finds the starting location
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
           if(island[i][j]==1)
           {
                srow=i;//returns the row value through parameters
                scol=j;//returns the col value through parameters
            }
        }
    }                
}
void print(int island[][20],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cout<<setw(3)<<island[i][j];//print each element with set width of 3
        }
        cout<<endl;
    }
    //prints a key
    cout<<"-1 = water  -8 = bridge  0 = land"<<endl;
    cout<<"each step the space the drunk enters is incremented"<<endl;
}
bool drunk(int island[][20],int row,int col)
{
    int DrunkRow,DrunkCol,counter;
    //get location of drunk through DrunkRow and DrunkCol
    search(island,row,col,DrunkRow,DrunkCol);
  
    for(counter=0;;counter++)
    {
        if (counter == 15)
            print(island,row,col);//print every 15 steps
        //moves north    
        if (rand()%4 == 0)
            DrunkRow--;
        //moves east    
        if (rand()%4 == 1)
            DrunkCol++;
        //moves south    
        if (rand()%4 == 2)
            DrunkRow++;
        //move west    
        if (rand()%4 == 3)
            DrunkCol--;
            
        if (island[DrunkRow][DrunkCol]==-1)
            return true;//returns true if drunk drowns
        if (island[DrunkRow][DrunkCol]==-8)
            return false;//returns false if drunk reaches bridge
        island[DrunkRow][DrunkCol]++;//increment the space entered by drunk
    }
}
