#include<iostream>
using namespace std; 

struct tree{
	    int id;

    tree *right = NULL;
    tree *left =NULL;
};

tree *root = NULL;


void push(int x){
    tree *current = new tree;
    current->id = x;
    if (root == NULL)
    {
        root = current;
    }
    else
    {
        tree *p = root; tree *k;
        while (p != NULL)
        {
            
            k=p;
            if (current->id > p->id)
            {
                p=p->right;
            }
            else if (current->id < p->id)
            {
                p=p->left;
            }
        }
        
        if (current->id > k->id)
        {
            k->right = current;
        }
        else
        {
            k->left = current;
        }
    }
}




void display(tree* pr){

if (pr!=NULL){
	cout<<pr->id<<" ";
	display(pr->left);
	display(pr->right);
	
}
	}


bool binarysearchtree(int x){
    tree *p = root;
    while (p !=NULL && p->id != x)
    {
        if (x > p->id)
        {
            p = p->right;
            
        }
        else
        {
            p=p->left;
           

        }
        
    }
    
if (p!=NULL){
	

    return true;
} else{
	return false;
}

}



void del(int x){
	tree* p=root; 
	tree* k;
	
	while (p->id!=x && p!=NULL)
	{
		k=p; 
		if (x>p->id){
			p=p->right; 
			
		}else{
			p=p->left;
			
		}
	}
	
	//CASE 1 
	//LEAF CASE
	
	
	if (p->left==NULL && p->right==NULL){
		if (k->left==p){

			k->left=NULL;
			delete p;
			
		}
		else{
			k->right=NULL;
			delete p;
			
		}
	}
	
	
	
	
	//CASE 2
	//ONE BRANCH 
	
	else if (p->left==NULL || p->right==NULL){
		//CASE 1
		 if  (p->left==NULL){
			if (k->right!=NULL && p->right!=NULL){
				k->right=p->right; 
				delete p; 
				
				
			}
			else if(k->left!=NULL && p->right!=NULL){
				k->left=p->right; 
				delete p;
				
			}
			
		}
		else if (p->right==NULL){
			if (k->left!=NULL && p->left!=NULL ){
				k->left=p->left;
				delete p;
				
			}else if(k->right!=NULL && p->left!=NULL){
				k->right=p->left; 
				delete p;
			}
		}
		
		else{
			
			tree* q=p->right;
			tree* d;
			
			while (q->left!=NULL){
				d=q;
				q=q->left; 	
			}
			//
			p->id=q->id; 
			
			//CASE 1
			if(q->right!=NULL){
				d->left=q->right; 
				delete q; 
				
			}else{
				
				//root node case;
				
				if (p->right!=NULL){
					d->left=NULL;
					delete q;
					
				}else{
					
					p->right=NULL;
					delete q;
					
				}
			}
		}
	}
	
}

int main(){
    
    int opt;
    do
    {
        cout<<"\n Enter 1 to Push"<<endl;
        cout<<"\n Enter 2 to Display"<<endl;
        
        cout<<"\n Enter 3 to Search"<<endl;
         cout<<"\n Enter 4 to Delete"<<endl;
        
        cout<<"\n Enter 0 to Exit"<<endl;
        cout<<"\n Enter Option : ";
        cin>>opt;

        switch (opt)
        {
        case 1:
            int x;
            cout<<"Enter Number : ";
            cin>>x;
            push(x);
            break;
        case 2:
            cout<<"Display"<<endl;
            display(root);
            break;
        case 3:
        {
            cout<<"BINARY SEARCH"<<endl;
            int y;
            cout<<"Enter a number to find: ";
            cin>>y;
            bool k;
			k=binarysearchtree(y);
//            cout<<k<<endl;
            if (k==true){
                cout<<"\nVALUE FOUND!"<<endl;
            }
            else{
                cout<<"\nVALUE NOT FOUND"<<endl;
            }

            break;
            
            case 4:
            	 int v;
            cout<<"Enter a number to delete: ";
            cin>>v;
            del(v);
            break;
        }
        default:
            cout<<"Program Terminated"<<endl;
            break;
        }
    } while (opt != 0);
    
    

    return 0;
}

