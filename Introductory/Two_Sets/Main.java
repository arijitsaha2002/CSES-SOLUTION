import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long total = n * (n + 1) / 2;
        long halfTotal = total / 2;
        String S1 = "", S2 = "";
        if (total % 2 == 0) {
            System.out.println("YES");
            long t = 0;
            long a = 0, b = 0;
            while (halfTotal != 0) {
                if (halfTotal < n) {
                    t = halfTotal;
                    S1 += " " + t;
                    a++;
                    break;
                }
                S1 += " " + n;
                a++;
                halfTotal -= n;
                n--;
            }
            System.out.println(a);
            System.out.println(S1.substring(1, S1.length()));
            while (n > 0) {
                if (n != t) {
                    b++;
                    S2 += n + " ";
                }
                n--;
            }
            System.out.println(b);
            System.out.println(S2.substring(0, S2.length() - 1));

        } else {
            System.out.println("NO");
        }
        sc.close();
    }
}