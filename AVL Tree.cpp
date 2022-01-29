#include <iostream>
using namespace std;

struct tree{
	int id; 
	tree* left=NULL;
	tree* right=NULL;
};
tree* root=NULL;

int Max(int left, int right){
	if (left>right){
		return left;
	}
	else{
		return right;
		
	}
}
int height(tree* t){
	if (t==NULL){
		return 0;
	}
	int left=height(t->left);
	int right=height(t->right);
	
	return Max(left,right)+1;
	
}

tree* GetParent(int value){
    tree *temp = root;
    bool Success = false;
    tree *par= NULL;
    if(value==root->id)
        {
            Success=true;
            return temp;
            
        }
    while(temp!=NULL){ 
        if(temp->id==value)
        {
            Success = true;
            break;
        }
        else if(value<temp->id)
        {
            par=temp;
            temp=temp->left;
        }
        else
        {
            par=temp;
            temp=temp->right;
        }
    }
    if(Success){
        return par;
    }
    else{
        cout<<"Value Doesnt Exist "<<endl;
        par=NULL;
        return par;
    }
}


tree* RotateLeft(tree *X){
    tree *Y = X->right;
    if(X==root){
        root=Y;
    }
    X->right=Y->left;
    Y->left=X;
    return Y;
}

tree* RotateRight(tree *X){
    tree *Y = X->left;
    if(X==root){
        root=Y;
    }
    X->left=Y->right;
    Y->right=X;
    return Y;
}
void rotateRightLeft(tree *X){
    tree *Y = X->right;
    tree *parent=GetParent(X->id);
    X->right=RotateRight(Y);
    parent->left=RotateLeft(X);
      
}
void rotateLeftRight(tree *X){
    tree *Y = X->left;
    tree *parent=GetParent(X->id);
    X->left=RotateLeft(Y);
    parent->right=RotateRight(X);
      
}
int BalanceFactor(tree* t){
	if (t==NULL){
		return 0;
		
	}
	int left=height(t->left);
	int right=height(t->right);
	return (left-right);
	
}


void Balancetree(tree *node){
   
    int balfactor=BalanceFactor(node);

    //Right/leftRight rotation IN CASE OF POSITIVE BALANCE FACTOR
    if(balfactor>1){   
        tree *Y=node->left;
     
        if(Y->left==NULL && Y->right!=NULL){
            rotateLeftRight(node);
            return;
        }

        else if(BalanceFactor(Y->left)<BalanceFactor(Y->right)){
            rotateLeftRight(node);
        }
        else{
            RotateRight(node);  
        }
       
            
    }

    // Left/rightLeft rotation IN CASE OF NEGATIVE BALANCE FACTOR
    else if(balfactor<-1){
        tree *Y=node->right;
        if(BalanceFactor(Y->left)<=BalanceFactor(Y->right))
            RotateLeft(node);
        else
            rotateRightLeft(node);
    }
}


bool IsBalance(int value){
    if(value==0)
    return true;

    tree *temp = GetParent(value);

    if(value < temp->id)
    temp=temp->left;
    else if(value>temp->id)
    temp=temp->right;

    int left =height(temp->left);
    int right = height(temp->right);

    if(left-right>1 || left-right<-1)
    return false;

    return true;
}
void insertNode(int value){
    tree *temp = new tree;
    temp->id=value;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
        cout<<"Node Inserted at root"<<endl;
        return;
    }
    else
    {
        tree *tra = root;
        tree *par = NULL;
        while(tra!=NULL)
        {
            par=tra;
            if(value<=tra->id)
            tra=tra->left;
            else
            tra=tra->right;
        }
        if(value<=par->id){
            par->left=temp;
            cout<<"Node at Left of : "<<par->id<<endl;
        }
        else{

            par->right=temp;
            cout<<"Node at Right of : "<<par->id<<endl;
        }

            //we need to check balance on every node from root to leaf
            temp=root;
            tree* ptr=NULL;
            while(temp!=NULL){
                if(!IsBalance(temp->id)){
                    ptr=temp;
                    
                }
                if(value<=temp->id)
                    temp=temp->left;
                else
                    temp=temp->right; 
            }
            
            if(ptr!=NULL){
                Balancetree(ptr);
            }      
    }
}




void Preorder(tree *temp){
    if(temp!=NULL)
    {
        cout<<temp->id<<" ";
        Preorder(temp->left);
        Preorder(temp->right); 
    }
}

void Inorder(tree *temp){
    if(temp!=NULL)
    {
        Inorder(temp->left);
        cout<<temp->id<<" ";
        Inorder(temp->right); 
    }
}

void Postorder(tree *temp){
    if(temp!=NULL)
    {
        Postorder(temp->left);
        Postorder(temp->right); 
        cout<<temp->id;
    }
}



int main(){
	
	int opt; 
	do{
		cout<<"Press 1 to insert in the AVL Tree"<<endl;
		cout<<"Press 2 to Display The post-Order"<<endl;
		cout<<"Press 3 to Display The In-Order"<<endl;
		cout<<"Press 4 to Display the Pre-Order"<<endl;
		
		cin>>opt;
		switch(opt){
			
			case 1:
				cout<<"Enter the value to insert: ";
				int val; 
				cin>>val; 
				insertNode(val);
				break;
			cas 2:
				cout<<"POST-ORDER DISPLAY "<<endl;
				
				
		}
	}
	insertNode(30);
	insertNode(20);
	insertNode(10);
	
	Preorder(root);
	
	cout<<"ROOT: "<<root->id<<endl;
	cout<<"LEFT: "<<root->left->id<<endl;
	cout<<"RIGHT: "<<root->right->id<<endl;
	
	
	
	
	
	
	return 0;
}
