import java.util.*;
public class Main {
    public static long F(long n, long m) {
        long result = 0, t = m;
        while (n >= t) {
            result += (n / t);
            t *= m;
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long a = F(n, 5), b = F(n, 2);
        System.out.println(Math.min(a, b));
        sc.close();
    }
}