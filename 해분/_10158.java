/*
    시간 제한이 0.15초이다. 즉 시간복잡도가 작은 코드를 짜야한다.
    반복문 쓰지 말고 접근하지 말라는 말로 보인다.
    움직일 때 좌표값이 증가하는 구간과 감소하는 구간의 특정 주기가 있다.
    그 주기로 식을 세울 수 있었다.
 */
import java.util.Scanner;

public class _10158 {
    public static void main(String[] args) {
        Scanner stdIn = new Scanner(System.in);
        int w = stdIn.nextInt();
        int h = stdIn.nextInt();

        int x = stdIn.nextInt();
        int y = stdIn.nextInt();

        int t = stdIn.nextInt();

        x += t;
        y += t;

        if((x/w) % 2 == 0) {    // x가 증가상태일 경우
            x %= w;
        } else {                // x가 감소상태일 경우
            x = w - (x%w);
        }
        if((y/h) % 2 == 0) {    // y가 증가상태일 경우
            y %= h;
        } else {                // y가 감소상태일 경우
            y = h - (y%h);
        }
        System.out.println(x+" "+y);
    }
}
