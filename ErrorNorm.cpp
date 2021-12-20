#include "Func.h"

double NormSol(double * Matrix, double* InvMatrix, int n)
{
        double shet, Norm=0, s=0;
	double* f;
        int i, j,  k;
        for(i=0; i<n; i++){
		shet=0;
                for(j=0; j<n; j++){
                  //      s=0;
			f=Matrix+i*n;
                        if(i==j){
				for(k=0; k<n; k++){
                                	s+=f[k]*InvMatrix[k*n+j];
                        	}
                                s=s-1;
                        }else{
				for(k=0; k<n; k++){
                                	s+=f[k]*InvMatrix[k*n+j];
                        	}
			}
			shet+=abs(s);
                }
		//if(Norm<abs(shet)){Norm=abs(shet);}
        }
        return s;
}
