import java.util.*;
import java.io.*;

class Main {
    static final int MAX_NUMBER = 10000;
    static int[] arr = new int[MAX_NUMBER];
    static int[] dp = new int[MAX_NUMBER];

    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(System.in);
        int group_number = s.nextInt();
        s.nextLine();
        for (int __ = 0; __ < group_number; ++__) {
            int n = s.nextInt();
            s.nextLine();
            Arrays.fill(dp, 0, n, 1);
            for (int i = 0; i < n; ++i) {
                arr[i] = s.nextInt();
            }

            int result = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (arr[i] >= arr[j]) {
                        dp[i] = Math.max(dp[i], dp[j] + 1);
                    }
                }
                if (dp[i] > result) {
                    result = dp[i];
                }
            }
            System.out.println(result);
        }
        s.close();
    }
}
