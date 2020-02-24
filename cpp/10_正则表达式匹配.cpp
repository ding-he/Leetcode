class Solution {
public:
    bool isMatch(string s, string p) {
        
        if(p.empty())
            return s.empty();
        
        // 第一个字符匹配
        bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');

        // 后面过滤*
        if(p.size() >= 2 && p[1] == '*')
        {
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
        }
        else
        {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }

    }
};