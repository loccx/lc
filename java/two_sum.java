class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] solution = new int[2];
        for (int k = 0; k < nums.length; k++) {
            for (int j = k + 1; j < nums.length; j++) {
                if (nums[k] + nums[j] == target) {
                    solution[0] = k;
                    solution[1] = j;
                    return solution;
                }
            }
        }
        return null;
    }
}
