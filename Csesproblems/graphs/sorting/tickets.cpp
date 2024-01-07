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

using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void solve() {
  // TODO: Implement the solution
    int n,m;
    cin>>n>>m;
    multiset<int> arr;
    for(int i=0;i<n;i++){
        int b;cin>>b;
        arr.insert(b);
    }
    while(m--){
        int a;cin>>a;
        auto it=arr.lower_bound(a);
        if(arr.size()==0){
            cout << -1 << endl;
            continue;
        }
        if(it!=arr.end()){
            if(*it==a){
                cout << a << endl;
                arr.erase(it);
            }
            else{
                if(it==arr.begin()){
                    if(*it>a){
                    cout << -1 << endl;
                    }
                    else{
                        cout << *it <<endl;
                        arr.erase(it); 
                    }
                }
                else{
                    it--;
                    cout << *it << endl;
                    arr.erase(it);
                }    
                
            }
            
        }
        else{
            it--;
            if(*it>a){
                cout << -1 << endl;
            }
            else{
                cout << *it << endl;
                arr.erase(it);
            }
        }
 
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}