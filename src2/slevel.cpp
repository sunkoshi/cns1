#include <bits/stdc++.h>
using namespace std;
struct Processor
{
    map<int, bool> hasData;
};

struct Node
{
    vector<int> needDataOf;
    int et;
};

bool hasData(Processor p, int n)
{
    return p.hasData.find(n) != p.hasData.end();
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int getExecutionTime(vector<Node> nodes, pair<int, int> sl)
{
    return nodes[sl.first].et;
}

int getSLevel(vector<pair<int, int>> &sl, int i, vector<vector<int>> &dag)
{
    int n = sl.size();
    if (sl[i].second != -1)
    {
        return sl[i].second;
    }

    int maxi = 0;
    int child_cnt = 0;
    for (int j = 0; j < n; j++)
    {
        if (i != j && dag[i][j] != 0)
        {
            child_cnt++;
            maxi = max(getSLevel(sl, j, dag), maxi);
        }
    }

    if (child_cnt == 0)
    {
        return dag[i][i];
    }
    else
    {
        return maxi + dag[i][i];
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e, p;
    cout << "Enter number of tasks in the dag:\n";
    cin >> n;
    cout << "Enter the number of edges in the dag:\n";
    cin >> e;
    cout << "Enter the number of processors\n";
    cin >> p;

    vector<vector<int>> dag(n, vector<int>(n, 0));
    cout << "Enter the dag:\n";
    vector<Node> nodes(n);
    for (int i = 0; i < e; i++)
    {
        int src, dest, comm_time;
        cin >> src >> dest >> comm_time;

        dag[src - 1][dest - 1] = comm_time;

        nodes[dest - 1].needDataOf.push_back(src - 1);
    }

    cout << "Enter the execution times of the tasks\n";
    for (int i = 0; i < n; i++)
    {
        int exec_time;
        cin >> exec_time;
        nodes[i].et = exec_time;
        dag[i][i] = exec_time;
    }

    vector<pair<int, int>> sl(n, {-1, -1});
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        sl[i] = {i, getSLevel(sl, i, dag)};
        cout << endl;
    }

    sort(sl.begin(), sl.end(), compare);
    for (auto x : sl)
        cout << x.first + 1 << " ";

    vector<Processor> processors(p);
    map<int, int> where;
    vector<vector<int>> table(p);
    processors[0].hasData[0] = true;

    // the sl(0) is in processor 1
    where[0] = 0;

    // storing the  
    table[0].push_back(getExecutionTime(nodes, sl[0]));

    for (int i = 1; i < sl.size(); i++)
    {
        for (int j = 0; j < p; j++)
        {
        }
    }
}
