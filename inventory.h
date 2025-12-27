#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <limits> // Untuk numeric_limits
using namespace std;

struct infotype {
    string name;
    int stock;
};

typedef struct Node* adrNode;

struct Node {
    infotype info;
    adrNode firstChild;
    adrNode nextSibling;
};

// --- PRIMITIF TREE ---
void createNode(infotype X, adrNode &P);
void insertNode(adrNode Parent, adrNode P);
adrNode findNode(adrNode root, string name);
void deleteNode(adrNode &root, string name);
void deleteTree(adrNode P);

// --- TRAVERSAL ---
void printTree(adrNode root, int depth = 0);
void printPreOrder(adrNode root);
void printInOrder(adrNode root);
void printPostOrder(adrNode root);

// --- FITUR UNIK ---
int countTotalAssetStock(adrNode root);
void findMaxStock(adrNode root, adrNode &maxNode);
int countNodes(adrNode root);

// --- FUNGSI BANTUAN (UTILITY) ---
void clearBuffer();
void waitForEnter();

#endif
