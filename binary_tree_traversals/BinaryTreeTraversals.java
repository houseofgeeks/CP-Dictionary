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
	}
}