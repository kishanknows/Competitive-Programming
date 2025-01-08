import java.util.*;

public class C2027 {
    static void dfs(HashMap<Long, List<Long>> mp, SortedSet<Long> vis, long u) {
        if (vis.contains(u))
            return;
        vis.add(u);
        if (mp.containsKey(u)) {
            for (long v : mp.get(u)) {
                dfs(mp, vis, v);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Integer T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            long a[] = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextLong();
            }
            HashMap<Long, List<Long>> mp = new HashMap<>();
            for (int i = 1; i < n; i++) {
                if (mp.containsKey(a[i] + i)) {
                    mp.get(a[i] + i).add(a[i] + 2 * i);
                } else {
                    mp.put(a[i] + i, new ArrayList<Long>());
                    mp.get(a[i] + i).add(a[i] + 2 * i);
                }
            }
            SortedSet<Long> vis = new TreeSet<>();
            dfs(mp, vis, n);
            System.out.println(vis.last());
        }
        sc.close();
    }
}