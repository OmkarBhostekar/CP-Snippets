// Euler's totient function, also known as phi-function the number of integers
// between 1 and  n inclusive, which are coprime to n.
int phi(int n) {
	int result = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0)
			n /= i;
			result -= result / i;
		}
	}
	if (n > 1) result -= result / n;
	return result;
}
// Find all the totient of all numbers between  1 and n inclusive.
vector<int> phi_1_to_n(int n) {
	vector<int> phi(n + 1);
	for (int i = 0; i <= n; i++)
		phi[i] = i;
		for (int i = 2; i <= n; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= n; j += i)
			phi[j] -= phi[j] / i;
		}
	}
	return phi;
} 