class Solution {
public:
#if 0
    int reverse(int x) {
        char digit[10] = {0};
        uint64_t ret = 0;
        int validDigit = 10;
        int sign = 1;
        int64_t temp = x;
        if(temp < 0)
        {
            sign = -1;
            temp = -temp;
        }

        for(int i = 0, coeff = 10; i < 10; i++)
        {
            digit[i] = temp % coeff;
            temp /= coeff;
        }

        for(int i = 9; i >= 0; i--)
        {
            if(digit[i] == 0)
                validDigit--;
            else
                break;
        }

        for(int i = 0; i < validDigit / 2; i++)
        {
            char t = digit[i];
            digit[i] = digit[validDigit - i - 1];
            digit[validDigit - i - 1] = t;
        }

        for(int i = validDigit - 1; i >= 0; i--)
        {
            ret = ret * 10 + digit[i];
        }

        if((sign == 1 && ret > INT_MAX) || (sign == -1 && ret > (uint64_t)INT_MAX + 1))
            return 0;
        
        return sign*ret;

    }
#endif

#if 1
    int reverse(int x) {
        int ret = 0;

        while(x)
        {
            int pop = x % 10;
            x /= 10;

            if(ret > INT_MAX / 10 || (ret == INT_MAX / 10 && pop > 7))
                return 0;
            if(ret < INT_MIN / 10 || (ret == INT_MIN / 10 && pop < -8))
                return 0;
            
            ret = ret*10 + pop;

        }

        return ret;

    }
#endif
};