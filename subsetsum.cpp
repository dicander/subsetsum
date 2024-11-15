#include <bits/stdc++.h>
using namespace std;

static const int dbg = true;
#define dout if(dbg)cout


int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> numbers(m);
    for (int i=0; i<m; i++) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    vector<int> d(n+1);
    d[0] = -1;
    // d[i] = talet som vi hoppade från för att komma hit.
    for (int i=0; i<n+1; i++) {
        dout << "inside loop " << i << endl;
        for (auto it=numbers.begin(); it!=numbers.end(); ++it) {
            dout << "testing number" << *it << endl;
            if (*it > i) {
                break;
            }
            if (dbg) {
                cout << *it << endl;
            }
            if (d[i-*it] != 0) {
                d[i] = *it;
            }
        }
    }
    if (dbg) {
        for (int i=0; i<=n; ++i) {
            cout << d[i] << " ";
        }
        cout << endl;
    }
    if (d[n] == 0) {
        cout << "No solution" << endl;
        return 0;
    }
    stack<int> s;
    int     index = n;
    while (index > 0) {
        s.push(d[index]);
        index = index - d[index];
    }
    while (s.size()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
