class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int st = 0 , end = n - 1;
        while(st<end)
        {
            swap(s[st++],s[end--]);
        }
    }
};