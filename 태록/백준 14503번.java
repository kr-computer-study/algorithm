package com.study;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int M;
    static int[][] map;

    static int result;

    static int r;
    static int c;

    // 북: 0, 동: 1, 남: 2, 서: 3
    static int d;
    static int[][] dir = {
            {-1, 0, 1, 0},
            {0, 1, 0, -1}
    };

    static void clean() {
        map[r][c] = -1;
        result = result + 1;
    }

    static boolean canBack() {
        int back = map[r + dir[0][(d + 2) % 4]][c + dir[1][(d + 2) % 4]];

        return back != 1;
    }

    static boolean canClean() {
        int front = map[r + dir[0][d]][c + dir[1][d]];
        return front == 0;
    }

    static boolean canMove(int cnt) {
        if (cnt == 4) {
            // c. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
            if (canBack()) {
                r = r + dir[0][(d + 2) % 4];
                c = c + dir[1][(d + 2) % 4];
                return true;
            }
            // d. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
            return false;
        }

        d = (d + 3) % 4;
        // a. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
        if (canClean()) {
            r = r + dir[0][d];
            c = c + dir[1][d];
            return true;
        }
        // b. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
        return canMove(cnt + 1);
    }

    public static void main(String[] args) throws Exception {
        // declaration
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        result = 0;

        // input
        st = new StringTokenizer(br.readLine(), " ");
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine(), " ");
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());

        map = new int[M][N];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        do {
            // 1. 현재 위치를 청소한다.
            if(map[r][c] == 0) {
                clean();
            }
            // 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
        } while (canMove(0));

        System.out.println(result);
    }
}
