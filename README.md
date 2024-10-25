
# Trivia Game - Are You Ready for the Challenge?

Welcome to the most intellectually stimulating, emotionally exhausting, and fun trivia game you've ever encountered! (Okay, maybe we're overselling it a bit, but it's still pretty cool.)

## What Is This?
This is a command-line **Trivia Game** built in C, where players answer questions from a carefully curated list of brain-busting trivia. Get ready to put your thinking cap on and score some points! 🎓

## Features

- **Exciting Questions**: Each round presents a question with two possible answers. Choose wisely!
- **Points System**: For every correct answer, you earn one point. Incorrect answers? Well... let's just say we believe in second chances (for the next question, of course).
- **Dynamic Scoreboard**: Compete with your friends, family, or just your inner genius by viewing the final scoreboard that tracks all players.
- **File-based Persistence**: Your results are saved, so there's no escape from your scores (and neither for your friends).

## How It Works

1. **Create a new game**: Load questions from a file (`questions.txt`) and test your trivia knowledge.
2. **Continue a game**: Already loaded your brainy questions? Just continue where you left off.
3. **Check the scoreboard**: Want to see who's the trivia champ? Check out the scoreboard and find out if you're at the top (or bottom, no judgments).
4. **Exit**: Had enough for today? You can exit whenever you're ready.

## What's In the Code?
- **Linked Lists**: Because one node is never enough! We use a linked list to manage our questions and answers dynamically.
- **File Handling**: All your trivia history is saved in `questions.txt` (for questions) and `clasament.txt` (for the high scores).
- **Pointers and Structures**: Ah, the magic of C! Each question is stored as a structure, linked in a beautiful chain of knowledge (aka a linked list).

## How to Play

1. Make sure you have your `questions.txt` file in the correct format:
   ```
   Question 1;Answer 1;Answer 2
   Question 2;Answer 1;Answer 2
   ...
   ```
2. Compile the program:
   ```
   gcc trivia_game.c -o trivia_game
   ```
3. Run the game:
   ```
   ./trivia_game
   ```
4. Answer the questions, see your score, and laugh at your mistakes (or not).

## Sample Gameplay
```
-= TRIVIA GAME =-
Bine ai venit !!
Selecteaza o optiune: 
1. Creeaza joc nou
2. Continua joc
3. Vizualizeaza clasament
4. Iesire
Enter your choice: 1
Introduceti numele jucatorului: Horatiu
Question: What's the capital of Romania?
Answer 1: Bucharest
Answer 2: Cluj-Napoca
Enter your response: Bucharest
Correct answer!
Final score: 1
```

## Why You Should Play
- Because trivia is life, and knowing random facts can be your superpower.
- Test your knowledge, sharpen your mind, and maybe—just maybe—beat your friends in the process.

## License
This game is free to play, share, modify, or brag about. Just don’t forget to have fun!
