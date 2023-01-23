#include<bits/stdc++.h>

using namespace std;

int a,b;
int p[100][100],q[100][100];

void rock_climbing(){

int i,j;
       for(j=1;j<=b;j++){
        q[0][j]=0;
    }
       for(i=0;i<=a;i++){
        q[i][0]=INFINITY;

    }
           for(i=0;i<=b;i++){
            q[i][b+1]=INFINITY;

    }
     for(j=1;j<=a;j++){
        q[1][j]=p[1][j];

    }

      for(i=2;i<=a;i++){
         for(j=1;j<=b;j++){
             if(q[i-1][j-1]<q[i-1][j] && q[i-1][j-1] < q[i-1][j+1]){
                q[i][j]=p[i][j]+q[i-1][j-1];
             }
             else if(q[i-1][j+1]<q[i-1][j] && q[i-1][j+1] <= q[i-1][j-1]){
                      q[i][j]=p[i][j]+q[i-1][j+1];
             }
             else{
                q[i][j]=p[i][j]+q[i-1][j];
             }
    }
  }

 }
void print(int i, int j){

    if(i==0 || j==0|| j==b+1){
         return;
    }

    if (q[i-1][j-1]<=q[i-1][j] &&q[i-1][j-1]<=q[i-1][j+1]){
            print(i-1,j-1);
    }

   else if (q[i-1][j]<=q[i-1][j-1] && q[i-1][j]<=q[i-1][j+1]){
             print(i-1,j);
   }

  else if (q[i-1][j+1]<=q[i-1][j-1] && q[i-1][j+1]<=q[i-1][j]){
           print(i-1,j+1);
  }

      cout<<" "<<p[i][j];

 }


int main()
{
  int i,j,c,k;
  cout<<"Enter row and column: ";
  cin>>a>>b;
  cout<<"Enter the element: ";
  for(i=1;i<=a;i++){
    for(j=1;j<=b;j++){
        cin>>p[i][j];
    }
  }
  rock_climbing();

  for(i=0;i<=a;i++){
    for(j=0;j<=b+1;j++){
        cout<<" "<<q[i][j];
    }
    cout<<endl;
  }

  c=q[a][1];
     for(j=1;j<=b;j++){
        if(q[a][j]<c){
            c=q[a][j];
            k=j;
     }
  }
  cout<<endl<<"Lowest risk path is: ";
  print(a,k);
}

