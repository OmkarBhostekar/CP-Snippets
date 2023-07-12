// Z Algorithm – TC – O(M+N)
void getZarr(string str, int Z[]){
	int n = str.length();
	int L, R, k;
	
	L = R = 0;
	for (int i = 1; i < n; ++i){
		if (i > R){
			L = R = i;
			while (R<n && str[R-L] == str[R])
			R++;
			Z[i] = R-L;
			R--;
		}else {
			k = i-L;
			if (Z[k] < R-i+1)
				Z[i] = Z[k];
			else{
				L = i;
				while (R<n && str[R-L] == str[R]) R++;
				Z[i] = R-L;
				R--;
			}
		}
	}
}
vector<int> z_search(string p, string t){
	string concat = p + "$" + t;
	int l = concat.length();
	int Z[l];
	getZarr(concat, Z);
	vector<int> ans;
	for (int i = 0; i < l; ++i){
		if (Z[i] == (int)p.length())
			ans.push_back(i-p.length()-1);
	}
	return ans;
} 