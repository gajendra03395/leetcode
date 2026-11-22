class Solution {
public:
    bool checkString(string s) {
        bool seenB = false;
        for(char x : s)
        {
            if(x == 'b')
            {
                seenB = true;
            }
            else if(x == 'a' && seenB)
            {
                return false;
            }
        }
        return true;
    }
    
};