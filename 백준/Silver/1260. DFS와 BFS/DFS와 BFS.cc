#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vi>
#define vb vector<bool>

using namespace std;

void dfs(vii graph, int start, vb visit);
void bfs(vii graph, int start, vb visit);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, start, u, v;
    cin >> N >> M >> start;

    vii graph(N + 1);
    vb visit(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(graph, start, visit);
    bfs(graph, start, visit);
}

void dfs(vii graph, int start, vb visit)
{
    stack<int> s;
    s.push(start);
    visit[start] = true;

    cout << start << " ";

    while (!s.empty())
    {

        int current_node = s.top();
        s.pop();
        for (int i = 0; i < graph[current_node].size(); i++)
        {

            int next_node = graph[current_node][i];

            if (visit[next_node] == false)
            {
                cout << next_node << " ";
                visit[next_node] = true;
                // pop()을 했었기 때문에 현재 current_node도 넣어줘야한다.
                s.push(current_node);
                s.push(next_node);
                break;
            }
        }
    }

    cout << "\n";
}

void bfs(vii graph, int start, vb visit)
{

    queue<int> q;

    q.push(start);
    visit[start] = true;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        cout << now << " ";

        for (int i = 0; i < graph[now].size(); i++)
        {
            int temp = graph[now][i];
            // 방문하지 않았다면
            if (visit[temp] == false)
            {

                // 큐에 넣어주고 방문했음을 표시한다.
                q.push(temp);
                visit[temp] = true;
            }
        }
    }
}