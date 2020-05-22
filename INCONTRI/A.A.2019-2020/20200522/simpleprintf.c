#include <stdio.h>
#include <stdarg.h>


int count_arg(const char *format)
{
  int result = 0 ;
  const char *p = format;
  while (*p != '\0')
  {
    if (*p == '%')
      result += 1;
    ++p;
  }
  return result;
}

void simple_printf(const char *format, ...)    /*modo per dichiarare argomenti variabili*/
{
  va_list l;
  int count = count_arg(format);
  int i = 0;
  va_start(l, format);
  for (i = 0; i < count; ++i)
  {
    /*COMPITO riempire come se riconosce solo gli int
    riconoscere dopo il percento*/
  }

}

int main()
{
  printf("%d\n",count_arg("test %d %d %d") );

}
