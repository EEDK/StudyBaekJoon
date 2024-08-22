#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	unordered_map<string, int> Books;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		Books[s]++;
	}

	vector<pair<string, int>> Table;

	for (const auto& book : Books) {
		Table.push_back(book);
	}

	sort(Table.begin(), Table.end(),[](const pair<string, int>& a, const pair<string, int>& b){
	  if (a.second != b.second) {
		  return a.second > b.second; 
	  } else {
		  return a.first < b.first;  
	  }
	});

	cout << Table[0].first << endl;

	return 0;
}
