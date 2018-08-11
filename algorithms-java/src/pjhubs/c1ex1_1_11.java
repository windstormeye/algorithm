package pjhubs;

import edu.princeton.cs.algs4.StdOut;

public class c1ex1_1_11 {
    public static void c1ex1_1_11(boolean[][] matrix) {
//        for (int i = 0; i < matrix.length; i++) {
//            StdOut.println(i);
//        }
//        for (int i = 0; i < matrix.length; i++) {
//            StdOut.println(i);
//            for (int j = 0; j < matrix[i].length; j ++) {
//                StdOut.println(matrix[i][j] ? '*' : ' ');
//            }
//        }

        System.out.print(' ');
        for (int i = 0; i < matrix.length; i++) {
            System.out.print(i);
        }
        System.out.println();
        for (int i = 0; i < matrix.length; i++) {
            System.out.print(i);
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] ? '*' : ' ');
            }
            System.out.println();
        }

    }
}
