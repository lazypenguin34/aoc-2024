#include <bits/stdc++.h>
using namespace std;

int main() {
    // Get input
    vector<int> a, b;
    for (int i=0;i<1000;i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }

    // Part 1
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long sum = 0;
    for (int i=0;i<1000;i++) {
        sum += abs(a[i] - b[i]);
    }
    cout << sum << endl;

    // Part 2
    long long score = 0;
    for (int x : a) {
        int instances = 0;
        for (int y : b) {
            if (x == y) {
                instances++;
            }
        }
        score += instances * x;
    }
    cout << score << endl;
}

