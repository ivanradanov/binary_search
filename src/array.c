#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = -1, ub = n;
  while (lb + 1 < ub) {
	  i = (lb + ub) / 2;
	  if (A[i] < k)
		  lb = i;
	  else
		  ub = i;
  }
  printf("%d\n", ub);
  return 0;
}
