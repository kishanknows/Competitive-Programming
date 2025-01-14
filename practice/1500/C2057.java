import java.util.Scanner;

public class C2057 {
    static boolean solve(int l, int r, int val) {
        boolean ok = false;
        for (int i = 29; i >= 0; i--) {
            int x = 1 << i;
            if (x > l && x < r) {
                System.out.printf("%d %d %d\n", val + x - 1, val + x, val + x + 1);
                ok = true;
                break;
            } else if (x > l && x == r) {
                System.out.printf("%d %d %d\n", val + x - 2, val + x - 1, val + x);
                ok = true;
                break;
            }
        }
        return ok;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int l = sc.nextInt(), r = sc.nextInt();
            if (solve(l, r, 0))
                continue;
            int val = 0;
            for (int i = 29; i >= 0; i--) {
                int x = 1 << i;
                if ((l & x) == (r & x)) {
                    val += (l & x);
                    continue;
                }
                solve(l - val, r - val, val);
                break;
            }
        }
        sc.close();
    }
}
