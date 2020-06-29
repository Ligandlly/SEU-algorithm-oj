import java.util.*;
import java.lang.*;

public class Main {
    static boolean match(int i, boolean[][] arr, boolean[] visited, int[] hai) {
        for (int j = 1; j < arr[0].length; ++j) {
            if (arr[i][j] && !visited[j]) {
                visited[j] = true;
                if (hai[j] == 0 || match(hai[j], arr, visited, hai)) {
                    hai[j] = i;
                    return true;
                }
            }
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner s  = new Scanner(System.in);
        int group_number = s.nextInt();
        for (int __ = 0; __ < group_number; ++__) {
            int n = s.nextInt();
            int m = s.nextInt();

            boolean[][] arr = new boolean[n + 1][m + 1];
            boolean[] visited = new boolean[m + 1];
            int[] hai_anthropoi = new int[m + 1];
            for (int i = 1; i <= n; ++i) {
                int k = s.nextInt();
                for (int ___ = 0; ___ < k; ++___) {
                    int j = s.nextInt();
                    arr[i][j] = true;
                }
            }

            int result = 0;
            for (int i = 1; i <= n; ++i) {
                Arrays.fill(visited, false);
                if (match(i, arr, visited, hai_anthropoi)) {
                    result++;
                }
            }

            System.out.println(result);


        }
    }
}
