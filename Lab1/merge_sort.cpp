#include <bits/stdc++.h>

using namespace std;
class merge_sort{
public:
    void divide(int arr[],int si,int ei) {
        if(si>=ei){
            return;
        }
        int mid = si+(ei-si)/2;
        divide(arr,si,mid);
        divide(arr,mid+1,ei);
        conquer(arr,si,mid,ei);
    }
    /*
    void divide(int arr[],int str,int end){
        if(str>=end){
            return;
        }
        int mid=str+(end-str)/2;
        divide(arr,str,mid);
        divide(arr,mid+1,end);
        conquer(arr,str,mid,end);
    }
     */
    /*
    void conquer(int arr[],int str,int mid,int end){
        int *merge =new int[end-str+1];
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
*/
    void conquer(int arr[],int si,int mid,int ei){
        int *merged=new int [ei-si+1];
        int idx1=si;
        int idx2=mid+1;
        int x=0;
        while(idx1<= mid && idx2<=ei){
            if(arr[idx1] <= arr[idx2]) {

                merged [x++] = arr[idx1++];
            }  else{
                merged [x++] = arr[idx2++];
            }
        }
        while(idx1 <= mid) {
            merged [x++] = arr[idx1++];
        }
        while(idx2 <= ei) {
            merged [x++] = arr[idx2++];
        }
        for(int i=0, j=si; i<6; i++,j++){
            arr[j] = merged [i];
        }
    }
};
int main() {

    /*
    int arr[6]={6,3,9,5,2,8};
    int n=sizeof (arr)/sizeof (int);
    merge_sort obj1;
    int str=0;
    int end=n-1;

    obj1.divide(arr,str,end);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
     */int arr[]={6,3,9,5,2,8};
     merge_sort obj1;
    int n=sizeof (arr)/sizeof (int);
    obj1.divide(arr,0,n-1);
    for (int i=0;i<n ;i++ ){
      cout<<arr[i]<<" ";
    }




}

