#include <bits/stdc++.h>
using namespace std;

int main() {
    // Get input
    vector<string> lines;
    string line;
    while (getline(cin, line) && !line.empty()) {
        lines.push_back(line);
    }

    // Part 1
    vector<pair<int, int>> directions = { // (i factor, j factor) (y, x)
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},  {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };
    int total = 0;

    for (int i=0;i<lines.size();i++) {
        line = lines[i];
        for (int j=0;j<line.size();j++) {
            char ch = line[j];
            if (ch == 'X') {
                string vec;
                pair<int, int> direction;
                for (int n=0;n<8;n++) {
                    vec.clear();
                    direction = directions[n];

                    try {
                        vec.push_back(lines.at(i + direction.first).at(j + direction.second));
                        vec.push_back(lines.at(i + direction.first * 2).at(j + direction.second * 2));
                        vec.push_back(lines.at(i + direction.first * 3).at(j + direction.second * 3));
                    } catch (const out_of_range& e) {
                        continue;
                    }

                    if (vec == "MAS") {
                        total++;
                    }
                }
            }
        }
    }
    cout << "Part 1: " << total << endl;

    // Part 2
    total = 0;
    directions = { // (i factor, j factor) (y, x)
        {-1, -1}, {-1, 1},
        {1, -1},  {1, 1}
    };

    for (int i=0;i<lines.size();i++) {
        string line = lines[i];
        string vec1; // diagonal top to down
        string vec2; // diagonal bottom to top
        for (int j=0;j<line.size();j++) {
            char ch = line[j];
            if (ch == 'A') {
                vec1.clear();
                vec2.clear();

                try {
                    vec1.push_back(lines.at(i + directions[0].first).at(j + directions[0].second));
                    vec1.push_back(lines.at(i + directions[3].first).at(j + directions[3].second));
                    vec2.push_back(lines.at(i + directions[1].first).at(j + directions[1].second));
                    vec2.push_back(lines.at(i + directions[2].first).at(j + directions[2].second));
                } catch (const out_of_range& e) {
                    continue;
                }

                bool vec1Pass = (vec1 == "SM") || (vec1 == "MS");
                bool vec2Pass = (vec2 == "SM") || (vec2 == "MS");
                if (vec1Pass && vec2Pass) {
                    total++;
                }
            }
        }
    }
    cout << "Part 2: " << total << endl;
}

