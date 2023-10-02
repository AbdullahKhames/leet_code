import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        System.out.println(isValid("<>"));

    }
    public static boolean isValid(String s) {
        if (s.length() % 2 != 0){
            return  false;
        }
        List<Character> openings = new ArrayList<>(Arrays.asList('(', '<', '[', '{'));
        List<Character> closings = new ArrayList<>(Arrays.asList(')', '>', ']', '}'));

        if (closings.contains(s.charAt(0))){
            return false;
        }

        for (int i = 0; i < s.length(); i++){
            int j;
            int openIdx = -1;
            int closingIdx = -1;
            boolean openSwapped = false;
            if (openings.contains(s.charAt(i))){
                openIdx = openings.indexOf(s.charAt(i));
                openSwapped = true;
            }
            else
                continue;
            for (j = 1; j < s.length(); j++){
                if (closings.contains(s.charAt(j))){
                    closingIdx = closings.indexOf(s.charAt(j));
                    if (openIdx == closingIdx)
                        break;
                }

            }
            if (i != 0 && !openSwapped)
            {
                break;
            }
            if (openIdx == -1 || closingIdx == -1 || openIdx != closingIdx)
                return false;
            if (i > j || (j - i) % 2 == 0)
                return  false;
        }
        return true;
    }
}