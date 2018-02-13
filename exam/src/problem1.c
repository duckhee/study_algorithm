/*
 * problem1.c
 *
 *  Created on: 2018. 2. 9.
 *      Author: CANDH
 *      탐욕알고리즘 문제
 */


#include <stdio.h>

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"
#define MAX_N       1000
#define MAX_WEIGHT  10000
#define MAX_VALUE   (50000 * MAX_WEIGHT)

int T, E, F, N;
int P[MAX_N], W[MAX_N];
int S[MAX_WEIGHT];
FILE *inf, *outf;

void input_data(void)
{
	int i;
	fscanf(inf, "%d %d\n", &E, &F);
	fscanf(inf, "%d\n", &N);

	for(i = 0; i < N; i++)
	{
		fscanf(inf, "%d %d\n", &P[i], &W[i]);
	}

}

void initialize_S(void)
{
	int i;
	S[0] = 0;

	for(i = 0; i <= F - E; i++)
	{
		S[i] = MAX_VALUE;
	}
}

void solve(void)
{
	int i, j;
	initialize_S();

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < F- E -W[i]; j++)
		{
			if(S[j]+P[i] < S[j + W[i]])
			{
				S[j+W[i]] = S[j] + P[i];
			}
		}
	}
}

void output_result(void)
{
	if(S[F-E] == MAX_VALUE)
	{
		fprintf(outf, "-1\n");
	}else
	{
		fprintf(outf, "스마트폰의 최소 실행시간 : %d\n", S[F-E]);
	}
}

void main()
{
	int i;
	inf = fopen(INPUT_FILE, "r");
	outf = fopen(OUTPUT_FILE, "w");
	fscanf(inf, "%d\n", &T);

	for(i = 0; i < T; i++)
	{
		input_data();
		solve();
		output_result();

	}

	fclose(inf);
	fclose(outf);
}
