package pjhubs;

import edu.princeton.cs.algs4.StdIn;

import static java.lang.Math.abs;

public class c1ex1_1_5 {
    public static void c1ex1_1_5() {

        /*
            第二种答案
            double x = StdIn.readDouble();
		    double y = StdIn.readDouble();
		    System.out.println(x > 0 && x < 1 && y > 0 && y < 1);
        */

        double x = StdIn.readDouble();
        double y = StdIn.readDouble();
        if (x * 10 < 10 && y * 10 < 10) {
            System.out.println(true);
        } else {
            System.out.println(false);
        }
    }
}
