#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Huffman tree node
struct Node {
    char letter;
    int frequency;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node for the Huffman tree
struct Node* createNode(char letter, int frequency) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->letter = letter;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to print the Huffman codes by traversing the tree
void printCodes(struct Node* root, int* code, int top) {
    // If the current node is not null
    if (root->left) {
        code[top] = 0;  // Move to left child
        printCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = 1;  // Move to right child
        printCodes(root->right, code, top + 1);
    }

    // If we reach a leaf node, print the character and its code
    if (!root->left && !root->right) {
        printf("%c: ", root->letter);
        for (int i = 0; i < top; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

// Function to build the Huffman tree
struct Node* buildHuffmanTree(char letters[], int frequencies[], int n) {
    struct Node* nodes[n];
    
    // Create a node for each letter and frequency
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(letters[i], frequencies[i]);
    }

    // Repeat until we have one node in the heap (Huffman Tree)
    while (n > 1) {
        // Sort the nodes based on frequency (simple bubble sort)
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nodes[i]->frequency > nodes[j]->frequency) {
                    struct Node* temp = nodes[i];
                    nodes[i] = nodes[j];
                    nodes[j] = temp;
                }
            }
        }

        // Take two nodes with the smallest frequency
        struct Node* left = nodes[0];
        struct Node* right = nodes[1];

        // Create a new internal node with these two as children
        struct Node* newNode = createNode('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        // Replace the first two nodes with the new node
        nodes[0] = newNode;
        nodes[1] = nodes[n - 1];
        n--;
    }

    // Return the root of the Huffman Tree
    return nodes[0];
}

int main() {
    // Input letters and their corresponding frequencies
    char letters[] = {'A', 'B', 'I', 'M', 'S', 'X', 'Z'};
    int frequencies[] = {10, 7, 15, 8, 10, 5, 2};
    int n = sizeof(letters) / sizeof(letters[0]);

    // Build the Huffman Tree
    struct Node* root = buildHuffmanTree(letters, frequencies, n);

    // Array to store the binary code (path in Huffman Tree)
    int code[100];
    int top = 0;

    // Print the Huffman Codes for each letter
    printf("Huffman Codes:\n");
    printCodes(root, code, top);

    return 0;
}
