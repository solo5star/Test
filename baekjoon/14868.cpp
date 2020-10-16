#include <iostream>
#include <map>
#include <queue>

using namespace std;

int k, n;

int yearElappsed = 0;

// map
int world[2001][2001];

// Union-Find
int parents[100001];

// Next civilization queue (BFS)
queue<pair<int, int>> civil_queue;
queue<pair<int, int>> union_queue;

// Offsets
pair<int, int> near[] = {
    make_pair(-1, 0),
    make_pair(1, 0),
    make_pair(0, -1),
    make_pair(0, 1)
};

int find(int a) {
    return parents[a] == 0 ? a : find(parents[a]);
}

bool merge(int a, int b) {
    int _a = find(a);
    int _b = find(b);

    if (_a == _b) return false;

    parents[b] = _a;
    return true;
}

inline bool outsideOfWorld(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

void do_union() {
    while (!union_queue.empty()) {
        int x = union_queue.front().first;
        int y = union_queue.front().second;

        union_queue.pop();

        for (int i = 0; i < 4; i++) {
            int x_ = x + near[i].first;
            int y_ = y + near[i].second;

            if (outsideOfWorld(x_, y_)) continue;

            if (world[y_][x_] != 0 && find(world[y_][x_]) != find(world[y][x])) {
                merge(world[y][x], world[y_][x_]);
                k--;
            }
        }
        civil_queue.push(make_pair(x, y));
    }
}

void do_civil() {
    while (!civil_queue.empty()) {
        int x = civil_queue.front().first;
        int y = civil_queue.front().second;

        civil_queue.pop();

        for (int i = 0; i < 4; i++) {
            int x_ = x + near[i].first;
            int y_ = y + near[i].second;

            if (outsideOfWorld(x_, y_)) continue;

            if (world[y_][x_] == 0) {
                world[y_][x_] = world[y][x];
                union_queue.push(make_pair(x_, y_));
            }
        }
    }
}

int main()
{
    // Optimize cin, cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--; // 0 base index
        world[y][x] = i; // i is civil id
        union_queue.push(make_pair(x, y));
    }

    while (true) {
        do_union();

        if (k <= 1) break;

        do_civil();

        yearElappsed++;
    }

    cout << yearElappsed;
}