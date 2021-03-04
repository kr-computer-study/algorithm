/*
    트리로 전위, 중위, 후위 순회 기능을 구현했다.

    작년 2학기 자료구조 수업을 들을 때는 그 개념만 이해했지만,
    수업 시간에 코드를 직접 작성하지 않아서 재귀 개념이 들어있는 줄 몰랐다.

    코드를 작성하고 보니 순회 기능을 구현하면서 재귀 개념이 포함되있는 것을 확인했다.

    이번 학기에 듣는 알고리즘 수업에서 구현하지 않은 자료구조를 C 언어로 구현하는 듯 하다.

    난 클래스 개념도 빨리 익힐 겸 계속해서 자바로 구현해야겠다.
*/

class TreeNode {
    char data;
    TreeNode left;
    TreeNode right;
}

public class BinaryTree {
    static TreeNode makeRootNode(char value, TreeNode left, TreeNode right) {
        TreeNode node = new TreeNode();
        node.data = value;
        node.left = left;
        node.right = right;

        return node;
    }

    // 전위 순회
    static void preorder(TreeNode root) {
        if(root != null){
            System.out.print(root.data);
            preorder(root.left);
            preorder(root.right);
        }
    }

    // 중위 순회
    static void inorder(TreeNode root) {
        if(root != null){
            inorder(root.left);
            System.out.print(root.data);
            inorder(root.right);
        }
    }

    // 후위 순회
    static void postorder(TreeNode root) {
        if(root != null){
            postorder(root.left);
            postorder(root.right);
            System.out.print(root.data);
        }
    }

    public static void main(String[] args) {
        TreeNode n7 = makeRootNode('D', null, null);
        TreeNode n6 = makeRootNode('C', null, null);
        TreeNode n5 = makeRootNode('B', null, null);
        TreeNode n4 = makeRootNode('A', null, null);
        TreeNode n3 = makeRootNode('/', n6, n7);
        TreeNode n2 = makeRootNode('*', n4, n5);
        TreeNode n1 = makeRootNode('-', n2, n3);

        System.out.print("\n전위 순회 : ");
        preorder(n1);

        System.out.print("\n중위 순회 : ");
        inorder(n1);

        System.out.print("\n후위 순회 : ");
        postorder(n1);
    }
}

