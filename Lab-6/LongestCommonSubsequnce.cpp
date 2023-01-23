
#include<bits/stdc++.h>
using namespace std;
class LCS{
public:
    int max(int a,int b){
        if(a>b){
            return a;
        }else{
            return b;
        }
    }
    int lcs(char X[],char Y[],int m,int n){

        if(m==0 || n==0) return 0;
        if(X[m-1]==Y[n-1]) return 1+lcs(X,Y,m-1,n-1);
        else return max(lcs(X,Y,m,n-1),lcs(X,Y,m-1,n));

    }
    void lcsAlgo(char *S1, char *S2, int m, int n) {
  int LCS_table[m + 1][n + 1];
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCS_table[i][j] = 0;
      else if (S1[i - 1] == S2[j - 1])
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      else
        LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
    }
  }

  int index = LCS_table[m][n];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;
    else
      j--;
  }
  cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << lcsAlgo << "\n";
}


};
int main(){
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);
    LCS obj1;

    cout<<"Length of LCS is "<< obj1.lcs( X, Y, m, n )<<endl ;

    obj1.lcsAlgo(X,Y,m,n);



}
