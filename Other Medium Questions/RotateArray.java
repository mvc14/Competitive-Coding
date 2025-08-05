class Solution {
    public void rotate(int[] nums, int k) {
        // reverse the entire ting 
        reverse(nums, 0, nums.length - 1);

        // reverse the first k elements
        k %= nums.length;
        reverse(nums, 0, k -1);

        // reverse the rest 
        reverse(nums, k, nums.length -1);
    }

    public void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;

            start++;
            end--;
        }
    }
}
