#include <iostream>
#include <map>
#include <vector>

typedef long long int64;
typedef long double ld;
#define pushf push_front
#define pushb push_back
#define loop(idx, start, end) for (int idx = start; idx < end; idx++)
#define foreach(iter, container) for (auto iter : container)
#define all(x) (x).begin(), (x).end()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int64 elements, targets;
    cin >> elements >> targets;
    int64 arr[2 * elements];
    loop(i, 0, 2 * elements) cin >> arr[i];
    map<int64, int64> freq;
    vector<int64> zero_occurrences, one_occurrences, two_occurrences;
    loop(i, 0, elements) freq[arr[i]]++;
    loop(i, 1, elements + 1) {
        if (freq[i] == 1) one_occurrences.pushb(i);
        else if (freq[i] == 0) zero_occurrences.pushb(i);
        else if (freq[i] == 2) two_occurrences.pushb(i);
    }
    if (two_occurrences.size() >= targets) {
        loop(i, 0, targets) cout << two_occurrences[i] << " " << two_occurrences[i] << " ";
        cout << endl;
    } else {
        if (one_occurrences.size() % 2 == 0) {
            if (2 * targets < one_occurrences.size()) {
                loop(i, 0, 2 * targets) cout << one_occurrences[i] << " ";
                cout << endl;
            } else {
                foreach(num, one_occurrences) cout << num << " ";
                int64 remaining = 2 * targets - one_occurrences.size();
                loop(i, 0, remaining / 2) cout << two_occurrences[i] << " " << two_occurrences[i] << " ";
                cout << endl;
            }
        } else {
            if (2 * targets < one_occurrences.size()) {
                loop(i, 0, 2 * targets) cout << one_occurrences[i] << " ";
                cout << endl;
            } else {
                loop(i, 0, one_occurrences.size() - 1) cout << one_occurrences[i] << " ";
                int64 remaining = 2 * targets - (one_occurrences.size() - 1);
                loop(i, 0, remaining / 2) cout << two_occurrences[i] << " " << two_occurrences[i] << " ";
                cout << endl;
            }
        }
    }
    if (zero_occurrences.size() >= targets) {
        loop(i, 0, targets) cout << zero_occurrences[i] << " " << zero_occurrences[i] << " ";
        cout << endl;
    } else {
        if (one_occurrences.size() % 2 == 0) {
            if (2 * targets < one_occurrences.size()) {
                loop(i, 0, 2 * targets) cout << one_occurrences[i] << " ";
                cout << endl;
            } else {
                foreach(num, one_occurrences) cout << num << " ";
                int64 remaining = 2 * targets - one_occurrences.size();
                loop(i, 0, remaining / 2) cout << zero_occurrences[i] << " " << zero_occurrences[i] << " ";
                cout << endl;
            }
        } else {
            if (2 * targets < one_occurrences.size()) {
                loop(i, 0, 2 * targets) cout << one_occurrences[i] << " ";
                cout << endl;
            } else {
                loop(i, 0, one_occurrences.size() - 1) cout << one_occurrences[i] << " ";
                int64 remaining = 2 * targets - (one_occurrences.size() - 1);
                loop(i, 0, remaining / 2) cout << zero_occurrences[i] << " " << zero_occurrences[i] << " ";
                cout << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test_cases;
    cin >> test_cases;
    while (test_cases--) solve();
    return 0;
}
