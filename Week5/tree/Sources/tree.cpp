#include "tree.h"
Status BST_init(BinarySortTreePtr BST)                         //��������
{
    BST->root = NULL;
    BST->count=0;
    return SUCCESS;
}

Status BST_insert(BinarySortTreePtr BST, ElemType e)                      //����һ����
{
    NodePtr p = BST->root, p1=p;                           //p1��¼�ϸ��ڵ�
    NodePtr node = new Node;
    node->left = NULL; node->right = NULL; node->value = e;     //node��ʼ��
    if (p == NULL) {
        BST->root = node;
        BST->count++;
        return SUCCESS;
    }
    while (p) {
        p1 = p;
        if (p->value > e) {                             //p��ֵ����e��˵��e�����
            p = p->left;
        }
        else if (p->value < e) {
            p = p->right;
        }
        else {
            cout << "�����Ѿ��д�ֵ�ˣ��޷�����" << endl;
            return false;
        }
    }
    BST->count++;
    if (p1->value > e) {                                //���ϸ��ڵ����߲���
        p1->left = node;
    }
    else {
        p1->right = node;
    }
    return SUCCESS;
}

Status BST_delete(BinarySortTreePtr BST, ElemType e)                   //ɾ��һ���ڵ㣬���������
{
    int pp = 0;
    NodePtr p_fa = BST_search(BST, e, &pp);                                  //�ҵ�e�ĸ���λ��p_fa
    NodePtr p_now;                                                             //p_now��e��λ��

    //����ͷ�ڵ�
    BST->count--;
    if (pp) {                                                           //pp���������Ƿ�Ҫɾ��ͷ�ڵ�
        p_now = BST->root;
        //1.������������
        if (p_now->left == NULL && p_now->right == NULL) {
            BST->root = NULL;
            return SUCCESS;
        }

        //2.������һ���յ�
        if (p_now->left == NULL || p_now->right == NULL) {
            if (p_now->left == NULL) {                         //p_now�����ӽڵ��ǿյģ�����p_now���ҽڵ�����
                BST->root = p_now->right;
            }
            else {
                BST->root = p_now->left;
            }
            delete(p_now);
            return SUCCESS;
        }

        //3.���Ҷ�������,���������������������滻��һ������1��2�����
        NodePtr p_max = p_now->left, p_max_fa = p_now;              //p_max�����������Ľڵ㣬p_max_fa��p_max�ĸ���
        while (p_max->right)
        {
            p_max_fa = p_max;
            p_max = p_max->right;
        }
        //p_max��p_now��λ,������ֻ��ֵ����
        BST->root->value = p_max->value;
        if (p_now->left == p_max) {
            p_now->left = p_max->left;
            delete(p_max);
            return SUCCESS;
        }
        p_now = p_max;
        p_fa = p_max_fa;
        //����ڵ����
        if (p_fa == BST->root) {
            p_fa->left = p_now->left;
        }
        else {
            p_fa->right = p_now->left;
        }
        delete(p_now);
        return SUCCESS;
    }

    //�Ҳ����˽ڵ㣬����false
    if (p_fa == NULL) {
        return false;
    }

    //�ҵ�ǰ�Ľڵ�p_now
    int dir;//p_now��p_fa����0�������ң�1��
    if (p_fa->left && p_fa->left->value == e) {
        p_now = p_fa->left;
        dir = 0;
    }
    else {
        p_now = p_fa->right;
        dir = 1;
    }

    //�������,�ظ�
        //1.������������
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

    //2.������һ���յ�
    if (p_now->left == NULL || p_now->right == NULL) {
        if (p_now->left == NULL) {                         //p_now�����ӽڵ��ǿյģ�����p_now���ҽڵ�����
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

    //3.���Ҷ�������,���������������������滻��������ڵ��滻��
    NodePtr p_max = p_now->left, p_max_fa = p_now;              //p_max�����������Ľڵ㣬p_max_fa��p_max�ĸ���
    while (p_max->right)
    {
        p_max_fa = p_max;
        p_max = p_max->right;
    }
    //p_max��p_now��λ,������ֻ��ֵ����
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

Status BST_Search(BinarySortTreePtr BST, ElemType e)                      //����һ����
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

NodePtr BST_search(BinarySortTreePtr BST, ElemType e, int* pp)                      //����һ����������������λ��,pp�����Ƿ�Ҫɾ��ͷ�ڵ�
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

Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr))    //ǰ������ĵݹ�д��
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

Status BST_preorderR(BinarySortTreePtr BST, void (*visit)(NodePtr))   //ǰ�������ջд��
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
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr))         //��������ĵݹ�
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

Status BST_inorderR(BinarySortTreePtr BST, void (*visit)(NodePtr))         //���������ջ
{
    int count = 0;
    if (BST->root == NULL) return FAILED;
    NodePtr o;
    stack <NodePtr> s;
    s.push(BST->root);
    while (!s.empty()) {
        if (count != s.size()) {                       //˵����ʱ��ջ��Ԫ��û�н���ڵ����
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

Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr))       //��������ĵݹ�
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

Status BST_postorderR(BinarySortTreePtr BST, void (*visit)(NodePtr))       //���������ջ
{
    int count = 0 ,Maxlen=BST->count+1;
    int* a = new int[Maxlen];
    memset(a, 0, Maxlen * sizeof(int));
    if (BST->root == NULL) return false;
    NodePtr o;
    stack <NodePtr> s;
    s.push(BST->root);
    while (!s.empty()) {                                //�����ȣ�����ÿ��ջ��Ԫ�ض�Ҫ�Ƚ�����left����
        if (count != s.size()) {                       //˵����ʱ��ջ��Ԫ��û�н���ڵ����
            ++count;
            o = s.top();
            while (o->left != NULL) {
                s.push(o->left);
                ++count;
                o = o->left;
            }
        }
        o = s.top();
        if (o->right != NULL && !a[count]) {           //�˵�û�з����ҽڵ�,��һ��ʱ���a��¼�Ƿ������ҽڵ�
            s.push(o->right);
            a[count] = 1;                               //�˵㱻�����ҽڵ����
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

Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr))       //�������
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
        cin.ignore(std::numeric_limits< streamsize >::max(), '\n');				//��ջ�����
        cout << "��Ĳ��������Ⱑ,�����������" << endl;
    }
    return OP;
}
