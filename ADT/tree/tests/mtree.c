#include "../tree.h"
#include <stdio.h>

int main()
{
    int type;
    scanf("%d", &type);

    TreeNode *first = createNode(1);
    TreeNode *child1 = createNode(2);
    TreeNode *child2 = createNode(3);
    TreeNode *child3 = createNode(4);
    TreeNode *child4 = createNode(5);
    addChild(first, child1);
    addChild(child1, child2);
    addChild(child2, child3);
    addChild(child3, child4);

    int target = 4;
    TreeNode *foundNode;

    switch (type)
    {
    case 1:

        printTree(first, 0);
        break;
    case 2:
        target = 4;
        foundNode = searchTree(first, target);

        if (foundNode != NULL)
        {
            printf("found");
        }
        else
        {
            printf("not found");
        }
        break;
    case 3:
        if (isOneElmt(first))
        {
            printf("satu elemen");
        }
        else
        {
            printf("bukan satu elemen");
        }
        
    }
    return 0;
}