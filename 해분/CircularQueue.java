/*
    원형 큐를 배열로 구현했다.

    순차 큐와 달리 isFull 가 아닐 경우 계속해서 사용할 수 있다.

    순차 큐와 원형큐를 배열과 연결리스트로 구현할 때 장단점을 생각해봤다.

    - 장점 -
    배열: 스택을 구현할 때와 같다. 보기 편함. 크기를 정해줄 수 있다.
    연결리스트 : 크기 제한이 없다. 메모리 낭비가 적다.

    - 단점 -
    연결리스트 : 스택을 구현할 때와 같다. 내부의 값을 쉽게 보기 힘들다.
    배열 : 큐의 크기만큼 사용하지 않으면 메모리 낭비다.

 +  오류 수정, 리팩토링

    오류는 print 메서드와 isFull 메서드에서 일어남.
    front 만 순환 후 0이 되는 시점에 rear 와 값이 같아 print 에 오류가 있었음.

 */

class CircularQueue {
    private int max;         // 큐 크기
    private int num = 0;
    private int front;       // 첫 번째 요소 커서
    private int rear;        // 마지막 요소 커서
    private int[] que;       // 큐 본체

    public CircularQueue(int size) {
        this.max = size;
        this.front = 0;
        this.rear = 0;
        this.que = new int[size];
    }

    public boolean isEmpty() {
        return num <= 0;
    }

    public boolean isFull() {
        return num >= max;
    }

    public void enQueue(int value) {
        if(! isFull()) {
            que[rear] = value;
            rear = (rear + 1) % max;
            num++;
        }
    }

    public void deQueue() {
        if(! isEmpty()) {
            front = (front + 1) % max;
            num--;
        }
    }

    public void print() {
        int first = front % max;
        int last = rear % max;
        int i = first;

        System.out.println("----------------");
        if(num == max) {
            System.out.printf("%d ", que[i]);
            i = (i + 1) % max;
        }

        while (i != last) {
            System.out.printf("%d ", que[i]);
            i = (i + 1) % max;
        }
        System.out.println("\n----------------");
    }

    public static void main(String[] args) {
        CircularQueue queue = new CircularQueue(3);

        queue.print();

        queue.enQueue(1);
        queue.print();
        queue.enQueue(2);
        queue.print();
        queue.enQueue(3);
        queue.print();

        queue.deQueue();
        queue.print();

        queue.enQueue(4);
        queue.print();
        queue.deQueue();
        queue.print();
        queue.enQueue(5);
        queue.print();

        queue.deQueue();
        queue.print();
        queue.deQueue();
        queue.print();
        queue.deQueue();
        queue.print();
    }
}
