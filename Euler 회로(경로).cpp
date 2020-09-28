#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <typeinfo>
#include <iomanip>


#define INF 2000000000
using namespace std;

vector<vector<int>> adj;
vector<int> indegree, outdegree;

//���� �׷����� ���� euler ��Ŷ(���) ã�� �˰��� // ������ ���� 

// �׷����� euler�� �����ϴ��� check
bool check_euler() {
	// out: outdegree�� 1��ŭ �� ���� ���� ����
	// in: indegree�� 1��ŭ �� ���� ���� ����
	int in = 0, out = 0;
	for (int i = 0; i < 26; i++) {
		int delta = outdegree[i] - indegree[i];
		if (delta > 1 || delta < -1) // ���� x�� ���
			return false;
		if (delta == 1)	out++;
		if (delta == -1)	 in++;
	}
	return (in == 1 && out == 1) || (in == 0 && out == 0); // (euler ��� ����) || (euler ��Ŷ ����)
}

// dfs�� ���Ϸ� ��Ŷ(���) ã��. // circuit�� �������� ����ȴ�.
void get_euler(int here, vector<int>& circuit) {
	for (int there = 0; there < 26; there++) {
		while (adj[here][there] > 0) {		// ���߱׷��� ��� // ���� ��Ŷ�� �ϳ� ã�Ƽ� circuit�� �߰��Ѵ�.
			adj[here][there]--;				// ������ �����
			get_euler(there, circuit);		// ���󰣴�.
		}
	}
	circuit.push_back(here);
}

// euler ��Ŷor��ΰ� �����Ҷ� ��� ã�Ƽ� ��ȯ.
vector<int> get_circle_or_trail() {
	vector<int> circuit;

	// Ʈ���Ϸ� �����ϴ°��
	for (int i = 0; i < 26; i++)
		if (outdegree[i] - indegree[i] == 1) { // �������� outdegree = indegree+1�� ������ ����.
			get_euler(i, circuit);
			return circuit;
		}

	// ��Ŷ�� ��� ������ �� �ִ� �ƹ� ������ ����
	for (int i = 0; i < 26; i++)
		if (outdegree[i]) {
			get_euler(i, circuit);
			return circuit;
		}

	// �� ���н� �� ���� ��ȯ. ���� ���� ���. �� �������� ���Ļ�.
	return circuit;
}



bool solve() {
	if (!check_euler) return false;
	
	//�����Ѵٸ�,
	vector<int> circuit = 
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	
	return 0;
}