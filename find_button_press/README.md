#Find button press
This was my attempt at making an arduino as close to concurrent as possible.  Since arduino doesn't support threading, I used rapid checking of the button press while the processes weren't being excecuted.
The big goal was to allow the program to check for button presses at all times.