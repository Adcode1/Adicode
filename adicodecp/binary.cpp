#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
  int n;cin>>n;
  string up,down;
  cin>>up>>down;
  vector<int> yno(n,0);
  string ans="";
  int i=0;
  int j=0;
  while(i<n){
    if(i+1<n and down[j]=='0'){
        if(up[i+1]=='0'){
            ans+=up[i];
            i++;j++;
        }
        else{
            ans+=up[i];
            j=i;
            break;
        }
    }
    else if(i+1==n){
        ans+=up[i];i++;
    }
    else{
        ans+=up[i];i++;j++;
    }
  }
  while(j<n){
    ans+=down[j];
    j++;
  }
  cout << ans << endl;
  int m=ans.length()-1;
  for(int k=n-1;k>=0;k--){
    if(ans[m]==down[k]){
        yno[k]=1;m--;
    }else{
        break;
    }
  }
  int val=0;
  for(int a=0;a<n;a++){
    if(yno[a]==1){
        val++;
        if(a+1<n and up[a+1]==down[a]){
            continue;
        }else{
            break;
        }
    }
  }
  cout << val << endl;
  }
}