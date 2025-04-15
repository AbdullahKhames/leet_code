package org.example.arrayStringsAreEqual;

import junit.framework.TestCase;

public class ArrayStringsAreEqualTest extends TestCase {
    ArrayStringsAreEqual arrayStringsAreEqual;
    public void setUp() throws Exception {
        super.setUp();
        arrayStringsAreEqual = new ArrayStringsAreEqual();
    }

    public void testArrayStringsAreEqual1() {
        String[] s1 = new String[] { "a", "b", "c" };
        String[] s2 = new String[] { "a", "b", "c" };
        assertTrue(arrayStringsAreEqual.arrayStringsAreEqual(s1, s2));
    }
    public void testArrayStringsAreEqual2() {
        String[] s1 = new String[] { "a", "bc"};
        String[] s2 = new String[] { "a", "b", "c" };
        assertTrue(arrayStringsAreEqual.arrayStringsAreEqual(s1, s2));
    }

    public void testArrayStringsAreEqual3() {
        String[] s1 = new String[] { "a", "cb"};
        String[] s2 = new String[] { "ab", "c" };
        assertFalse(arrayStringsAreEqual.arrayStringsAreEqual(s1, s2));
    }
    public void testArrayStringsAreEqual4() {
        String[] s1 = new String[] {"abc","d","defg"};
        String[] s2 = new String[] { "abcddef" };
        assertFalse(arrayStringsAreEqual.arrayStringsAreEqual(s1, s2));
    }
}