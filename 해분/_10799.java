/*
    백준 10799 - 쇠막대기

    스택이라는 태그가 달린 문제이다. 그냥 배열에 담아 풀었다.

    문제를 푸는 데, 그저 ) 괄호가 나올 경우, 파이프의 개수를 스택의 top-1 만큼 추가하고,
    top 을 감소하는 것으로 접근했다.

    예제의 값보다 더 큰 값이 나오기에 문제를 유심히 봤다.

    그림에 적힌 예를 두고 위에 top의 값을 적어봤다.

    3 + 4 + 4 + 3 + 2 + 3 + 2 + 2 + 1 + 0 + 1 + 1 = 26
            ↑     ↑   ↑ ↑ ↑     ↑ ↑   ↑ ↑ ↑     ↑   ↑ ↑
    1 2 3 4 3 4 5 4 5 4 3 2 3 4 3 2 3 2 1 0 1 2 1 2 1 0
    ( ( ( ( ) ( ( ) ( ) ) ) ( ( ) ) ( ) ) ) ( ( ) ( ) )

    문제에서 간과한 것은 맨 위에 있는 쇠막대기를 자를 때 아래 것 까지 자른 것을 포함하여 자르고 있었다.

    즉, 물질적으로 보면, 이미 자른 쇠막대기를 한번 더 잘라 카운트를 했던 것이다.

    이 부분을 예외처리하는 건 간단하다.
    top 에서 하나 내려올 땐 맨 위의 파이프만 자르고 나오는 것이다.

    if(line.charAt(i-1) == ')') {
        pipes++;
        top--;
    }
    그렇지 않다면 아래 파이프를 다 잘라주면 된다.
    else {
        pipes += --top;
    }
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _10799 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int length = line.length();
        int top = 0;
        int pipes = 0;

        int stack[] = new int[length];

        for(int i = 0; i < length; i++) {
            if(line.charAt(i) == '(') { // ( 괄호일 때.
                stack[top] = i;
                top++;
            }
            else {
                if(line.charAt(i-1) == ')') {
                    pipes++;
                    top--;
                }
                else {
                    pipes += --top;
                }
            }
        }
        System.out.println(pipes);
    }
}
