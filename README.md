# cppMemoryGamea
It's a text based memory game made in cpp as a class so can be easily reused. This is functional across all platform that is no specific OS libraries are used.

Memory games classics that never get old. Memory Match is one classic memory game based on the traditional board game where you have to pair matching cards that are upside down. This text based matching game will challenge your memory, concentration, attention and test your brain skills. Memory Match is a great way to exercise your memory and test your brain. Find the matching tiles!

Menu User Interaction:

  •	Level of Play – User selects at start of game
  
    4 x 4 grid (Easy)
    
    6 x 6 grid (Moderate)
    
    8 X 8 grid (Difficult)
    
  •	Speed  of Play – At start of game, User selects time interval for User selected term-pair to display
  
    2 seconds  (Difficult)
    
    4 seconds (Moderate)
    
    6 seconds (Easy)
    
Game Play:

1)	User selects a FIRST square, the theme/face term  in the grid square is replace with correspond stored term, from the 2-dim answer array

2)	User selects a SECOND square, the term theme/face in the second grid square is replace with the corresponding stored term, from the 2-dim answer array

3)	The computer compares the terms for the two selected squares.
If they are the same, the terms remain on the screen and can no longer be selected.
If they are different, the term remain the screen for 2, 4 or 6 seconds, depending on user selection at the beginning of the game.  After that elapse time, those two grid terms are replaced with the face/theme term.

This game is made fundamentally as a class, so can be easily reused.

Libraries Required:
<ul>
<li>iostream</li>
<li>stdlib.h</li>
<li>iomanip</li>
<li>random</li>
<li>algorithm</li>
</ul>
