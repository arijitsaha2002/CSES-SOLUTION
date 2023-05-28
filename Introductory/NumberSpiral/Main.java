import java.util.*;

public class Main {
    public static Long Number(Long x, Long y) {
        Long row,index;
        if(x > y){
            row = x;
            index = y;
        }
        else{
            row = y;
            index = (y << 1) - x;
        }

        if (row % 2 == 1) {
            row--;
            return row * row + index;
        }
        return row * row - index + 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Long testCase = sc.nextLong();
        for (; testCase > 0; testCase--) {
            System.out.println(Number(sc.nextLong(), sc.nextLong()));
        }
        sc.close();
    }
}