#include<iostream>
using namespace std;


typedef struct nodeType {
    int element;
    struct nodeType *left, *right;
} node_type;

typedef struct nodeType *treetype;

void MakeNullTree(treetype *T){ //tạo 1 cây rỗng
    *T=NULL;
}

int EmptyTree(treetype T){ 
    return T==NULL;
}

treetype LeftChild(treetype n) //truy cập cây con trái
{
    if (n!=NULL) return n->left; // nếu n khác rỗng thì n trỏ đến cây con trái
    else return NULL;
}

treetype RightChild(treetype n) //truy cập cây con phải
{
    if (n!=NULL) return n->right; //nếu n khác rỗng thì n trỏ đến cây con phải 
    else return NULL;
}

node_type *create_node(int NewData) // tạo nút mới có giá trị là newdata
{
    node_type *N=(node_type*)malloc(sizeof(node_type)); // cấp phát bộ nhớ động cho cây nhị phân
    if (N != NULL)
    {
        N->left = NULL;
        N->right = NULL;
        N->element = NewData;
    }
    return N;
}

// Ham nhap du lieu key tu ban phim 
node_type *CreateTree(node_type *p, int x)   
{   
        cout<<"Node: "; cin>>x; 
        if (x==0)return NULL;
        p=  create_node(x);
        cout<<"Nhap con trai cua node %d: "<<x;
        p->left=CreateTree(p->left,x);
        cout<<"Nhap con phai cua node " <<x;
        p->right=CreateTree(p->right,x);
        return p;       
}
//Điều kiện nhập của mình ở đây là nếu nhập bằng 0 thì sẽ kết thúc nhập. Thứ tự nhập như sau:

// Nhập node gốc trước, nếu node này bằng 0 thì kết thúc nhập ( return NULL );
// Nếu khác 0, gọi đệ quy nhập con bên trái
// Gọi đệ quy nhập con phải.
// Trả về node vừa nhập: Return P.

int IsLeaf(treetype n){ // kiểm tra 1 nút có phải lá
    if(n!=NULL) return(LeftChild(n)==NULL)&&(RightChild(n)==NULL); 
    else return -1;
}

//Thêm một nút vào vị trí trái nhất trên cây
treetype Add_Left(treetype *Tree, int NewData){     
    node_type *NewNode = create_node(NewData);      // tạo 1 node mới
    if (NewNode == NULL) return NewNode;          // nếu node mới ko có giá trị -> vứt
    if (*Tree == NULL) *Tree = NewNode;             //nếu cây rỗng thêm luoonvaof cây
    else{
        node_type *Lnode = *Tree;                   //tạo một node trái trỏ vào cây
        while (Lnode->left != NULL){
            Lnode = Lnode->left;
            Lnode->left = NewNode;
        }
    }
    return NewNode;

}

treetype Add_Right(treetype *Tree, int NewData){     //Thêm một nút vào vị trí phải nhất trên cây
    node_type *NewNode = create_node(NewData);      // tạo 1 node mới
    if (NewNode == NULL) return (NewNode);          // nếu node mới ko có giá trị -> vứt
    if (*Tree == NULL) *Tree = NewNode;             //nếu cây rỗng thêm luoonvaof cây
    else{
        node_type *Rnode = *Tree;                   //duyệt cây
        while (Rnode->left != NULL){
            Rnode = Rnode->right;
            Rnode->right = NewNode;
        }
    }
    return (NewNode);
}

int main(){
    int m,n,demL,demR;
    cout<<"Nhap n nut trai va m nut phai:";
    cin>>n>>m;
    nodeType *p;
    int x;
    CreateTree(p, x);

    return 0;

}