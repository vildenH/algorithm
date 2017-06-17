#include<iostream>  
#include<string>  
#include<queue>  
using namespace std;  
#define ERROR 1  
#define MAX_VERTEX_NUM 100  
typedef struct ArcNode{   //表（边）节点，存储边信息的结构体  
    int adjvex;       //存储与该边相连的另一个节点的索引  
    struct ArcNode *nextarc; //存储与表头节点相连的其他表节点的指针  
    string info;             //存储边的信息，例如权值  
}ArcNode;  

typedef struct VNode{<span style="white-space:pre">   //存储头节点信息的结构体  
    char date;              //存储头节点包含的数据，例如头节点的名字  
    ArcNode * firstarc;      //指向链表的指针  
}VNode,AdjList[MAX_VERTEX_NUM];  

typedef struct{  
    AdjList vertices;<span style="white-space:pre">  //存储头节点的数组<span style="white-space:pre"> </span>   
    int vexnum,arcnum;        //当前图的vexnum顶点数和arcnum弧数  
    int kind;<span style="white-space:pre">      //图的种类，  
}ALGraph; 

int LocateVex(ALGraph &G,char &v1)   //查找节点V1在图G的存储节点数组中的索引位置  
{  
    int i;  
    for(i=0;i<G.vexnum;i++)  
    {  
        if(G.vertices[i].date==v1) //如果数组中有这个节点，返回该节点在数组中的索引  
            return i;  
    }  
    if(i>=G.vexnum)  
        return ERROR;  
    else   
        return 0;  
}  

void CreateDG(ALGraph &G)  
{  
    ArcNode *p,*q;  
    char v1,v2;  
    char v;  
    int i,j,k,n;  
    cout<<"请输入图的顶点数和弧数："<<endl;  
    cin>>G.vexnum; //输入图的顶点数量  
    cin>>G.arcnum; //输入图的弧（边）的数量  
    cout<<"请输入顶点："<<endl;  
      
    for(i=0;i<G.vexnum;i++) //创建头结点  
    {  
        cin>>v;   //输入顶点名字  
        G.vertices[i].date=v;  
        G.vertices[i].firstarc=NULL;  
    }  
    cout<<"请输入弧尾和弧头：";  
    for(k=0;k<G.arcnum;k++) //创建边，并连接头结点  
    {  
        cin>>v1;  //v1为弧尾  
        cin>>v2;   //v2为弧头  
        i=LocateVex(G,v1);j=LocateVex(G,v2);  
          
        if(G.vertices[i].firstarc==NULL)  //如果链表为空新建一个表节点，让头节点的指针指向该表节点  
        {  
            p=(ArcNode *)new ArcNode;  
            G.vertices[i].firstarc=p;  
            q=G.vertices[i].firstarc;  
        }  
        else        //链表的插入  
        {  
            q=G.vertices[i].firstarc;//获取头结点的表头指针  
            for(n=0;n<G.arcnum;n++,q=q->nextarc)//将q指针移动至链表的尾巴处  
            {  
                if(!q->nextarc)  
                    break;  
            }  
            p=(ArcNode *)new ArcNode;  
            q->nextarc=p; //将该边（弧）加入到链表中  
            q=q->nextarc;  
        }  
        q->adjvex=j;  //记录弧头的索引  
        q->nextarc=NULL;   
    }  
    cout<<"图构建成功！";  
}  