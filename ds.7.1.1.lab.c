#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;


TreeNode* newNode(int value) {
    TreeNode *temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->val = value;
    temp->left = temp->right = NULL;
    return temp;
}


TreeNode* insert(TreeNode *root, int value) {
    if (root == NULL)
        return newNode(value);

    if (value < root->val)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}


void inorder(TreeNode *root) {
    if (root == NULL) {
        printf("The tree is empty\n");
        return;
    }

    if (root->left != NULL)
        inorder(root->left);

    printf("%d ", root->val);

    if (root->right != NULL)
        inorder(root->right);
}


void preorder(TreeNode *root) {
    if (root == NULL) {
        printf("The tree is empty\n");
        return;
    }

    printf("%d ", root->val);

    if (root->left != NULL)
        preorder(root->left);

    if (root->right != NULL)
        preorder(root->right);
}


void postorder(TreeNode *root) {
    if (root == NULL) {
        printf("The tree is empty\n");
        return;
    }

    if (root->left != NULL)
        postorder(root->left);

    if (root->right != NULL)
        postorder(root->right);

    printf("%d ", root->val);
}


TreeNode* minValueNode(TreeNode *root) {
    while (root && root->left != NULL)
        root = root->left;

    return root;
}


TreeNode* delete(TreeNode *root, int value, int *flag) {
    if (root == NULL)
        return NULL;

    if (value < root->val) {
        root->left = delete(root->left, value, flag);
    }
    else if (value > root->val) {
        root->right = delete(root->right, value, flag);
    }
    else {
        *flag = 1;


        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        else if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        else {
            TreeNode *temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = delete(root->right, temp->val, flag);
        }
    }

    return root;
}


void destroy(TreeNode *root) {
    if (root == NULL)
        return;

    destroy(root->left);
    destroy(root->right);
    free(root);
}


int main() {
    TreeNode *root = NULL;
    int choice, value;

    while (1) {
        printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Delete\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                inorder(root);
                printf("\n");
                break;

            case 3:
                preorder(root);
                printf("\n");
                break;

            case 4:
                postorder(root);
                printf("\n");
                break;

            case 5: {
                scanf("%d", &value);
                int found = 0;
                root = delete(root, value, &found);
                if (!found)
                    printf("Value not found\n");
                break;
            }

            case 6:
                destroy(root);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
