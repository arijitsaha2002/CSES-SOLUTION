import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long testCase = sc.nextLong(), a, b;
        while (testCase > 0) {
            a = sc.nextLong();
            a += sc.nextLong();
            if (a % 3 == 0) System.out.println("YES");
            else System.out.println("NO");

            testCase--;
        }
        sc.close();
    }
}