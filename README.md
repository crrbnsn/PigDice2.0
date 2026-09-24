# Pig Dice

## Background
Pig Dice is a simple game using one standard (6 sided) die. 

Rules of Pig Dice:
<ol>
<li>See how many turns it takes to reach a minimum of 20 points</li>
<li>A turn is over when you roll a 1 or you choose to hold</li>
<li>If you roll a 1, then all points for that turn are lost</li>
<li>If you hold, then points for the turn are added to total score for the game and the turn count increases by 1</li>
</ol>

## Directions
Complete the PigDice.cpp template provided which should use the procedural programming approach presented in CSC 175 to implement the Pig Dice game described above. 

### Your solution code should include the following:
<ul>
<li>Break the solution down into functions such as:</li>
<ul><li>playGame function</li>
<li>takeTurn function</li>
<li>roll function</li>
<li>hold function</li></ul>
<li>Pass parameters by reference between functions (no global variables)</li>
<li>Make use of loop constructs like the while loop</li>
<li>Make use of the GameState structure provided in the template</li>
</ul>

<b>Note: Your solution must recreate the <i>exact</i> user interface shown below.</b>




## Interface Prototype Example

### Test Case Output
<pre><b>Let's Play PIG Dice!

* See how many turns it takes you to get to 20 points.
* Turn ends when you hold or roll a 1.
* If you roll a 1, you lose all points for the turn.
* If you hold, you bank all points for the turn to the game score.

TURN 1 - Game Score: 0
roll or hold? (r/h): r
Die: 1
Turn over. No score.
Score Banked This Turn: 0

TURN 2 - Game Score: 0
roll or hold? (r/h): r
Die: 2 - Running score this turn: 2
roll or hold? (r/h): r
Die: 4 - Running score this turn: 6
roll or hold? (r/h): h
Score Banked This Turn: 6

TURN 3 - Game Score: 6
roll or hold? (r/h): r
Die: 6 - Running score this turn: 6
roll or hold? (r/h): r
Die: 1
Turn over. No score.
Score Banked This Turn: 0

TURN 4 - Game Score: 6
roll or hold? (r/h): r
Die: 3 - Running score this turn: 3
roll or hold? (r/h): r
Die: 6 - Running score this turn: 9
roll or hold? (r/h): h
Score Banked This Turn: 9

TURN 5 - Game Score: 15
roll or hold? (r/h): r
Die: 4 - Running score this turn: 4
roll or hold? (r/h): r
Die: 5 - Running score this turn: 9
roll or hold? (r/h): h
Score Banked This Turn: 9

You finished with a final score of 24 in 5 turns!
Thanks for playing PIG Dice!</b></pre>
