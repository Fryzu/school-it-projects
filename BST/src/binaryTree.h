#define MAXLINE 20 
#define CHARNUMBER 128

typedef struct TreeNode {
    //data:
    char name[MAXLINE]; 
    char surname[MAXLINE]; //key
    struct ListNode *numberList;
    //BST:
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

//BST
int addRecord(TreeNode*, char*);

int insert(TreeNode**);

int search(TreeNode*);

int findMin(TreeNode*);

int findMax(TreeNode*);

int nodeNumber(TreeNode*);

int height(TreeNode*);

void inOrder(TreeNode*);
