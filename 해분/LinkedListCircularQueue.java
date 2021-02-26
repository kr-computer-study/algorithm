/*
    원형 큐를 연결리스트로 구현했다.

    C로 배우는 쉬운 자료구조 책에서 그림으로 그려진 원리를 생각하며 구현해봤다.

    구현하는데 베이스가 된 건 원형 연결리스트 이다.

    구현에 충실했다. 차후에 리팩토링이 필요하다.

    따로 산 책에서 스택, 큐 개념을 배울 때,
    예외처리도 다루고 와서 다시 코드를 살펴보고 리팩토링할 예정이다.
 */

class QueueNode {
    int data;
    QueueNode next;
}

class LinkedListCircularQueue {
    QueueNode front;
    QueueNode rear;

    public LinkedListCircularQueue() {
        this.front = null;
        this.rear = null;
    }

    public boolean isEmpty() {
        return front == null;
    }

    public void enQueue(int value) {
        QueueNode node = new QueueNode();
        node.data = value;
        node.next = null;

        if(isEmpty()) {
            front = node;
            rear = node;
        } else {
            rear.next = node;
            rear = node;
            node.next = front;
        }
    }

    public void deQueue() {
        if (!isEmpty()) {
            if(front==rear) {
                front = null;
                rear = null;
            }
            else {
                front = front.next;
                rear.next = front;
            }
        }
    }

    public void print() {
        System.out.println("----------------");
        QueueNode node = front;

        do {
            if (node == null) break;
            System.out.print(node.data+" ");
            node = node.next;
        } while (node != front);

        System.out.println("\n----------------");
    }

    public static void main(String[] args) {
        LinkedListCircularQueue queue = new LinkedListCircularQueue();

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
