vector<int> getLps(string &pat, int n){
	vector<int> lps(n);
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < n) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}else{
			if (len != 0) {
				len = lps[len - 1];
			}else {
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}
vector<int> KMP(string pat, string txt){ // returns vector of start idx of occurances
	int M = pat.length();
	int N = txt.length();
	vector<int> lps = getLps(pat,pat.length());
	vector<int> idx;
	int i = 0;
	int j = 0;
	while ((N - i) >= (M - j)) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}
		if (j == M) {
			idx.push_back(i-j);
			j = lps[j - 1];
		}  else if (i < N && pat[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
	return idx;
}