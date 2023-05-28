import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (n == 1) {
            System.out.println("1");
        } else if (n == 4) {
            System.out.println("1 3 4 2");
        } else if (n > 4) {
            long i = 1;
            while (i < n) {
                System.out.print(i + " ");
                i += 2;
            }
            i = 2;
            System.out.print("2");
            while (i < n) {
                System.out.print(" "+i);
                i += 2;
            }
            System.out.println();

        }
        else {
            System.out.println("NO SOLUTION");
        }
        sc.close();
    }
}