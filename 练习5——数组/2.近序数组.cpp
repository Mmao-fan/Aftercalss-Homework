#include<bits/stdc++.h>

using namespace std;

bool isOrdered(const vector<int>& a, int start, int end) {
    if (start >= end) return true;
    bool inc = true;  
    bool dec = true;  
    for (int i = start + 1; i <= end; i++) {
        if (a[i] > a[i-1]) {
            dec = false;
        } else if (a[i] < a[i-1]) {
            inc = false;
        }
    }

    return inc || dec;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (isOrdered(a, 1, i) && isOrdered(a, i + 1, n)) {
            cout << "Yes" << endl;
            return 0;  
        }
    }
    cout << "No" << endl;
    return 0;
}

