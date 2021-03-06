#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
    int info;
    struct node *left;
    struct node *right;
}*root;

class tree
{
    public:
        void find(int, node **, node **);
        void insert(node *, node *);
        void del(int);
        void case_a(node *,node *);
        void case_b(node *,node *);
        void case_c(node *,node *);
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
        void display(node *, int);
        tree()
        {
            root = NULL;
        }
};

int main()
{
    int data, no;
    tree tree;
    node *temp;
    while (1)
    {
		cout<<"===============================================\n";
		cout<<"              P R O G R A M  T R E E\n";
		cout<<"===============================================\n";
        cout<<"1.Tambah"<<endl;
        cout<<"2.Hapus"<<endl;
        cout<<"3.Inorder"<<endl;
        cout<<"4.Preorder"<<endl;
        cout<<"5.Postorder"<<endl;
        cout<<"6.Tampilan Tree"<<endl;
        cout<<"7.Keluar"<<endl;
        cout<<"-----------------------------------------------\n";
        cout<<"Masukkan Pilihan : ";
        cin>>data;
        switch(data)
        {
        case 1:
            temp = new node;
            cout<<"Masukkan nomer : ";
	    cin>>temp->info;
            tree.insert(root, temp);
        case 2:
            if (root == NULL)
            {
                continue;
            }
            cout<<"Enter the nober to be deleted : ";
            cin>>no;
            tree.del(no);
            break;
        case 3:
            cout<<"Inorder :"<<endl;
            tree.inorder(root);
            cout<<endl;
            break;
	case 4:
            cout<<"Preorder :"<<endl;
            tree.preorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder :"<<endl;
            tree.postorder(root);
            cout<<endl;
            break;
        case 6:
        	
            cout<<"Tampilan:"<<endl;
            system("cls");
            tree.display(root,1);
            cout<<endl;
            break;
        case 7:
            exit(1);
        default:
            cout<<"kesalahan dalam data"<<endl;
        }
    }
}

void tree::find(int item, node **par, node **loc)
{
    node *pointer, *pointersave;
    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->info)
    {
        *loc = root;
        *par = NULL;
        return;
    }
    if (item < root->info)
        pointer = root->left;
    else
        pointer = root->right;
    pointersave = root;
    while (pointer != NULL)
    {
        if (item == pointer->info)
        {
            *loc = pointer;
            *par = pointersave;
            return;
        }
        pointersave = pointer;
        if (item < pointer->info)
            pointer = pointer->left;
	else
	    pointer = pointer->right;
    }
    *loc = NULL;
    *par = pointersave;
}

void tree::insert(node *tree, node *newnode)
{
    if (root == NULL)
    {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout<<"Root berhasil dibuat"<<endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout<<"data tree siap"<<endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);
	}
	else
	{
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<"Meletakkan data di kiri program"<<endl;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<""<<endl;
            return;
        }
    }
}

void tree::del(int item)
{
    node *parent, *location;
    if (root == NULL)
    {
        cout<<"Tree kosong"<<endl;
        return;
    }
    find(item, &parent, &location);
    if (location == NULL)
    {
        cout<<"Tidak terdapat data di tree"<<endl;
        return;
    }
    if (location->left == NULL && location->right == NULL)
        case_a(parent, location);
    if (location->left != NULL && location->right == NULL)
        case_b(parent, location);
    if (location->left == NULL && location->right != NULL)
        case_b(parent, location);
    if (location->left != NULL && location->right != NULL)
        case_c(parent, location);
    free(location);
}

void tree::case_a(node *par, node *loc )
{
    if (par == NULL)
    {
        root = NULL;
    }
    else
    {
        if (loc == par->left)
            par->left = NULL;
        else
            par->right = NULL;
    }
}

void tree::case_b(node *par, node *loc)
{
    node *child;
    if (loc->left != NULL)
        child = loc->left;
    else
        child = loc->right;
    if (par == NULL)
    {
        root = child;
    }
    else
    {
        if (loc == par->left)
            par->left = child;
        else
            par->right = child;
    }
}

void tree::case_c(node *par, node *loc)
{
    node *pointer, *pointersave, *suc, *parsuc;
    pointersave = loc;
    pointer = loc->right;
    while (pointer->left != NULL)
    {
        pointersave = pointer;
        pointer = pointer->left;
    }
    suc = pointer;
    parsuc = pointersave;
    if (suc->left == NULL && suc->right == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL)
    {
        root = suc;
    }
    else
    {
        if (loc == par->left)
            par->left = suc;
        else
            par->right = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}

void tree::preorder(node *pointer)
{
    if (root == NULL)
    {
        cout<<"Data tree kosong"<<endl;
        return;
    }
    if (pointer != NULL)
    {
        cout<<pointer->info<<"  ";
        preorder(pointer->left);
        preorder(pointer->right);
    }
}

void tree::inorder(node *pointer)
{
    if (root == NULL)
    {
        cout<<"Data tree kosong"<<endl;
        return;
    }
    if (pointer != NULL)
    {
        inorder(pointer->left);
        cout<<pointer->info<<"  ";
        inorder(pointer->right);
    }
}

void tree::postorder(node *pointer)
{
    if (root == NULL)
    {
        cout<<"Data tree kosong"<<endl;
        return;
    }
    if (pointer != NULL)
    {
        postorder(pointer->left);
        postorder(pointer->right);
        cout<<pointer->info<<"  ";
    }
}

void tree::display(node *pointer, int level)
{
    int i;
    if (pointer != NULL)
    {
        display(pointer->right, level+1);
        cout<<endl;
        if (pointer == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
	}
        cout<<pointer->info;
        display(pointer->left, level+1);
    }
}
