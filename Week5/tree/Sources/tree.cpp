#include "tree.h"
Status BST_init(BinarySortTreePtr BST)                         //建立新树
{
    BST->root = NULL;
    BST->count=0;
    return SUCCESS;
}

Status BST_insert(BinarySortTreePtr BST, ElemType e)                      //插入一个数
{
    NodePtr p = BST->root, p1=p;                           //p1记录上个节点
    NodePtr node = new Node;
    node->left = NULL; node->right = NULL; node->value = e;     //node初始化
    if (p == NULL) {
        BST->root = node;
        BST->count++;
        return SUCCESS;
    }
    while (p) {
        p1 = p;
        if (p->value > e) {                             //p的值大于e，说明e在左边
            p = p->left;
        }
        else if (p->value < e) {
            p = p->right;
        }
        else {
            cout << "树中已经有此值了，无法插入" << endl;
            return false;
        }
    }
    BST->count++;
    if (p1->value > e) {                                //往上个节点的左边插入
        p1->left = node;
    }
    else {
        p1->right = node;
    }
    return SUCCESS;
}

Status BST_delete(BinarySortTreePtr BST, ElemType e)                   //删掉一个节点，有三种情况
{
    int pp = 0;
    NodePtr p_fa = BST_search(BST, e, &pp);                                  //找到e的父亲位置p_fa
    NodePtr p_now;                                                             //p_now是e的位置

    //特判头节点
    BST->count--;
    if (pp) {                                                           //pp用来特判是否要删掉头节点
        p_now = BST->root;
        //1.左右子树都空
        if (p_now->left == NULL && p_now->right == NULL) {
            BST->root = NULL;
            return SUCCESS;
        }

        //2.其中有一个空的
        if (p_now->left == NULL || p_now->right == NULL) {
            if (p_now->left == NULL) {                         //p_now的左子节点是空的，就用p_now的右节点替它
                BST->root = p_now->right;
            }
            else {
                BST->root = p_now->left;
            }
            delete(p_now);
            return SUCCESS;
        }

        //3.左右都有子树,用左子树最大的来替它，替换后，一定满足1、2的情况
        NodePtr p_max = p_now->left, p_max_fa = p_now;              //p_max是左子树最大的节点，p_max_fa是p_max的父亲
        while (p_max->right)
        {
            p_max_fa = p_max;
            p_max = p_max->right;
        }
        //p_max和p_now换位,表面上只是值换了
        BST->root->value = p_max->value;
        if (p_now->left == p_max) {
            p_now->left = p_max->left;
            delete(p_max);
            return SUCCESS;
        }
        p_now = p_max;
        p_fa = p_max_fa;
        //用左节点替代
        if (p_fa == BST->root) {
            p_fa->left = p_now->left;
        }
        else {
            p_fa->right = p_now->left;
        }
        delete(p_now);
        return SUCCESS;
    }

    //找不到此节点，返回false
    if (p_fa == NULL) {
        return false;
    }

    //找当前的节点p_now
    int dir;//p_now在p_fa的左（0）还是右（1）
    if (p_fa->left && p_fa->left->value == e) {
        p_now = p_fa->left;
        dir = 0;
    }
    else {
        p_now = p_fa->right;
        dir = 1;
    }

    //三种情况,重复
        //1.左右子树都空
    if (p_now->left == NULL && p_now->right == NULL) {
        if (dir == 0) {
            p_fa->left = NULL;
        }
        else {
            p_fa->right = NULL;
        }
        delete(p_now);
        return SUCCESS;
    }

    //2.其中有一个空的
    if (p_now->left == NULL || p_now->right == NULL) {
        if (p_now->left == NULL) {                         //p_now的左子节点是空的，就用p_now的右节点替它
            if (dir == 0) {
                p_fa->left = p_now->right;
            }
            else {
                p_fa->right = p_now->right;
            }
        }
        else {
            if (dir == 0) {
                p_fa->left = p_now->left;
            }
            else {
                p_fa->right = p_now->left;
            }
        }
        delete(p_now);
        return SUCCESS;
    }

    //3.左右都有子树,用左子树最大的来替它，替换后，再用左节点替换它
    NodePtr p_max = p_now->left, p_max_fa = p_now;              //p_max是左子树最大的节点，p_max_fa是p_max的父亲
    while (p_max->right)
    {
        p_max_fa = p_max;
        p_max = p_max->right;
    }
    //p_max和p_now换位,表面上只是值换了
    if (dir == 0) {
        p_fa->left->value = p_max->value;
    }
    else {
        p_fa->right->value = p_max->value;
    }
    if (p_now->left == p_max) {
        p_now->left = p_max->left;
        delete(p_max);
        return SUCCESS;
    }
    p_now = p_max;
    p_fa = p_max_fa;
    p_fa->right = p_now->left;
    delete(p_now);
    return SUCCESS;
}

Status BST_Search(BinarySortTreePtr BST, ElemType e)                      //查找一个数
{
    NodePtr p = BST->root;
    while (p) {
        if (p->value > e) {
            p = p->left;
        }
        else if (p->value < e) {
            p = p->right;
        }
        else {
            return SUCCESS;
        }
    }
    return false;
}

