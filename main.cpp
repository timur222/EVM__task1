#include "Func.h"

double mach_eps(void);
double mach_eps(void)
{
	double eps = 1.0;

	while (1.0 + eps / 2.0 > 1.0)
	{
		eps /= 2.0;
	}
	return eps;
} // машинное эпсилон

int main(int argc, char* argv[])
{
	if(argc<4){
		printf("Incorrect input\n");
                return -1;
	}

	int n = atoi(argv[1]), m = atoi(argv[2]), k = atoi(argv[3]), prob, ans;
	double* MultInd;
	double start, end, ForNorm;
	double Norm=0.0;


	if (n == 0 || n < m) {
		printf("Incorrect input\n");
		return -1;
	}

	if ((k < 0) || (k > 4)) {
		printf("Incorrect input\n");
		return -1;
	}

	double* Matrix = (double*)malloc(n * n * (sizeof(double)));;

	if (Matrix == NULL)
	{
		printf("No memory allocated\n");
		free(Matrix);
		return -1;
	}
	if ((argc == 5) && (k == 0)) {		
		prob = Input(Matrix, argv[4], n, &Norm);
		if (prob == -1) {
			printf("File don't exist\n");
			free(Matrix);
			return -1;
		}
		if (prob == -2)
		{
			printf("Insufficient data \n");
			free(Matrix);
			return -1;
		}
	}
	if((argc!=5)&&(k==0))
	{
		printf("File don't exist\n");
		return -1;
	}
	if(k>0){
		for(int i=0; i<n ; i++){
			ForNorm=0;
			for(int j=0; j<n; j++){
				Matrix[i*n+j]=generate(k, n, i, j);
				ForNorm+=abs(generate(k, n, i, j));
			}
			if(ForNorm>Norm){Norm=ForNorm;}
		}
	}
	//      }
	//}

	double* InvMatrix = (double*)malloc(n * n * (sizeof(double)));;
	int* swap = (int*)malloc(n *  (sizeof(int)));;
	if (InvMatrix == NULL)
	{
		printf("No memory allocated\n");
		free(Matrix);
		free(swap);
		free(InvMatrix);
		return -1;
	}
	for (prob = 0; prob < n; prob++) { InvMatrix[prob * n + prob] = 1; }
	//инициализация и заполнение

	//решение
	printf("Matrix : \n");
	POut(Matrix, n, n, m);
	printf("\n");
	printf("%e \n \n", Norm);
	Norm = 1 / Norm;
	for (int i = 0; i < n; i++)
	{
		MultInd = Matrix + i * n;
		for (int j = 0; j < n; j++)
		{
			MultInd[j] = MultInd[j] * (Norm);
		}
	}
	start = clock();
	ans = Gauss(Matrix, InvMatrix, swap, n);
	end = clock();
	start = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time; %f \n", start);
	if (ans == -2) {
		printf("Degenerate matrix");
		free(Matrix);
		free(swap);
		free(InvMatrix);
		return -1;
	}


	for (int i = 0; i < n; i++)
	{
		MultInd = InvMatrix + i * n;
		for (int j = 0; j < n; j++)
		{
			MultInd[j] = MultInd[j] * (Norm);
		}
	}
	printf("Inverse Matrix: \n");
	POut(InvMatrix, m, n, m);

	//printf("Matrix : \n");
        //POut(Matrix, n, n, m);
        //printf("\n");

	if ((argc == 5) && (k == 0)) {
		prob = Input(Matrix, argv[4], n, &Norm);
		if (prob == -1) {
			printf("File not found\n");
			free(Matrix);
			free(swap);
			free(InvMatrix);
			return -1;
		}
		if (prob == -2)
		{
			printf("Insufficient data \n");
			free(Matrix);
			free(swap);
			free(InvMatrix);
			return -1;
		}
	}

	if(k>0){
                for(int i=0; i<n ; i++){
                	for(int j=0; j<n; j++){
                        	Matrix[i*n+j]=generate(k, n, i, j);
                	}
                }
        }


	printf("Error norm : %e\n", NormSol(Matrix, InvMatrix, n));

	free(Matrix);
	free(InvMatrix);
	free(swap);
	return 0;
}
