import java.util.*;

public class C2026 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            String s = sc.next();
            Deque<Integer> zDeque = new ArrayDeque<>();
            Deque<Integer> oDeque = new ArrayDeque<>();
            for (int i = 1; i <= n; i++) {
                if (s.charAt(i - 1) == '0')
                    zDeque.add(i);
                else
                    oDeque.add(i);
            }
            long res = 0;
            while (!oDeque.isEmpty() && !zDeque.isEmpty()) {
                if (oDeque.getLast() > zDeque.getLast()) {
                    res += zDeque.removeLast();
                    oDeque.removeLast();
                } else {
                    res += zDeque.removeLast();
                }
            }
            while (!oDeque.isEmpty()) {
                res += oDeque.removeFirst();
                if (!oDeque.isEmpty()) {
                    oDeque.removeLast();
                }
            }
            while (!zDeque.isEmpty()) {
                res += zDeque.removeLast();
            }
            System.out.println(res);
        }
        sc.close();
    }
}