NodePtr BST_search(BinarySortTreePtr BST, ElemType e, int* pp)                      //查找一个数，并返回它的位置,pp特判是否要删掉头节点
{
    NodePtr p = BST->root, p1 = NULL;
    while (p) {
        p1 = p;
        if (p->value > e) {
            p = p->left;
        }
        else if (p->value < e) {
            p = p->right;
        }
        if (p->value==e){
            if (p == BST->root) *pp = 1;
            return p1;
        }
    }
    return NULL;
}

Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr))    //前序遍历的递归写法
{
    if (BST->root != NULL) BST_preorderI_pro(BST->root, visit);
    else return false;
    return SUCCESS;
}

void BST_preorderI_pro(NodePtr p_now, void (*visit)(NodePtr))
{
    visit(p_now);
    if (p_now->left!=NULL) BST_preorderI_pro(p_now->left, visit);
    if (p_now->right != NULL)BST_preorderI_pro(p_now->right, visit);
    return;
}

Status BST_preorderR(BinarySortTreePtr BST, void (*visit)(NodePtr))   //前序遍历的栈写法
{
    if (BST->root == NULL) return false;
    stack <NodePtr> s;
    NodePtr o;
    s.push(BST->root);
    while (!s.empty()) {
        o = s.top();
        s.pop();
        visit(o);
        if (o->right != NULL) s.push(o->right);
        if (o->left != NULL)  s.push(o->left);
    }
    return SUCCESS;
}
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr))         //中序遍历的递归
{
    if (BST->root != NULL) BST_inorderI_pro(BST->root, visit);
    else return false;
    return SUCCESS;
}

void BST_inorderI_pro(NodePtr p_now, void (*visit)(NodePtr))
{
    if (p_now->left != NULL) BST_inorderI_pro(p_now->left, visit);
    visit(p_now);
    if (p_now->right != NULL)BST_inorderI_pro(p_now->right, visit);
    return;
}

Status BST_inorderR(BinarySortTreePtr BST, void (*visit)(NodePtr))         //中序遍历的栈
{
    int count = 0;
    if (BST->root == NULL) return FAILED;
    NodePtr o;
    stack <NodePtr> s;
    s.push(BST->root);
    while (!s.empty()) {
        if (count != s.size()) {                       //说明此时的栈顶元素没有将左节点放入
            ++count;
            o = s.top();
            while (o->left != NULL) {
                s.push(o->left);
                ++count;
                o = o->left;
            }
        }
        --count;
        o = s.top();
        s.pop();
        visit(o);
        if (o->right != NULL)  s.push(o->right);
    }
    return SUCCESS;
}

Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr))       //后序遍历的递归
{
    if (BST->root != NULL) BST_postorderI_pro(BST->root, visit);
    else return false;
    return SUCCESS;
}

void BST_postorderI_pro(NodePtr p_now, void (*visit)(NodePtr))
{
    if (p_now->left != NULL)BST_postorderI_pro(p_now->left, visit);
    if (p_now->right != NULL)BST_postorderI_pro(p_now->right, visit);
    visit(p_now);
    return;
}

Status BST_postorderR(BinarySortTreePtr BST, void (*visit)(NodePtr))       //后序遍历的栈
{
    int count = 0 ,Maxlen=BST->count+1;
    int* a = new int[Maxlen];
    memset(a, 0, Maxlen * sizeof(int));
    if (BST->root == NULL) return false;
    NodePtr o;
    stack <NodePtr> s;
    s.push(BST->root);
    while (!s.empty()) {                                //左优先，所以每个栈顶元素都要先将它的left放入
        if (count != s.size()) {                       //说明此时的栈顶元素没有将左节点放入
            ++count;
            o = s.top();
            while (o->left != NULL) {
                s.push(o->left);
                ++count;
                o = o->left;
            }
        }
        o = s.top();
        if (o->right != NULL && !a[count]) {           //此点没有放入右节点,用一个时间戳a记录是否放入过右节点
            s.push(o->right);
            a[count] = 1;                               //此点被放入右节点过了
            continue;
        }
        a[count] = 0;
        --count;
        o = s.top();
        s.pop();
        visit(o);
    }
    return SUCCESS;
}

Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr))       //层序遍历
{
    NodePtr o = BST->root;
    queue <NodePtr> s;
    s.push(o);
    while (!s.empty())
    {
        o = s.front();
        s.pop();
        if (o->left != NULL) s.push(o->left);
        if (o->right != NULL) s.push(o->right);
        visit(o);
    }
    return SUCCESS;
}

void COUT(NodePtr o)
{
    cout << o->value << " ";
    return;
}

int CIN()
{
    int OP;
    while (!scanf_s("%d", &OP)) {
        cin.ignore(std::numeric_limits< streamsize >::max(), '\n');				//清空缓冲区
        cout << "你的操作有问题啊,请重新输入吧" << endl;
    }
    return OP;
}
