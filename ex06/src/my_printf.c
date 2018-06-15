#include <stdarg.h>

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "itoa.h"
#include "strcpy.h"

typedef int bool;
#define true 1
#define false 0
#define EOF (-1)

int my_printf(const char *format, ...);

int padding(const char *format, int *curr_pos )
{
   int res = 0;
   while( format[ *curr_pos] >= '0' && format[ *curr_pos] <= '9')
   {
      res = res * 10 + (int)format[*curr_pos] - (int)'0';
      ++(*curr_pos);
   }
   return res;
}

void char_out( char *arg, int padding_)
{

                int arg_size = 0;
                for (int i = 0 ; *(arg + i) != '\0'; ++i)
                {
                  arg_size++;
                }
                //printf("%d", padding_);
                if( arg_size > padding_) padding_ = arg_size;
                char * out = malloc( (padding_ - arg_size) * sizeof(char *));
                memset( out, ' ', sizeof(char *) * (padding_ - arg_size) );
                write( 1, out, padding_ - arg_size);
                write( 1, arg, arg_size );
}

void int_out( int arg, int padding_, const char ch)
{
                int arg_size = my_strlen( my_itoa( arg));

                if (arg_size > padding_)
                padding_ = arg_size;

                char arr[padding_];

                memset( arr, ch, padding_ - arg_size);
                strcpy(arr + padding_ - arg_size, my_itoa( arg));
                write ( 1, arr, padding_);
}

int my_printf(const char *format, ...)
{
   int arg_count, format_size = strlen(format);
   va_list arg_;
   va_start( arg_, format);
   bool check_null = false;
   for(int i = 0; i < format_size; ++i)
   {
      if (format[i] == '%' && format[i + 1] == '0')
      {
          check_null = true;
      }
      if (format[i] == '%')
      {
          switch( format[++i])
          {
              case 'd':
              {
                int arg = va_arg( arg_, int);
                int_out( arg, 0, ' ');
                break;
              }

              case 's':
              {
                char * arg = va_arg(  arg_, char *);
                char_out ( arg, 0);
                check_null = false;
                break;
              }

              case '%':
              {
                write( 1, format + i, 1);
                break;
              }
              default:
              {
                int padding_ = padding(format, &i);
                if(format[i] == 's')
                {
                  char *arg = va_arg( arg_, char *);
                  char_out(arg, padding_);
                }

                else if(format[i] == 'd')
                {
                  int arg = va_arg( arg_, int);
                  if( check_null)
                    int_out(arg, padding_, '0');
                  else
                    int_out(arg, padding_, ' ');
                }
                check_null = false;
                break;
              }
          }
      }
      else
      {
        write(1, format + i, 1);
      }
   }

  va_end( arg_ );
  return 0;
}
