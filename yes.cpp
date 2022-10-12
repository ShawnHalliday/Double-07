/*
Name: Shawn and Zeren
Date: October 12, 2022
Program name: yes.cpp
Purpose: provide a fun time for people stuck in comic cons line, this is a double 0 seven game where you can shoot block or reload. 
*/


//Includes
#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

//Setting vars
string acknowledge;
string playOrExit;
string choice;
string enemyChoice;
string ammoStr;
string strScore;
string enemyAmmoStr;
int ammo = 0;
int enemyAmmo = 0;
int dryfire;
int score = 0;

//Allowing color change in console
HANDLE textcolor = GetStdHandle(STD_OUTPUT_HANDLE);

// defines ai algorithim, uses player input and ammo counts to decide ai move
void aiAlgorithm(){
// if player ammo is 0 and ai ammo is 0 then reload else shoot or reload
if (ammo == 0){
    if (enemyAmmo == 0){
        enemyChoice == "RELOAD";
        enemyAmmo = enemyAmmo + 1;
        SetConsoleTextAttribute(textcolor, 11);
        cout<<"Your enemy reloaded.\n";
        SetConsoleTextAttribute(textcolor, 7);
    }
    else{
        //chose shoot or reload randonmly
        string move_list1[2] = {"SHOOT", "RELOAD"};
        // randomizes move, can be either shoot or reload
        srand(time(NULL));
        int ai_rand = rand() % 1;
        enemyChoice = move_list1[ai_rand];
        // if shoot, remove one ammo and change text color
        if (enemyChoice == "SHOOT"){
            SetConsoleTextAttribute(textcolor, 12);
            cout<<"Your enemy shot\n";
            enemyAmmo = enemyAmmo - 1;
            SetConsoleTextAttribute(textcolor, 7);
            
        }
        // if ai choice is reload, add one to ammo count
        else if (enemyChoice == "RELOAD"){
            enemyAmmo = enemyAmmo + 1;
            SetConsoleTextAttribute(textcolor, 11);
            cout<<"Your enemy reloaded.\n";
            SetConsoleTextAttribute(textcolor, 7);
        }
    }
}

else{
    // if ai has no ammo, randomozise either block or reload
    if (enemyAmmo == 0){
        string move_list2[2] = {"BLOCK", "RELOAD"};
        srand(time(NULL));
        int ai_rand = rand() % 2;
        // chooses move from list with random number from 0-1
        enemyChoice = move_list2[ai_rand];
        if (enemyChoice == "BLOCK"){
            SetConsoleTextAttribute(textcolor, 13);
            cout<<"Your enemy blocked.\n";
            SetConsoleTextAttribute(textcolor, 7);
        }
        else if (enemyChoice == "RELOAD"){
            enemyAmmo = enemyAmmo + 1;
            SetConsoleTextAttribute(textcolor, 11);
            cout<<"Your enemy reloaded.\n";
            SetConsoleTextAttribute(textcolor, 7);
        }
    }

    else{
    //chose block or reload or shoot randmoly
    string move_list3[3] = {"SHOOT", "BLOCK", "RELOAD"};
    srand(time(NULL));
    int ai_rand = rand() % 3;
    enemyChoice = move_list3[ai_rand];
    
    if (enemyChoice == "BLOCK"){
            SetConsoleTextAttribute(textcolor, 13);
            cout<<"Your enemy blocked.\n";
            SetConsoleTextAttribute(textcolor, 7);
    }

    else if (enemyChoice == "SHOOT"){
            SetConsoleTextAttribute(textcolor, 12);
            enemyAmmo = enemyAmmo - 1;
            cout<<"Your enemy shot.\n";
            SetConsoleTextAttribute(textcolor, 7);
    }

    else{
            enemyAmmo = enemyAmmo + 1;
            SetConsoleTextAttribute(textcolor, 11);
            cout<<"Your enemy reloaded.\n";
            SetConsoleTextAttribute(textcolor, 7);
    }
}
}
}

