//KRUSKAL Implementation to BUS PROBLEM in Graphs Theory Discipline in Computer Science Degree at Unifesp-BR
//Douglas Diniz Landim, mrdfane@gmail.com // ddlandim@unifesp.br (this email should be invalid after 2021)
//Check the Spaning Three Folder in Graphs Theory at https://github.com/ddlandim

#include <iostream>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 200000

int n,m,
    u,v,w,
    k=0,
    total_weights = 0,
    min_weights = 0,
    cutted_weights = 0;
int set[MAX];

// the edge vector is the Graph G, we just deal it as a vector of Edges to make things easyer
struct node{ int src, dest, weight; }edge[MAX];

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

void MST_Kruskal(){
    //A = empty (i created a empty set in global variables at MAX size of this problem)

    //2 for each vertex V in G,V.
    for(int i=1;i<=n;i++) set[i]=i;

    //sort the edges of G,E into nondecreasing order by weight w
    sort(edge+1,edge+1+m, false);

    // for each edge (u,v) in G.E taken in nondecreasing order by weight
    for(int i=1;i<=m;i++)
    {
        if(k==n-1) break;

        //FIND-SET(v) no in FIND-SET(v)
        if(Find_Set(edge[i].src) != Find_Set(edge[i].dest))
        {
            //A = A union {(u,v)}
            Union(edge[i].src, edge[i].dest);

            //Sum of the weights of the Spanning Three
            min_weights+=edge[i].weight;

            //Sum of the connected edges of the Spanning Three
            k++;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		 scanf("%d%d%d",&u,&v,&w);
         edge[i].src = u;
         edge[i].dest = v;
         edge[i].weight = w;
        total_weights += w;
	}
    MST_Kruskal();
    cutted_weights = total_weights - min_weights;
	printf("%d", cutted_weights);
	return 0;
}