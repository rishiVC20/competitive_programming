#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define vi vector<ll>
#define vvp vector<pair<ll,ll>>
#define all(a) (a).begin(),(a).end()
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> direction(n, vector<char>(m, ' '));

    ll stx, sty, enx, eny;

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'A') stx = i, sty = j;
            if(a[i][j] == 'B') enx = i, eny = j;
            vis[i][j] = (a[i][j] == '#');
        }
    }

    queue<pair<int, int>> q;
    q.push({stx, sty});
    vis[stx][sty] = true;

    vi dx = {-1, 1, 0, 0}; 
    vi dy = {0, 0, -1, 1};
    char moveDir[] = {'U', 'D', 'L', 'R'};

    bool found = false;

    while (!q.empty()) {
        pair<ll,ll> tp= q.front();
        ll x=tp.first,y=tp.second;
        q.pop();

        if (x == enx && y == eny) {
            found = true;
            break;
        }

        for (ll i = 0; i < 4; i++) {
            ll nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                q.push({nx, ny});
                vis[nx][ny] = true;
                parent[nx][ny] = {x, y};  
                direction[nx][ny] = moveDir[i];
            }
        }
    }

    if (!found) {
        NO;
        return 0;
    }

    // Reconstruct path
    string path;
    int x = enx, y = eny;

    while (x != stx || y != sty) {
        path += direction[x][y];
        pair<ll,ll>tp = parent[x][y];
        ll px=tp.first,py=tp.second;
        x = px, y = py;
    }

    reverse(all(path));

    YES;
    cout << path.size() << "\n";
    cout << path << "\n";

    return 0;
}
