#include <stdio.h>

int n;
int k;
int A[100000];

int is_ok(int p)
{
	int sum = 0, num = 1;
	for (int i = 0; i < n; i++) {
		sum += A[i];
		if (sum > p) {
			if (++num > k)
				return 0;
			sum = A[i];
		}
	}
	return 1;
}

int main(){
  int i, lb, ub;
  int sum = 0, max = 0;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    sum += A[i];
    if (max < A[i])
	    max = A[i];
  }

  lb = max - 1, ub = sum;
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
