#include<iostream>
#include<climits>
using namespace std;
void printSubArray(int *arr,int size){
    int *helperArray=new int[size];
    helperArray[0]=arr[0];
    for(int i=1;i<size;i++)
    {
      helperArray[i]=helperArray[i-1]+arr[i];
    }
   for(int i=0;i<size;i++)
   {
     for(int j=i;j<size;j++)
     {
       for(int k=i;k<=j;k++)
       {
         cout<<arr[k]<<" ";
       }
       cout<<"\n";
     }
   }
   cout<<"helper Array";
     
   for(int i=0;i<size;i++)
   {
     cout<<helperArray[i]<<" ";
   }
   delete[] helperArray;
}

void maxSumSubArray(int *arr,int size){
 int *helperArray=new int[size];
 int maxSum=INT_MIN;
    helperArray[0]=arr[0];
    for(int i=1;i<size;i++)
    {
      helperArray[i]=helperArray[i-1]+arr[i];
    }
    for(int i=0;i<size;i++)
   {
     for(int j=i;j<size;j++)
     {
       int sumOfSubArray;
             if(i==0 && j==0)
             {
             sumOfSubArray=helperArray[j];
             }else
             {
               sumOfSubArray=helperArray[j]-helperArray[i-1];
             }
             maxSum=maxSum<sumOfSubArray?sumOfSubArray:maxSum;
     }
   }
   cout<<"maxSum of all subArray "<<maxSum;
}
int main(){

  int arr[]={10,-5,-3,4,2,12,-8,-12,9};

  //printSubArray(arr,9);
  maxSumSubArray(arr,9);
}