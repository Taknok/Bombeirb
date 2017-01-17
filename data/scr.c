#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main()
{
    int width, height;
    int k;
    int map;
    char str1[3], str2[3], str3[3];
    char out[3], hex_val[1];
    FILE * fr;
    FILE * fo;
    
   fr = fopen ("test.txt", "r+");
   fo = fopen ("test-sortie.txt", "w+");
   
   rewind(fr); //back to beginning of file
   fscanf(fr, "%i:%i", &width, &height);
   
   k = width * height;

   int i;
   for(i=0; i < k;i++){
       fscanf(fr, "%s", str1);

       if (0 == strcmp(str1,"Pl1")){ //PLAYER1
	   strcpy(out,"02");
       } else if ( 0 == strcmp(str1,"Pri")){
	   strcpy(out,"03");
       } else if ( 0 == strcmp(str1,"emp")){
	   strcpy(out,"00");
       } else if ( 0 == strcmp(str1,"tre")){
	   strcpy(out,"01");
       } else if ( 0 == strcmp(str1,"sto")){
	   strcpy(out,"11");
       } else if ( 0 == strcmp(str1,"bem")){
	   strcpy(out,"04");
       } else if ( 0 == strcmp(str1,"b+l")){
	   strcpy(out,"64");
       } else if ( 0 == strcmp(str1,"b+m")){
	   strcpy(out,"54");
       } else if ( 0 == strcmp(str1,"b-p")){
	   strcpy(out,"14");
       } else if ( 0 == strcmp(str1,"b+p")){
	   strcpy(out,"24");
       } else if ( 0 == strcmp(str1,"b-n")){
	   strcpy(out,"34");
       } else if ( 0 == strcmp(str1,"b+n")){
	   strcpy(out,"44");
       } else if ( 0 == strcmp(str1,"do")){
	   fscanf(fr, "%i", &map);
	   snprintf(hex_val,2,"%0x",map+8);
	   char* s = concat(hex_val, "9");
	   strcpy(out,s);
	   free(s); //deallocate the string
       } else if ( 0 == strcmp(str1,"dc")){
	   char n_map[2];
	   fscanf(fr, "%s", n_map);
	   char* s = concat(n_map, "9");
	   strcpy(out,s);
	   free(s); //deallocate the string
       } else if ( 0 == strcmp(str1,"key")){
	   strcpy(out,"08");
       } else if ( 0 == strcmp(str1,"bom")){
	   strcpy(out,"07");
       } else if ( 0 == strcmp(str1,"mon")){
	   strcpy(out,"06");
       } else if ( 0 == strcmp(str1,"+li")){
	   strcpy(out,"65");
       } else if ( 0 == strcmp(str1,"-pb")){
	   strcpy(out,"15");
       } else if ( 0 == strcmp(str1,"+pb")){
	   strcpy(out,"25");
       } else if ( 0 == strcmp(str1,"-nb")){
	   strcpy(out,"45");
       } else if ( 0 == strcmp(str1,"+nb")){
	   strcpy(out,"35");
       } 
 
       fputs(out, fo);
       fputs(" ",fo);
   }

   fclose(fr);
   fclose(fo);
   
   return(0);
}
