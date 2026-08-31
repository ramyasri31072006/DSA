#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Custom comparator to sort people with following priority:
    1. Descending order of number of questions (a.first > b.first)
    2. If tied, descending order of score (a.second.first > b.second.first)
    3. If still tied, ascending order of name (a.second.second < b.second.second)

    Data Structure:
    Each element is a pair in the form:
        { questions, { score, name } }
*/
bool cmp(const pair<int, pair<int, string>>& a, const pair<int, pair<int, string>>& b) {
    // Compare number of questions (descending)
    if (a.first != b.first) 
        return a.first > b.first;

    // If questions are equal, compare score (descending)
    if (a.second.first != b.second.first) 
        return a.second.first > b.second.first;

    // If score is also equal, compare name (ascending)
    return a.second.second < b.second.second;
}

int main() {
    // Example data: {questions, {score, name}}
    vector<pair<int, pair<int, string>>> people = {
        {10, {85, "Alice"}},
        {10, {85, "Bob"}},
        {10, {90, "Charlie"}},
        {12, {80, "Dave"}}
    };

    // Sort using custom comparator
    sort(people.begin(), people.end(), cmp);

    // Print sorted output
    for (auto &p : people) {
        cout << p.second.second << " "  // Name
             << p.first << " "          // Questions
             << p.second.first << "\n"; // Score
    }
}
