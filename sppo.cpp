#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>
int N = 100000;
int M = 500000;

static int delta_time(const _timeb &t1, const _timeb &t2)
{
  return (int) ((t2.time - t1.time) * 1000 
             + ((int) t2.millitm) - ((int) t1.millitm));
}

using namespace std;

static int test_fprintf()
{
  _timeb time0;
  _timeb time1;
  
  FILE* t = fopen("test_fprintf.txt","wt");
  
  _ftime(&time0);

  for (int i=0; i<M; i++)
    fprintf(t,"%i %i %i %i\n",i*4,i*4+1,i*4+2,i*4+3);

  _ftime(&time1);
  
  fclose(t);
  return delta_time(time0,time1);
}

static int test_ofstream()
{
  _timeb time0;
  _timeb time1;
  
  ofstream outfile("test_ofstream.txt");
  
  _ftime(&time0);

  for (int i=0; i<N; i++)
    outfile << i*4 << ' '<< i*4+1<< ' ' << i*4+2<< ' ' << i*4+3 << '\n';

  _ftime(&time1);
  
  outfile.close();
  return delta_time(time0,time1);
}

static int test_ifstream()
{
  _timeb time0;
  _timeb time1;
  
  ifstream infile("test_ofstream.txt");
  
  _ftime(&time0);

  int x1,x2,x3,x4;

  for (int i=0; i<N; i++){
    infile >> x1 >> x2 >> x3 >> x4;
    //printf("%i %i %i %i\n",x1,x2,x3,x4);
    }

  _ftime(&time1);
  
  infile.close();
  return delta_time(time0,time1);
}

static int test_fscanf()
{
  _timeb time0;
  _timeb time1;
  
  FILE* t = fopen("test_fprintf.txt","rt");
  
  _ftime(&time0);

  int x1,x2,x3,x4;

  for (int i=0; i<M; i++){
    fscanf(t,"%i %i %i %i\n",&x1,&x2,&x3,&x4);
    //printf("%i %i %i %i\n",x1,x2,x3,x4);
    }

  _ftime(&time1);
  
  fclose(t);
  return delta_time(time0,time1);
}

static long filesize(FILE *stream)
{
  const long curpos = ftell(stream);
  fseek(stream, 0L, SEEK_END);
  const long length = ftell(stream);
  fseek(stream, curpos, SEEK_SET);
  return length;
}

static int test_fread()
{
  _timeb time0;
  _timeb time1;
  
  FILE* b = fopen("test_fprintf.txt","rb");
  const long size = filesize(b);

  char* buf = new char[size];

  _ftime(&time0);

  const int N = (int) fread(buf,1,size,b);

  _ftime(&time1);
  
  fclose(b);
  delete [] buf;
  return delta_time(time0,time1);
}

int main(int argc, char* argv[])
{
  const int dt_fprintf = test_fprintf();
  printf( "\ntest_fprintf takes %i milliseconds\n", dt_fprintf);
  
  const int dt_ofstream = test_ofstream();
  printf( "\ntest_ofstream takes %i milliseconds\n", dt_ofstream);
  
  const int dt_ifstream = test_ifstream();
  printf( "\ntest_ifstream takes %i milliseconds\n", dt_ifstream);
  
  const int dt_fscanf = test_fscanf();
  printf( "\ntest_fscanf takes %i milliseconds\n", dt_fscanf);
  
  const int dt_fread = test_fread();
  printf( "\ntest_fread takes %i milliseconds\n", dt_fread);
  
  getch();
  return 0;
}
