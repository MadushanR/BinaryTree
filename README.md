# BinaryTree

A simple, efficient implementation of the Binary Tree data structure in Python.

## Overview

This project provides a clean and extensible binary tree implementation. Binary trees are powerful data structures for organizing hierarchical data, supporting operations such as searching, inserting, and deleting nodes efficiently.

## Features

- Creation of binary trees
- Insertion and deletion of nodes
- Traversal algorithms (in-order, pre-order, post-order)
- Search functionality
- Support for custom data types

## Usage

Clone the repository:

```bash
git clone https://github.com/MadushanR/BinaryTree.git
cd BinaryTree
```

Import the BinaryTree module and start using it:

```python
from binary_tree import BinaryTree

# Create a new binary tree
tree = BinaryTree()

# Insert elements
tree.insert(5)
tree.insert(3)
tree.insert(7)

# Search for a value
node = tree.search(3)
if node:
    print("Found:", node.value)

# Traverse the tree
print("In-order traversal:")
for value in tree.inorder():
    print(value)
```

## Project Structure

- `binary_tree.py`: Main implementation of the binary tree
- `tests/`: Unit tests for tree operations

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request for any improvements or bug fixes.

## License

This project is licensed under the MIT License.

## Author

- [MadushanR](https://github.com/MadushanR)
