package org.example.elzero_assignments;

import java.util.Arrays;

public class SortNamesStartsWithA {
    public static String[] sortNamesStartsWithA(String[] names) {
        String[] sortedNames = new String[names.length];
        int inputIdx = 0;
        for (int i = 0; i <names.length; i++) {
            if (notStartWithA(names[i])) {
                continue;
            }
            for (int j = i + 1; j < names.length; j++) {
                if (notStartWithA(names[j])) {
                    continue;
                }
                if (names[i].length() > names[j].length()) {
                    swapArrayIndices(names, i, j);
                }
                if (shouldBeSwapped(names[i], names[j])) {
                    swapArrayIndices(names, i, j);
                }
                int flag = sameLengthSort(names[i], names[j]);
                if (flag == 0 || flag == 1) {
                    continue;
                }
                if (flag == 2) {
                    swapArrayIndices(names, i, j);
                }

            }
            if (names[i] != null){
                sortedNames[inputIdx] = names[i];
                inputIdx++;
            }
        }

        System.out.println(Arrays.toString(names));
        return sortedNames;
    }
    public static boolean notStartWithA(String name) {
        return name.charAt(0) != 'a' && name.charAt(0) != 'A';
    }
    public static boolean shouldBeSwapped(String name1, String name2) {
        return name1.charAt(0) == 'A' && name2.charAt(0) == 'a';
    }
    public static int sameLengthSort(String name1, String name2) {
        if (name1.length() != name2.length()){
            return 0;
        }
        for (int i = 0; i < name1.length(); i++) {
            if (name1.charAt(i) < name2.charAt(i)) {
                continue;
            }
            else {
                return 2;
            }
        }
        return 1;
    }
    public static void swapArrayIndices(String[] names, int i, int j) {
        String temp = names[i];
        names[i] = names[j];
        names[j] = temp;
    }
}
