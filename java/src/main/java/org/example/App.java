package org.example;

import org.example.problem_of_the_day.ArrayStringsAreEqual;
import org.example.problem_of_the_day.PascalTriangle;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        Solution solution = new Solution();
        String[] strs = {"eat","tea","tan","ate","nat","bat","ac","bd","aac","bbd","aacc","bbdd","acc","bdd"};
        System.out.println(solution.groupAnagrams(strs));
    }
}
