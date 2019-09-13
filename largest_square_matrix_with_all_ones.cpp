#include<iostream>
using namespace std;

void largestSquarematrixWithAllOnes(int arr[][4],int row,int col){
        
        int **newArray=new int*[row];
        for(int i=0;i<row;i++)
        {
             newArray[i]=new int[col]; 
        }
        for(int i=0;i<row;i++)
        {
          for(int j=0;j<col;j++)
          {
            if(i==0 || j==0 || arr[i][j]==0)
            {
              newArray[i][j]=arr[i][j];
              continue;
            }
           int min=0; 
           if(arr[i][j-1]<=arr[i][j])
           {
             min=arr[i][j-1];
           }
           if(arr[i-1][j]<=min)
           {
             min=arr[i-1][j];
           }    
           if(arr[i-1][j-1]<=min)
           {
             min=arr[i-1][j-1];
           }
          newArray[i][j]=arr[i][j]+min; 
          }
        }
      for(int i=0;i<row;i++)
      {
        for(int j=0;j<col;j++)
        {
          cout<<newArray[i][j]<<" ";
        }
        cout<<"\n"; 
      }  
}

int main(){
int arr[4][4]={{1,1,1,1},{0,0,1,1},{1,1,1,1},{0,1,1,1}};
largestSquarematrixWithAllOnes(arr,4,4); 

}