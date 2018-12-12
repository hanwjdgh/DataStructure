# Tree

## 1. Terminology

node, edge, root node, terminal node, internal node

<img width="500" height="300" src="https://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F23674B345724A809084359"></img>

root node = level 1

## 2. Binary tree

A tree whose elements have at most 2 children is called a binary tree. Since each element in a binary tree can have only 2 children, we typically name them the left and right child

<img width="500" height="300" src="https://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F215C3B4E5724AB643607E5"></img>

### 2.1. Full Binary Tree

 A Binary Tree is full if every node has 0 or 2 children

### 2.2. Perfect Binary Tree

A Binary tree is Perfect Binary Tree in which all internal nodes have two children and all leaves are at the same level

### 2.3. Complete Binary Tree

 A Binary Tree is complete Binary Tree if all levels are completely filled except possibly the last level and the last level has all keys as left as possible

<img width="500" height="400" src="http://3.bp.blogspot.com/-lmaB5otknPM/Uc_cs5CH_TI/AAAAAAAAADE/noEWQUlDmX4/s714/completetree.png"></img>

## 3. Order

<img width="300" height="300" src="https://www.geeksforgeeks.org/wp-content/uploads/2009/06/tree12.gif"></img>

### 3.1 Inorder Traversal

- Inorder (Left, Root, Right) : 4 2 5 1 3

  1. Traverse the left subtree, i.e., call Inorder(left-subtree)
  2. Visit the root
  3. Traverse the right subtree, i.e., call Inorder(right-subtree)

### 3.2 Preorder Traversal

- Preorder (Root, Left, Right) : 1 2 4 5 3
  1. Visit the root
  2. Traverse the left subtree, i.e., call Preorder  (left-subtree)
  3. Traverse the right subtree, i.e., call Preorder(right-subtree)

### 3.3 PostOrder Traversal

- Postorder (Left, Right, Root) : 4 5 2 3 1
  1. Traverse the left subtree, i.e., call Postorder  (left-subtree)
  2. Traverse the right subtree, i.e., call Postorder  (right-subtree)
  3. Visit the root