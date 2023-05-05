#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s1,s2;
int dp[10000][10000];
char direction[10000][10000];


void printing(int x,int y){
     for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<""<<endl;
    }
}
void printingdir(int x,int y){
     for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                cout<<direction[i][j]<<" ";
            }
            cout<<""<<endl;
    }
}

void printstring(int i,int j){
  if(i==0||j==0){
    return ;
  }
  else if(direction[i][j]=='D'){
    printstring(i-1,j-1);
    cout<<s1[i-1];
  }
  else if(direction[i][j]=='L'){
     printstring(i-1,j);
  }
  else{
    printstring(i,j-1);
  }
}

void find_lcs(string s1,string s2){
    for(int i=0;i<=s1.length();i++){
        for(int j=0;j<=s2.length();j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
           else if(s1[i-1]==s2[j-1]){
            dp[i][j]=dp[i-1][j-1]+1;
            direction[i][j]='D';
           }
           else{
            if(dp[i-1][j]>dp[i][j-1]){
            dp[i][j]=dp[i-1][j];
            direction[i][j]='L';
            }
            else{
            dp[i][j]=dp[i][j-1];
            direction[i][j]='T';
            }
           }
        }
        }
cout<<"THE SOLN MATRIX IS :"<<endl;
printing(s1.length(),s2.length());
cout<<"THE DIRECTION MATRIX IS :"<<endl;
printingdir(s1.length(),s2.length());
cout<<"THE Length of LCS IS "<<dp[s1.length()][s2.length()]<<endl;
printstring(s1.length(),s2.length());
}
void solve(){
    cout<<"Enter your string1 :";
    cin>>s1;
    cout<<"Enter your string2 :";
    cin>>s2;
    find_lcs(s1,s2);
}

int main()
{
    solve();
    return 0;
}