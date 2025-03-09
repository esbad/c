#include<stdio.h>
#include<malloc.h>

//深度优先遍历 前序遍历//广度优先 层级遍历
typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100

typedef struct 
{
    VertexType vertex[MAXSIZE];//顶点
    EdgeType arc[MAXSIZE][MAXSIZE];//边
    int vertex_num;
    int edge_num;
}Mat_Graph;

int visited[MAXSIZE];//顶点是否被访问过
int front = 0;
int rear = 0;
int queue[MAXSIZE];

void create_graph(Mat_Graph* G)
{
    G->vertex_num = 9;
    G->edge_num = 15;
    G->vertex[0] = 'A';
    G->vertex[1] = 'B';
    G->vertex[2] = 'C';
    G->vertex[3] = 'D';
    G->vertex[4] = 'E';
    G->vertex[5] = 'F';
    G->vertex[6] = 'G';
    G->vertex[7] = 'H';
    G->vertex[8] = 'I';

    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j = 0; j < G->vertex_num; j++)
        {
            G->arc[i][j] = 0;
        }
    }

    //AB AF
    G->arc[0][1] = 1;
    G->arc[0][5] = 1;
    //BC BG BI
    G->arc[1][2] = 1;
    G->arc[1][6] = 1;
    G->arc[1][8] = 1;
    
    G->arc[2][3] = 1;
    G->arc[2][8] = 1;

    G->arc[3][4] = 1;
    G->arc[3][6] = 1;
    G->arc[3][7] = 1;
    G->arc[3][8] = 1;
    
    G->arc[4][5] = 1;
    G->arc[4][7] = 1;
    G->arc[5][6] = 1;
    G->arc[6][7] = 1;
    
    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            G->arc[i][j] = G->arc[j][i];
        }
    }
}

void dfs(Mat_Graph G, int i)//深度优先遍历//输入顶点
{
    visited[i] = 1;
    printf("%c\n",G.vertex[i]);

    for (int j = 0; j < G.vertex_num; j++)
    {
        if (G.arc[i][j] == 1 && visited[j] == 0)
        {
            dfs(G, j);
        }
    }
}

void bfs(Mat_Graph G)//广度优先
{
    int i = 0;//从第零层开始遍历
    visited[i] = 1;
    printf("%c\n",G.vertex[i]);//遍历A
    queue[rear] = i;//层数入队
    rear++;
    while(front != rear)//队不为空
    {
        i = queue[front];//对头元素
        front++;//第零层出队
        for (int j = 0; j < G.vertex_num; j++)
        {
            if (G.arc[i][j] == 1 && visited[j] == 0)
            {
                queue[rear] = j;
                rear++;
                visited[j] = 1;
                printf("%c\n",G.vertex[j]);
            }
        }
    }
}

int main()
{
    Mat_Graph G;
    create_graph(&G);

    for (int i = 0; i < G.vertex_num; i++)
    {
        visited[i] = 0;
    }
    //dfs(G, 0);
    bfs(G);
    return 0;
}