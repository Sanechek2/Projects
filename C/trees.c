//
// Created by Sanechek on 02/04/2026.
//

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    struct Node *left;
    struct Node *right;
    int key;
} Node;

Node* create_node(int value);
Node* insert_bst(Node* root, int value);
Node* insert_avl(int left, int right, int array[]);
Node* remove_node(Node* root, int key);
Node* deleting(Node* root);
Node* rotate_right(Node* root);
Node* rotate_left(Node* root);
void print_postorder(Node* root);
void print_preorder(Node* root);
void print_inorder(Node* root);
void exportTikZ(struct Node* node, FILE* f);
void findMax(struct Node* node);
void findMin(struct Node* node);
void dsw_rebalance(Node** root_ptr);
void make_compression(Node* dumny, int count);
void print_tree_pretty(Node* root, int level);

void quick_sort(int array[], int left, int right);
void print_tikz(Node* root);

int main(int argc, char const *argv[]) {
    Node *root = NULL;
    int w_tree;
    int n;
    srand(time(NULL));

    for (int i = 1; i <argc; i++) {
        if (strcmp(argv[i],"--tree") == 0) {
            if (i+1 < argc && strcmp( argv[i+1],"AVL")== 0) {
                w_tree = 1;
            }
            else if (i+1 < argc && strcmp(argv[i+1],"BST")== 0) {
                w_tree = 2;
            }
        }
    }

    printf("nodes> ");
    fflush(stdout);
    scanf("%d", &n);

    printf("insert> ");
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (w_tree == 2) {
        for (int i = 0; i < n; i++) {
            root = insert_bst(root, arr[i]);
        }
    } else if (w_tree == 1) {
        quick_sort(arr, 0, n - 1);
        root = insert_avl(0, n - 1, arr);
    }

    while (getchar() != '\n');

    char action[20];
    while (1) {
        printf("action> ");
        fflush(stdout);

        if (scanf(" %s", action) == EOF) {//add space between %s
            break;
        }
        if (strcmp(action, "Export") == 0) {
            FILE *f = fopen("export.tikz", "w");
            if (f) {
                fprintf(f, "\\begin{tikzpicture}[every node/.style={circle,draw,minimum size=0.8cm},\n");
                fprintf(f, "  level 1/.style={sibling distance=60mm},\n");
                fprintf(f, "  level 2/.style={sibling distance=30mm},\n");
                fprintf(f, "  level 3/.style={sibling distance=15mm},\n");
                fprintf(f, "  level distance=1.5cm]\n");
                fprintf(f, "\\");

                exportTikZ(root, f);

                fprintf(f, ";\n\\end{tikzpicture}\n");
                fclose(f);
                printf("TikZ code exported to export.tikz\n");
            }
        } else if (strcmp(action, "Remove") == 0) {
            int value;
            printf("Remove> ");
            fflush(stdout);
            //Zastosowanie fgets pozwala wczytać całą linię naraz,
            //a sscanf bezpiecznie wyciąga z niej tylko liczby.
            //Dzięki temu bufor jest zawsze czysty przed kolejną iteracją pętli głównej.
            //Dodałem getchar() do oczyszczenia bufora oraz zastosowałem sscanf z operatorem %n,
            //aby poprawnie parsować listę liczb do usunięcia z jednej linii.
            getchar();

            char line[256];
            if (fgets(line, sizeof(line), stdin)) {
                char *ptr = line;
                int value;
                int offset;
                //
                while (sscanf(ptr, "%d%n", &value, &offset) == 1) {
                    root = remove_node(root, value);
                    ptr += offset;
                }
            }
            //to jest poprzedni kod z błedem
            // while (scanf("%d", &value) == 1) {
            //     root = remove_node(root, value);
            // }
            // while (getchar() != '\n');

        } else if (strcmp(action, "Exit")==0) {
            break;
        } else if (strcmp(action, "Print") == 0) {
            printf("In-order: ");
            print_inorder(root);
            printf("\n");
            printf("Post-order: ");
            print_postorder(root);
            printf("\n");
            printf("Pre-order: ");
            print_preorder(root);
            printf("\n");
        } else if (strcmp(action, "Find_min_max") == 0) {
            findMin(root);
            findMax(root);
        } else if (strcmp(action, "Delete") == 0) {
            printf("Deleting: ");
            root = deleting(root);
            printf("\n");
        } else if (strcmp(action, "Rebalance")==0) {
            dsw_rebalance(&root);
            print_preorder(root);
            printf("\n");
        } else if (strcmp(action, "Help")==0) {
                printf("Help         Show this message\n");
                printf("Print        Print the tree using In-order, Pre-order, Post-order\n");
                printf("Remove       Remove elements of the tree\n");
                printf("Delete       Delete whole tree\n");
                printf("Export       Export the tree to file\n");
                printf("Rebalance    Rebalance the tree\n");
                printf("Find_min_max Finding minimum i maximum number in tree\n");
                printf("Exit         Exits the program\n");
        } else {
            printf("Invalid action\n");
        }
    }
    free(arr);
}

