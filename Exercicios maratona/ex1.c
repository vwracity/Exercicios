#include <stdio.h>
#include <math.h>

int main(){

    int L, C, resultado;
    float L1;

    scanf("%d %d", &L, &C);

    L1 = L;

    if(L%2==0) resultado = L/2;
    
    else resultado = ceil(L1/2.0);

    C = ceil(C/2.0);

    printf("%d", resultado*C);

    return 0;
}