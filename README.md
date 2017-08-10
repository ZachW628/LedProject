# LedProject
Led matrix project

Current Progress as of 8/3/17
   All charcaters have been made and numbers but no special characters.
   Characters are currently working with the wiring Pi library.
   Character list that moves strings accross the board is complete.
   Imporved performance able to toggle 8 LEDS at once instead of 1 using my library instead of wiring pi
   
 Things to do still:
    All the characters need to be fixed so they use my library to interact with the mcp23017 instead of wiring pi



Current Progress 8/6/17
   got my queue working and all of the characters switched over to my i2c library, and everything
   is working fine text is scrolling across the board at a good rate. No memory leaks from 
   i2c_base and characters.
   
   === still need to do ===
       - need a layer above the queue that interacts with the queue and the user.
       + need to figure out which lights that need to come on for the next generation, and find
         the anti-union between that array and the current lights on array. and turn those lights
         off instead of the entire lights on array. This will solve the flickering problem
       + also need to loop through the linked list deleteing items for proper memory management
       + need to add a way to interupt the scrolling to quit for a proper exit of the program.

   === Things that I might want to do in the future ===
       - time the calaculations of the list so that i sleep for the same time in between 
         position changes. this might have a very insigniicant impact...
		^^^ i TRIED THIS CHANGE IT MADE IT WAY MORE INCONSITENT ^^^
