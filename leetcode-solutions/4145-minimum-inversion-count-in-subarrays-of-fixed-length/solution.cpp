#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        int n = nums.size();
        ordered_set st;
        long long inv = 0, ans = LLONG_MAX;
        int l = 0, r = 0;

        while (r < n) {
            inv += st.size() - st.order_of_key({nums[r], r});
            st.insert({nums[r], r});
            if (r - l + 1 == k) {
                ans = min(ans, inv);
                inv -= st.order_of_key({nums[l], l});
                st.erase({nums[l], l});
                l++;
            }
            r++;
        }
        return ans;
    }
};
