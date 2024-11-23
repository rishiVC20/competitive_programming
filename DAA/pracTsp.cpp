#include <bits/stdc++.h>
using namespace std;
#define N 5
#define INF INT_MAX

struct Node
{
    /* data */
    vector<pair<int, int>> path;
    int mat[N][N];
    int cost;
    int ver;
    int level;
};

Node *newNode(int par[N][N], vector<pair<int, int>> path, int lev, int i, int j)
{
    Node *node = new Node;
    node->path = path;

    if (lev != 0)
    {
        node->path.push_back({i, j});
    }

    memcpy(node->mat, par, sizeof node->mat);

    for (int k = 0; k < N && lev != 0; k++)
    {
        node->mat[i][k] = INF;
        node->mat[k][j] = INF;
    }
    node->mat[j][0] = INF;
    node->level = lev;
    node->ver = j;

    return node;
}

int main()
{
    int costma[N][N], result;
    cout << "Enter : \n";
    for ()
}