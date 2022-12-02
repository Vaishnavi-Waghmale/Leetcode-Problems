class Solution {
public:
    bool closeStrings(string word1, string word2) {
         if(word1.size() != word2.size()) // the length of words need to be same
 	return false;
 unordered_map<char,int> ump1, ump2, check;
 
 for(char ch:word1) ump1[ch]++;  // getting the frequecies of each in character in word1
 for(char ch: word2) ump2[ch]++; // getting the frequecies of each in character in word2
 
 if(ump1.size() != ump2.size()) return false; // both strings should contain same no.of distinct words
 unordered_map<int,int> num; // to match the frequencies of characters in both the strings
 for(auto ele: ump1) 
 {
     check[ele.first]++;
     num[ele.second]++;
 }
 for(auto ele : ump2)
 {
     check[ele.first]--;
     if(check[ele.first]==0) check.erase(ele.first);
     num[ele.second]--;
     if(num[ele.second] == 0) num.erase(ele.second);
 }

 return num.size()==0 && check.size()==0;

    }
};
