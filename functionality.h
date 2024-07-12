/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//
void fallingPiece(float& timer, float& delay,int &colorNum){
    if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
             }
        if (!anamoly()){
          for (int i=0;i<4;i++)
              gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;
               int bombcolor;
              colorNum=1+rand()%7;
              int color=colorNum;
              int n=rand()%8;
                for (int i=0;i<4;i++){
                    point_1[i][1] = BLOCKS[n][i] % 2; 
                    point_1[i][0] = BLOCKS[n][i] / 2;
                    if (n==8)
                    {
                    bombcolor=colorNum;
                    if (bombcolor==color)
                    {
                    gameGrid[M][N]==0;
                }
                }
                }
                }
      
                     
        timer=0;
        }
         delay=0.3; //after every one click on the downward key they delay again becomes 0.3
        } 
           
/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
//THE RIGHT MOVEMENT
//For the right movement delta_x will be taken as 1 and in the while loop point_1  will get incremented by 1 on the x axis as the x axis is denoted by 0 hence it will get incremented each time the right key is pressed while the y coordinate is already increasing by 1 through the previous function. The loop will run until it reaches 4 while as the value for delta_x constantly changes it will get 0 once the loop ends so if the value +1 only then the loop runs. The anamoly condition is set to ensure that that block remains within the grid and doesnot fall out. In this manner the block moves to the right using this function.
void movementright(int& delta_x)
{
int a=0;
if (delta_x==+1) 
{

           while (a<4)
           { 
             point_2[a][0]=point_1[a][0];
            point_2[a][1]=point_1[a][1];
            point_1[a][0]=point_1[a][0]+1; 
            a++; 
         }
          delta_x=0;
        if (!anamoly()){
               for (a=0;a<4;a++)
               {
               point_1[a][1]=point_2[a][1]; 
               point_1[a][0]=point_2[a][0];
          }
          }
          }
          }
 //THE LEFT MOVEMENT
//For the left movement delta_x will be taken as -1 and in the while loop point_1  will get decremented by 1 on the x axis as the x axis is denoted by 0 hence it will get decremented each time the left key is pressed while the y coordinate is increasing by 1 through the previous function. The loop will run until it reaches 4 while as the value for delta_x constantly changes it will get 0 once the loop ends so if the value -1 only then the loop runs. The anamoly condition is set to ensure that that block remains within the grid and doesnot fall out. In this manner the block reaches the bottom of the grid. In this manner the block moves to the left using this function        
void movementleft(int& delta_x)
{
int a=0;
if (delta_x==-1)
{

           while (a<4)
           { 
             point_2[a][0]=point_1[a][0];
            point_2[a][1]=point_1[a][1];
            point_1[a][0]=point_1[a][0]-1; 
            a++;
         }
          delta_x=0; 
        if (!anamoly()){
               for (a=0;a<4;a++)
               {
               point_1[a][1]=point_2[a][1]; 
               point_1[a][0]=point_2[a][0];
          }
          }
          }
          }
//ROTATION 
//For rotation the point_1[1][0] and point_1[1][1] are taken as the center of rotation for both x and y as the y coordinate becomes the x cordinate and the x coordinate becomes the y coordinate where point_1[1][1] is for y axis and point_1[1][0] is for x axis.The x coordinate each time is subtracted from the x centre of rotation as it gets rotated about the x axis centre of rotation inorder to rotate the object as when an object gets rotated it's x coordinate gets negative.The y coordinate is added each time as the y coordinate remains positive time while x gets negative and it gets rotated each time according to the y center of rotation as it gets rotated about the y center of rotation. After each rotation the condition for rotation becomes false as the block must get rotated once.
void rotated(bool& rotate)
 { 
 int a=0;
 int xcord=0,ycord=0;
 int score=0;
 if (rotate==true)
 {
 while (a<4)
           { 
          xcord=point_1[a][1]-point_1[1][1]; 
          ycord=point_1[a][0]-point_1[1][0];  
          point_1[a][0]=point_1[1][0]-xcord; 
          point_1[a][1]=point_1[1][1]+ycord; 
           a++;
           }
           }
           if (!anamoly()){
               for (a=0;a<4;a++)
               {
               point_1[a][1]=point_2[a][1]; 
               point_1[a][0]=point_2[a][0];
          }
          }
          rotate=false; 
          }
          
  //CLEARING LINES
  //For clearing the lines two loops are used to check and clear the lines that are completely filled with blocks. The first loop is for the number of rows which start from the bottom as M-1 is the bottom as the grid ends at M hence it reduces until it reaches the top, while the second loop is for the number of columns which are increasing from left to right from to to N. Another variable is initialized with M-1. The array for the game grid with this variable gets equal to the game grid array for the rows each time the loop runs until the grid reaches the top. A if condition is used to count the number of blocks in each line as the condition states that if the number of blocks are not equal to 0 then the counter increments by 1. Now if the sum is less than N, it means that the blocks are not enough to complete the line hence the line gets decremented. As the number of rows are also decremented in the same loop hence the line is not removed as the array for the line is equal to that of the rows. However, if the line is completed then the line does not get decremented which the number of rows are decremneted each time the loop runs and so the line gets cleared which the line above takes it's place. In this manner this function checks each line till it reaches the top of the grid. Now if the sum is equal to the number of columns, the number of lines cleared increases by 1. So, outside the loop it is compared with the consecutive line numbers and if the line number matches the score gets added accordingly.
    void clearlines(int& score,float& delay,int& level)
    {
    int col=0;
    int sum=0;
    int nrows=M-1; 
    int lines=M-1;
    int nlines=0;
     while (nrows>0) 
    {
    for (col=0;col<N;col++)
    {
    if (gameGrid[nrows][col]!=0)
    {
    sum=sum+1;
    }
    gameGrid[lines][col]=gameGrid[nrows][col];
    }
    if (sum<N)
    { 
    lines--;
    }
    if (sum==N)
    {
    nlines=nlines+1;
    }
    sum=0;
    nrows--;
    }
     if (nlines==1)
    {
    score=score+10;
    }
    else if (nlines==2)
    {
    score=score+30;
    }
    else if (nlines==3)
    {
    score=score+60;
    }
    else if (nlines==4)
    {
    score=score+100;
    }
   if (score>50) 
    {
    delay=0.15;
    level=2;
    }
        if (!anamoly()){
               for (int a=0;a<4;a++)
               {
               point_1[a][1]=point_2[a][1]; 
               point_1[a][0]=point_2[a][0];
          }
          }
    }
//GAME OVER 
//If the block reach the top of the grid then the game gets over which means that the number of columns will increase while the row will remain 0. Hence this condition will be applied and will check if there is a block on the top of the grid. If a block is present then the game will terminate as the condition will get true while if there is no block present then the condition will remain false.In this manner it sends the boolean if the game has to end as it is called in the main function and terminates the game
 bool gameOver() 
 {
  for (int i=0;i<N;i++) 
  {
  if (gameGrid[0][i]!=0) 
  {
  return true; 
  }
  } 
  return false;
  }
//SPACE
//For the space, the delay time is reduced as much as possible for the block to fall as quickly as it can to the base of the grid. All the other blocks fall on the normal speed after it falls. This function therefore results in fall
void Space(bool& space, float& delay)
{
if (space==true)
{
delay=0.003;
}        
}     
///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
