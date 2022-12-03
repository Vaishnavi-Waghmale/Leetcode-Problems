class Solution {
public:
    string frequencySort(string s) {
        map<char,int> freq_counter;
        
        //taking the frequency using map we can also use unordered map
        for(auto ch:s){
            freq_counter[ch]++;
        }
        
        //storing the freuqency using pair value to sort it 
        vector<pair<int,int>> to_sort;
        
        for(auto i:freq_counter){
            to_sort.push_back({i.second,i.first});    
        }
        
        sort(to_sort.begin(),to_sort.end());
        
        
        int n=to_sort.size();
        string res="";
        
        //as sorted frequency in ascending order traversing from reverse and appending it to the string
        for(int i=n-1;i>=0;i--){
            string temp="";
            while(to_sort[i].first--){
                temp+=to_sort[i].second;
            }
            res+=temp;
        }
        
        
        
        return res;
    }
};
