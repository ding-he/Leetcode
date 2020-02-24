#include <vector>
#include <map>

using namespace std;

class Solution {
public:

#if 0
    // 暴力法
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0;
        
        for(vector<int>::iterator iteri = nums.begin(); iteri != nums.end() - 1; iteri++)
        {
            for(vector<int>::iterator iterj = iteri + 1; iterj != nums.end(); iterj++)
            {
                if(target == (*iteri + *iterj))
                {
                    vector<int> ret;
                    ret.push_back(iteri - nums.begin());
                    ret.push_back(iterj - nums.begin());
                    return ret;
                }
            }
        }
        
        return vector<int>(2);
    }
#endif


#if 0
    // 两次遍历哈希表
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;

        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        {
            m.insert(make_pair(*iter, iter - nums.begin()));
        }

        int i = 0;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++, i++)
        {
            int key = target - *iter;
            if(m.count(key) == 1 && m[key] != i)
            {
                vector<int> ret;
                if(m[key] < i)
                {
                    ret.push_back(m[key]);
                    ret.push_back(i);
                }
                else
                {
                    ret.push_back(i);
                    ret.push_back(m[key]);
                }
                return ret;
            }
        }

        return vector<int>(2);
    }
#endif

#if 0
    // 一次遍历哈希表
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;

        int i = 0;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++, i++)
        {
            int key = target - *iter;
            if(m.count(key) > 0)
            {
                vector<int> ret;
                if(m[key] < i)
                {
                    ret.push_back(m[key]);
                    ret.push_back(i);
                }
                else
                {
                    ret.push_back(i);
                    ret.push_back(m[key]);
                }
                return ret;
            }
            
            m.insert(make_pair(*iter, i));
        }

        return vector<int>(2);
    }
#endif

#if 1
    // 一次遍历哈希表
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> ret(2, -1);

        for(vector<int>::size_type i = 0; i != nums.size(); i++)
        {
            int key = target - nums[i];
            if(m.count(key) > 0)
            {
                ret[0] = m[key];
                ret[1] = i;
                break;
            }
            m.insert(make_pair(nums[i], i));
        }

        return ret;
    }
#endif
};