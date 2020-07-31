class Solution {
public:
    int getIndex(int left, int right, vector<int>& nums) {
        if(left > right) return -1;
        int mid = (right - left)/2 + left;
        if(getIndex(left, mid-1, nums) != -1) return getIndex(left, mid-1, nums);
        else if(nums[mid]==mid) return mid;
        return getIndex(mid+1, right, nums); 
    }

    int findMagicIndex(vector<int>& nums) {
        int n = nums.size();
        int res = getIndex(0, n-1, nums);
        return res;
    }
};