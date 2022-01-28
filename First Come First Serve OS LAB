#include <stdio.h>

int main ()
{

  int no_of_problems;
  printf ("Enter total number of processes\n");
  scanf ("%d", &no_of_problems);

  static int time = 0;

  int *arrival_time = (int *) malloc (no_of_problems * sizeof (int));
  int *burst_time = (int *) malloc (no_of_problems * sizeof (int));
  int *completion_time = (int *) malloc (no_of_problems * sizeof (int));
  int *turn_around_time = (int *) malloc (no_of_problems * sizeof (int));
  int *waiting_time = (int *) malloc (no_of_problems * sizeof (int));

  for (int i = 0; i < no_of_problems; i++)
    {
      printf ("\n Enter arrival time of %dst process : ", (i + 1));
      scanf ("%d", &arrival_time[i]);
      printf ("\n Enter burst time of %dst process : ", (i + 1));
      scanf ("%d", &burst_time[i]);
    }

  completion_time[0] = burst_time[0];
  turn_around_time[0] = completion_time[0];
  waiting_time[0] = 0;

  for (int i = 1; i < no_of_problems; i++)
    {
      time = time + burst_time[i - 1];
      completion_time[i] = time + burst_time[i];
      turn_around_time[i] = completion_time[i] - arrival_time[i];
      waiting_time[i] = turn_around_time[i] - burst_time[i];
    }

  for (int i = 0; i < no_of_problems; i++)
    {
      printf ("\n\n\n");
      printf ("Waiting Time of process %d = %d\n", (i + 1),
	      waiting_time[i]);
      printf ("Completion Time of process %d = %d\n", (i + 1),
	      completion_time[i]);
      printf ("Turn Around Time of process %d = %d\n", (i + 1),
	      turn_around_time[i]);
    }
  printf("\n\n\n\nTotal Execution Time = %d",time);
  return 0;
}
