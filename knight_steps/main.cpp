#include <iostream>
#include <set>
#include <queue>
#include <climits>
using namespace std;

int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };

bool valid(int x, int y)
{
    if (x < 0 || y < 0 || x >= 8 || y >= 8)
        return false;
    return true;
}

struct Node
{
    int x, y, dist;

    Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}

    bool operator<(const Node& m_node) const
    {
        return x < m_node.x || (x == m_node.x && y < m_node.y);
    }
};

int BFS(Node src, Node dest)
{
    set<Node> visited;
    queue<Node> q;
    q.push(src);
    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        int x = node.x;
        int y = node.y;
        int dist = node.dist;

        if (x == dest.x && y == dest.y)
            return dist;

        if (!visited.count(node)) {
            visited.insert(node);

            for (int i = 0; i < 8; ++i) {
                int x1 = x + row[i];
                int y1 = y + col[i];

                if (valid(x1, y1))
                    q.push({x1, y1, dist + 1});
            }
        }
    }
    return 0;
}

int main()
{
    char src_input[2];
    char dest_input[2];
    scanf("%s %s", src_input, dest_input);
    int x1,y1,x2,y2;
    x1 = src_input[0] - 'a';
    y1 = src_input[1] - '1';
    x2 = dest_input[0] - 'a';
    y2 = dest_input[1] - '1';
    Node src = {x1,y1};
    Node dest = {x2, y2};
    return BFS(src, dest);
}