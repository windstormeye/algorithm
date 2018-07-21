package pjhubs;

import edu.princeton.cs.algs4.StdOut;

public class c1ex1_1_7 {
    public static void c1_ex1_1_7() {
        /*
        *   a
        * */
//        double t = 9.0;
//        while (Math.abs(t - 9.0/t) > .001) {
//            t = (9.0/t + t) / 2.0;
//            StdOut.println(t);
//        }
//        StdOut.printf("%.5f\n", t);

        // 只要/的双方有一个是小数，则不省略小数点后的值，反之省略
//        StdOut.println(9.0/5.0);
//        StdOut.println(9./5.0);
//        StdOut.println(9.0/5);
//        StdOut.println(9/5);

        /*
        *   b
        *   出了一个小问题。注意看第一层循环条件，并没有到1000，所以只是49950
        * */

//        int sum = 0;
//        for (int i = 1; i < 1000; i ++) {
//            for (int j = 0; j < i; j ++) {
//                sum ++;
//                StdOut.println(sum);
//            }
//        }
//
//        StdOut.println(sum);

        /*
        *   c
        *   做出的答案是 999 * 9 = 8991，都忘了第一次实际上是算在内的。10000
        * */

        int sum = 0;
        for (int i = 1; i < 1000; i *= 2) {
            for (int j = 0; j < 1000; j++) {
                sum ++;
            }
        }
        StdOut.print(sum);

    }
}
