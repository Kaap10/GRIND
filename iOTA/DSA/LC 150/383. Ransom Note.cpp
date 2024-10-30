class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> magazineMap;
    for (char c : magazine) {
        magazineMap[c]++;
    }
    for (char c : ransomNote) {
        if (magazineMap[c] > 0) {
            magazineMap[c]--;
        } else {
            return false; 
        }
    }
    return true; 
}
};