#include <bits/stdc++.h>
using namespace std;
int p[100][100];
int q[100][100];
int m,n;
class RockClimbing{
public:
    void Rc() {
        for (int j = 1; j <= n; j++) {
            p[0][j]=0;
        }
        for(int i=0; i<=m; i++){
            p[i][0]=INT_MAX;
        }
        for(int i=0; i<=n; i++){
            p[i][n+1]=INT_MAX;
        }
        for(int j=1; j<=m; j++){
            p[1][j]=q[1][j];
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(p[i-1][j-1]<p[i-1][j] && p[i-1][j-1]<p[i-1][j+1]){
                    p[i][j]=p[i-1][j-1]+q[i][j];
                }else if(p[i-1][j]<=p[i-1][j-1] && p[i-1][j]<=p[i-1][j+1]){
                    p[i][j]=p[i-1][j]+q[i][j];
                }else{
                    p[i][j]=p[i-1][j+1]+q[i][j];
                }
            }
        }





    }
    void Path_Print(int i,int j){
        if(i==0 || j==0 || j==n+1){
            return;
        }else if(p[i-1][j-1]<=p[i][j] && p[i-1][j-1]<=p[i-1][j+1]){
            Path_Print(i-1,j-1);
        }else if(p[i-1][j]<=p[i-1][j-1] && p[i-1][j]<=p[i-1][j+1]){
            Path_Print(i-1,j);
        }else{
            Path_Print(i-1,j+1);
        }
        cout<<" "<<p[i][j];
    }


};
int main() {

    cout<<"Enter the row and the column value:"<<endl;
    cin>>m>>n;
    cout<<"M and N Value:"<<m<<" "<<n<<endl;
    cout<<"Enter the values of your array:"<<endl;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin>>q[i][j];
        }
    }
    RockClimbing obj1;

    obj1.Rc();
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n+1; j++){
            cout<<" "<<p[i][j];
        }
        cout<<endl;
    }


    int min=p[m][1];
    int loc;
    for(int j=1; j<=n; j++){
        if(p[m][j]<min){
            min=p[m][j];
            loc=j;
        }
    }
    cout<<endl<<"Lowest risk path is: ";
    obj1.Path_Print(m,loc);


}
