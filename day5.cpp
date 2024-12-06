#include <bits/stdc++.h>
using namespace std;

bool passesPartOne(const unordered_map<int, vector<int>> &rules, const vector<int> &update) {
    for (int i=0;i<update.size();i++) {
        int x = update[i];
        if (rules.find(x) == rules.end()) {
            continue; // if there's no rules for a character, we can skip it
        }

        vector<int> specificRules = rules.at(x);
        for (int y : specificRules) {
            auto it = find(update.begin(), update.end(), y);
            if (it == update.end()) {
                continue; // if y isn't in the update, then it can't have broken the rule
            }

            int index = distance(update.begin(), it);
            if (index < i) { // then we have broke the rule
                return false;
            }
        }
    }

    return true;
}

int partTwoMidPage(const unordered_map<int, vector<int>> &rules, vector<int> &update) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i=0;i<update.size();i++) {
            int x = update[i];
            if (rules.find(x) == rules.end()) {
                continue; // if there's no rules for a character, we can skip it
            }

            vector<int> specificRules = rules.at(x);
            for (int y : specificRules) {
                auto it = find(update.begin(), update.end(), y);
                if (it == update.end()) {
                    continue; // if y isn't in the update, then it can't have broken the rule
                }

                int index = distance(update.begin(), it);
                if (index < i) { // then we have broke the rule, so swap the positions of x and y
                    swapped = true;
                    swap(update[i], update[index]);
                }
            }
        }
    }

    return update[update.size() / 2];
}

int main() {
    // Get input
    unordered_map<int, vector<int>> rules;
    vector<vector<int>> updates;
    string line;
    while(getline(cin, line) && !line.empty()) {
        int x = stoi(line.substr(0, 2));
        int y = stoi(line.substr(3, 2));

        rules[x].push_back(y);
    }

    while(getline(cin, line) && !line.empty()) {
        vector<int> update;
        for (int i=0;i<line.length();i += 3) {
            int x = stoi(line.substr(i, 2));
            update.push_back(x);
        }
        updates.push_back(update);
    }

    // Part 1
    int total = 0;
    for(vector<int> update : updates) {
        if (passesPartOne(rules, update)) {
            total += update[update.size() / 2];
        }
    }
    printf("Part 1: %d\n", total); // gonna start using printf now cause internet man said cout is ass (it is)


    // Part 2
    total = 0;
    for (vector<int> update : updates) {
        if (!passesPartOne(rules, update)) {
            int mid = partTwoMidPage(rules, update);
            total += partTwoMidPage(rules, update);
        }
    }

    printf("Part 2: %d\n", total);

    return 0;
}
