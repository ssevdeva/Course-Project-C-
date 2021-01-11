# Course Project
Game "Who Wants to Be a Millionaire" (console app)

Game Instructions:

1. After starting the application, choose a menu option:
   * Type 'N' or 'n' to start a new game.
   * Type 'A' or 'a' to add a new question.
   * Type 'M' or 'm' to modify an existing question.
   * Type 'E' or 'e' to exit the app.
   
   
2. NEW GAME:
   * Before starting a new game the player is asked to choose a category for the questions that will be given during the game.
       > Available options: Geography, History, Literature, Physics, Politics, All categories.
       
   * After choosing a category, if the number of questions is not enough to be used during the game, a warning message is displayed on the screen.
   
   * If the game has successfully started, a temporary text file is created to store the questions that might be included in the game.
   * The user is given 15 questions.
       > Questions 1 - 5: easy.
       > Questions 6 - 10: normal difficulty.
       > Questions 11 - 15: difficult.
   
   * For each question, the player is asked if they would like to use any lifelines (if they are still available) before entering their answer.
       > Type 'Y'/'y' for Yes and 'N'/'n' for No.
       > Available lifelines: "50:50", "Ask the Audience", "Phone a friend".
       > "50:50" eliminates two wrong answers.
       > "Ask the Audience" displays the votes of a simulated audience in support of each answer.
       > "Phone a Friend" simulates a call to a friend who gives their opinion in support of one of the answers.
  
   * Each correct answer increases the prize reached according to the current stage of the game.
       > Question 1 - 3: each adds 100$ to the prize reached.
       > Question 4: reached prize gets 500$.
       > Question 6 - 11: each doubles the prize reached.
       > Question 12: reached prize gets 125 000$.
       > Question 13 - 14: each doubles the prize reached.
       > Question 15: reached prize gets 1 000 000$.
       
* If a wrong answer is given, the game ends and the player takes their prize according to reached stage of the game.
       > Wrong answered questions 1 - 4: 0$.
       > Wrong answered questions 5 - 12: 500$.
       > Wrong answered questions 13 - 15: 125 000$.
       > Correctly answered question 15: 1 000 000$.

* The player is redirected to the main menu.


3. ADD QUESTION:
   * Before adding a new question the user is asked to enter a category and level of difficulty of the question.
   
   * The user has to write the question.
       > NOTICE: A question mark '?' is expected to be put at the end of each question. 
       
  * The user has to write the available answer options. 
  * The user has to write the letter of the correct answer.
  * Each new question is given a newly generated ID number starting with a '#'.
  * The player is redirected to the main menu.  
   

4. MODIFY QUESTION:
   * Before modifying a new question the user is asked to enter the ID number of the question which could be taken from the source text files.
   * If a question with this ID number is not found, a message is displayed on the screen. The user is asked to enter another ID number.
   * If the question with this ID number is found, the user is asked to enter all the information for this question again.
       > NOTICE: A question mark '?' is expected to be put at the end of each question. 
       
       
5. EXIT:
   * A final message is displayed on the screen.
   * All processes are terminated.

   
   
