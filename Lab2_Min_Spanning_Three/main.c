// dear teacher im refactoring to ENGLISH, all my codes of my Disciplines to post them on my Github Portfolio (is important my carrier)

//KRUSKAL Implementation to BUS PROBLEM in Graphs Theory Discipline in Computer Science Degree at Unifesp BR
//Douglas Diniz Landim, mrdfane@gmail.com // ddlandim@unifesp.br (this email should be invalid after 2021)
//Check the Spaning Three Folder in Graphs Theory Repository at https://github.com/ddlandim

#include <stdio.h>
#include <stdlib.h>

typedef struct{ int src, dest, weight; }Edge;
#define MAX 200000
int set[MAX];
/* OK you win about global variables, i cant declare a complete graph with max size of edges,
 * But set still is global, because it doesnt work inside Kruskal allocation, as my intention was having a collection of algorithms and choose one on main.
 * So the intention was: in main, i declare a int set* and then realloc MAX size only if Kruskal is called, to optimize space
*/

//Utility function of qsort from stdlib.h with weight attribute of struct edge
int compareWeights (const void *x, const void *y){
    int a = ((Edge *)x)->weight;
    int b = ((Edge *)y)->weight;
    return (a - b);
}

//Kruskal Implementations
int Find_Set(int value);
void Union(int u, int v);
int MST_Kruskal(Edge* Graph,int n, int m);

int main(){
    int i,
    n,m,
    u,v,w,
    total_weights = 0,
    min_weights = 0,
    cutted_weights = 0;

    scanf("%d%d",&n,&m);

    //avoiding tricks
    if(n < 1 || m < 1 || m > MAX)
        return 0;

    Edge* Graph = malloc((m+1) * sizeof (*Graph));
    //Ok, it didn't hurt as much as I thought

    for(i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        Graph[i].src = u;
        Graph[i].dest = v;
        Graph[i].weight = w;
        total_weights += w;
    }

    min_weights = MST_Kruskal(Graph,n,m);
    cutted_weights = total_weights - min_weights;
    printf("%d", cutted_weights);
    return 1;
}
//Kruskal Implementations

    //Utility function of Kruskal Algorithm
    int Find_Set(int value){
        if(set[value] != value)
            return Find_Set(set[value]);
        else return value;
    }
    //Utility function of Kruskal Algorithm
    void Union(int u, int v){
        set[Find_Set(v)] = Find_Set(u);
    }

    int MST_Kruskal(Edge* Graph,int n, int m){

        int n_Edges = 0, min_weights = 0;
        int i=1; //c90 limitation from judge...

        // for each vertex V in G,V.
        for(i=1;i<=n;i++)
            set[i]=i;

        // sort the edges of G,E into nondecreasing order by weight w
        qsort(Graph, m+1, sizeof(Edge), compareWeights);

        // for each Graph (u,v) in G.E taken in nondecreasing order by weight

        for(i=1;i<=m;i++){
            if(n_Edges == n - 1)
                break;

            // FIND-SET(u) no in FIND-SET(v)
            if(Find_Set(Graph[i].src) != Find_Set(Graph[i].dest)){
                // A = A union {(u,v)}
                Union(Graph[i].src, Graph[i].dest);

                // Sum of the weights of the Spanning Three
                min_weights+=Graph[i].weight;

                // Sum of the connected edges of the resultant Minimum Spanning Three
                n_Edges++;
            }
        }
        // or return n_Edges;
        return min_weights;
    }