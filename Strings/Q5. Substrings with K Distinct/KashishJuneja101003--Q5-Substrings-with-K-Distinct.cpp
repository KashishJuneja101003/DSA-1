#include <bits/stdc++.h>
using namespace std;

// Function to count substrings with at most K distinct characters
int countAtMostKDistinct(string &s, int k) {
    if (k == 0) return 0;
    
    unordered_map<char, int> freq;
    int left = 0, right = 0, count = 0, distinctCount = 0;

    while (right < s.size()) {
        if (freq[s[right]] == 0) distinctCount++;
        freq[s[right]]++;
        
        while (distinctCount > k) {  // Shrink window if distinct characters exceed k
            freq[s[left]]--;
            if (freq[s[left]] == 0) distinctCount--;
            left++;
        }
        
        count += (right - left + 1);  // Count valid substrings
        right++;
    }
    
    return count;
}

// Function to count substrings with exactly K distinct characters
int countSubstringsWithKDistinct(string s, int k) {
    return countAtMostKDistinct(s, k) - countAtMostKDistinct(s, k - 1);
}

// Driver code
int main() {
    string str = "aba";
    int k = 2;
    cout << countSubstringsWithKDistinct(str, k) << endl;
    
    str = "abaaca";
    k = 1;
    cout << countSubstringsWithKDistinct(str, k) << endl;
    
    str = "cdad";
    k = 4;
    cout << countSubstringsWithKDistinct(str, k) << endl;
    
    return 0;
}
