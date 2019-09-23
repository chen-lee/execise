#include <iostream>

/* 链表反转
 * 这篇博客不错: https://www.cnblogs.com/kubixuesheng/p/4394509.html
 * 反转链表，最直接的做法就是把链表中的指针的方向反转
 */
struct Node {
    int data;
    Node* next;
};

/* 或者这样定义node
typedef Node {
    int datq;
    Node* next;
}Node; 

 */

Node* reverse(Node* head) {
    // 定义三个指针，保存原来的指针的状态
    // 当前指针
    Node* pnow = head;
    // 当前指针的前驱节点，初始化为NULL
    Node* pre = NULL;
    // 当前节点的后继节点，初始化为pnow->next
    Node* pnext = pnow->next;
    // 定义尾指针,也可以不用
    Node* tail = NULL;
    // 开始遍历链表
    while (pnext) {
        pnext = pnow->next;  // 保存后继节点的值
        pnow->next = pre;  // 指针反转
        pre = pnow;  // 更新前驱节点的值
        pnow = pnext;  // 更新当前节点的值
    }
    return pre;
}

void printNode(Node* pNode) {
    while(pNode) {
        std::cout << pNode->data << "\t";
        pNode = pNode->next;
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    // 创建链表
    Node node1;
    node1.data = 1;
    Node node2;
    node2.data = 2;
    node1.next = &node2;
    Node node3;
    node3.data = 3;
    node2.next = &node3;
    Node node4;
    node4.data = 4;
    node3.next = &node4;
    node4.next = NULL;
    printNode(&node1);

    // 反转
    Node* newNode = reverse(&node1);
    printNode(newNode);
    return 0;
}
