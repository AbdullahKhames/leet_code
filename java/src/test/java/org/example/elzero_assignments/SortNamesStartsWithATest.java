package org.example.elzero_assignments;

import junit.framework.TestCase;

import java.util.Arrays;

public class SortNamesStartsWithATest extends TestCase {

    public void testSortNamesStartsWithA() {
        String[] names = SortNamesStartsWithA.sortNamesStartsWithA(new String[]{"Ameer", "alsayed", "Mahmoud", "Ahmed", "ayman", "Israa", "Anas", "amal", "amr", "aml"});
        System.out.println(Arrays.toString(names));
    }
}