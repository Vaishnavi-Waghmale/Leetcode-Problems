class Solution {
public:
    string removeDuplicates(string S) {
        string a;
        for (auto& c : S) 
            if (a.size() && a.back() == c) a.pop_back();
            else a.push_back(c);
        return a;
    }
};
