//KRUSKAL Implementation to BUS PROBLEM in Graphs Theory Discipline in Computer Science Degree at Unifesp-BR
//Douglas Diniz Landim, mrdfane@gmail.com // ddlandim@unifesp.br (this email should be invalid after 2021)
//Check the Spaning Three Folder in Graphs Theory at https://github.com/ddlandim

#include <stdio.h>
#include <stdlib.h>
#define MAX 200000

//lets make things easyer and define all to global variable
int n,m,
        u,v,w,
        k=0,
        total_weights = 0,
        min_weights = 0,
        cutted_weights = 0;

int set[MAX];

struct edge{ int src, dest, weight; }Graph[MAX];

int Find_Set(int node)
{
    if(set[node] != node)
        return Find_Set(set[node]);
    else return node;
}
void Union(int u, int v)
{
    set[Find_Set(v)] = Find_Set(u);
}
//compare function to use of qsort from stdlib.h with weight atrribute of struct edge
int compareWeights (const void *x, const void *y) {
    int a = ((struct edge *)x)->weight;
    int b = ((struct edge *)y)->weight;
    return (a - b);
}

void MST_Kruskal(){
    //A = empty (i created a empty set in global variables at MAX size of this problem)

    //2 for each vertex V in G,V.
    for(int i=1;i<=n;i++) set[i]=i;

    //sort the edges of G,E into nondecreasing order by weight w
    qsort(Graph, 1 + m, sizeof(struct edge), compareWeights);

    // for each Graph (u,v) in G.E taken in nondecreasing order by weight
    for(int i=1;i<=m;i++)
    {
        if(k==n-1) break;

        //FIND-SET(v) no in FIND-SET(v)
        if(Find_Set(Graph[i].src) != Find_Set(Graph[i].dest))
        {
            //A = A union {(u,v)}
            Union(Graph[i].src, Graph[i].dest);

            //Sum of the weights of the Spanning Three
            min_weights+=Graph[i].weight;

            //Sum of the connected edges of the Spanning Three
            k++;
        }
    }
}
int main()
{
    //avoiding tricks
    scanf("%d%d",&n,&m);
    if(n < 1 || m < 1)
        return 0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        Graph[i].src = u;
        Graph[i].dest = v;
        Graph[i].weight = w;
        total_weights += w;
    }
    MST_Kruskal();
    cutted_weights = total_weights - min_weights;
    printf("%d", cutted_weights);
    return 0;
}