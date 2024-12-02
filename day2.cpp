#include <bits/stdc++.h>
using namespace std;

bool isSafe(const vector<int>& report) {
    bool isIncreasing = false;
    bool isDecreasing = false;
    for (int i = 1; i < report.size(); i++) {
        int diff = report[i] - report[i - 1];

        if (diff == 0 || abs(diff) > 3) {
            isIncreasing = false;
            isDecreasing = false;
            break;
        }

        // Check direction
        if (diff > 0) {
            isIncreasing = true;
        } else if (diff < 0) {
            isDecreasing = true;
        }
    }

    // A report is safe if it is exclusively increasing or decreasing
    if (isIncreasing != isDecreasing) {
        return true;
    }
    return false;
}

int main() {
    // Get input
    vector<vector<int>> reports;
    string line;
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        vector<int> report;
        int x;

        while (ss >> x) {
            report.push_back(x);
        }

        reports.push_back(report);
    }

    // Part 1
    int numSafe = 0;

    for (const vector<int>& report : reports) {
        bool isIncreasing = false;
        bool isDecreasing = false;
        for (int i = 1; i < report.size(); i++) {
            int diff = report[i] - report[i - 1];

            if (diff == 0 || abs(diff) > 3) {
                isIncreasing = false;
                isDecreasing = false;
                break;
            }

            // Check direction
            if (diff > 0) {
                isIncreasing = true;
            } else if (diff < 0) {
                isDecreasing = true;
            }
        }

        // A report is safe if it is strictly increasing or strictly decreasing
        if (isIncreasing != isDecreasing) {
            numSafe++;
        }
    }

    cout << numSafe << endl;

    // Part 2
    numSafe = 0;
    bool usedDampener;

    for (const vector<int>& report : reports) {
        usedDampener = false;
        if (isSafe(report)) {
            numSafe++;
        } else {
            // Try removing each number and see if it's safe
            for (int i=0;i<report.size();i++) {
                vector<int> reportClone = report;
                reportClone.erase(reportClone.begin() + i);

                if (isSafe(reportClone)) {
                    numSafe++;
                    break;
                }
            }
        }
    }
    cout << numSafe << endl;
}

