#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef int island_id;
typedef int sea_id;

const island_id ISLAND_UNKNOWN = -1;

const sea_id SEA_UNKNOWN = -1;
const sea_id SEA_GLOBAL = -2;

typedef struct {
	island_id island_id;
	sea_id sea_id;
	bool visited;
} tile;

struct {
	int islandCounter;

	int width;
	int height;

	tile tiles[50][50];
} world;

typedef struct {
	island_id parent;
	bool visited;
	int height;

	unordered_set<island_id> children;
} island;

unordered_map<int, island> islands;

int temporalInteger;

bool isTileEqual(tile& a, tile& b) {
	return a.island_id == b.island_id && a.sea_id == b.sea_id;
}

void floodfill(int x, int y, tile* criteria, void (*tile_callback)(tile& tile), bool (*flood_continue)(tile&, tile&) = isTileEqual, bool diagonal = false) {
	if (x < 0 || x >= world.width || y < 0 || y >= world.height) return;

	if (criteria == nullptr) {
		criteria = &world.tiles[y][x];
	}

	if (!flood_continue(*criteria, world.tiles[y][x])) return;

	if (world.tiles[y][x].visited) return;

	world.tiles[y][x].visited = true;

	floodfill(x - 1, y, criteria, tile_callback, flood_continue, diagonal);
	floodfill(x + 1, y, criteria, tile_callback, flood_continue, diagonal);
	floodfill(x, y - 1, criteria, tile_callback, flood_continue, diagonal);
	floodfill(x, y + 1, criteria, tile_callback, flood_continue, diagonal);

	if (diagonal) {
		floodfill(x - 1, y - 1, criteria, tile_callback, flood_continue, diagonal);
		floodfill(x + 1, y - 1, criteria, tile_callback, flood_continue, diagonal);
		floodfill(x - 1, y + 1, criteria, tile_callback, flood_continue, diagonal);
		floodfill(x + 1, y + 1, criteria, tile_callback, flood_continue, diagonal);
	}

	tile_callback(world.tiles[y][x]);
}

void _floodfillSeaGlobalTileCallback(tile& tile) {
	tile.sea_id = SEA_GLOBAL;
}

void floodfillSeaGlobal() {
	for (int x = 0; x < world.width; x++) {
		if (world.tiles[0][x].sea_id == SEA_UNKNOWN) {
			floodfill(x, 0, nullptr, _floodfillSeaGlobalTileCallback);
		}
		if (world.tiles[world.height - 1][x].sea_id == SEA_UNKNOWN) {
			floodfill(x, world.height - 1, nullptr, _floodfillSeaGlobalTileCallback);
		}
	}
	for (int y = 0; y < world.height; y++) {
		if (world.tiles[y][0].sea_id == SEA_UNKNOWN) {
			floodfill(0, y, nullptr, _floodfillSeaGlobalTileCallback);
		}
		if (world.tiles[y][world.width - 1].sea_id == SEA_UNKNOWN) {
			floodfill(world.width - 1, y, nullptr, _floodfillSeaGlobalTileCallback);
		}
	}
}

void _floodfillIslandPrivateSeaCallback(tile& tile) {
	tile.sea_id = temporalInteger;
}

void _floodfillIslandTileCallback(tile& tile) {
	tile.island_id = world.islandCounter;
}

void floodfillIsland() {
	for (int y = 0; y < world.height; y++) {
		for (int x = 0; x < world.width; x++) {
			if (world.tiles[y][x].island_id == ISLAND_UNKNOWN) {
				int islandId = ++world.islandCounter;

				islands[islandId] = { ISLAND_UNKNOWN, false, 0 };

				floodfill(x, y, NULL, _floodfillIslandTileCallback, isTileEqual, true);
			}

			// it seems not SEA_GLOBAL
			// figure out left tile
			if (
				world.tiles[y][x].sea_id == SEA_UNKNOWN
				&& world.tiles[y][x - 1].island_id > 0
			) {
				temporalInteger = world.tiles[y][x - 1].island_id;

				floodfill(x, y, NULL, _floodfillIslandPrivateSeaCallback);
			}

			// if left tile is private sea and current tile is isolated island ...
			if (
				x > 0
				&& world.tiles[y][x - 1].sea_id > 0
				&& world.tiles[y][x].island_id > 0
				&& world.tiles[y][x].island_id != world.tiles[y][x - 1].sea_id
			) {
				islands[world.tiles[y][x].island_id].parent = world.tiles[y][x - 1].sea_id;
				islands[world.tiles[y][x - 1].sea_id].children.insert(world.tiles[y][x].island_id);
			}
		}
	}
}

void printWorld() {
#ifdef DEBUG
	cout << "\n";
	for (int y = 0; y < world.height; y++) {
		for (int x = 0; x < world.width; x++) {
			if (world.tiles[y][x].island_id > 0) {
				cout << "[" << world.tiles[y][x].island_id << "]";
			}
			else if (world.tiles[y][x].sea_id == SEA_UNKNOWN) {
				cout << "(U)";
			}
			else if (world.tiles[y][x].sea_id == SEA_GLOBAL) {
				cout << "(G)";
			}
			else if (world.tiles[y][x].sea_id > 0) {
				cout << "(" << world.tiles[y][x].sea_id << ")";
			}
			else {
				cout << "[?]";
			}
		}
		cout << "\n";
	}
#endif
}

int getHeight(island& island) {
	if (island.visited) return island.height;

	island.visited = true;

	if (island.children.empty()) return island.height = 0;

	int maxh = 0;
	for (island_id child_id : island.children) {
		maxh = max(maxh, getHeight(islands[child_id]));
	}

	return island.height = maxh + 1;
}

void eachHeights() {
	unordered_map<int, int> heights;

	int maxHeight = -1;

	for (auto& it : islands) {
		int height = getHeight(it.second);

		maxHeight = max(maxHeight, height);

		if (heights.count(height) == 0) heights[height] = 1;
		else heights[height]++;

#ifdef DEBUG
		cout << "Island " << it.first << ". includes=(";

		for (island_id child_id : it.second.children) {
			cout << child_id << " ";
		}

		cout << ")" << " height=" << height << "\n";
#endif
	}

	if (maxHeight == -1) cout << -1; else  for (int h = 0; h <= maxHeight; h++) {
		if (heights.count(h) == 0) cout << 0 << " ";
		else cout << heights[h] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> world.height >> world.width;

	char ch;
	for (int y = 0; y < world.height; y++) {
		for (int x = 0; x < world.width; x++) {
			cin >> ch;

			switch (ch) {
			case 'x':
				world.tiles[y][x].island_id = ISLAND_UNKNOWN;
				break;
			case '.':
				world.tiles[y][x].sea_id = SEA_UNKNOWN;
				break;
			}
		}
	}

	floodfillSeaGlobal();
	floodfillIsland();

	printWorld();

	eachHeights();
}