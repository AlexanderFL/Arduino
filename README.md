# Arduino Project

## Countdown

### About
This is a simple game where players try to be the first to hit the button on their side when a countdown timer reaches zero.

When the game starts a random number between 3-9 is generated and set as the number to start the timer at, then another random number is generated from 250-550 which represents the speed of the game. If the number 250 is generated there are 0.25 seconds between numbers and 550 means 0.55 seconds between numbers.
### Controls
To start the game press either one of the two buttons and get the players ready, this will initiate the timer. When the timer hits 0 each player must try to be the first to hit the button on their side, the player to first hit his button will get a green light on his side of the board, while the other player gets a red light. The board will then reset itself after 3 seconds. If one of the players presses his button before the timer hits 0, he loses and the board resets itself.
### References
Connecting the 7-digit-display &mdash; http://www.instructables.com/id/Arduino-7-Segment-Click-Counter/

User *'CrossRoads'* for timer template &mdash; http://forum.arduino.cc/index.php?topic=45787.0

This project is based on the project ideas in canvas.

---

*Project made by Alexander Freyr Lúðvíksson, Helga Eyþórsdóttir, Íris Ósk Óttardóttir and Jóhann Kjartansson*
