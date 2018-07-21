package pjhubs;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class c1ex1_1_9 {
    public static void c1ex1_1_9() {

        /*
        *   // 系统方法
        *   StdOut.println(Integer.toBinaryString(N));
        *
        *   标程：
        *   for(int n = N; n > 0; n /= 2) {
        *       s = (n % 2) + s;
        *   }
        *
         * */

        int N = StdIn.readInt();
        String s = "";
        while (N / 2 != 0) {
            s = N % 2 + s;
            N = N / 2;
        }
        s = N + s;
        StdOut.println(s);
    }
}
