import java.util.Scanner;

public class Main {
	
	static class Node {
		int data;
		Node next;
		Node prev;
		
		Node(int x) {
			data = x;
			prev = null;
			next = null;
		}
		
	}
	
	static String deleteK(Node head, int k) {
		Node cur = head;
		StringBuilder sb = new StringBuilder("<");
		
		if (cur == null) {
			return null;
		}
		
		while(cur.next != cur) {
			for (int i = 1; i < k; i++) {
				cur = cur.next;
			}
			
			sb.append(cur.data).append(", ");
			
			cur.prev.next = cur.next;
			cur.next.prev = cur.prev;
			cur = cur.next;
		}
		
		return sb.append(cur.data).append(">").toString();
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		int K = s.nextInt();
		
		Node head = new Node(1);
		head.prev = head;
		head.next = head;
		
		for (int i = 2; i < N + 1; i++) {
			Node node = new Node(i);
			
			head.prev.next = node;
			node.next = head;
			node.prev = head.prev;
			head.prev = node;
		}
		System.out.println(deleteK(head, K));
	}
}
