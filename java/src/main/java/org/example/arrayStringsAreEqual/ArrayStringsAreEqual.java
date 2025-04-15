package org.example.arrayStringsAreEqual;


import java.util.LinkedList;
import java.util.Queue;

public class ArrayStringsAreEqual {
    static class Position{
        private int row;
        private int col;
        public Position(int row, int col) {
            this.row = row;
            this.col = col;
        }

        public int getRow() {
            return row;
        }

        public void setRow(int row) {
            this.row = row;
        }

        public int getCol() {
            return col;
        }

        public void setCol(int col) {
            this.col = col;
        }
    }
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        Position p1 = new Position(0, 0);
        Position p2 = new Position(0, 0);

        while (true) {
            char c1 = getNextChar(word1, p1);
            char c2 = getNextChar(word2, p2);
            if (c1 == ' ' && c2 == ' '){
                return true;
            }
            if (c1 != c2) {
                return false;
            }
        }
    }

    private char getNextChar(String[] words, Position p) {
        int row = p.getRow();
        int col = p.getCol();
        if (words.length < row + 1){
            return ' ';
        }
        String s = words[row];
        char c;
        int length = s.length();
        if (col < length){
            c = s.charAt(col);
        }else {
            c = ' ';
        }
        if (col + 1 >= length){
            p.setCol(0);
            p.setRow(row + 1);
        }else {
            p.setCol(col + 1);
        }
        return c;
    }
}
