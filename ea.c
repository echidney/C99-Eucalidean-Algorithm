
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int *args;
static int *rems;
int *traceback(int brg1, int brg2, int cnt){
	if (cnt > -1){
		//expanding factors from the remainders
		return traceback((args[cnt]*brg1 + brg2), brg1, cnt-1);
	}
	else{
		//formatting the result
		int num[] = {brg1, 0-brg2};
		int *res = malloc(sizeof(num));
		memcpy(res, num, sizeof(num));
		return res;
	}
}

int e_algo(int arg1, int arg2, int sic){
	int ing = arg1 % arg2;
	int soc = arg1 / arg2;
	int w7 = sizeof(int)*(sic-1);
	int w8 = sizeof(int)*(sic);
	int *a = malloc(w8);
	int *b = malloc(w8);
	if(a != NULL && b != NULL){
		memcpy(a, args, w7);
		memcpy(b, rems, w7);
	}
	else{
		//memory allocation fails
		return -1;
	}

	if (ing < 1){
		//providing the sentinel value for end of array
		a[sic-1] = 0x00;
		b[sic-1] = 0x00;
		args = realloc(a, w8);
		rems = realloc(b, w8);
		return arg1;
	}
	else{
		//modifying the factor array
		a[sic-1] = soc;
		b[sic-1] = ing;
		args = realloc(a, w8);
		rems = realloc(b, w8);
		return e_algo(arg2, ing, sic+1);
	}
}

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("Need two arguments, man.\n");
		exit(1);
	}
	printf("Eucalidean Algorithm result: %d\n", e_algo(atoi(argv[1]),atoi(argv[2]), 1));
	int t = 0;
	while((args[t] != '\0') && (rems[t] != '\0')){
		printf("%d\t%d\n", args[t], rems[t]);
		t++;
	}
	int *u = traceback(1, 1, t-2);
	printf("Multiplicative Inverse result: %d\t%d\n", u[0], u[1]);
	exit(0);
}
