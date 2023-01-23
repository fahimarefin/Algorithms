#include<bits/stdc++.h>
using namespace std;
class Knapsack{
public:
    int max(int a,int b){
        if(a>b){
            return a;
        }else{
            return b;
        }
    }
    int knapsack(int capacity,int value[],int weight[],int n){
        int k[n+1][capacity+1];

        for(int i=0; i<=n; i++){
            for(int w=0; w<=capacity; w++){
                if(i==0 || w==0){
                    k[i][w]=0;
                }else if(weight[i-1]<=w){

                    k[i][w]=max(value[i-1]+k[i-1][w-weight[i-1]],k[i-1][w]);
                }else{
                    k[i][w]=k[i-1][w];
                }
            }
        }
        cout<<"Optimal:";
        return k[n][capacity];

    }
    void printknapSack(int W, int wt[], int val[], int n)
    {
        int i, w;
        int K[n + 1][W + 1];


        for (i = 0; i <= n; i++) {
            for (w = 0; w <= W; w++) {
                if (i == 0 || w == 0)
                    K[i][w] = 0;
                else if (wt[i - 1] <= w)
                    K[i][w] = max(val[i - 1] +
                                  K[i - 1][w - wt[i - 1]], K[i - 1][w]);
                else
                    K[i][w] = K[i - 1][w];
            }
        }


        int res = K[n][W];
        cout<<"Paths are:";
        cout<< res << " ";

        w = W;
        for (i = n; i > 0 && res > 0; i--) {

            if (res == K[i - 1][w])
                continue;
            else {
                cout<<" "<<wt[i - 1] ;
                res = res - val[i - 1];
                w = w - wt[i - 1];
            }
        }
    }




};
int main(){
    int capacity=5;
    int n=4;

    int value[]={12,10,20,15};
    int weight[]={2,1,3,2};
    Knapsack obj1;
    cout<<obj1.knapsack(capacity,value,weight,n);
    cout<<endl;
    obj1.printknapSack(capacity,weight,value,n);
}
