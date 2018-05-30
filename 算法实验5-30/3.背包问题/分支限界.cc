#include<iostream>
#include<cstdio>
#include<iomanip>
#include<stdlib.h>
using namespace std;

//物品结构体
struct obj {
int v;//物品价值
int w;//物品重量
double avg;//物品单位价值
int id;//物品编号
};

//节点结构体
struct node
{
node *parent,//父亲结点指针
   *next;//后继结点指针
int   level,//节点所处的层
    isin,//记录物品是否装入背包，0代表不装,1代表装入
    cw,//当前背包已经装入的物品重量
    cv;//当前背包已经装入的物品价值
double ub;//结点的上界值

};

//划分
int Partition(obj r[],int first,int end){
int i=first,j=end;
while(i<j)
{
while(i<j&&r[i].avg>r[j].avg)
j--;
if(i<j)
{
  obj temp=r[i];
r[i]=r[j];
r[j]=temp;
i++;
}
while(i<j &&r[i].avg>r[j].avg)
i++;
if(i<j)
{
obj temp=r[i];
r[i]=r[j];
r[j]=temp;
j--;
}
}
return i;
}

//快速排序
void QuickSort(obj r[],int first,int end){
int pivot;
if(first<end){
pivot=Partition(r,first,end);
QuickSort(r,first,pivot-1);
QuickSort(r,pivot+1,end);
}
}

class fzjx{
private:
node *front,//队首指针
   *first,//根节点指针
   *popv;//解结点指针
double opv;//背包可产生的最大价值
obj *pro;//物品
int  n,//物品个数
    c;//背包容量
public:
fzjx(obj *pro1,int w1,int n1 );
~fzjx();
int *flag;
double Upb(int i,int cw,int cv);//计算上界值
node *nnoder(node * parent1,int isin1,double ub1);
void addnode(node *node1);//将结点添加到队列中
node *nextnode(); //取下一个结点
void  fenzjx();
void  output();

};
fzjx::fzjx(obj *pro1,int c1,int n1 )
{
int i;
n=n1;c=c1;
pro=new obj [n];
flag=new int[n];
for(i=0;i<n;i++)
{
  pro[i].w=pro1[i].w;
  pro[i].v=pro1[i].v;
  pro[i].id=pro1[i].id;
  pro[i].avg=pro1[i].avg;
  flag[i]=i;
}
front=new node[1];
front->next=NULL;
opv=0;
popv=new node[1];
popv=NULL;
QuickSort(pro,0,n-1);
}
fzjx::~fzjx()
{
  delete[]first;
  delete[]front;
  delete[]popv;
  delete[]pro;

}
double fzjx::Upb(int i,int cw,int cv)
{
 int cleft=c-cw;
 double v=(double)cv;
 if (i<n)
 v+=1.0*pro[i].avg*cleft;
 return v;
}
node * fzjx::nnoder(node * parent1,int isin1,double ub1)
{//生成一个新结点
node * node2=new(node);
node2->parent=parent1;
node2->next=NULL;
node2->level=(parent1->level)+1;
node2->isin=isin1;
node2->ub=ub1;
if(isin1==1)
{
node2->cw=parent1->cw+pro[parent1->level].w;
node2->cv=parent1->cv+pro[parent1->level].v ;
}
else
{
node2->cw=parent1->cw;
node2->cv=parent1->cv;
}
return(node2);
}
void fzjx::addnode(node *node1)
{//将结点加入优先队列
node *p=front->next,*next1=front;
double ub=node1->ub;
while(p!=NULL)
{
if(p->ub<ub)
  {node1->next=p;next1->next=node1;break;}
next1=p;
p=p->next;
}
if(p==NULL){next1->next=node1;
}
}
node * fzjx::nextnode()
{//取上限最大结点
node *p=front->next;
front->next=p->next;
return(p);
}
void fzjx::fenzjx()
{
  int i;
double ub2;
node *node3;
first=new node[1]; //根结点
first->parent=NULL;
first->next=NULL;
first->level=0;
first->cw=0;
first->cv=0;
first->isin=0;
ub2=Upb(0,0,0);
first->ub=ub2;
front->next=first;
while(front->next!=NULL)
{
  node3=nextnode();
  i=node3->level;
  if(i==n-1)
    {
      if(node3->cw+pro[i].w<=c&&(node3->cv+pro[i].v)>opv)
        {
          opv=node3->cv+pro[i].v;
          popv=nnoder(node3,1,opv);
        }
      if((node3->cv)>opv)
        {
          opv=node3->cv;
          popv=nnoder(node3,0,opv);
        }
    }
  if(i<n-1)
    {
      if(node3->cw+pro[i].w<=c&&Upb(i+1,
        node3->cw+pro[i].w,node3->cv+pro[i].v)>opv)
        {
          ub2=Upb(i,node3->cw+pro[i].w,node3->cv+pro[i].v);
          addnode(nnoder(node3,1,ub2));
        }
      ub2=Upb(i,node3->cw,node3->cv);
      if(ub2>opv)
        addnode(nnoder(node3,0,ub2));
    }
  }


}

void fzjx::output()
{
  int i;
for(i=n-1;i>=0;i--)
{
  flag[pro[i].id]=popv->isin;
  popv=popv->parent;
}
cout<<"装入背包的物品编号为: ";
for(i=0;i<n;i++)
  {
      if(flag[i]==1)
          cout<<i+1<<" ";

  }
  cout<<endl;
cout<<"背包可以产生的最大价值是: "<<opv<<endl;
}
int main ()
{
  int c,n;
int i=0;
obj *pro1;
cout<<"请输入背包的容量: ";
cin>>c;
cout<<"请输入物品的个数: ";
cin>>n;
pro1 = new obj[n];
cout<<"请分别输入物品的重量和价值:";
for(i=0;i<n;i++)
  {
       cin>>pro1[i].w>>pro1[i].v;
       pro1[i].avg=1.0*pro1[i].v/pro1[i].v;
       pro1[i].id=i;
  }
  fzjx fzjx(pro1,c,n);
  fzjx.fenzjx();
  fzjx.output();
  return 0;
}
