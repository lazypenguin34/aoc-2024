#include <bits/stdc++.h>
using namespace std;

int main() {
    // Get input
    string input; // removes newlines before pasting into terminal
    string line;
    while (getline(cin, line) && !line.empty()) {
        input += line;
    }

    // Part 1
    regex mulPattern(R"(mul\((\d+),(\d+)\))");
    smatch match;
    auto begin = input.cbegin();
    auto end = input.cend();

    long long result = 0;
    while (regex_search(begin, end, match, mulPattern)) {
        int x = stoi(match[1].str());
        int y = stoi(match[2].str());

        result += x * y;

        begin = match.suffix().first; // move to the next match
    }

    cout << result << endl;


    // Day 2
    begin = input.cbegin();
    regex mulDoDontPattern(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");

    result = 0;
    bool doFlag = true; // do is a fucking reserved keyword lol
    while (regex_search(begin, end, match, mulDoDontPattern)) {
        if (match[1].matched && doFlag) {
            int x = stoi(match[1].str());
            int y = stoi(match[2].str());
            result += x * y;
        } else if (match[0].str() == "do()") {
            doFlag = true;
        } else if (match[0].str() == "don't()") {
            doFlag = false;
        }

        begin = match.suffix().first; // move to the next match
    }
    cout << result << endl;
}