void choiceFunction(){
        //Check if the choice is reload and if so get all outcomes
        if (choice == "RELOAD"){
            Sleep(500);
            ammo = ammo + 1;
            ammoStr = to_string(ammo);
            cout<<"You reloaded. \n";
            Sleep(500);
            // ascii art of reload 
            cout<<"\n       _  __________=__\n        \\\\@([____]_____()\n       _/\\|-[____]\n      /     /(( )\n     /   / '----'\n    /___/	\n             ____\n            /.../\n           /.../\n          /.../\n         /___/\n\n";
            Sleep(500);
            if (enemyChoice == "SHOOT"){
                cout<<"YOU LOSE!\n";
                // removes from score because of loss then converts int to string to print to console
                score = score - 1;
                strScore = to_string(score);
                cout<<"Your current score is: " + strScore + "\n";
                Sleep(500);
                cout<<"enter anything to go back to the menu.\n";
                cin>>acknowledge;
                choice == "LEAVE";
                ammo = 0;
                enemyAmmo = 0;
                // resets choices to blank for next round so ai decides a new move
                choice = " ";
                enemyChoice = " ";
            }
        }

        //Check if the choice is block and if so get all outcomes
        else if (choice == "BLOCK"){
            Sleep(500);
            cout<<"You blocked\n";
            Sleep(500);
            //ascii art for block
            cout<<"\n  |`-._/\\_.-`|\n  |    ||    |\n  |___o()o___|\n  |__((<>))__|\n  \\   o\\/o   /\n   \\   ||   /\n    \\  ||  /\n     '.||.'\n       ``\n\n";
            Sleep(500);
            if (enemyChoice == "SHOOT"){
                cout<<"You blocked their shot.\n";
                Sleep(500);
                // resets choices to blank
                choice = " ";
                enemyChoice = " ";

            }
        }
        
        //Check if the choice is shoot and if so get all outcomes
        else if (choice == "SHOOT"){
            // dry fire check to see if you have ammo to shoot, if no ammo then player bassicly nullifies their turn
            if (ammo <= 0){
            Sleep(500);
            SetConsoleTextAttribute(textcolor, 4);
            cout<<"You dry fired because you have no ammo.\nPay attention next time.\n";
            // dry fire variable so the game does not think you win if the enemey reloads even if you have ammo
            int dryfire = 1;
            SetConsoleTextAttribute(textcolor, 7);
            Sleep(500);
            choice = " ";
            enemyChoice = " ";
            }

            else if (ammo > 0){
            ammo = ammo -1;
            //ascii art 
            cout<<"You shot.";
            Sleep(500);
            cout<<"\n  (                                 _\n   )                               /=>\n  (  +____________________/\\/\\___ / /|\n   .''._____________'._____      / /|/\\\n  : () :              :\\ ----\\|    \\ )\n   '..'______________.'0|----|      \\\n                    0_0/____/        \\\n                        |----    /----\\\n                       || -\\\\ --|      \\\n                       ||   || ||\\      \\\n                        \\\\____// '|      \\\n                                .'/       |\n                               .:/        |\n                               :/_________|\n\n";
            if (enemyChoice == "BLOCK"){
                Sleep(500);
                cout<<"Your enemy blocked your shot.\n";
                Sleep(500);
                choice = " ";
                enemyChoice = " ";
            }
            }

            if (enemyChoice == "SHOOT"){
                //randomly decides who wins and prints score
                srand(time(NULL));
                int winner = rand() % 2 + 1;
                if (winner == 1){
                    cout<<"YOU WIN!\n";
                    score = score + 1;
                    strScore = to_string(score);
                    cout<<"Your current score is: " + strScore + "\n";
                    Sleep(500);
                    cout<<"enter anything to go back to the menu.\n";
                    cin>>acknowledge;
                    choice == "LEAVE";
                    // resets variables
                    ammo = 0;
                    enemyAmmo = 0;
                    choice = " ";
                    enemyChoice = " ";
                }
                else {
                    cout<<"YOU LOSE!\n";
                    score = score - 1;
                    strScore = to_string(score);
                    cout<<"Your current score is: " + strScore + "\n";
                    Sleep(500);
                    cout<<"enter anything to go back to the menu.\n";
                    cin>>acknowledge;
                    choice == "LEAVE";
                    // resets variables for next round
                    ammo = 0;
                    enemyAmmo = 0;
                    choice = " ";
                    enemyChoice = " ";
                }
            }
            // checks enemy choice and if player ha
            if (enemyChoice == "RELOAD" && dryfire == 0){
            cout<<"YOU WIN!\n";
            score = score + 1;
            string strScore = to_string(score);
            cout<<"Your current score is: " + strScore + "\n";
            Sleep(500);
            cout<<"enter anything to go back to the menu.\n";
            cin>>acknowledge; 
            choice == "LEAVE";
            ammo = 0;
            enemyAmmo = 0;
            choice = " ";
            enemyChoice = " ";
            }
            int dryfire = 0;
        }

        //Error checking
        else{
            SetConsoleTextAttribute(textcolor, 4);
            cout<<"ERROR: Please enter a valid choice.\n";
            Sleep(500);
            SetConsoleTextAttribute(textcolor, 7);
            if (enemyChoice == "SHOOT"){
                cout<<"YOU LOSE!\n";
                int score = score - 1;
                strScore = to_string(score);
                cout<<"Your current score is: " + strScore + "\n";
                Sleep(500);
                cout<<"enter anything to go back to the menu.\n";
                cin>>acknowledge;
                choice == "LEAVE";
                ammo = 0;
                enemyAmmo = 0;
                choice = " ";
                enemyChoice = " ";
        }
        choice = " ";
        enemyChoice = " ";
    }
    }

