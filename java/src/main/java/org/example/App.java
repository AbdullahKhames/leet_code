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
        int arr[] = {1,2,3,1,2,3};
        System.out.println(solution.containsNearbyDuplicate(arr, 2));
    }
}
