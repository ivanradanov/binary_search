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
  int min = 0, max = 1000000000;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    if (A[i] > max) max = A[i];
    else if (A[i] < min) min = A[i];
  }

  lb = min - 1, ub = max;
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
