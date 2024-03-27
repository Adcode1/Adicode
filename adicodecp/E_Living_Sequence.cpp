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

string decimal_to_base9(ll decimal_number) {
    std::string base9_number = "";
    
    while (decimal_number > 0) {
        ll remainder = decimal_number % 9;
        base9_number = std::to_string(remainder) + base9_number;
        decimal_number /= 9;
    }
    
    // If the input number is 0
    if (base9_number == "")
        base9_number = "0";
    
    return base9_number;
}
void solve() {
  // TODO: Implement the solution
  ll k;cin>>k;
  string temp=decimal_to_base9(k);
  string ans="";
  for(int i=0;i<temp.size();i++){
    if(temp[i]>'3'){
        int x=temp[i]-'0';x++;
        ans+=x+'0';
    }else{
        ans+=temp[i];
    }
  }
   cout << ans << endl;
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