using System;

class BST
{
	class Tree
	{
		Node root;

		public Tree()
		{
			root = null;
		}

		public void traverse()
		{
			if (root != null)
				root.visit();
		}

		public Node search(int value)
		{
			if (root == null)
				return null;
			return root.search(value);
		}

		public void add(int value)
		{
			var node = new Node(value);
			if (root == null)
				root = node;
			else
				root.insert(node);
		}
	}

	class Node
	{
		public int value;
		public Node left;
		public Node right;

		public Node(int value)
		{
			this.value = value;
			this.left = null;
			this.right = null;
		}

		public Node search(int value)
		{
			if (this.value == value)
				return this;
			if (this.value > value && left != null)
				return left.search(value);
			if (this.value < value && right != null)
				return right.search(value);
			return null;
		}

		public void visit()
		{
			if (left != null)
				left.visit();
			
			Console.WriteLine(value);

			if (right != null)
				right.visit();
		}

		public void insert(Node node)
		{
			if (node.value < value)
			{
				if (left == null)
					left = node;
				else
					left.insert(node);
			}
			else if (node.value > value)
			{
				if (right == null)
					right = node;
				else
					right.insert(node);
			}
		}
	}

	public static void Main(string[] args)
	{
		var random = new Random();
		var tree = new Tree();
		for (var i = 0; i < 10; i++)
			tree.add(random.Next(0, 100));
		tree.traverse();

		Console.WriteLine();

		tree = new Tree();
		for (var i = 0; i < 10; i++)
			tree.add(i);
		for (var i = 0; i < 10; i++)
		{
			Node node = tree.search(i);
			if (node != null)
				Console.WriteLine(String.Format("Found {0}", node.value));
		}
	}
}
