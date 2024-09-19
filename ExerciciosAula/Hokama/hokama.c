#include <stdio.h>
#include <stdlib.h>

typedef struct pixel pixel;

struct pixel
{
    int R, G, B;
};

int main()
{
    int n, i, j, k, cor;
    char P3[3];

    printf("Insira a entrada:\n");
    scanf("%[^\n]", P3);
    scanf(" %d", &n);
    scanf(" %*d"); // ignorar o segundo número já que a matriz é quadrada
    scanf(" %d", &cor);

    // Alocação da matriz
    pixel **imagem = (pixel **)malloc(n * sizeof(pixel *));

    imagem[0] = (pixel *)malloc(n * n * sizeof(pixel));

    pixel **filtro = (pixel **)malloc(n * sizeof(pixel *));

    filtro[0] = (pixel *)malloc(n * n * sizeof(pixel));

    for (i = 1; i < n; i++)
    {
        imagem[i] = imagem[i - 1] + n;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf(" %d %d %d", &imagem[i][j].R, &imagem[i][j].G, &imagem[i][j].B); // Grava cada pixel da imagem
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf(" %d %d %d", &filtro[i][j].R, &filtro[i][j].G, &filtro[i][j].B); // Grava cada pixel do filtro
        }
    }

    // multiplicacao de matriz
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                imagem[i][j].R += imagem[i][k].R * filtro[k][j].R;
                imagem[i][j].G += imagem[i][k].G * filtro[k][j].G;
                imagem[i][j].B += imagem[i][k].B * filtro[k][j].B;
            }
        }
    }

    // Saida

    printf("%s\n", P3);
    printf("%d %d\n", n, n);
    printf("%d\n", cor);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" %d %d %d", imagem[i][j].R, imagem[i][j].G, imagem[i][j].B); // Grava cada pixel da imagem
        }
        printf("\n");
    }

    free(imagem[0]);
    free(imagem);

    free(filtro[0]);
    free(filtro);

    return 0;
}
