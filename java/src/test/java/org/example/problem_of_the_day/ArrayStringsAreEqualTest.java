package org.example.problem_of_the_day;

import junit.framework.TestCase;

public class ArrayStringsAreEqualTest extends TestCase {

    public void testArrayStringsAreEqual() {
        boolean res = ArrayStringsAreEqual.arrayStringsAreEqual(new String[]{"ab", "c"}, new String[]{"a", "bc"});
        assertTrue(res);
        System.out.println(res);
    }
    public void testArrayStringsAreNotEqual() {
        boolean res = ArrayStringsAreEqual.arrayStringsAreEqual(new String[]{"ab", "bc"}, new String[]{"a", "bc"});
        assertFalse(res);
        System.out.println(res);
    }
}