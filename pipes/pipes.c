static void forkSort(int* parentNums, int size, int write_fd)
{
  int fd[2];
  printf("PPid:%ld Pid:%ld Size:%d\n", (long)getppid(), (long)getpid(), size);
  int childNums[size/2], left, right;
  if(size <= 100) //Send sorted array to parent thru pipe
    {
      qsort(parentNums, size, sizeof(int), compare);
      write(write_fd, parentNums, size*sizeof(int));
      exit(0);
    }
  if (pipe(fd)==-1){perror("Failed");}

  printf("Creating child processes...\n");
  size /= 2;

  if(!(left = tryFork()) || !(right = tryFork())) //Children
  {
      if(left)    copy(childNums, parentNums, size);
      else        copy(childNums, parentNums + size, size);
      forkSort(childNums, size, fd[1]);
  }

  /* parent */
  int first[size], second[size], combined[size*2];
  read(fd[0], first, sizeof(first));
  read(fd[0], second, sizeof(second));
  printf("\n\nMerge sorting...  Size:%d\n", size*2);
  mergeSort(first, second, combined, size);
  if(size*2 == SIZE) { //Finished, write to out.dat
    printf("\nFinished!!! (%d)\n\n", size * 2);
    printArray(combined, SIZE);
  }
  else {
    write(write_fd, combined, sizeof(combined));
    exit(0);
  }
}