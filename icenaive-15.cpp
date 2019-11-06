class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, res;
        vector<int> ans;
        vector<vector<int>> answer;
        int len = nums.size() - 1;
        if(len == -1) return answer;
        sort(nums.begin(), nums.end());
        if(nums[0] <= 0 && nums[len] >= 0) {
            for(i = 0;i < len - 1;) {
                if(nums[i] > 0) break;
                int first = i + 1, last = len;
                while(first < last) {
                    if(first > last || nums[i] / 100 * nums[last] / 100 > 0) break;    // first < last 并且三个数不能够同号

                    res = nums[i] + nums[first] + nums[last];           // 三数和
                    if(res == 0) {          // 先添加结果 最后等于0是也需要修改first 或者 last
                        vector<int> ans = {nums[i], nums[first], nums[last]};
                        answer.push_back(ans);
                    }
                    if(res >= 0) {while(first < last && nums[last] == nums[--last]) {};}        //
                    else if(last >= 0){ while(first < last && nums[first] == nums[++first]) {};}
                }
                while(nums[i] == nums[++i] && i < len) {};
            }
        }
        return answer;
    }
};
