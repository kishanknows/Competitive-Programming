import java.util.Scanner;

public class D2072 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            int l = 0, r = 0, mx = 0;
            for (int i = 0; i < n; i++) {
                int tmp = 0;
                for (int j = i + 1; j < n; j++) {
                    if (a[j] > a[i])
                        tmp--;
                    else if (a[i] > a[j])
                        tmp++;
                    if (tmp > mx) {
                        l = i;
                        r = j;
                        mx = tmp;
                    }
                }
            }
            l++;
            r++;
            System.out.println(l + " " + r);
        }
        sc.close();
    }
}