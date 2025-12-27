#include "inventory.h"

// --- IMPLEMENTASI PRIMITIF TREE ---

void createNode(infotype X, adrNode &P) {
    P = new Node;
    P->info = X;
    P->firstChild = NULL;
    P->nextSibling = NULL;
}

void insertNode(adrNode Parent, adrNode P) {
    if (Parent == NULL || P == NULL) return;

    if (Parent->firstChild == NULL) {
        Parent->firstChild = P;
    } else {
        adrNode temp = Parent->firstChild;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = P;
    }
}

adrNode findNode(adrNode root, string name) {
    if (root == NULL) return NULL;
    if (root->info.name == name) return root;

    adrNode found = findNode(root->firstChild, name);
    if (found != NULL) return found;

    return findNode(root->nextSibling, name);
}

void deleteNode(adrNode &root, string name) {
    if (root == NULL) return;

    if (root->firstChild != NULL) {
        if (root->firstChild->info.name == name) {
            adrNode temp = root->firstChild;
            root->firstChild = temp->nextSibling;
            temp->nextSibling = NULL;
            deleteTree(temp);
            return;
        }
        adrNode prev = root->firstChild;
        adrNode curr = prev->nextSibling;
        while (curr != NULL) {
            if (curr->info.name == name) {
                prev->nextSibling = curr->nextSibling;
                curr->nextSibling = NULL;
                deleteTree(curr);
                return;
            }
            prev = curr;
            curr = curr->nextSibling;
        }
        deleteNode(root->firstChild, name);
    }
    deleteNode(root->nextSibling, name);
}

void deleteTree(adrNode P) {
    if (P == NULL) return;
    deleteTree(P->firstChild);
    deleteTree(P->nextSibling);
    delete P;
}

// --- IMPLEMENTASI TRAVERSAL ---

void printTree(adrNode root, int depth) {
    if (root == NULL) return;

    adrNode current = root;
    while (current != NULL) {
        for (int i = 0; i < depth; i++) cout << "   |";

        cout << "-- " << current->info.name;
        if (current->info.stock > 0) cout << " [Stok: " << current->info.stock << "]";
        cout << endl;

        if (current->firstChild != NULL) {
            printTree(current->firstChild, depth + 1);
        }
        current = current->nextSibling;
    }
}

void printPreOrder(adrNode root) {
    if (root == NULL) return;
    cout << root->info.name << " -> ";
    printPreOrder(root->firstChild);
    printPreOrder(root->nextSibling);
}

void printInOrder(adrNode root) {
    if (root == NULL) return;
    printInOrder(root->firstChild);
    cout << root->info.name << " -> ";
    printInOrder(root->nextSibling);
}

void printPostOrder(adrNode root) {
    if (root == NULL) return;
    printPostOrder(root->firstChild);
    printPostOrder(root->nextSibling);
    cout << root->info.name << " -> ";
}

// --- IMPLEMENTASI FITUR UNIK ---

int countTotalAssetStock(adrNode root) {
    if (root == NULL) return 0;

    int total = 0;
    if (root->info.stock > 0) {
        total += root->info.stock;
    }
    total += countTotalAssetStock(root->firstChild);
    total += countTotalAssetStock(root->nextSibling);
    return total;
}

void findMaxStock(adrNode root, adrNode &maxNode) {
    if (root == NULL) return;

    if (root->info.stock > maxNode->info.stock) {
        maxNode = root;
    }

    findMaxStock(root->firstChild, maxNode);
    findMaxStock(root->nextSibling, maxNode);
}

int countNodes(adrNode root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->firstChild) + countNodes(root->nextSibling);
}

// --- IMPLEMENTASI FUNGSI BANTUAN ---

void clearBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void waitForEnter() {
    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.get();
}
