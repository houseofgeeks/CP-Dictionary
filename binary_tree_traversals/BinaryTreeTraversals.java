import java.util.*;

public class BinaryTreeTraversals {

	/* A binary tree node has data, pointer to left child 
	and a pointer to right child */
	static class Node {

		int data;
		Node left, right;

		Node(int data) {
			this.data = data;
			left = right = null;
		}
	}

	// Prints the pre-order traversal of 
	// a binary tree, provide the root node 
	// of the same.
	public static void printPreorder(Node node) {

		if (node == null)
			return;

		// First deal with current node.
		System.out.print(node.data + " ");

		// Recur on left sub-tree.
		printPreorder(node.left);

		// Recur on right sub-tree.
		printPreorder(node.right);
	}

	// Prints the in-order traversal of 
	// a binary tree, provide the root node 
	// of the same.
	public static void printInorder(Node node) {

		if (node == null)
			return;

		// Recur on left sub-tree.
		printInorder(node.left);

		// Deal with current node.
		System.out.print(node.data + " ");

		// Recur on right sub-tree.
		printInorder(node.right);
	}

	// Prints the post-order traversal of 
	// a binary tree, provide the root node 
	// of the same.
	public static void printPostOrder(Node node) {

		if (node == null)
			return;

		// Recur on left sub-tree.
		printPostOrder(node.left);

		// Recur on right sub-tree.
		printPostOrder(node.right);

		// Now deal with current node.
		System.out.print(node.data + " ");
	}

	// Prints the level-order traversal of 
	// a binary tree, provide the root node 
	// of the same.
	public static void printLevelOrder(Node root)  
    { 
        Queue<Node> queue = new LinkedList<Node>(); 
        queue.add(root); 
        while (!queue.isEmpty())  
        { 
  
            // poll() removes the present head. 
            Node tempNode = queue.poll(); 
            System.out.print(tempNode.data + " "); 
  
            /*Enqueue left child */
            if (tempNode.left != null) { 
                queue.add(tempNode.left); 
            } 
  
            /*Enqueue right child */
            if (tempNode.right != null) { 
                queue.add(tempNode.right); 
            } 
        } 
    } 

	// Prints the zig-zag level-order traversal of 
	// a binary tree, provide the root node 
	// of the same.
	public static void printZigZagLevelOrder(Node root) {

		List<List<Integer>> zigzagLevelOrder = zigzagLevelOrder(root);

		for (List<Integer> list : zigzagLevelOrder) {
			for (int element : list) {
				System.out.print(element + " ");
			}
		}

		System.out.println();
	}

	// Helper method to return zig-zag level-order traversal.
	public static List<List<Integer>>  zigzagLevelOrder(Node root) {

        List<List<Integer>> res = new ArrayList<List<Integer>>();

        if (root == null) {
            return res;
        }

        Queue<Node> queue = new LinkedList<>();

        queue.offer(root);
        boolean from_left = true;

        while (!queue.isEmpty()) {

            // We will have all next level child nodes in the queue.

            int num_level_nodes = queue.size();

            List<Integer> curr_level = new LinkedList<Integer>();

            for (int i = 0; i < num_level_nodes; i++) {

                Node curr_node = queue.poll();

                if (from_left)
                    curr_level.add(curr_node.data);
                else 
                    curr_level.add(0, curr_node.data); // Insert at other end

                if (curr_node.left != null)
                    queue.offer(curr_node.left);
                if (curr_node.right != null)
                    queue.offer(curr_node.right);
            }

            res.add(curr_level);
            from_left = !from_left;
        }

        return res;
    }


	public static void main(String[] args) {
		
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);

		/*

	    The above statements create the 
	    binary tree as follows:

	        1
	       / \
	      2   3
	     / \
	    4   5

	    */ 

	    System.out.println("\nPreorder traversal of binary tree: ");
	    printPreorder(root);

	    System.out.println("\nInorder traversal of binary tree: ");
	    printInorder(root);

	    System.out.println("\nPostorder traversal of binary tree: ");
	    printPostOrder(root);

	    System.out.println("\nLevel-order traversal of binary tree: ");
	    printLevelOrder(root);

	    System.out.println("\nZig zag level-order traversal of binary tree: ");
	    printZigZagLevelOrder(root);
	}
}