// main game loop
int main(){
// add console window title
SetConsoleTitle ("Double 07");
//Changing console text color
SetConsoleTextAttribute(textcolor, 2);
cout<<"Hello, welcome to Double 07.\nYour objective is to beat the ai in a game of Double 07.\nThe rules are pretty simple, every turn, you have 3 options:\n1. Reload: Reloading give you 1 ammo that you can use to shoot with your gun or save to stockpile ammo.\n2. Shoot: Shooting requires 1 ammo and shoots at your enemy, if they dont block, you win.\n3. Blocking: Blocking blocks getting shot at so if you get shot at, you will live.\nException 1: if they both people shoot, the winner will be decided at random.\nException 2: If you do not enter a proper input, the game will continue and you will miss a turn.\nOnce you understand, enter anything to proceed.\n";
SetConsoleTextAttribute(textcolor, 7);
cin>>acknowledge;
Sleep(500);
SetConsoleTextAttribute(textcolor, 2);
cout<<"\nTo start, type \"play\" to exit, type \"exit\".\n";
SetConsoleTextAttribute(textcolor, 7);
cin>>playOrExit;

//Converting to uppercase
transform(playOrExit.begin(), playOrExit.end(), playOrExit.begin(), ::toupper);

//Just giving the person a second to understand whats going on
Sleep(500);
while (!(playOrExit == "EXIT" || playOrExit == "PLAY")){
    SetConsoleTextAttribute(textcolor, 4);
    cout<<"ERROR: Please enter a valid choice.\n";
    Sleep(500);
    SetConsoleTextAttribute(textcolor, 7);
    cin>>playOrExit;
    transform(playOrExit.begin(), playOrExit.end(), playOrExit.begin(), ::toupper);
}
//Goodbye statement
if (playOrExit == "EXIT"){
cout<<"Goodbye :)\n";
Sleep(1000);
return 0;
}

else if (playOrExit == "PLAY"){

    //Checking if they want to leave
    while (choice != "LEAVE"){
        SetConsoleTextAttribute(textcolor, 10);
        cout<<"\n\nTo go back to the main menu, type \"Leave\".\nIf you wish to continue playing, here are the options:\nTo reload, type \"Reload\".\nTo block, type \"Block\".\nTo shoot, type \"Shoot\".\n\n";
        // converts ammo int to string to print to console window 
        ammoStr = to_string(ammo);
        enemyAmmoStr = to_string(enemyAmmo);
        cout<<"Current ammo count: " + ammoStr + "\n";
        cout<<"Current enemy ammo count: " + enemyAmmoStr + "\n";

   
        //Take the users choice
        SetConsoleTextAttribute(textcolor, 7);
        cin>>choice;
        transform(choice.begin(), choice.end(), choice.begin(), ::toupper);
        Sleep(500);
        // runs ai choice decider
        aiAlgorithm();
        Sleep(500);
        choiceFunction();
    }
}
}