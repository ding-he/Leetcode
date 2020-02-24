class Solution {
public:
    bool isPalindrome(int x) {
        int y = 0;
        int t = x;
        if(t < 0)
            return false;
        
        while(t != 0)
        {
            int pos = t % 10;
            t /= 10;

            if(y > INT_MAX / 10 || (y == INT_MAX / 10 && pos > 7))
                return false;

            y = y*10 + pos;
        }

        if(x == y)
            return true;
        else 
            return false;

    }
};