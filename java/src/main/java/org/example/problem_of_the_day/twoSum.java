package org.example.problem_of_the_day;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class twoSum {
        public int[] twoSum(int[] nums, int target) {
        int diff;
        Map<Integer, Integer> numbers = new HashMap<>(nums.length);
        for (int i = 0; i < nums.length ; i++) {
            numbers.put(nums[i], i);
        }
        numbers.forEach((k, v) -> System.out.println(k + " " + v));
        for (int i = 0; i < nums.length ; i++) {
            diff = target - nums[i];
            if (numbers.containsKey(diff)) {
                return new int[]{numbers.get(diff), i};
            }
        }
        return null;
    }

    public static void main(String[] args) {
        twoSum twoSum = new twoSum();
        System.out.println(Arrays.toString(twoSum.twoSum(new int[]{2,7,11,15}, 9)));
    }
}
