import java.util.*;
public class Main {
    public static long powerCal(long n, long t, long m) {
        if (n == 1) return m % t;
        if (n == 0) return 1;
        long p = (powerCal((n >> 1), t, ((m * m) % t))) % t;
        if (n % 2 == 1) {
            return (p * m) % t;
        }
        return p;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();
        long t = 1000000000 + 7;
        System.out.println(powerCal(n, t, 2));
        sc.close();
    }
}