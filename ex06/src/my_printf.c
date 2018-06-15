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
   while( format[++( *curr_pos)] > '0' && format[*curr_pos] <= '9')
   {
      res = res * 10 + (int)format[*curr_pos] - (int)'0';
   }
   return res;
}

void char_out( char *arg, int padding_, const char ch)
{

                int arg_size;
                for (int i = 0, arg_size = 0; *(arg + i) != '\0'; ++i, arg_size++);

                if( arg_size > padding_) padding_ = arg_size;
                char * out = malloc(padding_ - arg_size);
                memset( out, ch, sizeof(out) );
//              strcpy( out + padding_ - arg_size, arg); //чет якась хуйня
                write( 1, out, sizeof(out) );
                write( 1, arg, arg_size );
}

void int_out( int arg, int padding_, const char ch)
{
                int arg_size = my_strlen( my_itoa( arg));

                if (arg_size > padding_)
                padding_ = arg_size;

                char arr[padding_];


                strcpy(arr, my_itoa( arg));
                memset( arr + arg_size, ch, padding_ - arg_size);
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
                char_out ( arg, 0, ' ');
                check_null = false;
                break;
              }

              case '%':
              {
                write( 1, format + i, 1);
                break;
              }
              case '0':
              {
                continue;
                break;
              }
              default:
              {
                int padding_ = padding(format, &i);

                if(format[i] == 's')
                {
                  char *arg = va_arg( arg_, char *);
                  char_out(arg, padding_, ' ');
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
int main (){
  my_printf("%s\n", "Hello Printf");
  my_printf("We need 100%% of %s\n", "use case");
  my_printf("It's %s's %s (%s)\n", "iGor", "phone", "TEXT");
  my_printf("[%10s] [%4s] [%8s] [%12s]\n", "THIS", "IS", "PADDED", "TEXT");

  printf("%s\n", "Hello Printf");
  printf("We need 100%% of %s\n", "use case");
  printf("It's %s's %s (%s)\n", "iGor", "phone", "TEXT");
  printf("[%10s] [%4s] [%8s] [%12s]\n", "THIS", "IS", "PADDED", "TEXT");

  return 0;
}

