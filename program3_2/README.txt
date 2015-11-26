                Parent-Child Cooperation

Write a program, based on parent-child cooperation, which performs "parallel"
merge sort of a sequence of 800 integers.

These numbers will be stored in an input text file, the name of which your program
must ask the user to type in. 



Program should: 

    read 800 integers two children "f" - first ; "s" - second
                                       800p    
                     400f                                 400s
               200f        200s                    200f          200s
            100f  100s   100f  100s              100f  100s   100f  100s
sort 100s   sort  sort   sort  sort              sort  sort   sort  sort
pipe vals   pipe  pipe   pipe  pipe              pipe  pipe   pipe  pipe
exit child  exit  exit   exit  exit              exit  exit   exit  exit
retrieve       200          200                     200          200
               sort         sort                    sort         sort
               pipe         pipe                    pipe         pipe
                     400                                  400
                     sort                                 sort
                     pipe                                 pipe
                                       800
                                       sort
                              \                    /
                               \-------Done-------/