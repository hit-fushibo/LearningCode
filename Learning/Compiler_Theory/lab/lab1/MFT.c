#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MFT_node
{
    // 节点属性
    int value;

    // 右兄弟指针
    struct MFT_node *right_bro;

    // 第一个孩子指针
    struct MFT_node *children;
};

// for test
char *get_next(char *input, int *index)
{
    char *current_char = (char *)malloc(sizeof(char) * 5);
    int c_index = 0;
    while (input[*index] != ' ' && input[*index] != '\0')
    {
        current_char[c_index] = input[*index];
        *index += 1;
        c_index += 1;
    }
    current_char[c_index] = '\0';
    *index += 1;
    return current_char;
}

// for test
struct MFT_node *creat_MFT(char *input, int *index)
{
    char *current_char = get_next(input, index);
    if (strcmp(current_char, "$") != 0)
    {
        int value = atoi(current_char);
        struct MFT_node *root = NULL;
        root = (struct MFT_node *)malloc(sizeof(struct MFT_node));
        root->value = value;
        root->right_bro = creat_MFT(input, index);
        root->children = creat_MFT(input, index);
        return root;
    }
    else
    {
        return NULL;
    }
}




// 多叉树输出
void print_tree(struct MFT_node *root, int depth)
{
    for (int i = 0; i < depth; i++)
    {
        printf("\t");
    }
    if (root == NULL)
    {
        // 结构体属性输出
        printf("right\n");
    }
    printf("%d\n", root->value);
    if (root->children != NULL)
    {
        print_tree(root->children, depth + 1);
    }
    if (root->right_bro != NULL)
    {
        print_tree(root->right_bro, depth);
    }
}

int main()
{
    /*
    构建多叉树，构建的时候先创建当前节点并从出入中获取value值，之后构建其右兄弟，再构建其孩子，遇见$则直接返回
    */
    char *test_input = "1 $ 2 6 12 $ 13 $ $ 7 8 $ 9 10 11 $ $ $ $ $ 3 4 5 $ $ $ $";
    int index = 0;
    struct MFT_node *root = creat_MFT(test_input, &index);
    print_tree(root, 0);
    return 0;
}
