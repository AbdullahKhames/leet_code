package org.example;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {

    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        Map<Character, Integer> frequency = new HashMap<>();
        for (char c : s.toCharArray()) {
            if (frequency.containsKey(c)) {
                frequency.put(c, frequency.get(c) + 1);
            } else {
                frequency.put(c, 1);
            }
        }
        for (char c : t.toCharArray()) {
            Integer freq = frequency.get(c);
            if (freq != null && freq != 0) {
                frequency.put(c, freq - 1);
            } else {
                return false;
            }
            if (freq - 1 == 0) {
                frequency.remove(c);
            }
        }
        return frequency.isEmpty();
    }

    private int hashString(String str) {
        int result = 0;
        for (char c : str.toCharArray()) {
            result += (int) c;
        }
        return result % 100;
    }
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> result = new ArrayList<>();
        Map<String, List<String>> sortedHashes = new HashMap<>();
        List<String> temp;
        for (String str : strs) {
            char []arr = str.toCharArray();
            Arrays.sort(arr);
            String sortedVersion = new String(arr);
            if (sortedHashes.containsKey(sortedVersion)) {
                temp = sortedHashes.get(sortedVersion);
            } else {
                temp = new ArrayList<>();
            }
            temp.add(str);
            sortedHashes.put(sortedVersion, temp);
        }
        
        sortedHashes.forEach((key, val) -> {
            result.add(val);
        });
        return result;
    }
    class NumberPosition{
        int index;
        int number;
        int repeated;
        public NumberPosition(int index, int number, int repeated) {
            this.index = index;
            this.number = number;
            this.repeated = repeated;
        }
        
    }
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, NumberPosition> frequency = new HashMap<>();
        NumberPosition val;
        for (int i = 0; i < nums.length; i++) {
            val = frequency.get(nums[i]);
            if (val == null) {
                val = new NumberPosition(i, nums[i], 1);
                frequency.put(nums[i], val);
            } else if (i != val.index && Math.abs(i - val.index) <= k) {
                return true;
            } else {
                val.repeated++;
                val.index = i;
            }
        }
        return false;
    }

}
