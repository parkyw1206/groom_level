#include<cstdio>
#include<cstdlib>
#include<memory.h>
#include<iostream>
#include<algorithm>


using namespace std;


int get_minimum_trashes(int **waste, int N, int K) {
	int answer = K * K;
	int count;
	for(int i  = 0 ; i < N-K +1 ; i++){
		for(int j = 0 ; j < N-K+1 ; j++){
			count = 0;
			for(int m = i ; m < i + K ; m++){
				for(int n = j ; n < j + K ; n++){
					count += waste[m][n];
				}
			}
			if(count < answer){
				answer = count;
			}
		}
	}

	return answer;
}

void test_case(int caseIndex) {
	int N, K;
	scanf("%d %d", &N, &K);

	int **wastes = new int *[N];
	for (int r = 0; r < N; r += 1) {
		wastes[r] = new int[N];
		for (int c = 0; c < N; c += 1) {
			scanf("%d", &wastes[r][c]);
		}
	}

	int answer = get_minimum_trashes(wastes, N, K);
	printf("%d\n", answer);

	for (int r = 0; r < N; r += 1) {
		delete[] wastes[r];
	}
	delete[] wastes;
}

int main() {
	int caseSize;
	scanf("%d", &caseSize);

	for (int caseIndex = 0; caseIndex < caseSize; caseIndex += 1) {
		test_case(caseIndex);
	}
	return 0;
}