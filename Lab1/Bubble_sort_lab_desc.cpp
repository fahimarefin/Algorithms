
#include<bits/stdc++.h>

using namespace std;
#define n 1000
int data[n];
class Bubble_Sort{
public:

 void myfileWrite();
 void myfileRead();
  void bubble_sort();
  void PrintValues();
};
void Bubble_Sort:: myfileWrite(){
    ofstream myfile("C:\\Users\\Fahim Arefin\\Desktop\\file\\fahims.txt");
    for(int i=0; i<n; i++){
        myfile<<rand()<<" "<<endl;
    }
    myfile.close();
}
void Bubble_Sort::myfileRead(){
    string data1;
    int i=0;
    ifstream MyreadFile("C:\\Users\\Fahim Arefin\\Desktop\\file\\fahims.txt");
    cout<<"After reading The values from file:"<<endl;
    while(getline(MyreadFile,data1)){
       data[i]=stoi(data1);
       cout<<data[i]<<" ";
       i++;
    }
    cout<<endl;

}

void Bubble_Sort::bubble_sort(){
    for(int i=0; i<n; i++){
            int flag=0;
        for(int j=0; j<n-i; j++){
            if(data[j]<data[j+1]){
                int temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }

}

void Bubble_Sort::PrintValues(){
    cout<<"After the bubble sort algo the values are:"<<endl;
    for(int i=0; i<n; i++){
        cout<<data[i]<<" ";
    }
}





int main(){

    clock_t start,end,start1,end1;
    Bubble_Sort obj1;
    start1=clock();
    obj1.myfileWrite();
    obj1.myfileRead();
    end1=clock();
    double time_taken1 = ((double)(end1-start1))/CLOCKS_PER_SEC;
    cout<<endl;
    cout<<"Time taken for rand values:"<<time_taken1<<endl;

    start=clock();
    obj1.bubble_sort();
    obj1.PrintValues();
    end=clock();
    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    cout<<endl;
    cout<<"Time taken for sorting:"<<time_taken;


}





