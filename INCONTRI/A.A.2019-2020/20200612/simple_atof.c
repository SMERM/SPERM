
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double simple_atof(const char*str)
{
  double result=0.0;
  /*da fare a casa*/
  return result;
}

int main () {
   float val;
   char str[20];

   strcpy(str, "98993489");
   val = simple_atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   strcpy(str, "3.1459e-4");
   val = simple_atof(str);
   printf("String value = %s, Float value = %12.10f\n", str, val);

   strcpy(str, "3.1459E-4");
   val = simple_atof(str);
   printf("String value = %s, Float value = %12.10f\n", str, val);

   strcpy(str, " \t\n3.1459");
   val = simple_atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   strcpy(str, "3ciao.34");
   val = simple_atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   strcpy(str, "3.1459eciao");
   val = simple_atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   strcpy(str, "sbagliato");
   val = simple_atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   return(0);
}
