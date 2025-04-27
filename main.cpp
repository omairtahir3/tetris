/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */

#include <SFML/Graphics.hpp>
#include <time.h>
#include <fstream>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include <iostream>
#include <string>
#include "cstdlib"
using namespace sf;
using namespace std;
int main(){
    srand(time(0));
    string username="\0";
    cout<<"Please Enter Your Username: ";
    cin>>username;
    RenderWindow window(VideoMode(320, 480), title);
    RenderWindow window1(VideoMode(225, 308), menu); //a new window is made to display menu
    Texture obj1, obj2, obj3, obj4,obj5;
    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/background.png");
    obj3.loadFromFile("img/frame.png");
    obj4.loadFromFile("img/menu.png"); //image is loaded inorder to display the menu onto another window
    obj5.loadFromFile("img/gameover.png");
    Sprite sprite(obj1), background(obj2), frame(obj3), menu(obj4),over(obj5); //sprite for the menu is created
    int delta_x=0, colorNum=1,num=1,score=0,size=0,level=1;
    float timer=0, delay=0.3;
    bool rotate=0,gamecond=0,cont=0;
    bool space=0;
    Clock clock;
    while(window1.isOpen()) //a loop added for that menu
    {
    Event y;
    while (window1.pollEvent(y))
    {
    if (y.type==Event::Closed) //if the event is closed then the window will remain closed
    {
    window1.close();
    }
    if (y.type==Event::KeyPressed)
    {
        if (y.key.code == Keyboard::Num1) //if 1 is pressed then the game condition becomes true
        {
        gamecond=true;    
        window1.close(); //the menu window gets closed
    }
    }
        if (y.type==Event::KeyPressed)
    {
        if (y.key.code == Keyboard::Num2) //if 3 is pressed then the game condition becomes true
        {
        window.close();   
        window1.close(); //the menu window & the game window gets closed and the terminal is loaded which shows the scoreboard
    }
    }
    if (y.type==Event::KeyPressed) //if 4 is pressed then the user wants to quit the game hence the window closes
    {
    if (y.key.code == Keyboard::Num4)
        {
        window1.close();
        window.close();
    }
    }
    window1.draw(menu);
    window1.display();
    }
    if (gamecond==true || cont==true) //if the game condition and condition are true then the window opens up
    {
    while (window.isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        //---Event Listening Part---//
        Event e;
        while (window.pollEvent(e)){                    //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
            if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
                if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
                    rotate = true;                         //Rotation gets on
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                    delta_x = -1;                          //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                    delta_x = 1;                          //Change in X-Axis - Positive
                  else if (e.key.code == Keyboard::H)    //if H is pressed during the game then the game halts and ends 
                  window.close();    
     }
     }
        if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.1;                    //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.1
            if (Keyboard::isKeyPressed(Keyboard::Space)) //cases for space entered
            {space=true; } 
            else if (Keyboard::isKeyPressed(Keyboard::Down))
            {
            delay=0.1;
            }
              else if (score>50) 
              {
              delay=0.15; 
                }  
                else 
                {
                delay=0.3;
                }        
        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
        fallingPiece(timer, delay,colorNum);   
        movementright(delta_x); 
        movementleft(delta_x);
        rotated(rotate);
        clearlines(score,delay,level);
        gameOver();
        Space(space,delay);
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////

        window.clear(Color::Black);
        window.draw(background);
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
          }
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
          if (gameOver())
       {
         window.clear();
         window.draw(over);
         window.display();
         }
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
       
    }
    }
    }
    cout<<"Your Score is: "<<score<<endl; //The score of each player is displayed
    cout<<"Level: "<<level<<endl;
    fstream file("file.txt",ios::app);
    file<<username<<" "<<score<<endl;
    file.close();
ifstream infile1("file.txt");
 while(infile1>>username>>score){
 size++;
 }
 infile1.close();
 
 int score1[size];
 string name1[size];
 
ifstream infile("file.txt");
int index=0;
 while(infile>>name1[index]>>score1[index])
 {
index++;
}
infile.close();
cout<<"Scoreboard: "<<endl;
	for(int i=0; i<size; i++)
	{
	cout<<name1[i]<<" "<<score1[i]<<endl;
	}
	
	
	

    
    return 0;
}

