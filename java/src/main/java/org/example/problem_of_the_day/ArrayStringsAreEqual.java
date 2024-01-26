package org.example.problem_of_the_day;

public class ArrayStringsAreEqual {
    public static boolean arrayStringsAreEqual(String[] word1, String[] word2) {

        StringBuilder word1Builder = new StringBuilder(word1.length);
        StringBuilder word2Builder = new StringBuilder(word2.length);

        for (String word1SubString : word1) {
            word1Builder.append(word1SubString);
        }
        for (String word2SubString : word2) {
            word2Builder.append(word2SubString);
        }
        return word1Builder.toString().contentEquals(word2Builder);
    }
}
