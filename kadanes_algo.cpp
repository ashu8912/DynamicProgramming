#include<iostream>
using namespace std;

void kadanes_algo_find_max_sum_subarray(int *arr,int size){
    int max_sum_so_far=0;
    int current_sum=0;
    int index;
    for(int i=0;i<size;i++)
    {
      current_sum=current_sum+arr[i];
      if(current_sum<0)
      {
        current_sum=0;
      }
      if(max_sum_so_far<current_sum)
      {
        max_sum_so_far=current_sum;
        index=i;
      }
    }
    //print the sub array that has largest sum
    int sum=0,start_of_sub_array=index;
    while(sum!=max_sum_so_far){
       sum=sum+arr[start_of_sub_array];
       start_of_sub_array--;
    }
    for(int i=start_of_sub_array+1;i<index;i++)
    {
      cout<<arr[i]<<" ";
    }

}
int main(){
  int arr[]={-5,-3,4,2,12,10,-8,-12,9};

    kadanes_algo_find_max_sum_subarray(arr,9);
}