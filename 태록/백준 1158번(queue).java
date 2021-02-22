import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		int K = s.nextInt();

		Queue<Integer> q = new LinkedList<>();
		for (int i = 1; i < N + 1; i++) {
			q.add(i);
		}

		StringBuilder sb = new StringBuilder("<");

		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < K - 1; j++) {
				q.add(q.poll());
			}
			sb.append(q.poll()).append(", ");
		}
		System.out.println(sb.append(q.poll()).append(">"));
	}
}
