class Solution {
public:

#if 0
    string longestPalindrome(string s) {
        
        int maxLength = 1;
        int index = 0;
        int currentLength = 2;
        bool find = false;

        while (currentLength <= s.size())
        {
            for (string::size_type i = 0; i <= s.size() - currentLength; i++)
            {
               for (int j = i; j < i + currentLength / 2; j++)
                {
                    if (s[j] != s[2*i + currentLength - j - 1])
                        break;
                    if (j == i + currentLength / 2 - 1)
                        find = true;
                }
                if (find)
                {
                    find = false;
                    maxLength = currentLength;
                    index = i;
                    break;
                }
            }
            currentLength++;
        }

        return s.substr(index, maxLength);

    }
#endif

#if 1

    inline int farCenter(string *s, int l, int r)
    {
        while(l >= 0 && r < s->size() && (*s)[l] == (*s)[r])
        {
            l--;
            r++;
        }

        return r - l - 1;
    }

    string longestPalindrome(string s) {
        
        int maxLen = 0;
        int start = 0;

        for(string::size_type i = 0; i < s.size(); i++)
        {
            int len1 = farCenter(&s, i, i);
            int len2 = farCenter(&s, i, i + 1);
            int len = max(len1, len2);
            if(len > maxLen)
            {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
#endif

};