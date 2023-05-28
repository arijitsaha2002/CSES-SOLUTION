import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        HashMap<Character, Integer> M = new HashMap<Character, Integer>();
        for (int i = 0; i < s.length(); i++) {
            M.put(s.charAt(i), M.get(s.charAt(i)) + 1);
        }
        boolean isMid = false;
        Character c;
        String m = "";
        Integer t;
        s = "";
        for (HashMap.Entry<Character, Integer> e : M.entrySet()) {
            c = e.getKey();
            t = e.getValue();
            System.out.println(c + " " + t);
            // if (t % 2 == 0) {
            //     t = (t >> 1);
            //     for (int j = 0; j < t; j++) {
            //         s += c + "";
            //     }
            // } else {
            //     if (!isMid) {
            //         System.out.println("NO SOLUTION");
            //         sc.close();
            //         return;
            //     }
            //     t = (t >> 1);
            //     for (int j = 0; j < t; j++) {
            //         s += c + "";
            //     }
            // }
        }
        s = s + m + s;
        System.out.println(s);
        sc.close();
    }
}