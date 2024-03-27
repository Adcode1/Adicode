#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define pf push_front
#define pb push_back
#define F first
#define S second
#define loop(i, m, n) for (int i = m; i < n; i++)
#define arep(i, v) for (auto i : v)
#define all(x) (x).begin(), (x).end()
#define yeah cout << YES << endl;
#define noi cout << NO << endl;

using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int func(int i,int arr[],int prev,int n){
    if(i==n-1){
        if(prev==1){
            return 0;
        }else{
            return prev;
        }
    }
    if(prev==0){
        int a=1+func(i+1,arr,prev,n);
        int b=func(i+1,arr,arr[i],n);
        return min(a,b);
    }else{
        int c=1+func(i+1,arr,prev,n);
        int d=func(i+1,arr,prev--,n);
        return min(c,d);

    }


}
void solve() {
  // TODO: Implement the solution
  int n;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout << func(0,arr,0,n) <<endl;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}