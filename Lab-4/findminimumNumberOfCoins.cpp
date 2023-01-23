#include<bits/stdc++.h>
using namespace std;

int deno[]={1,2,5,10,20,50,100,500,1000};
    int n=sizeof(deno)/sizeof(deno[n]);
     vector <int> ans;

class coinChange{
public:

    void findMin(int V){
        sort(deno,deno+n);

        for(int i=n-1; i>=0; i--){
           while(V>=deno[i]){
            V=V-deno[i];
            ans.push_back(deno[i]);
           }
        }
    }
    void printResult(){
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
    }
};
int main(){
    int v=91;
    coinChange obj1;
    obj1.findMin(v);
    obj1.printResult();
}
