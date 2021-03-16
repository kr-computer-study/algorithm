package com.study.algorithm;

import java.io.*;

public class Main12728 {
    static int matrix[][][];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());


        matrix = new int[32][2][2];
        matrix[0] = new int[][]{{1, 0}, {0, 1}};
        matrix[1] = new int[][]{{6, -4}, {1, 0}};
        int a0 = 2;
        int a1 = 6;

        for (int i = 2; i < matrix.length; i++) {
            matrix[i] = powerMatrix(matrix[i - 1], matrix[i - 1]);
        }

        for (int i = 1; i <= T; i++) {
            int result = pow(Integer.parseInt(br.readLine()), a0, a1);

            sb.append("Case #").append(i).append(": ")
                    .append(String.format("%03d\n", ((result - 1) % 1000 + 1000) % 1000));
        }
        bw.write(sb.toString());
        bw.flush();
    }

    public static int[][] powerMatrix(int[][] a, int[][] b) {
        int[][] result = new int[a.length][b[0].length];

        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b[0].length; j++) {
                for (int k = 0; k < b.length; k++) {
                    result[i][j] += (a[i][k] * b[k][j]);
                }
                result[i][j] %= 10000;
            }
        }

        return result;
    }

    public static int pow(int n, int a0, int a1) {
        int index = 1;
        int[][] tempMatrix = new int[][]{{1, 0}, {0, 1}};
        while (n > 0) {

            if (n % 2 == 1) {
                tempMatrix = powerMatrix(tempMatrix, matrix[index]);
            }
            index++;
            n = n >> 1;
        }

        return (tempMatrix[1][0] * a1 + tempMatrix[1][1] * a0);
    }
}
