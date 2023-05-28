import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();
        while(n != 1){
            System.out.print(n+" ");
            if(n % 2 == 0) n = n >> 1;
            else n = 3*n +1;
        }
        System.out.println(1);
        sc.close();
    }
}