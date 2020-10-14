#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        for (auto& str : A) {
            sort(str.begin(), str.end());
        }

        int pos = 0;
        while (true) {
            bool is_exist = true;
            if (pos >= A.front().size()) {
                break;
            }
            char ch = A.front()[pos];
            for (auto& str : A) {
                if (pos >= str.size() || ch != str[pos]) {
                    is_exist = false;
                    break;
                }
            }
            ++pos;
        }

        vector<string> ans;
        for (int i = 0; i < pos; ++i) {
            ans.emplace_back(A.front()[i], 1);
        }

        return ans;
    }
};

int main()
{
    vector<string> str_array = {"bella","label","roller"};
    auto ans = Solution().commonChars(str_array);

    for (auto& str : ans) {
        cout << str << " ";
    }
    cout << endl;
}