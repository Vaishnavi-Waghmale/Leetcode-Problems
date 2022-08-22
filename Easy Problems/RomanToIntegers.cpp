class Solution {
public:
    int getInteger(char c)
{
    switch(c)
    {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
        default : return -1;
    }
}
int romanToInt(string s)
{
    int n = s.size() , result = 0 , current , next , i = 0;
    while(i < n)
    {
        if(i == n - 1)
        {
            result += getInteger(s[i]);
            return result;
        }
        current = getInteger(s[i]) , next = getInteger(s[i + 1]);
        if(current >= next)
            result += current , i++;
        else
            result += next - current , i += 2;
    }
    return result;
}
int main()
{
    string s = "CXXIX";
    cout << romanToInt(s) << '\n';
    return 0;
}
};
