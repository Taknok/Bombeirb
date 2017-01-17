#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

int main()
{
    int i;
    
    FILE * fo;
    fo = fopen ("test-sortie.txt", "w+");
    fputs("a", fo);
    fputs(" ",fo);
    fputs("b", fo);
    fputs("c", fo);
    fclose(fo);
}
