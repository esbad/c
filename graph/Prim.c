#include<stdio.h>
//最小生成树问题

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAX 0x7fffffff//2^31-1
typedef struct 
{
    VertexType vertex[MAXSIZE];
    EdgeType arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;
}Mat_Graph;

typedef struct 
{
    int beigin;
    int end;
    int weight;
}Edge;


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
            if( i == j)
            {
                G->arc[i][j] = 0;
            }
            else
            {
                G->arc[i][j] = MAX;
            }
        }
    }
        //AB AF
    G->arc[0][1] = 10;
    G->arc[0][5] = 11;
    //BC BG BI
    G->arc[1][2] = 18;
    G->arc[1][6] = 16;
    G->arc[1][8] = 12;
    
    G->arc[2][3] = 22;
    G->arc[2][8] = 8;

    G->arc[3][4] = 20;
    G->arc[3][6] = 24;
    G->arc[3][7] = 17;
    G->arc[3][8] = 21;
    
    G->arc[4][5] = 26;
    G->arc[4][7] = 7;
    G->arc[5][6] = 17;
    G->arc[6][7] = 19;
    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            G->arc[i][j] = G->arc[j][i];
        }
    }
}

void prim(Mat_Graph *G)
{
    int i,j,k;
    int min;//最小权值
    int weight[MAXSIZE];//候选边,待选权值
    int vex_index[MAXSIZE];//值表示出发点，下标表示到达点

    //从顶点A开始
    weight[0] = 0;
    vex_index[0] = 0;

    for (int i = 1; i < G->vertex_num; i++)
    {
        weight[i] = G->arc[0][i];
        vex_index[i] = 0;
    }

    for (int i = 1; i < G->vertex_num; i++)
    {
        min = MAX;
        j = 0;
        k = 0;

        //找到最小的，与之连接
        while(j < G->vertex_num)
        {
            if (weight[j] != 0 && weight[j] < min)
            {
                min = weight[j];
                k = j;
            }
            j++;
        }

        //值是出发点的下标，k下标是到达点的下标
        printf("(%c,%c)\n",G->vertex[vex_index[k]],G->vertex[k]);
        weight[k] = 0;//连过

        //更新侯选边
        for (j = 0; j < G->vertex_num; j++)
        {
            //确定下一轮的待选边权值
            if(weight[j] != 0 && G->arc[k][j] < weight[j])
            {
                weight[j] = G->arc[k][j];
                vex_index[j] = k;//下一轮出发点，待选值都是赋值上k
            }
        }
    }
}

void sortEdges(Edge edges[],int edge_num)
{
    for (int i = 0; i < edge_num; i++)
    {
        for (int j = 0; j < edge_num; j++)
        {
         
        }
    }
}

int find(int* parent, int index)
{
    while (parent[index] > 0)
    {
        index = parent[index];
    }
    return index;
}

//kruskal克鲁斯卡尔，先找最短路径
void Kruskal(Mat_Graph G)
{
    Edge edges[MAXSIZE];
    int k = 0;

    for (int i = 0; i <G.vertex_num; i++)
    {
        for (int j = i + 1; j < G.vertex_num; j++)
        {
            if (G.arc[i][j] < MAX)
            {
                edges[k].beigin = i;//出发点下标
                edges[k].end = j;//达到点下标
                edges[k].weight = i;//权值
                k++;
            }
        }
    }

    sortEdges(edges,G.edge_num);
    int parent[MAXSIZE];
    for(int i = 0;i < G.vertex_num; i++)
    {
        parent[i] = 0;
    }
    int n,m;
    for (int i = 0; i < G.edge_num; i++)
    {
        n = find(parent,edges[i].beigin);
        m = find(parent,edges[i].end);
        if (n != m)
        {
            parent[n] = m;
            printf("(%c,%c)",G.vertex[edges[i].beigin,G.vertex[edges[i].end]]);
        } 
    }
}



int main()
{
    Mat_Graph G;
    create_graph(&G);
    
    prim(&G);
    return 0;
}