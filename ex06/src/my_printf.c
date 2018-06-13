#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0
#define EOF (-1)

int my_strlen(const char *str){
  int i = 0;
  for (i = 0; str[i] != '\0'; ++i){
}
return i;
}

int check_flag(char flag){
  int type_name;
  if ( flag == 's' )      type_name = 1;
  else if ( flag == 'd' ) type_name = 2;
  else                    type_name = 0;
  return type_name;
}

int my_printf(const char *format, ...)
{
  int arg_count = 100, format_Size = my_strlen(format) - 1;  // костиль, нада fix
  va_list arg_;

  va_start( arg_, arg_count );
  for(int i = 0; i < format_Size; ++i){
    if ( format[i] == '%' )
    {
      if ( !check_flag(format[i + 1]) )
      {
        if ( check_flag(format[i + 1]) == 1 )
        {
          char *out = malloc( strlen( va_arg( arg_, char *)));
          out = va_arg( arg_, char *);
          write( 1, out, sizeof(char *) * my_strlen(out));
        }
        if ( check_flag(format[i + 1]) == 2 )
        {
          double out = va_arg( arg_, double);
          write( 1, &out, sizeof(double) );
        }
        else
        {
          if (format[i + 1] == '%')
          {
            write( 1, *(format + i), 1);
          }
          else
          {
            write( 1, *(format + i), 2);
            i++;
          }
        }
      }
    }
    else
    {
      write( 1, *(format + i), 1);
    }
  }
  va_end( arg_ );
  return 0;
}















