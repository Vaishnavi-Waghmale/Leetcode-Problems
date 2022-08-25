class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::multiset<char> mag(magazine.begin(), magazine.end());
        std::multiset<char> ransom(ransomNote.begin(), ransomNote.end());
        return std::includes(mag.begin(), mag.end(), ransom.begin(), ransom.end());
    }
};
