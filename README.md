# SaveHogwarts
The game involves saving the Hogwarts School of Witchcraft and Wizardry from the Dementors. While not all scenarios are fully covered in this version, future updates will expand the gameplay. 

# Installing Required Tools
 * Qt Creator 6.7:
    Download from the Qt Creator Official Website. link [https://www.qt.io/offline-installers]
 * CMake:
    Install CMake by following the instructions on the CMake Official Website. link [https://cmake.org/download/]
    Note : For Qt Creator 6.7, the required CMake version is typically 3.21 or higher, In my case 3.29.3 version was installed.
  
# Game Demo:
For now, here are the game rules:

    - Harry can move up (^), right (>), and left (<), and must cast the Patronus (using the keayboard space) Charm to defeat the Dementors.  
    - When a Patronus collides with a Dementor, the Dementor is defeated, and the game's score increases. 
    - If a Dementor collides with Harry, he loses health point (Harry has a maximum of 3 health points).
    - If his health reaches 0, Harry dies and the game is over. 
    - The game also ends if a Dementor enters Hogwarts. 
    - Your score reflects the number of defeated Dementors. If the score reaches Max_Game_Score, Harry wins!
    
![SaveHogwarts_GameDemo](https://github.com/MansAsma/SaveHogwarts/assets/77064769/afe6e8a3-2792-4945-a02c-0adf82ff9cff)

