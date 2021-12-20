#include "Func.h"


int Gauss(double* Matrix, double* InvMatrix, int* swap, int n){


        double eps = 1.0;
        while (1.0 + eps/ 2.0 > 1.0)
        {
                eps /= 2.0;
        }
        //int IntSwap;
        eps=eps*1000;

        double max;
        int maxJ;
        double prob;
        double Del, BigDel;
        int k;
        double* MultInd;
	double* MultInd2;
        //double* MultInd1;
        //int* swap= (int *)malloc(n*(sizeof(int)));
        // определение переменных
	
	for(int i=0; i<n; i++){swap[i]=i;}

        for(int i=0; i<n; i++){
                //swap[i]=i;
                max=0;
                // поиск максимального по строчке
                MultInd= Matrix+i*n;
                maxJ=i;
                for(int j=i; j<n; j++){
                        if(fabs(max)<fabs(MultInd[j])){
                                max=MultInd[j];
                                maxJ=j;
                        }
                }
                if(fabs(MultInd[maxJ])<eps){
                        return -2;
                }
                // поиск максимального по строчке
                //меняем столбцы
                for(k=0; k<n; k++){
                        prob=Matrix[k*n+i];
                        Matrix[k*n+i]=Matrix[k*n+maxJ];
                        Matrix[k*n+maxJ]=prob;

                }
		k=swap[i];
		swap[i]=swap[maxJ];
		swap[maxJ]=k;
                //меняем столбцы
		BigDel=Matrix[i*n+i];

		//printf("Matrix' : \n");
        	//POut(Matrix, n, n, n);
        	//printf("\n");
		
                // диагонализируем
                for(k=i; (k<n); k++){
                        if(k!=i){
                                Del = Matrix[n*k+i]/BigDel;
                                if(eps<fabs(Del)){
                                        for(int t=0; t<n; t++){
                                                Matrix[k*n+t]=Matrix[k*n+t]-Del*Matrix[i*n+t];
                                                InvMatrix[k*n+t]=InvMatrix[k*n+t]-Del*InvMatrix[i*n+t];
						//printf("Matrix''' : \n");
                				//POut(Matrix, n, n, n);
                				//printf("\n");
                                        }
                                }
                        }
                }

                // диагонализируем
        }
	//return 0;
	//printf("Hi \n");
	for(k=n-1; k>-1; k--){
                MultInd2=InvMatrix+k*n;
                MultInd=Matrix+k*n;
		for(int i=0; i<n; i++){
			Del=0;
			for(int j=k+1; j<n; j++){
                        	Del+=MultInd[j]*InvMatrix[j*n+i];
                        	//printf("Hi2");
                	}
			//printf("Hi1 \n");
			MultInd2[i]=(MultInd2[i]-Del)/Matrix[k*n+k];
			
		}
        }
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(swap[j]==i){
				swap[j]=swap[i];
				swap[i]=i;
				MultInd=InvMatrix+j*n;
				MultInd2=InvMatrix+i*n;
				for(int t=0; t<n; t++){
                                	Del=MultInd[t];
                                	MultInd[t]=MultInd2[t];
                                	MultInd2[t]=Del;
                        	}
			}
		}
	}

        return 0;
}


