package pjhubs;

import edu.princeton.cs.algs4.StdIn;

public class c1ex1_1_3 {

    public static void c1ex1_1_3(String[] args) {
        int a = StdIn.readInt();
        int b = StdIn.readInt();
        int c = StdIn.readInt();
        if (a == b && b == c) {
            System.out.println("equal");
        } else {
            System.out.println("not equal");
        }
    }

}
