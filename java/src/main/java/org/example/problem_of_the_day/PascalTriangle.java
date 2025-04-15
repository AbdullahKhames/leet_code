package org.example.problem_of_the_day;

import java.util.ArrayList;
import java.util.List;

public class PascalTriangle {
    public static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>(numRows);
        List<Integer> temp = null;
        for (int i = 0; i < numRows; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = i; j >= 0; j--) {
                row.add(0);
            }
            for (int j = i; j >= 0; j--) {
                if (j == 0 || j == i) {
                    row.set(j, 1);
                } else {
                    row.set(j, temp.get(j - 1) + temp.get(j));
                }
            }
            result.add(row);
            temp = row;
        }
        return result;
    }
}
