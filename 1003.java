import java.util.Scanner;

public class Main {
    static int[] arr = new int[1000];

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int group_number = s.nextInt();
        s.nextLine();
        for (int __ = 0; __ < group_number; ++__) {
            int n = s.nextInt();
            for (int i = 0; i < n; ++i) {
                arr[i] = s.nextInt();
            }

            for (int i = 0; i < n - 1; ++i) {
                if (arr[i] > arr[i + 1]) {
                    int tmp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = tmp;
                }
            }

            for (int i = 0; i< n; ++i) {
                System.out.print(arr[i]);
                System.out.print(' ');
            }
            System.out.print('\n');


        }
    }
}
