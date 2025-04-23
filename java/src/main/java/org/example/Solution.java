package org.example;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

public class Solution {
    class CharacterTraversed {
        public char val;
        public int index;
        public boolean traversed;
        
        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + getEnclosingInstance().hashCode();
            result = prime * result + val;
            result = prime * result + index;
            result = prime * result + (traversed ? 1231 : 1237);
            return result;
        }
        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            CharacterTraversed other = (CharacterTraversed) obj;
            if (!getEnclosingInstance().equals(other.getEnclosingInstance()))
                return false;
            if (val != other.val)
                return false;
            if (index != other.index)
                return false;
            if (traversed != other.traversed)
                return false;
            return true;
        }
        public CharacterTraversed(char val, int index) {
            this.val = val;
            this.index = index;
        }
        public CharacterTraversed() {

        }

        private Solution getEnclosingInstance() {
            return Solution.this;
        }
        @Override
        public String toString() {
            return "CharacterTraversed [val=" + val + ", index=" + index + ", traversed=" + traversed + "]";
        }
        
        
    }
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        Set<CharacterTraversed> sList = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            sList.add(new CharacterTraversed(s.charAt(i), i));
        }
        CharacterTraversed temp = new CharacterTraversed();
        CharacterTraversed current;
        for (int i = 0; i < t.length(); i++) {
            temp.val = t.charAt(i);
            Iterator<CharacterTraversed> it = sList.iterator();
            while(it.hasNext()) {
                current = it.next();
                if (current.val == temp.val) {
                    current.traversed = true;
                }
            }
        }
        Iterator<CharacterTraversed> it = sList.iterator();
        while(it.hasNext()) {
            current = it.next();
            if (current.traversed == false) {
                return false;
            }
        }
        return true;
    }
}
