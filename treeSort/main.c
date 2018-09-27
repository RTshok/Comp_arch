#include "tree_sort.h"
#include <stdbool.h>
#include <time.h>

/**
 * timespec_diff() - returns time difference in milliseconds for two timespecs.
 * @stop:	time after event.
 * @start:	time before event.
 *
 * Uses difftime() for time_t seconds calcultation.
 */
double timespec_diff(struct timespec *stop, struct timespec *start)
{
	double diff = difftime(stop->tv_sec, start->tv_sec);
	diff *= 1000;
	diff += (stop->tv_nsec - start->tv_nsec) / 1e6;
	return diff;
}
int main(int argc, char *argv[])
{
	int *items;
	int amount;
	char * file_name;
/* Parse arguments */
	if (argc == 1) goto exc_noargs;
	if (argc > 1){
		file_name = malloc(strlen(argv[1])*sizeof(*file_name));
		strcpy(file_name,argv[1]);
		if(file_name == NULL)
			goto exc_malloc;
	}
	if(argc == 3){
		amount = atoi(argv[2]);
		items = malloc(amount*sizeof(*items));
		if(items == NULL)
			goto exc_noargs;
	}
	if (argc > 4) goto exc_argtoomuch;

	FILE *file,*fp_rand;
	file = fopen (file_name,"w");
	fprintf(file,"#AmountOfElements,N\t\t#TimeOfSorting,ms");

/* Initialize pseudo-random generator with truly random number */
	if ((fp_rand = fopen("/dev/random", "rb")) == NULL) goto exc_fopen;
	unsigned int seed;
	fread(&seed, sizeof(seed), 1, fp_rand);
	if (ferror(fp_rand)) goto exc_fread;
	fclose(fp_rand);
	srand(seed);
	int *array;
 	double time=0;
	double whole_sort_time = 0;	
for (int i=0; i < amount;i++)
{		
	items[i] = (i*i*i*amount+amount)*3;//generating the size of future array;
	/* Fill array with random numbers */
	array = malloc(items[i]*sizeof(*array));
	if (array == NULL) goto exc_malloc;
	unsigned int cnt;
	for (cnt = 0; cnt < items[i]; cnt++)
		array[cnt] = rand();

	/* Sort array */
	struct timespec time_now, time_after;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_now);
	tree_sort(array,items[i]);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_after);
	/* Gets the time of sorting */
	time = timespec_diff(&time_after, &time_now);
	fprintf(file,"\n%d\t\t\t\t\t%g",items[i],time);
	/* Calculates whole sorting time */
	whole_sort_time += time ;
	free(array);

}
	printf("%d arrays have been sorted for %g,ms using %s flag",amount,whole_sort_time,file_name);
	free(items);
	free(file_name);
	fclose(file);
	printf("\nall data have been deleted\n");
	return 0;

	/* Exception handling */
	exc_noargs:
	printf("Error: no arguments provided\n");
	goto exc_usage;

	exc_argunknown:
	printf("Error: unknown argument (%s)\n", argv[2]);
	goto exc_usage;

	exc_argtoomuch:
	printf("Error: too much arguments\n");
	/* Notice: no goto here */

	exc_usage:
	printf("Usage:\n%s <Name_of_File> <Amount of Arrays>\n", argv[0]);
	return 1;

	exc_fopen:
	printf("Error: could not open /dev/random\n");
	return 1;

	exc_fread:
	printf("Error: read I/O mismatch\n");
	fclose(fp_rand);
	return 1;

	exc_malloc:
	printf("Error: could not allocate array\n");
	free(array);
	return 1;
}