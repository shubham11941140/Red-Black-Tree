/* ASSIGNMENT for data structures regarding Red Black Tree is as follows in the code.

Request the user who is compiling to not tamper with the code and compile it as it is it 
works perfectly fine. Use the readMe file attached to understand the inputs. */

#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

#define MAX(a,b) (((a)>(b))?(a):(b))

struct node
{
	int key;
	int color;
	struct node *parent;
	struct node *left;
	struct node *right;
};

struct node *ROOT;
struct node *NILL;
struct node  T_Nil_Node;
struct node* T_Nil = &T_Nil_Node;

void left_rotate(struct node *x)
{
	struct node *y;
	y = x->right;
	x->right = y->left;
	if(y->left != NILL)
	{
		y->left->parent = x;
	}
	y->parent = x->parent;
	if(y->parent == NILL)
	{
		ROOT = y;
	}
	else if(x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void right_rotate(struct node *x)
{
	struct node *y;
	y = x->left;
	x->left = y->right;
	if(y->right != NILL)
	{
		y->right->parent = x;
	}
	y->parent = x->parent;
	if(y->parent == NILL)
	{
		ROOT = y;
	}
	else if(x == x->parent->left)
	{
		x->parent->left = y;	
	}
	else
	{
		x->parent->right = y;
	}
	y->right = x;
	x->parent = y;
}

int height(struct node *Root)
{
    if (Root != NULL) 
    {
        if (Root == T_Nil)
        {
            return  1;
        }
        else
        {
            return 1 + MAX(height(Root->left),height(Root->right));
        }
    }
}

unsigned int getLeafCount(struct node* root)  
{  
    if(root == NULL) 
    {
        return 0;  
    }
    if((root->left == NULL 
			&& root->right == NULL) 
				&& (root->color == 1))
    {
        return 1;          
    }
    else
    {
        return getLeafCount(root->left)+ getLeafCount(root->right);  
    }
}  

void tree_print(struct node *x)
{
	if(x != NILL)
	{
		tree_print(x->left);
		printf("%d\t", x->key);
		tree_print(x->right);
	}
}

void printinrange(struct node *root, int k1, int k2) 
{ 
    if (root == NILL ) 
    {
        return; 
    }
    if ( k1 < root->key ) 
    {
        printinrange(root->left, k1, k2); 
    }
    if ( k1 <= root->key 
			&& k2 >= root->key ) 
    {
        printf("%d ", root->key); 
    }
    if ( k2 > root->key) 
    {
        printinrange(root->right, k1, k2); 
    }
} 

struct node *tree_search(int key)
{
	struct node *x;
	x = ROOT;
	while(x != NILL 
			&& x->key != key)
	{
		if(key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	return x;
}

struct node *tree_minimum(struct node *x)
{
	while(x->left != NILL)
	{
		x = x->left;
	}
	return x;
}

void red_black_insert_fixup(struct node *z)
{
	while(z->parent->color == RED)
	{
		if(z->parent == z->parent->parent->left)
        {
			if(z->parent->parent->right->color == RED)
            {
				z->parent->color = BLACK;
				z->parent->parent->right->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
            {
        		if(z == z->parent->right)
                {
					z = z->parent;
					left_rotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				right_rotate(z->parent->parent);
			}
		}
		else
		{
			
			if(z->parent->parent->left->color == RED)
			{
				z->parent->color = BLACK;
				z->parent->parent->left->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if(z == z->parent->left)
				{
					z = z->parent;
					right_rotate(z);
			    }
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				left_rotate(z->parent->parent);
			}
		}
	}
	ROOT->color = BLACK;
}

void red_black_insert(int key)
{
	struct node *z, *x, *y;
	z = malloc(sizeof(struct node));
	z->key = key;
	z->color = RED;
	z->left = NILL;
	z->right = NILL;
	x = ROOT;
	y = NILL;
	while(x != NILL)
	{
		y = x;
		if(z->key <= x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	if(y == NILL)
	{
		ROOT = z;
	}
	else if(z->key <= y->key)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}
	z->parent = y;
	red_black_insert_fixup(z);
}

void red_black_delete_fixup(struct node *x)
{
	struct node *w;	
	while(x != ROOT 
			&& x->color == BLACK)
	{
		if(x == x->parent->left)
		{
			w = x->parent->right;
			if(w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				left_rotate(x->parent);
				w = x->parent->right;
			}
			if(w->left->color == BLACK 
					&& w->right->color == BLACK)
			{
				w->color = RED;
				x->parent->color = BLACK;
				x = x->parent;
			}
			else
			{
				if(w->right->color == BLACK)
				{
					w->color = RED;
					w->left->color = BLACK;
					right_rotate(w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				x->right->color = BLACK;
				left_rotate(x->parent);
				x = ROOT;		
			}
		}
		else
		{
			w = x->parent->left;
			if(w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = BLACK;
				right_rotate(x->parent);
				w = x->parent->left;
			}
			if(w->left->color == BLACK 
					&& w->right->color == BLACK)
			{
				w->color = RED;
				x->parent->color = BLACK;
				x = x->parent;
			}
			else
			{
				if(w->left->color == BLACK)
				{
					w->color = RED;
					w->right->color = BLACK;
					left_rotate(w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				right_rotate(x->parent);
				x = ROOT;
			}
		}
	}
	x->color = BLACK;
}

void red_black_transplant(struct node *u, struct node *v)
{
	if(u->parent == NILL)
	{
		ROOT = v;
	}
	else if(u == u->parent->left)
	{
		u->parent->left = v;
	}
	else
	{
		u->parent->right = v;
	}
	v->parent = u->parent;
}

void red_black_delete(struct node *z)
{
	struct node *y, *x;
	int yOriginalColor;
	y = z;
	yOriginalColor = y->color;
	if(z->left == NILL)
	{
		x = z->right;
		red_black_transplant(z, z->right);
	}
	else if(z->right == NILL)
	{
		x = z->left;
		red_black_transplant(z, z->left);
	}
	else
	{
		y = tree_minimum(z->right);
		yOriginalColor = y->color;
		x = y->right;
		if(y->parent == z)
		{
			x->parent = y;
		}
		else
		{
			red_black_transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		red_black_transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	if(yOriginalColor == BLACK)
	{
		red_black_delete_fixup(x);
	}
}

int main(){
	NILL = malloc(sizeof(struct node));
	NILL->color = BLACK;
	ROOT = NILL;
	int t,p,a,b;
	printf("###******************\tRED BLACK TREE ASSIGNMENT COMPILATION\t************###\n\n");
	printf("Enter any integer from 1 to 6: ");
	scanf("%d",&t);
	while(1 == 1)
	{
	    if(t==1)
	    {
	        printf("THE CASE OF INSERTION INTO THE RED BLACK TREE\n");
	        printf("Enter the number to be inserted: ");
	        scanf("%d",&p);
	        red_black_insert(p);
	    }
	    if(t==2)
	    {
	        printf("THE CASE OF DELETION INTO THE RED BLACK TREE\n");
	        printf("Enter the number to be deleted: ");
	        scanf("%d",&p);
	        red_black_delete(tree_search(p));
	    }
	    if(t==3)
	    {
	        printf("THE CASE OF COUNTING THE NUMBER OF LEAVES OF THE RED BLACK TREE\n");
	        printf("%d\n",getLeafCount(ROOT));
	    }
	    if(t==4)
	    {
	        printf("THE CASE OF RETURNING THE HEIGHT OF THE RED BLACK TREE\n");
	        printf("%d\n",height(ROOT));
    	}
	    if(t==5)
	    {
	        printf("THE CASE OF RETURNING ALL KEYS IN THE GIVEN RANGE\n");
	        printf("Enter the lower limit and upper limit of the range: ");
	        scanf("%d%d",&a,&b);
    	    printinrange(ROOT,a,b);
    	    printf("\n");
	    }
	    if(t==6)
	    {
	        printf("THE CASE OF PRINTING THE RED BLACK TREE IN IN-ORDER TRAVERSAL\n");
	        tree_print(ROOT);
	        printf("\n");
	    }
	    printf("Enter the next integer from 1 to 6(Press 0 to exit): ");
	    scanf("%d",&t);
	    if(t==0)
	    {
	        printf("\n###********\tCOMPILATION TERMINATED\t\t*********###\n");
	        break;
	    }
    }
	return 0; 
}

