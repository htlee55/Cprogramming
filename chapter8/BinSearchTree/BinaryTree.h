// BinaryTree.h: 이진트리 클래스
#include "BinaryNode.h"
#include "CircularQueue.h"
class BinaryTree
{
protected:
	BinaryNode* root;
public:
	BinaryTree() : root(NULL) {}
	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	///////// 이진트리의 순회 연산: 8.5절 내용  ////////////////
	// 이진트리의 inorder 순회 연산
	void inorder() { printf("\n   inorder: "); inorder(root); }
	void inorder(BinaryNode* node) {			// 순환적인 트리의 순회 함수
		if (node != NULL) {
			if (node->getLeft() != NULL) inorder(node->getLeft());
			printf(" [%d] ", node->getData());
			if (node->getRight() != NULL) inorder(node->getRight());
		}
	}
	// 이진트리의 preorder 순회 연산
	void preorder() { printf("\n  preorder: "); preorder(root); }
	void preorder(BinaryNode* node) {			// 순환적인 트리의 순회 함수
		if (node != NULL) {
			printf(" [%d] ", node->getData());
			if (node->getLeft() != NULL) preorder(node->getLeft());
			if (node->getRight() != NULL) preorder(node->getRight());
		}
	}
	// 이진트리의 postorder 순회 연산
	void postorder() { printf("\n postorder: "); postorder(root); }
	void postorder(BinaryNode* node) {			// 순환적인 트리의 순회 함수
		if (node != NULL) {
			if (node->getLeft() != NULL) postorder(node->getLeft());
			if (node->getRight() != NULL) postorder(node->getRight());
			printf(" [%d] ", node->getData());
		}
	}
	void levelorder() {
		printf("\nlevelorder: ");
		if (!isEmpty()) {
			CircularQueue q;
			q.enqueue(root);
			while (!q.isEmpty()) {
				BinaryNode* n = q.dequeue();
				if (n != NULL) {
					printf(" [%d] ", n->getData());
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
		}
		printf("\n");
	}

	/////////////// 이진트리의 추가 연산: 8.6절 내용 ////////////////////
	// 트리의 노드 개수를 구하는 함수
	int	getCount() { return isEmpty() ? 0 : getCount(root); }
	// 순환 호출에 의해 node를 루트로 하는 서브트리의 노드 수 계산 함수
	int getCount(BinaryNode* node) {
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}
	// 트리의 단말노드 개수를 구하는 함수
	int	getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	// 순환 호출에 의해 node를 루트로 하는 서브트리의 단말노드 수 계산 함수
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) return 0;
		if (node->isLeaf()) return 1;
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}
	// 트리의 높이를 구하는 함수
	int	getHeight() { return isEmpty() ? 0 : getHeight(root); }
	// 순환 호출에 의해 node를 루트로 하는 서브트리의 높이 계산 함수
	int getHeight(BinaryNode* node) {
		if (node == NULL) return 0;
		int	hLeft = getHeight(node->getLeft());
		int	hRight = getHeight(node->getRight());
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}
	// 수식트리 계산 함수
	int evaluate() { return evaluate(root); }
	// 순환 호출에 의해 node를 루트로 하는 수식 트리의 계산 함수
	int evaluate(BinaryNode* node) {
		if (node == NULL) return 0;
		if (node->isLeaf()) return node->getData();
		else {
			int op1 = evaluate(node->getLeft());
			int op2 = evaluate(node->getRight());
			switch (node->getData()) {
			case '+': return op1 + op2;
			case '-': return op1 - op2;
			case '*': return op1 * op2;
			case '/': return op1 / op2;
			}
			return 0;
		}
	}
	// 디렉터리 용량 계산 함수
	int	calcSize() { return calcSize(root); }
	// 순환 호출에 의해 node를 루트로 하는 트리의 전체 용량 계산 함수
	int calcSize(BinaryNode* node) {
		if (node == NULL) return 0;
		return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
	}

};


