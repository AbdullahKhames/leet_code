package org.example.problem_of_the_day;

public class ArrayStringsAreEqual {
    public static boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        int [] firstArrayCurrentIndex = {0, 0};
        int [] secondArrayCurrentIndex = {0, 0};
        Character firstArrayCurrentChar = getChar(word1, firstArrayCurrentIndex);
        Character secondArrayCurrentChar = getChar(word2, secondArrayCurrentIndex);
        while (firstArrayCurrentChar != null && secondArrayCurrentChar != null) {
            if (!firstArrayCurrentChar.equals(secondArrayCurrentChar)) {
                return false;
            } else {
                firstArrayCurrentChar = getChar(word1, firstArrayCurrentIndex);
                secondArrayCurrentChar = getChar(word2, secondArrayCurrentIndex);
            }
        }
        return firstArrayCurrentChar == null && secondArrayCurrentChar == null;
    }

    private static Character getChar(String[] word, int[] arrayCurrentIndex) {
        if (arrayCurrentIndex[0] < word.length) {
            String currentWord = word[arrayCurrentIndex[0]];
            if (currentWord.length() > arrayCurrentIndex[1]) {
                return extractChar(currentWord, arrayCurrentIndex);
            } else {
                arrayCurrentIndex[0]++;
                arrayCurrentIndex[1] = 0;
                if (arrayCurrentIndex[0] < word.length) {
                    return extractChar(word[arrayCurrentIndex[0]], arrayCurrentIndex);
                }
            }
        }
        return null;
    }

    private static char extractChar(String word, int[] arrayCurrentIndex) {
        char c = word.charAt(arrayCurrentIndex[1]);
        arrayCurrentIndex[1]++;
        return c;
    }
}
