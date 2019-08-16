#include <windows.h>
#include <stdio.h>
main()
{
      int i;
      SetConsoleTextAttribute
      (
        GetStdHandle(STD_OUTPUT_HANDLE),
        BACKGROUND_BLUE |
        FOREGROUND_INTENSITY |
        FOREGROUND_RED |
        FOREGROUND_GREEN |
        FOREGROUND_BLUE
      );

      printf("TESTE MODIFICANDO FOREGROUND E BACKGROUND\n");

      for(i=0;i<=255;i++)
      {
         SetConsoleTextAttribute
         (
            GetStdHandle(STD_OUTPUT_HANDLE),
            i
         );

         printf("teste %03d\n",i);
      }

      for(;;) ;
}
