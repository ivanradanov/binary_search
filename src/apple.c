#include <stdio.h>

int n;
int k;
int A[100000];

int is_ok(int p)
{
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A[i] / p + !!(A[i] % p);
		if (sum > k)
			return 0;
	}
	return 1;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = A[0] - 1, ub = A[n - 1];
  while (lb + 1 < ub) {
	  i = (lb + ub) / 2;
	  if (is_ok(i))
		  ub = i;
	  else
		  lb = i;
  }
  printf("%d\n", ub);
  return 0;
}
