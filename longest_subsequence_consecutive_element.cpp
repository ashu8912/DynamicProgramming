#include<iostream>

using namespace std;


void merge(int* arr,int p,int q,int r){
     
     int *newArray=new int[r-p];
     int i=p;
     int j=q+1,k=0;
     while(i<=q && j<=r)
     {
       if(arr[i]<arr[j])
       {
           
           newArray[k]=arr[i];
           i++;
           
       }else{
           newArray[k]=arr[j];
           j++;
       }
       k++;
     }
     while(i<=q)
     {
          newArray[k]=arr[i];
          i++;
          k++;
     }
     while(j<=r)
     {
         newArray[k]=arr[j];
         j++;
         k++;
     }
     int temp=0;
    
     
     for(int i=p;i<=r;i++)
     {
       arr[i]=newArray[temp];
       temp++;
     }
}

void mergeSort(int *arr,int start,int end){
           if(start<end)
           {
         int mid=(start+end)/2;    
         mergeSort(arr,start,mid);
         mergeSort(arr,mid+1,end);
         merge(arr,start,mid,end);  
           }
}

int longestSubsequenceConsecutive(int *arr,int size){
         int lenOfLargestConsecutiveSubsequence=0;
         int maxLength=0;
         for(int i=0;i<size;i++)
         {
           if((arr[i+1]-arr[i])==1)
           {
              lenOfLargestConsecutiveSubsequence++;
           }else{
             maxLength=maxLength<lenOfLargestConsecutiveSubsequence?maxLength:lenOfLargestConsecutiveSubsequence;
             lenOfLargestConsecutiveSubsequence=0;
           }
         }
         return maxLength;
}

int main(){
int arr[]={4,5,1,2,3};
    mergeSort(arr,0,4);
    int len=longestSubsequenceConsecutive(arr,4);
    cout<<len;
}