#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main (int argc, char **argv)
{
  //First line of the code
  printf("       +------+------+------+------+------+------+------+ FFFFFFFF\n");

  //Save the address of the first element to put into argv
  char firstEle[32];
  sprintf(firstEle, "%p", &argv[1]);
  
  //Creating the map before arguments' content address
  for ( int i=0; i<2; i++)
    printf("       +------+------+------+------+------+------+------+\n");

  //Creating string of all the arguments
  int len = argc-1;
  for (int i=1; i<argc; i++)
    len += strlen(argv[i]);
  char words[len];
  strcpy(words, argv[1]);
  strcat(words, "/");
  for (int i=2; i<argc; i++)
    {
      strcat(words, argv[i]);
      strcat(words, "/");
    }
  
  //Rows for the map
  int row = len/7;
  int row2 = len/7;
  
  //Columns not empty at top row and columns remaining
  int col = len%7;
  int rem = 7-col;
  
  //Populating the map
  int curpos = len-1;
  
  for (int i=row; i>=0; i--)
    {
      printf("       +------+------+------+------+------+------+------+\n");
      printf("       ");
      if (col != 0)
	{
	  for (int i=0; i<rem; i++)
	    {
	      printf("|  --  ");
	    }
	  for (int i=1; i<=col; i++)
	    {
		if (words[curpos] == '/')
		{
		  printf("|  00  ");
		}
	      else
		printf("|  %x  ", words[curpos]);
	      curpos--;
	    }
	  col=0;
	}
      else
	{
	  for (int i=0; i<7; i++)
	    {
	      if (words[curpos] == '/')
		{
		  printf("|  00  ");
		}
	      else
		printf("|  %x  ", words[curpos]);
		curpos--;
	    }
	}
      if (row == 1 && rem == 7)
	    {
	      char buf[128];
	      sprintf(buf, "%p",&argv[1][0]);
	      printf("| %s\n",buf);
	      break;
	    }
      else if (i==1 && rem == 7)
	{
	   char buf[128];
	      sprintf(buf, "%p",&argv[1][0]);
	      printf("| %s\n",buf);
	      break;
	    }
      else if (i==0)
	    {
	      char buf[128];
	      sprintf(buf, "%p",&argv[1][0]);
	      printf("| %s\n",buf);
	    }
      
	  else
	    printf("|\n");
	  
    }
   //The few lines between the argv elements and argv/argc
  for (int i=0; i<4; i++)
    printf("       +------+------+------+------+------+------+------+ \n");

       
  //Creating the argv+# thing
  for ( int i=argc-1; i>0; i--)
    {
      printf("       +------+------+------+------+------+------+------+\n");
      printf("argv+");
      printf("%d ", i-1);
      char addr[32];
      sprintf(addr, "%p", &argv[i][0]);

      //Addresses being put in the boxes
      for (int i=0; i<(strlen(addr)-1); i+=2)
	{
	  printf("|  %c%c  ",addr[i],addr[i+1]);
	}
      printf("| ");

      char buf[128];
      sprintf(buf, "%p",&argv[i]);
      printf("%s\n", buf);
    }

  //The few lines between the argv elements and argv/argc
  for (int i=0; i<4; i++)
    printf("       +------+------+------+------+------+------+------+ \n");

  //argv map
  printf("argv   ");
  for (int i=0; i<(strlen(firstEle)-1); i+=2)
    {
      printf("|  %c%c  ",firstEle[i],firstEle[i+1]);
    }
  printf("| ");
  printf("%p\n", (void*)&argv);

  //argc map
  printf("       +------+------+------+------+------+------+------+\n");
  printf("argc   |  00  |  00  |  00  |  00  |  00  |  00  |  ");
  
  if ( argc < 10)
    {
      printf("0");
      printf("%d  | ", argc-1);
    }
  else
    printf("%d  | ", argc-1);
  
  printf("%p\n", (void*)&argc);

  //Finishing up the map
  for (int i=0; i<4; i++)
    printf("       +------+------+------+------+------+------+------+ \n");

  printf("       +------+------+------+------+------+------+------+ 00000000000000\n");
  return 0;
    }
