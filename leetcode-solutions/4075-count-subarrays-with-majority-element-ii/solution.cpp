#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        ordered_multiset s;
        s.insert(0);
        long long ans = 0, prefix = 0;
        for (int x : nums) {
            prefix += (x == target ? 1 : -1);
            ans += s.order_of_key(prefix);
            s.insert(prefix);
        }
        return ans;
    }
};
