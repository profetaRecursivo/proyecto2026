int n, m;
vector<vector<ll>> mat, prefix;

void build() {
	fore(i, 1, n + 1) {
		fore(j, 1, m + 1) {
			prefix[i][j] = mat[i][j] + prefix[i - 1][j] + prefix[i][j - 1] -
						   prefix[i - 1][j - 1];
		}
	}
}

ll query(int r1, int c1, int r2, int c2) {
	return prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] +
		   prefix[r1 - 1][c1 - 1];
}

int main() {
	cin >> n >> m;
	mat.assign(n + 1, vector<ll>(m + 1, 0)); 
	prefix.assign(n + 1, vector<ll>(m + 1, 0));

	fore(i, 1, n + 1) { fore(j, 1, m + 1) cin >> mat[i][j]; }

	build();
}
