
#include <bits/stdc++.h>
using namespace std;
// Adjacency matrix representation of the graph
// Can be further extended to cost adjacency matrix
// class graph

class Graph
{
    int nodes;

public:
    vector<vector<int>> matrix;
    Graph(int n)
    {
        nodes = n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
};
int main()
{
    // Creating a new graph
    Graph *g1 = new Graph(6);
    g1->matrix[0][5] = 1;
    g1->matrix[1][5] = 1;
    g1->matrix[2][4] = 1;
    g1->matrix[2][3] = 1;
    g1->matrix[3][2] = 1;
    g1->matrix[3][4] = 1;
    g1->matrix[3][5] = 1;
    g1->matrix[4][3] = 1;
    g1->matrix[5][0] = 1;
    g1->matrix[5][1] = 1;
    g1->matrix[5][3] = 1;

    return 0;
}
