import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long a = 0 , b = 6, c = 16, d = 30, e = 12;
        while(n > 0){
            System.out.println(a);
            a += b;
            b += c;
            c += d;
            d += e;
            n--;
        }

        sc.close();
    }
}