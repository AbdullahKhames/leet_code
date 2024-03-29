package org.example.alx;
import java.util.HashMap;
import java.util.Map;
public class ransom_note {
    public boolean ransomNote(String ransomNote, String magazine){

        Map<Character, Integer> magazineMap = new HashMap<>(255);
        for (int i = 0; i < magazine.length(); i++) {
            magazineMap.put(magazine.charAt(i), magazineMap.getOrDefault(magazine.charAt(i),0) + 1);
        }
        for (int i = 0; i < ransomNote.length(); i++) {
            if (!magazineMap.containsKey(ransomNote.charAt(i)) ||  magazineMap.get(ransomNote.charAt(i)) <= 0){
                return false;
            }
            magazineMap.put(ransomNote.charAt(i), magazineMap.get(ransomNote.charAt(i)) - 1);
        }
        return true;
    }
}
