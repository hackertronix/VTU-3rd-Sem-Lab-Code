#include"iostream"
using namespace std;
struct node
{
    int data;
    node *lchild,*rchild;
};

typedef struct node* NODEPTR;

class BIN_TREE
{
    NODEPTR root;
public:
    BIN_TREE():root(NULL){}
    void create();
    NODEPTR tree(NODEPTR, int);
    void traverse();
    void inorder(NODEPTR);
    void postorder(NODEPTR);
    void preorder(NODEPTR);
};

void BIN_TREE::traverse()
{
    if(root==NULL)
        cout<<"Tree is empty\n";
    else
    {
        cout<<"Preorder traversal is \t";
        preorder(root);
        cout<<"\nPostorder traversal is \t";
        postorder(root);
        cout<<"\nInorder traversal is \t";
        inorder(root);
    }
}

void BIN_TREE::inorder(NODEPTR root)
{

    if(root!=NULL)
    {
        inorder(root->lchild);
        cout<<root->data<<"\t";;
        inorder(root->rchild);
    }
}
void BIN_TREE::preorder(NODEPTR root)
{

    if(root!=NULL)
    {

        cout<<root->data<<"\t";;
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void BIN_TREE::postorder(NODEPTR root)
{

    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        cout<<root->data<<"\t";

    }
}
void BIN_TREE::create()
{
    int n;
    cout<<"\nEnter -1 for NULL\nEnter the root element\n";
    cin>>n;
    root=tree(root,n);
}


NODEPTR BIN_TREE::tree(NODEPTR t, int n)
{
    int ele;
    if(n==-1)
        return NULL;
    t=new node;
    t->data=n;
    t->lchild=t->rchild=NULL;
    cout<<"\nEnter left child of "<<t->data<<"\t";
    cin>>ele;
    t->lchild=tree(t->lchild,ele);
    cout<<"\n Enter the right child of "<<t->data<<"\t";
    cin>>ele;
    t->rchild=tree(t->rchild,ele);
    return t;
}

int main()
{
    BIN_TREE btree;
    btree.create();
    btree.traverse();
    return 0;
}
