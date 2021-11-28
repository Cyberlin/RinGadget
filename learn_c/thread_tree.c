//keep inputing the data ,untill the input is #
//
//create the binary tree
//threadify the binary tree using the pre and cur pointers
//recurse the thread_tree
#include <stdio.h>
#include <stdlib.h>
#define DataType char
typedef enum {
		Node,
		Thread,
} NodeTag;
typedef struct TreeNode {
		DataType data;
		struct TreeNode *lchild, *rchild;
		NodeTag ltag, rtag;
} TreeNode, *BiTreeNode;
//take the input and cram the input into the tree immediately in a recursive way
//para:None
//return:BiTreeNode
//pre_ord to create
void debug(BiTreeNode node){
		printf("%c--%d--%d\n",node->data,node->ltag,node->rtag);
}
void normal_traverse(BiTreeNode node)
{
		if (!node) {
				return;
		} else {
				printf("val:%c\n", node->data);
				if (node->ltag == Node)
						normal_traverse(node->lchild);
				if (node->rtag == Node)
						normal_traverse(node->rchild);
		}
}
BiTreeNode create()
{
		char val;
		//you input all so that the nonwhite char will not screw thing up
		//just use scanf("%c",&val),and give it the whole values at one time
		//but this would only prompt you to input once.because the input buffer
		//has gotten all the chars it needs
		scanf("%c", &val);
		if (val != '#') {
				BiTreeNode node = (BiTreeNode)malloc(sizeof(TreeNode));
				//pre_ord
				node->data = val;
				node->rtag = Node;
				node->ltag = Node;
				node->lchild = create();
				node->rchild = create();
				return node;
		} else {
				return NULL;
		}
}
//use the pre and cur to threadify the tree recursively
void threadify(BiTreeNode cur, BiTreeNode pre)
{
		if (cur == NULL) {
				return;
		}
		BiTreeNode copy = cur;
		if (pre != NULL && pre->rchild == NULL) {
				pre->rtag = Thread;
				pre->rchild = cur;
		}
		if (cur != NULL && cur->lchild == NULL) {
				cur->ltag = Thread;
				cur->lchild = pre;
		}
		if (cur->ltag == Node) {
				pre= copy;
				threadify(cur->lchild, pre);
		}
		if (cur->rtag == Node) {
				pre=copy; 
				threadify(cur->rchild, pre);
		}
}
//if the ltag or rtag is operative ,then use it directly instead of gonig deeper by taking another recursion
//the recursion will end when the highest recursion is over nartually
void pre_ord_traverse(BiTreeNode node)
{
		if (node == NULL)
				return;
		debug(node);
		if (node->rtag == Thread) {
				pre_ord_traverse(node->rchild);
		} else {
				if (node->ltag == Node)
						pre_ord_traverse(node->lchild);
				if (node->rtag == Node)
						pre_ord_traverse(node->rchild);
		}
}
void in_ord_traverse(BiTreeNode node)
{
		if (node == NULL) {
				return;
		}
		BiTreeNode cur = node;
		while (cur) {
				while (cur->ltag == Node) {
						cur = node->lchild;
				}
				debug(cur);
				while (cur->rtag == Thread) {
						cur = cur->rchild;
						debug(cur);
				}
				cur = cur->rchild;
		}
}
int main(int argc, char* argv[])
{
		printf("input the data and # to end\n");
		BiTreeNode root = create();
		BiTreeNode pre = NULL;
		threadify(root, pre);
		normal_traverse(root);
		pre_ord_traverse(root);
		//in_ord_traverse(root);
		return 0;
}
