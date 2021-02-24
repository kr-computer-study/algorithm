/*
    순차 큐를 연결리스트로 구현했다.

    순차 큐와 달리 크기에 제한이 없다.

    생각보다 구현하는 데 크게 어렵지 않았다.

    이유는 전에 작성한 LinkedListStack 에서
    연결리스트를 구현하고 넘어가니 보다 쉽게 작성할 수 있었다.

    그렇다면, 연결리스트로 원형 큐를 어떻게 구현할까 고민해봤다.

    맨 처음 노드의 front 가 맨 마지막 노드가 될 것이다.

    구현 시 수정, 생성해야 할 메서드는 print, enQueue, isFull 정도가 될 것 같다.
 */
class QueueNode {
    int data;
    QueueNode next;
}

class LinkedListQueue {
    QueueNode front;
    QueueNode rear;

    public LinkedListQueue() {
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
        }
    }

    public void deQueue() {
        if (!isEmpty()) {
            front = front.next;
        }
    }

    public void print() {
        System.out.println("----------------");
        QueueNode node = front;

        while (node != null) {
            System.out.print(node.data+" ");
            node = node.next;
        }
        System.out.println("\n----------------");
    }

    public static void main(String[] args) {
        LinkedListQueue queue = new LinkedListQueue();

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