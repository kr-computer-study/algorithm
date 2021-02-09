/*
    스택을 연결리스트로 구현했다.
    연결리스트를 어떻게 구현할 지가 문제였다. 이 부분은 인터넷의 힘을 빌렸다.

    구조체로는 쉽게 이해했지만 클래스로 구현하는건 아직까지도 낯설다. 더 공부해야한다.

    link 로 node를 이어나가는 대신, pop과 push의 용이성을 위해 next의 개념을 이용했다.

    즉, top down 으로 구현했다.

    ① 처음 push한 node엔 next가 존재하지 않는다.
    ② 이후로 push한 node엔 top을 next에 저장하고 새로운 node를 top으로 저장한다.

    스택이 비어있을 땐 node.next 가 null 이기 때문에(①) 빈 스택은 print 가 작동하지 않는다.
    if(top == null) { }로 예외처리는 가능하다.

    연결리스트로 구현한 스택은 추가로 size나 top을 바로 확인하기 어렵다.

    배열과 연결리스트의 차이점에서 read 는 눈에 보여서 쉽게 알 수 있었지만
    create, update, delete 에 대한 차이도 있다는 것을 처음 알았다.

    지금 당장은 두 구현방식의 차이점을 이해하기가 어렵다.
    구글에 검색해보거나 더 유심히 생각해 보아야겠다.
 */

class StackNode {
    int data;
    StackNode next;
}

public class LinkedListStack {
    StackNode top;

    public LinkedListStack() {
        this.top = null;
    }

    public boolean isEmpty() {
        return (this.top == null);
    }

    public void push(int data) {
        StackNode node = new StackNode();
        node.data = data;
        node.next = top;
        top = node;
    }

    public void pop() {
        if(! isEmpty()) {
            StackNode node = top;
            top = node.next;
        }
    }

    public int peek() {
        if(! isEmpty()) {
            return top.data;
        } else {
            return -1;
        }
    }

    public void print() {
        int top_index = 1;
        System.out.println("----------------");

        StackNode node = top;

        while (node.next != null) {
            System.out.print(node.data+" ");
            node = node.next;
            top_index++;
        }
        System.out.print(node.data);
        System.out.println("\n----------------");


        System.out.println("top: "+ top_index);
        System.out.println("peek: "+ peek());
        System.out.println("isEmpty: "+ isEmpty());
    }

    public static void main(String[] args) {
        LinkedListStack stack = new LinkedListStack();

        System.out.println("isEmpty: "+stack.isEmpty());

        stack.push(1);
        stack.print();

        stack.push(2);
        stack.print();

        stack.push(4);
        stack.print();

        stack.pop();
        stack.print();

        stack.pop();
        stack.print();

        stack.pop();

        System.out.println("isEmpty: "+stack.isEmpty());
    }
}