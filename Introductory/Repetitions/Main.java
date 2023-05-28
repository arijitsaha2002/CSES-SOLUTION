import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        char [] arr = s.toCharArray();
        
        int m = 0,maxVal = 0;
        char prev = 'u';
        for(int i = 0; i < s.length(); i++){
            if(arr[i] == prev) {
                m ++;
                
            }
            else {
                prev = arr[i];
                m = 1;
            }
            maxVal = Math.max(m,maxVal);
        }

        System.out.println(maxVal);
        sc.close();
    }
}