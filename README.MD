# ATMega32 and OUSB Libraries

Libraries targetting the ATMega32 MCU found on the OUSB board purchasable at RMIT.

## Building

Simply `cd` into any directory 

## How to contribute

1. Make a fork of this _ENTIRE_ repository on your own GitHub account
2. Create a new branch with the following command: `git branch <branchname>`. Don't include the <>.
3. Make any changes you need/want to make. 
4. Include the files you've changed via the following command: `git add <filename>'
5. Run `git commit` and enter the commit message. This will probably use VIM. If you're using the GUI, enter your commit message here in the text box.
6. Push the changes to your fork with: `git push -u origin <branchname>`. 
7. Using GitHub (on our ECE GitHub account) open a Pull Request. 
8. Your changes will then be merged by me (Jesse) or one of the other team members. 

If you get stuck, don't be afraid to ask for help in the Discord. GIT can be a little bit intimidating for first time contributers. It will probably be best for you to use a GUI client at first. If you stuff up your commit, don't panic, we can fix it :^)

## How to build

Simply `cd` into the folder whose library code you want to build. You'll end up with a `.a` library file that can be linked into your own project using `avr-ld`, which is part of the GCC Toolchain. Make sure you copy the header file into your own project so you have all the correct `#define`'s and prototypes! 

If you get stuck, @ me (Jesse) on Discord and I'll try to fix your issues to the best of my abilities, however, it's best you get used to reading documentation, even if it looks scary at first (GNU documentation is evil for a first time reader).


