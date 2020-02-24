class Solution {
public:
    int myAtoi(string str) {

        int pos = 0;
        int sign = 1;
        int ret = 0;

        while(str[pos] == ' ')
            pos++;

        if(str[pos] == '-')
            sign = -1;
        else if(str[pos] == '+')
            sign = 1;
        else if(str[pos] <= '9' && str[pos] >= '0')
            ret = str[pos] - '0';
        else
            return 0;
        
        pos++;
        
        while(str[pos] <= '9' && str[pos] >= '0')
        {
            int num = str[pos] - '0';

            if(sign == 1 && (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && num > 7)))
                return INT_MAX;
            if(sign == -1 && (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && num >= 8)))
                return INT_MIN;

            ret = ret*10 + num;
            pos++;
        }

        return sign*ret;

    }
};