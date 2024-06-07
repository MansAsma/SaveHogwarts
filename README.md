# SaveHogwarts
As a devoted Harry Potter fan, I decided to implement a simple game (using Qt Creator (6.7) and C++), which involves saving the Hogwarts School of Witchcraft and Wizardry from the Dementors. While not all scenarios are fully covered in this version, future updates will expand the gameplay. 

For now, here are the game rules:

    - Harry can move up, right, and left, and must cast the Patronus Charm to defeat the Dementors. 
    - When a Patronus collides with a Dementor, the Dementor is defeated, and the game's score increases. 
    - If a Dementor collides with Harry, he loses health point (Harry has a maximum of 3 health points).
    - If his health reaches 0, Harry dies and the game is over. 
    - The game also ends if a Dementor enters Hogwarts. 
    - Your score reflects the number of defeated Dementors. If the score reaches Max_Game_Score, Harry wins!