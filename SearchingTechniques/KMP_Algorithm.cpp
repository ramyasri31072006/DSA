
/* The KMP algorithm is used for pattern matching.
 It efficiently finds all occurrences of a pattern string pat 
 in a text string txt in O(n + m) time by avoiding unnecessary
 comparisons using a preprocessed LPS (Longest Prefix Suffix) array.*/

#include <iostream>
#include <vector>
using namespace std;

/*
--------------------------------------------------------
 KMP (Knuth-Morris-Pratt) String Matching Algorithm
--------------------------------------------------------

 Goal:
Efficiently find all occurrences of a pattern string `pat`
within a text string `txt` in linear time.

 Time Complexity:
- Preprocessing (LPS array): O(m)
- Searching: O(n)
  where:
    - n = length of the text
    - m = length of the pattern

 Key Components:
1. LPS Array (Longest Prefix which is also Suffix):
   - For pattern `pat`, LPS[i] stores the length of the longest
     proper prefix which is also a suffix for pat[0...i].

2. Pattern Matching using LPS:
   - While scanning the text, if there's a mismatch, instead of restarting
     from the beginning, we use the LPS array to skip unnecessary comparisons.

*/

class KMP {
public:
    // Function to build the LPS (Longest Prefix Suffix) array
    vector<int> buildLPS(const string &pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);
        int len = 0;  // length of the previous longest prefix suffix
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    // backtrack to the previous possible prefix
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    // Function to search for pattern in text using KMP
    vector<int> search(const string &text, const string &pattern) {
        int n = text.length();
        int m = pattern.length();
        vector<int> lps = buildLPS(pattern);
        vector<int> result;  // stores starting indices of matches

        int i = 0;  // index for text
        int j = 0;  // index for pattern

        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;

                if (j == m) {
                    // Match found at index (i - m)
                    result.push_back(i - m);
                    j = lps[j - 1];  // prepare for next possible match
                }
            } else {
                if (j != 0) {
                    j = lps[j - 1];  // skip using lps
                } else {
                    i++;
                }
            }
        }

        return result;
    }
};

int main() {
    KMP kmp;
    string text = "ababcababcababc";
    string pattern = "ababc";

    vector<int> matches = kmp.search(text, pattern);

    cout << "Pattern found at indices: ";
    for (int idx : matches) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
