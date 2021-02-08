/*
    추상클래스로 스택을 배열로 구현했다.
    연결리스트와 배열로 구현할 때의 장단점을 생각해봤다.

    - 장점 -
    배열: 스택 내부에 쌓인 값을 배열의 인덱스를 통해 쉽게 볼 수 있다.
    연결리스트: 값을 추가할 때마다 link를 하나 연결해 주는게 다 이기 때문에 메모리 낭비가 적다.

    - 단점 -
    연결리스트 : 스택 내부에 쌓인 값을 보려면 link의 link의 link의 ... 를 반복해야 한다. 즉, 불편하다.
    배열: 만들 때 스택의 크기를 미리 정해둬서 스택을 다 쓰지 않는 경우 메모리 낭비라고 볼 수 있다.
 */

public class Stack {
    public int top = 0;
    public int size;
    public int[] list;

    public Stack(int size) {
        this.size = size;
        this.list = new int[size];
    }

    public void push(int value) {
        if(top<size) {
            this.list[this.top++] = value;
        }
    }

    public boolean isEmpty() {
        return (this.top==0) ? true : false;
    }

    public void pop() {
        if(! isEmpty()) {
            this.top--;
        }
    }

    public int peek() {
        if(! isEmpty()) {
            return this.list[this.top-1];
        }
        else return -1;
    }

    public void print() {
        System.out.println("----------------");
        for(int i = 0; i < this.top; i++) {
            System.out.printf("%d ",this.list[i]);
        }
        System.out.println("\n----------------");
        System.out.println("top: "+this.top);
        System.out.println("peek: "+this.peek());
        System.out.println("isEmpty: "+this.isEmpty());
    }

    public static void main(String[] args) {
        Stack stack = new Stack(2);

        stack.print();

        stack.push(1);
        stack.print();
        stack.push(2);
        stack.print();
        stack.push(3);  // overflow 로 error가 나야 한다. 하지만, 넘쳐 흐른걸로 간주하고 예외 처리는 안했다.
        stack.print();
        stack.pop();
        stack.print();
        stack.pop();
        stack.print();
        stack.pop();
        stack.print();
    }
}