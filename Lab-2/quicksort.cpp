#include <bits/stdc++.h>

using namespace std;
class quickSort{


public:
    int partition(int arr[],int low,int high){
        int pivot=arr[high];
        int i=low-1;
        for(int j=low; j<high; j++){
            if(arr[j]<pivot){
                i++;
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }

        }
        i++;
        int temp=arr[i];
        arr[i]=pivot;
        arr[high]=temp;
        return i;

    }
    void quick_sort(int arr[],int low,int high){
        if(low<high) {
            int pivot_indx = partition(arr, low, high);

            quick_sort(arr, low, pivot_indx - 1);
            quick_sort(arr, pivot_indx + 1, high);
        }
    }




};
int main() {
    int arr[6]={6,3,9,5,2,8};
    int n=6;
    int low=0;
    int high=n-1;
  quickSort obj1;
  obj1.partition(arr,low,high);
  obj1.quick_sort(arr,low,high);
  cout<<"Sorted array is:"<<endl;
  for(int i=0; i<n; i++){
      cout<<arr[i]<<" ";
  }
}

