package com.study.algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main14502 {
    static int N;
    static int M;
    static int result;
    static int[][] dir = {
            {0, 1, 0, -1},
            {1, 0, -1, 0}
    };
    static char[][] map;
    static boolean[][] check;
    static ArrayDeque<int[]> queue;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new char[N][M];

        queue = new ArrayDeque<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < M; j++) {
                map[i][j] = st.nextToken().charAt(0);
                if (map[i][j] == '2') {
                    queue.add(new int[]{i, j});
                }
            }
        }
        result = 0;

        dfs(0, 0);

        System.out.println(result);

    }

    public static ArrayDeque<int[]> copyDeep(ArrayDeque<int[]> queue) {
        ArrayDeque<int[]> queueTemp = new ArrayDeque<>();
        for (int[] node : queue) {
            queueTemp.add(node.clone());
        }
        return queueTemp;
    }

    public static int countZero() {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == '0' && !check[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    public static void dfs(int cnt, int idx) {
        if (cnt == 3) {
            check = new boolean[N][M];

            bfs(copyDeep(queue));

            int cntZero = countZero();
            result = Math.max(cntZero, result);

            return;
        }

        for (int i = idx; i < N * M; i++) {
            if (map[i / M][i % M] != '0') {
                continue;
            }

            map[i / M][i % M] = '1';
            dfs(cnt + 1, i + 1);
            map[i / M][i % M] = '0';
        }
    }

    public static void bfs(ArrayDeque<int[]> queue) {

        while (!queue.isEmpty()) {
            int[] node = queue.poll();
            check[node[0]][node[1]] = true;

            for (int i = 0; i < 4; i++) {
                int dx = dir[0][i] + node[0];
                int dy = dir[1][i] + node[1];

                if (dx < 0 || dx >= N || dy < 0 || dy >= M) {
                    continue;
                }

                if (map[dx][dy] != '0' || check[dx][dy]) {
                    continue;
                }

                queue.add(new int[]{dx, dy});
            }
        }
    }
}
