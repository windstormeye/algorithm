package pjhubs;

import edu.princeton.cs.algs4.StdOut;

public class c1ex1_1_6 {
    public static void c1ex1_1_6() {
        int f = 0;
        int g = 1;
        for (int i = 0; i < 15; i++) {
            StdOut.println(f);
            f += g;
            g = f -g;
        }
    }
}
