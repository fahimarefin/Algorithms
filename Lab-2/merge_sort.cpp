#include <bits/stdc++.h>
using namespace std;
class merge_sort{
public:

    void divide(int arr[],int str,int end){
        if(str>=end){
            return;
        }
        int mid=str+(end-str)/2;
        divide(arr,str,mid);
        divide(arr,mid+1,end);
        conquer(arr,str,mid,end);
    }

    void conquer(int arr[],int str,int mid,int end){
        int merge [end-str+1];
        int indx1=str;
        int indx2=mid+1;
        int x=0;
        while(indx1<=mid && indx2<=end){
            if(arr[indx1]<=arr[indx2]){
                merge[x++]=arr[indx1++];

            }else{
                merge[x++]=arr[indx2++];

            }
        }
        while(indx1<=mid){
            merge[x++]=arr[indx1++];
        }
        while(indx2<=end){
            merge[x++]=arr[indx2++];
        }
        for(int i=0, j=str; i<sizeof (merge)/sizeof (int); i++,j++){
            arr[j]=merge[i];
        }
    }

};
int main() {

     int arr[]={6,3,9,5,2,8};
     merge_sort obj1;
    int n=sizeof (arr)/sizeof (int);

    obj1.divide(arr,0,n-1);
    for (int i=0;i<n ;i++ ){
      cout<<arr[i]<<" ";
    }




}

