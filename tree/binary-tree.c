#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

struct bst_node
{
    int data;
    struct bst_node *left; // each bst_node can have at most 2 children ( *binary* tree )
    struct bst_node *right;
};

enum options
{
    quit,
    insert
};

typedef int bool;

struct bst_node *root_ptr = NULL;

// functions
void ShowOptions();
int min_element(struct bst_node *root);
int max_element(struct bst_node *root);
bool Search(struct bst_node *root, int value);
void Insert(struct bst_node **root, int value);

int main()
{
    int data;
    bool search;
    enum options opt;

    do
    {
        ShowOptions();
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            break;

        case 1:
            scanf("%d", &data);
            Insert(&root_ptr, data);
            break;

        case 2:
            scanf("%d", &data);
            search = Search(root_ptr, data);

            if (search == true)
                printf("found!\n");
            else
                printf("not found!\n");

            break;

        case 3:
            printf("min: %d\n", min_element(root_ptr));
            break;

        case 4:
            printf("max: %d\n", max_element(root_ptr));
            break;

        default:
            printf("\ntry again!\n");
            break;
        }
    } while (opt);

    return 0;
}

void ShowOptions()
{
    printf("\n");
    printf("options:\n");
    printf("(00) quit\n");
    printf("(01) insert node\n");
    printf("(02) search value\n");
    printf("(03) min\n");
    printf("(04) max\n");
    printf("\ninsert an option: ");
}

bool Search(struct bst_node *root, int value)
{
    if (root == NULL)
        return false;
    if (root->data == value)
        return true;

    if (value <= root->data)
        Search(root->left, value);
    else
        Search(root->right, value);
}

void Insert(struct bst_node **root, int value)
{
    if (*root == NULL)
    {
        struct bst_node *new_node = (struct bst_node *)malloc(sizeof(struct bst_node));

        *root = new_node;

        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return;
    }

    if (value <= (**root).data)
        Insert(&((**root).left), value);
    else
        Insert(&((**root).right), value);
}

int min_element(struct bst_node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root->data;
}

int max_element(struct bst_node *root)
{
    while (root->right != NULL)
        root = root->right;

    return root->data;
}