class Solution {
public:

#if 0
    int lengthOfLongestSubstring(string s) {
        
        int maxLength = 0;
        set<char> se;

        for(string::size_type i = 0; i < s.size(); i++)
        {
            se.insert(s[i]);
            int length = 1;
            for(string::size_type j = i + 1; j < s.size(); j++)
            {
                if(se.count(s[j]) > 0)
                    break;
                else
                    se.insert(s[j]);
                length++;
            }

            if(maxLength < length)
                maxLength = length;
            
            if(maxLength >= s.size() - i)
                break;

            se.clear();
        }

        return maxLength;

    }
#endif

#if 0
    int lengthOfLongestSubstring(string s) {
        
        int maxLength = 0;
        set<char> c;
        string::size_type i(0), j(0);

        while(i < s.size() && j < s.size())
        {
            if(c.count(s[j]) == 0)
            {
                c.insert(s[j++]);
                maxLength = maxLength > j - i ? maxLength : j - i;
            }
            else
                c.erase(s[i++]);
        }
        return maxLength;
    }
#endif

#if 1
    int lengthOfLongestSubstring(string s) {
        
        int maxLength = 0;
        map<char, int> m;
        
        for(string::size_type i = 0, j = 0; j < s.size(); j++)
        {
            if(m.count(s[j]) > 0)
            {
                i = m[s[j]] > i ? m[s[j]] : i;
                m.erase(s[j]);
            }
            maxLength = maxLength > j - i + 1 ? maxLength : j - i + 1;
            m.insert(make_pair(s[j], j + 1));
        }

        return maxLength;
    }
#endif
};