Node* create_node(int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->key = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert_bst(Node* root, int value) {
    if (root == NULL) {
        root = create_node(value);
    } else if (value < root->key) {
        root->left = insert_bst(root->left, value);
    } else if (value > root->key) {
        root->right = insert_bst(root->right, value);
    }
    return root;
}

Node* insert_avl(int left, int right, int array[]) {
    if (left > right) {
        return NULL;
    }

    int mid = (left + right) / 2;

    Node* root = create_node(array[mid]);

    root->left = insert_avl(left, mid -1, array);
    root->right = insert_avl(mid + 1, right, array);

    return root;
}

void quick_sort(int array[], int left, int right) {
    int random = rand() % (right - left + 1) + left;

    if (left < right) {
        int temp = array[left];
        array[left] = array[random];
        array[random] = temp;

        int pivot = array[left];
        int i = left;

        for (int j = left +1; j <= right; j++) {
            if (array[j] < pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        int temp_last = array[left];
        array[left] = array[i];
        array[i] = temp_last;

        quick_sort(array, left, i - 1);
        quick_sort(array, i + 1, right);
    }
}

Node* remove_node(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = remove_node(root->left, key);
    } else if (key > root->key) {
        root->right = remove_node(root->right, key);                     
    }
    else {
        if (root->left == NULL) {
        Node* temp = root->right;
        free(root);
        return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->key = temp->key;
        root->right = remove_node(root->right, temp->key);
    }
    return root;
}

void print_inorder(Node* root) {
    if (root == NULL) {return;}
    print_inorder(root->left);
    printf("%d ", root->key);
    print_inorder(root->right);
}

void print_preorder(Node* root) {
    if (root == NULL) {return;}
    printf("%d ", root->key);
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_postorder(Node* root) {
    if (root == NULL) {return;}
    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->key);

}

void findMax(struct Node* node){
    if(node == NULL){
        printf("Tree is empty\n");
        return;
    }
    struct Node* current = node;
    while(current->right != NULL){
        current = current->right;
    }
    printf("Max value: %d\n", current->key);
}

void findMin(struct Node* node){
    if(node == NULL){
        printf("Tree is empty\n");
        return;
    }
    struct Node* current = node;
    while(current->left != NULL){
        current = current->left;
    }
    printf("Min value: %d\n", current->key);
}

Node* deleting(Node* root) {
    if (root == NULL) {return NULL;}
    root->left = deleting(root->left);
    root->right = deleting(root->right);
    printf("%d ", root->key);
    free(root);
    return NULL;
}

Node* rotate_right(Node* root) {
    if (root == NULL || root->left == NULL) {return root;}
    Node* child = root->left;
    root->left = child->right;
    child->right = root;
    return child;
}

Node* rotate_left(Node* root) {
    if (root == NULL || root->right == NULL) {return root;}
    Node* child = root->right;
    root->right = child->left;
    child->left = root;
    return child;
}

void dsw_rebalance(Node** root_ptr) {
    if (*root_ptr == NULL) {return;}

    Node dummy;
    dummy.right = *root_ptr;
    dummy.left = NULL;

    Node* p = &dummy;
    while (p->right != NULL) {
        Node* curr = p->right;
        if (curr->left != NULL) {
            p->right = rotate_right(curr);
        } else {
            p = p->right;
        }
    }

    int lenth = 0;
    Node* temp = dummy.right;
    while (temp != NULL) {
        lenth++;
        temp = temp->right;
    }

    int h = (int)log2(lenth+1);
    int m = (int) pow (2, h) -1;

    make_compression(&dummy, lenth-m);

    while (m > 1) {
        m = m / 2;
        make_compression(&dummy, m);
    }
    *root_ptr = dummy.right;
}

void make_compression(Node* dumny, int count) {
    Node* p = dumny;
    for (int i = 0; i < count; i++) {
        Node* child = p->right;
        if (child == NULL || child->right == NULL) {break;}
        p->right = rotate_left(child);
        p = p->right;
    }
}

void print_tikz(Node* root) {

    if (root == NULL) return;

    printf("node {%d}\n", root->key);

    if (root->left != NULL || root->right != NULL) {
        if (root->left != NULL) {
            printf("child { ");
            print_tikz(root->left);
            printf("} ");
        } else {
            printf("child[missing] ");
        }

        if (root->right != NULL) {
            printf("child { ");
            print_tikz(root->right);
            printf("} ");
        } else {
            printf("child[missing] ");
        }
    }
}

void exportTikZ(Node* node, FILE* f) {
    if (node == NULL) return;

    fprintf(f, "node {%d}\n", node->key);

    if (node->left != NULL || node->right != NULL) {

        fprintf(f, "child { ");
        if (node->left != NULL) {
            exportTikZ(node->left, f);
        } else {
            fprintf(f, "node[inner sep=0pt, minimum size=0pt] {} edge from parent[draw=none]");
        }
        fprintf(f, " }\n");

        fprintf(f, "child { ");
        if (node->right != NULL) {
            exportTikZ(node->right, f);
        } else {
            fprintf(f, "node[inner sep=0pt, minimum size=0pt] {} edge from parent[draw=none]");
        }
        fprintf(f, " }\n");
    }
}

void print_tree_pretty(Node* root, int level) {
    if (root == NULL) return;

    print_tree_pretty(root->right, level + 1);

    for (int i = 0; i < level; i++) {
        printf("    ");
    }

    printf("---(%d)\n", root->key);

    print_tree_pretty(root->left, level + 1);
}

