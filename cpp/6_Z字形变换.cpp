class Solution {
public:
#if 0
    string convert(string s, int numRows) {
        
        int step = 2*numRows - 2;
        string *pStr = new string[numRows];

        if(numRows == 1)
            return s;

        for(int i = 0; i < numRows; i++)
        {
            int currentStep = step - 2*i;
            currentStep = currentStep == 0 ? step : currentStep;

            int index = i;
            pStr[i] += s[index];
            index += currentStep;
            while(index < s.size())
            {
                pStr[i] += s[index];
                currentStep = step - currentStep;
                currentStep = currentStep == 0 ? step : currentStep;
                index += currentStep;
            }
        }

        s.clear();
        for(int i = 0; i < numRows; i++)
            s += pStr[i];
        
        delete []pStr;

        return s;

    }
#endif

#if 1
    string convert(string s, int numRows) {
        
        if(numRows == 1)
            return s;

        vector<string> ret(numRows);
        int currentRow = 0;
        bool goingDown = false;

        for(char c : s)
        {
            ret[currentRow] += c;
            if(currentRow == 0 || currentRow == numRows - 1)
                goingDown = ! goingDown;
            
            currentRow += goingDown ? 1 : -1;
        }

        for(vector<string>::iterator iter = ret.begin() + 1; iter != ret.end(); iter++)
        {
            ret[0] += *iter;
        }

        return ret[0];

    }
#endif
};