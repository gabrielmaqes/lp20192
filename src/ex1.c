#include <stdio.h>

float min (float a, float b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main (void) {
    float n1, n2, n3, n4;
    printf ("Entre com 3 notas:");
    scanf ("%f %f %f", &n1,&n2,&n3);
    float media = (n1+n2+n3) / 3;
    printf ("media eh %g\n", media);
    if (media >= 7){
        printf ("Aprovado e Boas ferias\n");
    } else {
        printf ("Reposicao:");
        scanf ("%f",&n4);
        float menor = min (min (min (n1, n2), n3), n4);
        media = (n1 + n2 + n3 + n4 - menor) / 3;
        printf ("nova media eh %g\n", media);
        if (media >= 7) {
            printf ("Aprovado e Boas ferias\n");
        } else if (media < 2) { // nao tem media suficiente
            printf ("so sorry\n");
        } else { // final
            float nf;
            printf ("Nota final:");
            scanf ("%f",&nf);
            media = ( media + nf ) / 2;
            printf ("nova media eh %g\n", media);
            if (media >= 6) {
                printf ("Aprovado e Boas ferias\n");
            } else {
                printf ("so sorry\n");
            }
        }
    }    
    return 0;
}