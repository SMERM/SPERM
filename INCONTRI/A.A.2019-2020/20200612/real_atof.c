
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   float val;
   char str[20];

   strcpy(str, "98993489");
   val = atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   strcpy(str, "3.1459e-4");
   val = atof(str);
   printf("String value = %s, Float value = %12.10f\n", str, val);

   strcpy(str, "3.1459E-4");
   val = atof(str);
   printf("String value = %s, Float value = %12.10f\n", str, val);

   strcpy(str, " \t\n3.1459");
   val = atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   strcpy(str, "3.1459eciao");
   val = atof(str);
   printf("String value = %s, Float value = %f\n", str, val);



   strcpy(str, "sbagliato");
   val = atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   return(0);
}
