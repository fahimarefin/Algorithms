#include<bits/stdc++.h>
using namespace std;
class Item{
public:
    int value;
    int weight;
    Item(int v,int w){
       this->value=v;
       this->weight=w;
    }
};
bool compare(Item a,Item b){
    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;
    return r1>r2;

}

double fractionalKnapsack(Item arr[],int n,int W){
    for(int i=0; i<n; i++){
        cout<<arr[i].value<<" "<<arr[i].weight<<":"<<(double)arr[i].value/(double)arr[i].weight<<endl;
    }
    sort(arr,arr+n,compare);
    double finalValue=0.0;
    for(int i=0; i<n; i++){
        if(arr[i].weight<=W){
            W=W-arr[i].weight;
            finalValue=finalValue+arr[i].value;
        }else{
            finalValue=finalValue+arr[i].value*((double)W/(double)arr[i].weight);
            break;

        }

    }
    return finalValue;
}
int main(){
    int W=60;
    Item arr[]={{30,5},{40,10},{45,15},{77,22},{90,25}};
    int n=sizeof(arr)/sizeof(arr[n]);
    cout<<"Fractional Knapsack Value is:"<<fractionalKnapsack(arr,n,W);
}
