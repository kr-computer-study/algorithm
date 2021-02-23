import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		for (int i = 0; i < T; i++) {
			int H = s.nextInt();
			int W = s.nextInt();
			int N = s.nextInt();
			
			int floor = (N-1)%H+1;
			int room = (N-1)/H+1;
			
			System.out.printf("%d%02d\n", floor, room);			
		}
	}
}
