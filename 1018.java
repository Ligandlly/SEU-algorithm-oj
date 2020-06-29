import java.util.*;
import java.lang.*;

class Gem {
    public int value;
    public int space;
    Gem() {
       value = space = 0;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner s  = new Scanner(System.in);
        int groupNumber = s.nextInt();
        for (int __ = 0; __ < groupNumber; ++__) {
            int N = s.nextInt();
            int C = s.nextInt();
            int[] dp = new int[C + 1];
            Gem[] arr = new Gem[N];
            for (int i = 0; i < N; ++i) {
                arr[i] = new Gem();
            }
            for (int i = 0; i < N; ++i) {
                arr[i].space = s.nextInt();
                arr[i].value = s.nextInt();
            }

            Arrays.fill(dp, Integer.MIN_VALUE);
            dp[0] = 0;

            for (int i = 0; i < N; ++i) {
                for (int j = C; j >= arr[i].space; --j) {
                    dp[j] = Math.max(dp[j], dp[j - arr[i].space] + arr[i].value);
                }
            }

            System.out.println(Math.max(dp[C], 0));

        }
    }
}
