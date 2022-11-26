#include <set>
#include <map>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

map<pair<int, int>, vector<pair<int, int>>> g;
map< pair<int, int>, bool> used;
vector<vector<int>> d;

void dfs(pair<int, int> v) {
	//cout << v.first << " " << v.second << endl;
	used[v] = true;

	for (vector<pair<int, int>>::iterator i = g[v].begin(); i != g[v].end(); ++i) {
		if (!used[*i])
		{
			d[i->first][i->second] = max(d[i->first][i->second], d[v.first][v.second] + 1);
			dfs(*i);
		}
	}
	//used[v] = false;
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	d.resize(n);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		d[i].resize(m);
		for (int j = 0; j < m; j++) {
			if (s[j] == '1') {
				d[i][j] = -1;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (d[i][j] == 0) {
				if (i - 1 >= 0 && d[i - 1][j] == 0) {
					g[{i, j}].push_back({ i - 1,j });
				}
				
				if (i + 1 < n && d[i + 1][j] == 0) {
					g[{i, j}].push_back({ i + 1,j });
				}
				if (j + 1 < m && d[i][j + 1] == 0) {
					g[{i, j}].push_back({ i,j + 1});
				}
			}
		}
	}
	for (auto p : g) {
		used[p.first] = false;
	}
	/*for (auto p : d) {
		for (int i : p)
			cout << i << " ";
		cout << endl;
	}*/
	dfs({ 0, 0 });

	/*for (auto p : d) {
		for (int i : p)
			cout << i << " ";
		cout << endl;
	}*/
	if (d[n - 1][m - 1] != 0) {
		cout << d[n - 1][m - 1] + 1 << endl;
	}
	else {
		cout << -1 << endl;
	}
}


/*

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> d(n, vector<int>(m,0));
	vector<vector<pair<int, int>>> pr(n, vector<pair<int, int>>(m, { -1,-1 }));

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '1') {
				d[i][j] = -1;
			}
		}
	}
	/*
	for (auto p : d) {
		for (int i : p)
			cout << i << " ";
		cout << endl;
	}
	

d[0][0] = 1;
pr[0][0] = { -2, -2 };
queue<pair<int, int>> q;
q.push({ 0, 0 });
while (!q.empty()) {
	pair<int, int> p = q.front();
	q.pop();
	int i = p.first, j = p.second;
	cout << i << " " << j << endl;
	cout << endl << endl;
	for (auto p : d) {
		for (int i : p)
			cout << i << " ";
		cout << endl;
	}
	cout << endl;
	for (auto p : pr) {
		for (auto i : p)
			cout << i.first << " " << i.second << "|";
		cout << endl;
	}
	cout << endl;
	if (i - 1 >= 0 && d[i - 1][j] != -1 && (i - 1 != pr[i][j].first || j != pr[i][j].second)) {
		//cout << i - 1 << "U" << j << endl;
		if (d[i][j] + 1 > d[i - 1][j]) {
			d[i - 1][j] = d[i][j] + 1;
			pr[i - 1][j] = { i, j };

		}
		q.push({ i - 1, j });
	}
	//cout << i << ' ' << pr[i][j].first << ' ' << j + 1 << ' ' << pr[i][j].second << endl;
	if (j + 1 < m && d[i][j + 1] != -1 && (i != pr[i][j].first || j + 1 != pr[i][j].second)) {
		//cout << i << "R" << j + 1<< endl;
		if (d[i][j] + 1 > d[i][j + 1]) {
			d[i][j + 1] = d[i][j] + 1;
			pr[i][j + 1] = { i, j };

		}
		q.push({ i, j + 1 });
	}
	if (i + 1 < n && d[i + 1][j] != -1 && (i + 1 != pr[i][j].first || j != pr[i][j].second)) {
		//cout << i + 1 << "D" << j << endl;
		if (d[i][j] + 1 > d[i + 1][j]) {
			d[i + 1][j] = d[i][j] + 1;
			pr[i + 1][j] = { i, j };

		}
		q.push({ i + 1, j });
	}


}

cout << endl << endl;
for (auto p : d) {
	for (int i : p)
		cout << i << " ";
	cout << endl;
}
if (d[n - 1][m - 1] == 0) {
	cout << -1 << endl;
}
else {
	cout << d[n - 1][m - 1] << endl;
}
}


*/

/*

	string s;
	cin >> s;
	int k;
	cin >> k;
	stack<int> pos;
	int n = s.size();
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '(')
			pos.push(i);
		else {
			int x = pos.top();
			pos.pop();
			if (i - x == k)
			{
				cnt +=
			}
		}
	}
	cout << cnt;
*/
