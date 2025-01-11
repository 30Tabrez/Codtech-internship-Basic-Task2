# Codtech-internship-Basic-Task2
Data Structures in C

# Data Structures Program: Linked List, Binary Tree, and Graph

## Overview
This program allows users to interactively perform operations on three common data structures: **Linked List**, **Binary Tree**, and **Graph**. The user can choose from a menu to:
- Create a Linked List and perform insertion, deletion, and traversal.
- Create a Binary Tree and perform insertion, traversal (preorder, inorder, and postorder), and searching.
- Create a Graph and perform operations such as adding edges and traversing the graph using BFS (Breadth-First Search) and DFS (Depth-First Search).

This program is designed to demonstrate the implementation and use of various data structures in C.

---

## Features
1. **Linked List Operations**:
   - Insert nodes at the beginning, end, and at a specific position.
   - Delete nodes from the beginning, end, and from a specific position.
   - Traverse the list and display the elements.
   
2. **Binary Tree Operations**:
   - Insert nodes into the binary tree.
   - Preorder, inorder, and postorder traversals.
   - Search for a specific node.
   
3. **Graph Operations**:
   - Add edges between nodes.
   - Perform BFS and DFS traversals on the graph.
   
4. **Menu-Driven Interface**:
   - Allows the user to select the data structure they want to work with.
   - Provides an interactive interface for performing operations.

---

## Menu Options
Upon running the program, the user is presented with a menu to choose from:
1. **Linked List**:
   - Insert elements.
   - Delete elements.
   - Traverse and print the list.
   
2. **Binary Tree**:
   - Insert elements.
   - Perform Preorder, Inorder, Postorder Traversal.
   - Search for an element.
   
3. **Graph**:
   - Add edges between nodes.
   - Perform BFS and DFS traversals.

4. **Exit**: Exit the program.

---

## Compilation and Execution
1. Save the program code in a file named `data_structures.c`.
2. Open a terminal and compile the program:
   ```bash
   gcc data_structures.c -o data_structures
   ```
3. Run the program:
   ```bash
   ./data_structures
   ```

---

## Sample Screenshots

### **Main Menu**
The user can choose between Linked List, Binary Tree, and Graph operations.

![Main Menu Screenshot](https://via.placeholder.com/600x200.png?text=Main+Menu+Example)

### **Linked List Operations**
Input Example:  
```
Choose Linked List operation:
1. Insert at Beginning
2. Delete from Beginning
3. Traverse
```

Output Example:  
```
Linked List after insertion: 5 -> 10 -> 15
```

### **Binary Tree Operations**
Input Example:  
```
Choose Binary Tree operation:
1. Insert Node
2. Preorder Traversal
```

Output Example:
```
Binary Tree Preorder Traversal: 10 5 15
```

### **Graph Operations**
Input Example:
```
Choose Graph operation:
1. Add Edge
2. Perform BFS
```

Output Example:
```
Graph BFS Traversal: 0 1 2 3
```

---

## Code Walkthrough

### Main Program Flow:
1. The program starts by displaying the main menu.
2. Based on the user's choice, the appropriate function for Linked List, Binary Tree, or Graph is called.
3. The functions for Linked List, Binary Tree, and Graph contain the necessary operations like insertion, deletion, traversal, etc.
4. The program continues to display the menu until the user chooses to exit.

### Linked List Implementation:
- A structure `Node` is defined with integer data and a pointer to the next node.
- Functions are implemented for insertion at the beginning, end, and at specific positions, as well as deletion and traversal.

### Binary Tree Implementation:
- A structure `TreeNode` is defined with integer data, a pointer to the left child, and a pointer to the right child.
- Functions are implemented for insertion, traversals (preorder, inorder, postorder), and searching for a node.

### Graph Implementation:
- The graph is represented using an adjacency matrix (for simplicity).
- Functions are implemented to add edges and perform BFS and DFS traversals.

---

## Future Enhancements
1. **Graph Representation**: Consider using an adjacency list for a more efficient graph representation.
2. **Additional Traversal**: Implement level-order traversal for Binary Trees and other graph traversal algorithms like Dijkstra's.
3. **Error Handling**: Add error handling to manage edge cases, such as attempting to delete from an empty list or tree.

---

## License
This project is released under the MIT License.

---

## Contributions
Feel free to contribute by submitting pull requests, issues, or suggestions.

---

