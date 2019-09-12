#include<iostream>
using namespace std;

int* max_sum_increasing_subsequence(int *arr,int size){
       int *helperArr=new int[size];
       int j=0; 
       int temp,maxSum,sum;
       for(int i=0;i<size;i++)
       {
         maxSum=arr[i];
         j=i;
         temp=arr[j];
         
         while(j>0)
         {
             if(temp<arr[j-1])
             {
                 j--;
                continue;
            }else{
              sum=arr[i]+helperArr[j-1];
              if(sum>maxSum)
              {
                maxSum=sum;
              }
            }
           
           j--;
         }
          
          helperArr[i]=maxSum;
       }
return helperArr;
}

int main(){
      int arr[]={20,3,1,15,16,2,12,13};
      int *max_sum_arr=max_sum_increasing_subsequence(arr,8);
      for(int i=0;i<8;i++)
      {
           cout<<max_sum_arr[i]<<" ";
      }
}