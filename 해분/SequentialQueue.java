/*
    순차 큐를 배열로 구현했다.

    순차 큐는 데이터를 쓰고 지우는 enQueue, deQueue 과정을 큐 크기의 두배만큼만 사용할 수 있다.

    즉, 다 쓰고나면 재사용이 불가능 하다. 포화상태가 된다.

    다음 구현할 큐는 재사용이 가능한 큐, 즉 이 큐를 순환시키는 고리 형태의 원형 큐를 구현하는 것이다.
    구현은 간단할 듯 하다.

    front = (front+1) % max;
    rear = (rear+1) % max;
 */

public class SequentialQueue {
    private int max;         // 큐 크기
    private int front;       // 첫 번째 요소 커서
    private int rear;        // 마지막 요소 커서
    private int[] que;       // 큐 본체

    public SequentialQueue(int size) {
        this.max = size;
        this.front = -1;
        this.rear = -1;
        que = new int[size];
    }

    public boolean isEmpty() {
        return (this.front == this.rear) ? true : false;
    }

    public boolean isFull() {
        if(this.rear == max - 1) {
            return true;
        }
        return false;
    }

    public void enQueue(int value) {
        if(! isFull()) {
            this.rear++;
            this.que[rear] = value;
        }
    }

    public void deQueue() {
        if(! isEmpty()) {
            this.front++;
        }
    }

    public void print() {
        System.out.println("----------------");
        for(int i = this.front+1; i < this.rear+1; i++) {
            System.out.printf("%d ", que[i]);
        }
        System.out.println("\n----------------");
    }

    public static void main(String[] args) {
        SequentialQueue queue = new SequentialQueue(3);

        queue.print();

        queue.enQueue(5);
        queue.print();
        queue.enQueue(4);
        queue.print();
        queue.enQueue(3);
        queue.print();

        queue.deQueue();
        queue.print();
        queue.deQueue();
        queue.print();
        queue.deQueue();
        queue.print();
    }
}
