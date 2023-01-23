
#include<bits/stdc++.h>
using namespace std;
#define n 100
int data[n];
class Insertion_sort{
public:

 void myfileWrite();
 void myfileRead();
  void InsertionSort();
  void PrintValues();
};
void Insertion_sort:: myfileWrite(){
    ofstream myfile("C:\\Users\\Fahim Arefin\\Desktop\\file\\fahims2.txt");

    for(int i=0; i<n; i++){
        myfile<<rand()<<" "<<endl;
    }
    myfile.close();
}
void Insertion_sort::myfileRead(){
    string data1;
    int i=0;
    ifstream MyreadFile("C:\\Users\\Fahim Arefin\\Desktop\\file\\fahims2.txt");
    cout<<"After reading The values from file:"<<endl;
    while(getline(MyreadFile,data1)){
       data[i]=stoi(data1);
       cout<<data[i]<<" ";
       i++;
    }
    cout<<endl;

}
void Insertion_sort::InsertionSort(){
    for(int i=1; i<n; i++){
        int Unsorted=data[i];
        int sorted=i-1;
        while(data[sorted]>Unsorted && sorted>=0){
            data[sorted+1]=data[sorted];
            sorted--;
        }
        data[sorted+1]=Unsorted;
    }

}

void Insertion_sort::PrintValues(){
    cout<<"After the bubble sort algo the values are:"<<endl;
    for(int i=0; i<n; i++){
        cout<<data[i]<<" ";
    }
}





int main(){

    clock_t start,end;
    Insertion_sort obj1;
    obj1.myfileWrite();
    obj1.myfileRead();
    start=clock();
    obj1.InsertionSort();
    obj1.PrintValues();
    end=clock();
    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    cout<<endl;
    cout<<"Time taken:"<<time_taken;


}





