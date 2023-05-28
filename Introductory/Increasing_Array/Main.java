import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long temp,moves = 0;
        long prev = sc.nextLong();

        for(int i = 1; i < n; i++ ){
            temp = sc.nextInt();
            if(temp > prev){
                prev = temp;
            }
            else moves += (prev - temp);
        }
        System.out.println(moves);
        sc.close();
    }
}