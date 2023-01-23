
#include<bits/stdc++.h>
using namespace std;
class Activity{
public:
    int start;
    int finish;
};
bool compare(Activity S1,Activity S2){
    return (S1.finish<S2.finish);
}
void maxmimumTaskSelection(int n,Activity arr[]){
    sort(arr,arr+n,compare);
    cout<<"Following activities are selected:"<<endl;
    int count=1;
    int last=0;
      cout<<"("<<arr[last].start<<","<<arr[last].finish<<")";

    for(int i=1; i<n; i++){
        if(arr[i].start>=arr[last].finish){
                count++;
                 cout<<"("<<arr[i].start<<","<<arr[i].finish<<")";
                last=i;

        }
    }
    cout<<endl;
    cout<<"The number of activities are:"<<count;


}
int main(){
    Activity arr[]={{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}};
                                      int n=sizeof(arr)/sizeof(arr[n]);
                                       maxmimumTaskSelection(n,arr);

}
