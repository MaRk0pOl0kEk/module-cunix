#include <stdarg.h>
#include <unistd.h>
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
  switch( flag ) {
    case '0':
      type_name = 0;
      break;
    case 's':
      type_name = 1;
      break;
    case 'd':
      type_name = 2;
      break;
    case '-':
      type_name = 3;
      break;
    case '%':
      type_name = 4;
      break;
    default:
      type_name = -1;
      break;
  }
  return type_name;
}

int my_printf(const char *format, ...)
{
  int arg_count, format_Size = my_strlen(format) - 1;
  va_list arg_;

  va_start( arg_, format );
  for(int i = 0; i < format_Size; ++i)
  {

    int padding;
    char *buf = malloc(sizeof(const char *) * (my_strlen(format) + 1));


    if ( check_flag( format[i]) == 4 )
    {

        if ( check_flag( format[i + 1]) == 0 )
        {
           int begin = 0;
           while( check_flag(format[++i]) == 0 && i < format_Size )
           {
             buf[begin] = format[i];
             begin++;
           }
           buf[i] = '\0';
           --i;
           padding = 1;
        }


        else if ( check_flag( format[i + 1]) == 1)
        {
          char *out = malloc( strlen( va_arg( arg_, char *)));
          out = va_arg( arg_, char *);
          write( 1, out, sizeof(char *) * my_strlen(out));
        }


        else if ( check_flag( format[i + 1]) == 2 )
        {
          double out = va_arg( arg_, double);
          write( 1, &out, sizeof(double) );
        }


        else if ( check_flag( format[i + 1]) == 3)
        {
          int begin = 0;
          while ( (check_flag( format[++i]) == 3 || check_flag( format[i]) == 0) && i < format_Size );
          padding = 0;
          --i;
        }


        else if ( check_flag( format[++i]) == 4 )
        {
          write( 1, format + i, 1);
        }


        else
        {
            write( 1, format + i, 2);
            i++;
        }
    }


    else
    {
      write( 1, format + i, 1);
    }

    if (padding == 0)
    {
      free( buf );
      buf = malloc( sizeof(char*) * 2);
      buf[0] = '-';
      buf[1] = '\0';
    }
    else if (padding == 1)
    {
      bool check = false;

      for (int count = 0; count < strlen(buf); ++count)
      {
        if(buf[count] == '-')
        {
          check = true;
          break;
        }
      }

      if (check)
      {
        free(buf);
        buf = malloc(sizeof(char) * 2);
        buf[0] = '-';
        buf[1] = '\0';
      }

      else
      {
        if ( check_flag( format[i + 1]) == -1 || check_flag( format[i + 1] == 4)
        {
          
        }
      }
    }

  }
  va_end( arg_ );
  char n = '\n';
  write(1, &n, 1);
  return 0;
}















