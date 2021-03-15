package com.study.algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main1028 {
    static int R;
    static int C;
    static int[][][] map;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        int result = 0;
        map = new int[R][C][2];
        String input = br.readLine();
        for (int i = 0; i < C; i++) {
            map[0][i][0] = input.charAt(i) - '0';
            map[0][i][1] = map[0][i][0];
            if (map[0][i][0] == 1) {
                result = 1;
            }
        }

        Queue<int[]> queue = new PriorityQueue<>((o1, o2) -> -Integer.compare(o1[4], o2[4]));

        for (int i = 1; i < R; i++) {
            input = br.readLine();
            for (int j = 0; j < C; j++) {
                if (input.charAt(j) == '0') {
                    continue;
                }

                if (j < C - 1) {
                    map[i][j][0] = map[i - 1][j + 1][0] + 1;
                } else {
                    map[i][j][0] = 1;
                }
                if (j > 0) {
                    map[i][j][1] = map[i - 1][j - 1][1] + 1;
                } else {
                    map[i][j][1] = 1;
                }

                queue.add(new int[]{i, j, map[i][j][0], map[i][j][1], Math.min(map[i][j][0], map[i][j][1])});
            }
        }

        while (!queue.isEmpty()) {
            int[] node = queue.poll();
            if (node[0] < node[4] - 1 || node[1] < node[4] - 1 || (node[1] + node[4] - 1) >= C
                    || map[node[0] - node[4] + 1][node[1] - node[4] + 1][0] < node[4]
                    || map[node[0] - node[4] + 1][node[1] + node[4] - 1][1] < node[4]) {
                node[4]--;
                queue.add(node);
                continue;
            }
            result = node[4];
            break;
        }
        System.out.println(result);

    }
}
