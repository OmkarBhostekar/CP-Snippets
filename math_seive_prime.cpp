vector<bool> sv;
void computePrimes(int N){
	sv.resize(N+1,true);
	sv[0] = false;
	sv[1] = false;
	for(int i=2;i<=N;i++){
		if(sv[i]){
			for(int j=i*i;j<=N;j+=i)
				sv[j] = false;
		}
	}
}