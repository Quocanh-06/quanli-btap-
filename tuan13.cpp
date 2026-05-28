#include <iostream>
using namespace std;

// Khai bao cau truc 1 nut tren cay nhi phan
struct Node {
    int data; // Luu nam sinh
    Node* trai;
    Node* phai;
};

// B1: Dung cay (Khoi tao nut moi)
Node* initial_BST(int giatri) {
    Node* p = new Node();
    p->data = giatri;
    p->trai = NULL;
    p->phai = NULL;
    return p;
}

// B2: Them nut vao BST
// Quy luat cua co tren bang: Trai <= , Phai >
Node* add_node_BST(Node* root, int giatri) {
    // Neu cay rong thi tao nut moi lam goc
    if (root == NULL) {
        return initial_BST(giatri);
    }
    
    // Thoa man dieu kien Trai <=
    if (giatri <= root->data) {
        root->trai = add_node_BST(root->trai, giatri);
    } 
    // Thoa man dieu kien Phai >
    else {
        root->phai = add_node_BST(root->phai, giatri);
    }
    return root;
}

// B3: Tim kiem tren BST
Node* Search_BST(Node* root, int giatri_tim) {
    // Neu cay rong hoac da tim thay gia tri thi tra ve nut do
    if (root == NULL || root->data == giatri_tim) {
        return root;
    }
    
    // Neu gia tri can tim nho hon nut hien tai thi re sang nhanh trai
    if (giatri_tim < root->data) {
        return Search_BST(root->trai, giatri_tim);
    }
    
    // Nguoc lai, lon hon thi re sang nhanh phai
    return Search_BST(root->phai, giatri_tim);
}

// Ham in cay de kiem tra (In-order: Trai -> Goc -> Phai)
// In ra nhu nay thi du lieu se duoc sap xep tang dan
void inCay(Node* root) {
    if (root != NULL) {
        inCay(root->trai);
        cout << root->data << " ";
        inCay(root->phai);
    }
}

int main() {
    Node* root = NULL;
    
    // Tap du lieu tap nam sinh lay y het tren bang cua co
    int nam_sinh[] = {2001, 2002, 2006, 2007, 2003, 2004, 2005, 2001, 1999, 2004};
    int so_luong = sizeof(nam_sinh) / sizeof(nam_sinh[0]);

    // Lan luot them tung nam sinh vao cay
    for (int i = 0; i < so_luong; i++) {
        root = add_node_BST(root, nam_sinh[i]);
    }

    cout << "Du lieu nam sinh sau khi dua vao BST va sap xep: ";
    inCay(root);
    cout << endl;

    // Tim sinh vien co nam sinh 2004
    int can_tim = 2004;
    Node* kq = Search_BST(root, can_tim);

    if (kq != NULL) {
        cout << "=> KET QUA: Da tim thay sinh vien co nam sinh " << kq->data << " trong cay!" << endl;
    } else {
        cout << "=> KET QUA: Khong tim thay sinh vien nao sinh nam " << can_tim << endl;
    }

    return 0;
}
