// 时间复杂度应该是O（n）
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len, l, r, mid, l_ans = -1, r_ans = -1;
        len = nums.size();
        l = 0; r = len - 1;
        while(l <= r) {
            mid = l + (r - l) >> 1;
            if(target == nums[mid]) {
                int index = mid;
                while(-1 < index && index < len && nums[index] == target) {l_ans = index; --index;}
                while(-1 < mid && mid < len && nums[mid] == target) {r_ans = mid; ++mid;}
                break;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        vector<int> ans = {l_ans, r_ans};
        return ans;
    }
};
// 二分查找
// 两次二分查找找边界
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int mid, l = 0, r = nums.size();
        while(l < r) {
            mid = l + r >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if(l == nums.size() || nums[l] != target) return {-1, -1};
        int start = l;

        l = 0, r = nums.size(), mid = 0;
        while(l < r) {
            mid = l + r >> 1;
            if(nums[mid] <= target) l = mid + 1;
            else r = mid;
        }
        int end = l - 1;
        return {start, end};
    }
};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int left = left(nums, target);

        if(left == nums.size() || nums[left] != target) return {-1, -1};
        int right = left(nums, target, false) - 1;
        return {left, right};
    }
private:
    int left(const vector<int>& nums, const int target, const bool left = true) {
        int l = 0, r = nums.size(), mid = 0;
        while(l < r) {
            mid = l + (r - l) / 2;
            if(nums[mid] > target || (left && nums[mid] == target)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};
