#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

const int MAXN = 100003;

int n; // file size
int A[MAXN]; // file, one-base
int B[MAXN]; // likelihood, one-base

int dp[MAXN]; // dp[i] : i인덱스 까지만 봤을 때 복구 가능한가
int tmp[MAXN]; // tmp[i] :

bool is_possible(int x) { // x = maxlikelihood
   // 가능성 x이하인 원소만 지워서 복구가능한가
   
   memset(dp, 0, sizeof(dp));
   memset(tmp, 0, sizeof(tmp));

   vector<int> over; // 반드시 포함되어야 하는 인덱스의 목록
   for (int i = 1; i <= n; i++){
      if (B[i] > x){
         over.push_back(i);
      }
   }

   int osz = over.size();
   int oi = 0;

   tmp[0] = 1, tmp[1] = -1;
   int add = 1;
   dp[0] = add;
   // printf("\nx:%d\n",x);
   
   for(int i=1;i<=n;i++){
      if (oi<osz && over[oi]==i) oi++;

      if (dp[i-1]) {
         // 1) i번만 쓱 지우기
         if (B[i] <= x) {
            tmp[i]++;

            if (i + 1 <= n)
               tmp[i+1]--;
         }

         // 2) i번 살리기
         int sti = i+A[i]-1;
         if(sti<=n) {
            tmp[sti]++;
         }

         int ed = oi+A[i]-1;
         int edi=n+1;
         if(ed<osz){
            edi = over[ed];
            tmp[edi]--;
         }
         // printf("i:%d, A[i]:%d, sti:%d edi:%d\n", i, A[i], sti, edi);
      }

      add += tmp[i];
      dp[i] = add;
   }

   return (dp[n]>0);
}

int main() {
	// read input
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &A[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d", &B[i]);
	}

	// algorithm
	int L = 0, R = 100002;

	while (L < R) { // maxlikelihood를 바이너리 서치로 범위를 좁혀나간다
		int M = (R + L) / 2;

		if (is_possible(M)) R = M;
		else L = M + 1;
	}

	// print result
	printf("%d\n", L);

	return 0;
}
