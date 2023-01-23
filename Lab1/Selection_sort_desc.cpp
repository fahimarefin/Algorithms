
#include<bits/stdc++.h>
#include<time.h>
using namespace std;
#define n 30000
int data[n];
class SelectionSort{
public:

  void myfileWrite();
  void myfileRead();
  void selection_sort();
  void PrintValues();


};

void SelectionSort:: myfileWrite(){
    ofstream myfile("C:\\Users\\user\\Desktop\\LabTj1\\1.txt");

    srand(time(NULL));
    for(int i=0; i<n; i++){
        myfile<<rand()<<" "<<endl;
    }
    myfile.close();
}
void SelectionSort::myfileRead(){
    string data1;
    int i=0;
    int count=0;
    ifstream MyreadFile("C:\\Users\\user\\Desktop\\LabTj1\\1.txt");
    cout<<"After reading The values from file:"<<endl;
    while(getline(MyreadFile,data1)){
       data[i]=stoi(data1);
       cout<<data[i]<<" ";
       i++;
       count++;
    }
    cout<<endl;
    cout<<"Number of times:"<<count<<endl;
    cout<<endl;

}
void SelectionSort::selection_sort(){


    for(int i=0; i<n; i++){
        int mn=data[i];
        int min_indx=i;
        for(int j=i+1; j<n; j++){
            if(data[j]<mn){
               mn=data[j];
                min_indx=j;
            }
        }
        if(min_indx!=i){


            int temp=data[i];
            data[i]=data[min_indx];
            data[min_indx]=temp;

        }
    }

}


void SelectionSort::PrintValues(){
    cout<<"After the selection sort algo the values are:"<<endl;
    for(int i=0; i<n; i++){
        cout<<data[i]<<" ";
    }
}



int main(){

    clock_t start,end;
    SelectionSort obj1;
    obj1.myfileWrite();
    obj1.myfileRead();
    start=clock();
    obj1.selection_sort();
    obj1.PrintValues();
    end=clock();
    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    cout<<endl;
    cout<<"Time taken:"<<time_taken;


}




