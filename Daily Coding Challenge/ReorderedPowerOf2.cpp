const int TEN = 10;

class Solution {
vector<int> updateFreq(int n)
{
    vector<int> temp(10, 0);
    while (n) {
 
        int digit = n % TEN;

        temp[digit]++;
 
        n /= TEN;
    }
    return temp;
}

bool isPowerOf2(int N)
{
    vector<int> freq = updateFreq(N);
    for (int i = 0; i < 31; i++) {
    
        if (freq == updateFreq(1 << i)) {
            return true;
        }
    }
    return false;
}
    
public:
    bool reorderedPowerOf2(int n) {
        return isPowerOf2(n);
    }
};
