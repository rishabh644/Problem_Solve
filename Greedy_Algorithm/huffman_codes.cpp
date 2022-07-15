#include<bits/stdc++.h>

using namespace std;

struct node{
    struct node *lnode=NULL;
    struct node *rnode=NULL;
    int fre=0;
};
struct myComp{
  constexpr bool operator()(struct node *a,struct node *b)const noexcept
  {
    
          return a->fre<=b->fre;
          
      
  }

};

void preorder(struct node *root,vector<string>&av,string d)
{    
     string k;
    if(root->lnode->lnode==NULL || root->lnode->rnode==NULL)
    {   cout<<"Inside 1stif"<<endl;
        cout<<d+"0"<<endl;
    }
    else
    {   cout<<"Inside 1stelse"<<endl;
        k=d+"0";
        preorder(root->lnode,av,k);
    }    
    if(root->rnode->lnode==NULL || root->rnode->rnode==NULL)
    {   cout<<"Inside 2nd if"<<endl;
        cout<<d+"1"<<endl;
    }
    else
    {   cout<<"Inside 2ndelse"<<endl;
        k=d+"1";
        preorder(root->rnode,av,k);
    }
    
    
}
class Solution
{
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		 // Code here
		priority_queue<struct node *,vector<struct node *>,myComp>q;
	    struct node *ans;
	    vector<string>av;
	    string d="";
		int i=0;
		while(i<N)
		{
		 struct node *nwnd=new node();
		 nwnd->fre=(-1)*f[i];
		 i++;
		 q.push(nwnd);
		}
	while(q.size()!=1)
		{
		    struct node *z=new node();
		    z->lnode= q.top();
            cout<<"q top "<<q.top()->fre<<endl;
		    z->fre+=(q.top())->fre;
		    q.pop();
		    z->rnode=q.top();
		    z->fre+=(q.top())->fre;
            cout<<"q top "<<q.top()->fre<<endl;
		    q.pop();
            cout<<"z "<<z->fre<<endl;
		    q.push(z);
		   ans=z;
		}
		
      preorder(ans,av,d);
      return av;
		     
		}
};

int main()
{
    Solution obj;
    string s="abcdef";
    vector<int>v={5,9,12,13,16,45};
    vector<string>ans=obj.huffmanCodes(s,v,6);
    return 0;
}