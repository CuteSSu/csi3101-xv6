#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int my_atoi(const char *str) {
   int result = 0;
   int sign = 1;

   if (*str == '-') {
      sign = -1;
      str++;
   } else if (*str == '+') {
      str++;
   }
 
   while (*str >= '0' && *str <= '9') {
      result = result * 10 + (*str - '0');
      str++;
   }

   return sign * result;
}

int
main(int argc, char *argv[])
{
  int value;
  if(argc < 2){
    printf(2,"Usage: nice value\n");
    exit();
  }

  value = my_atoi(argv[1]);
  
  nice(value);

  exit();
}

