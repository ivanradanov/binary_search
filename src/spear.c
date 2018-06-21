#include <stdio.h>

int n;
int k;
int A[100000];

int is_ok(int p)
{
	if (p == 0)
		return 1;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A[i] / p;
		if (sum >= k)
			return 1;
	}
	return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0, ub = A[n - 1] + 1;
  while (lb + 1 < ub) {
	  i = (lb + ub) / 2;
	  if (is_ok(i))
		  lb = i;
	  else
		  ub = i;
  }
  printf("%d\n", lb);
  return 0;
}
