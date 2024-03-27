#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long int;

vector<int> mexi(const vector<int>& a) {
    int n = a.size();
    vector<int> mex(n, 0);
    set<int> L;

    int current_mex = 0;
    for (int i = 0; i < n; ++i) {
        L.insert(a[i]);
        while (L.find(current_mex) != L.end()) {
            ++current_mex;
        }
        mex[i] = current_mex;
    }

    return mex;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> mex(n), mexr(n);
        mex = mexi(a);
        vector<int> r(n);
        for(int i=0;i<n;i++){
            r[i]=a[i];
        }
        reverse(r.begin(),r.end());
        mexr = mexi(r);
        reverse(mexr.begin(), mexr.end());

        int j = -1;
        int i = 0;
        while (i < n - 1) {
            if (mex[i] == mexr[i + 1]) {
                j = i;
            }
            i++;
        }

        if (j  == -1) {
            cout << -1 << endl;
        } else {
            cout << 2 << endl;
            cout << 1 << " " << j + 1 << endl;
            cout << j + 2 << " " << n << endl;
        }
    }
    return 0;
}
