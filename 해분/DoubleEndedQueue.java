/*
    데크(덱)를 이중 연결리스트로 구현했다.

    구조체 개념과 흡사하지만 달랐던 클래스를 구현하는 것이 최근 들어 재미있다.

    앞을 체우고 싶으면 앞을 체우고(insertFront), 뒤를 체우고 싶으면 뒤를 체우고(insertRear)
    앞을 비우고 싶으면 앞을 비우고(deleteFront), 뒤를 비우고 싶으면 뒤를 비우고(deleteRear)

    백준 문제 풀 때 배열만 고집하던 내게
    메모리 초과로 막히던 문제에서 요긴하게 써먹을 수 있는 자료구조인 듯 하다.

    물론 메모리 주소를 어떻게 할당하는 지에 따라 처리 속도가 배열보다 비효율적일 수 있다.

    배열은 포인터 주소를 규칙적(ex. 1번지~3번지)으로 뽑아오지만,
    데크는 어느 포인터 주소를 랜덤(ex. 24번지, 35번지, 204056번지)하게 불러올 지 모른다.

    클래스 생성 시 메모리 주소가 어디에 할당되는 지를 알아야 한다.
 */
class DequeNode {
    int data;
    DequeNode lLink;
    DequeNode rLink;
}

class DoubleEndedQueue {
    DequeNode front;
    DequeNode rear;

    public DoubleEndedQueue() {
        this.front = null;
        this.rear = null;
    }

    public boolean isEmpty() {
        return (front == null);
    }

    public void insertFront(int value) {
        DequeNode node = new DequeNode();
        node.data = value;
        if(front == null) {
            front = node;
            rear = node;
        }
        else {
            front.lLink = node;
            node.rLink = front;
            node.lLink = null;
            front = node;
        }
    }

    public void insertRear(int value) {
        DequeNode node = new DequeNode();
        node.data = value;
        if(rear == null) {
            rear = node;
            front = node;
        }
        else {
            rear.rLink = node;
            node.lLink = rear;
            node.rLink = null;
            rear = node;
        }
    }

    public void deleteFront() {
        if(! isEmpty()) {
            if(front.rLink == null) {
                front = null;
                rear = null;
            }
            else {
                front = front.rLink;
                front.lLink = null;
            }
        }
    }

    public void deleteRear() {
        if(! isEmpty()) {
            if(rear.lLink == null) {
                rear = null;
                front = null;
            }
            else {
                rear = rear.lLink;
                rear.rLink = null;
            }
        }
    }

    public void print() {
        DequeNode node = front;
        System.out.println("----------------");
        while (node != null) {
            System.out.print(node.data+" ");
            node = node.rLink;
        }
        System.out.println("\n----------------");
    }


    public static void main(String[] args) {
        DoubleEndedQueue deq = new DoubleEndedQueue();

        deq.print();

        deq.insertFront(1);
        deq.print();

        deq.insertFront(2);
        deq.print();

        deq.insertRear(3);
        deq.print();

        deq.insertRear(4);
        deq.print();

        deq.deleteFront();
        deq.print();

        deq.deleteRear();
        deq.print();

        deq.deleteRear();
        deq.print();

        deq.deleteFront();
        deq.print();
    }
}