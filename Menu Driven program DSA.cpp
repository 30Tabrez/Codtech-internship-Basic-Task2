#include <stdio.h>
#include <stdlib.h>

// Linked List Node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Binary Tree Node
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

// Graph structure using adjacency list
typedef struct Graph {
    int vertices;
    int **adjMatrix;
} Graph;

// Function prototypes
void linkedListMenu();
void binaryTreeMenu();
void graphMenu();

void insertLinkedList(Node **head, int data);
void deleteLinkedList(Node **head, int data);
void traverseLinkedList(Node *head);
int searchLinkedList(Node *head, int data);

TreeNode* insertBinaryTree(TreeNode *root, int data);
TreeNode* deleteBinaryTree(TreeNode *root, int data);
void inorderTraversal(TreeNode *root);
int searchBinaryTree(TreeNode *root, int data);

Graph* createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
void removeEdge(Graph *graph, int src, int dest);
void displayGraph(Graph *graph);
void freeGraph(Graph *graph);

int main() {
    int choice;

    do {
        printf("\n--- Menu-Driven Program ---\n");
        printf("1. Linked List\n");
        printf("2. Binary Tree\n");
        printf("3. Graph\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                linkedListMenu();
                break;
            case 2:
                binaryTreeMenu();
                break;
            case 3:
                graphMenu();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

// --- Linked List Functions ---
void linkedListMenu() {
    Node *head = NULL;
    int choice, data;

    do {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Search\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertLinkedList(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteLinkedList(&head, data);
                break;
            case 3:
                printf("Linked List: ");
                traverseLinkedList(head);
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (searchLinkedList(head, data))
                    printf("Data found in the list.\n");
                else
                    printf("Data not found in the list.\n");
                break;
            case 5:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
}

void insertLinkedList(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d into the linked list.\n", data);
}

void deleteLinkedList(Node **head, int data) {
    Node *temp = *head, *prev = NULL;
    while (temp && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("Data not found in the list.\n");
        return;
    }
    if (!prev)
        *head = temp->next;
    else
        prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the linked list.\n", data);
}

void traverseLinkedList(Node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int searchLinkedList(Node *head, int data) {
    while (head) {
        if (head->data == data)
            return 1;
        head = head->next;
    }
    return 0;
}

// --- Binary Tree Functions ---
void binaryTreeMenu() {
    TreeNode *root = NULL;
    int choice, data;

    do {
        printf("\n--- Binary Tree Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. In-order Traversal\n");
        printf("4. Search\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertBinaryTree(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteBinaryTree(root, data);
                break;
            case 3:
                printf("In-order Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (searchBinaryTree(root, data))
                    printf("Data found in the tree.\n");
                else
                    printf("Data not found in the tree.\n");
                break;
            case 5:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
}

TreeNode* insertBinaryTree(TreeNode *root, int data) {
    if (!root) {
        TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (data < root->data)
        root->left = insertBinaryTree(root->left, data);
    else
        root->right = insertBinaryTree(root->right, data);
    return root;
}

TreeNode* deleteBinaryTree(TreeNode *root, int data) {
    if (!root) return NULL;
    if (data < root->data)
        root->left = deleteBinaryTree(root->left, data);
    else if (data > root->data)
        root->right = deleteBinaryTree(root->right, data);
    else {
        if (!root->left) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        TreeNode *succ = root->right;
        while (succ->left)
            succ = succ->left;
        root->data = succ->data;
        root->right = deleteBinaryTree(root->right, succ->data);
    }
    return root;
}

void inorderTraversal(TreeNode *root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int searchBinaryTree(TreeNode *root, int data) {
    if (!root) return 0;
    if (data == root->data)
        return 1;
    else if (data < root->data)
        return searchBinaryTree(root->left, data);
    else
        return searchBinaryTree(root->right, data);
}

// --- Graph Functions ---
void graphMenu() {
    Graph *graph = NULL;
    int vertices, choice, src, dest;

    printf("Enter the number of vertices for the graph: ");
    scanf("%d", &vertices);
    graph = createGraph(vertices);

    do {
        printf("\n--- Graph Operations ---\n");
        printf("1. Add Edge\n");
        printf("2. Remove Edge\n");
        printf("3. Display Graph\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;
            case 2:
                printf("Enter source and destination vertices to remove: ");
                scanf("%d %d", &src, &dest);
                removeEdge(graph, src, dest);
                break;
            case 3:
                displayGraph(graph);
                break;
            case 4:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    freeGraph(graph);
}

Graph* createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int *)calloc(vertices, sizeof(int));
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    if (src < graph->vertices && dest < graph->vertices) {
        graph->adjMatrix[src][dest] = 1;
        graph->adjMatrix[dest][src] = 1;
        printf("Edge added between %d and %d.\n", src, dest);
    } else {
        printf("Invalid vertices.\n");
    }
}

void removeEdge(Graph *graph, int src, int dest) {
    if (src < graph->vertices && dest < graph->vertices) {
        graph->adjMatrix[src][dest] = 0;
        graph->adjMatrix[dest][src] = 0;
        printf("Edge removed between %d and %d.\n", src, dest);
    } else {
        printf("Invalid vertices.\n");
    }
}

void displayGraph(Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

