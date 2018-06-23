// Tarik Seyceri - 2012
// CS C++2 Project - Phase(2)

#include <iostream>
using namespace std;


class Game{
public:  // Variables   
    char a[7],b[7],c[7],d[7],e[7],f[7];  // Variables for columns and rows  // for drawing function
    char q;  // A Varible for answering some questions with (Y or N) / (E or H)
    int j;  // This varible is for counting played stones // to finish the game with DRAW if no one wins (42 stone)
    int i,l,m,n;  // Varibles for  ( Artificial Intelligence )
    int x,y; // x varible for User, y varible for PC
	bool WhoPlayFirst,PCMod,UserPlayed,PCPlayed;  // We will need this boolean varibles during the game
	
	Game(){  // Constructor
    	LoadingGame();  // Start the Game
    }

	void LoadingGame(){  // Initialization of all Variables
		for(i=0;i!=8;i++){a[i]=' ';b[i]=' ';c[i]=' ';d[i]=' ';e[i]=' ';f[i]=' ';}
		q=' ';
		j=0;
		i=0,l=0,m=0,n=0;
		x=0,y=0;
		WhoPlayFirst=true;
		PCMod=true;
		UserPlayed=false;
		PCPlayed=false;
		ChooseWhoPlayFirst();
	}

	void ChooseWhoPlayFirst(){  // This Function Will Choose Who Will Start Playing First (User or PC)
		ClearScr();
		q=' ';
		cout<<"Hello User, Hope You Enjoy This Game.....!!\n\n";
		cout<<"\n\n\n\n\n\n                       Do You Want To Play First....??\n\n";
		cout<<"                          YES : Y            NO : N\n\n\n";
		cout<<"                          Enter Your Choice : ";
		cin>>q;
		if ((q=='y') || (q=='Y')){WhoPlayFirst=true;ChoosePCMod();}
		else if ((q=='n') || (q=='N')){WhoPlayFirst=false;ChoosePCMod();}
		else ChooseWhoPlayFirst();
	}
	
	void ChoosePCMod(){  // This Function Will Choose The PC Mod (Easy or Hard)
		ClearScr();
		q=' ';
		cout<<"Hello User, Hope You Enjoy This Game.....!!\n\n";
		cout<<"\n\n\n\n\n\n                       Choose Your Opponent Mod.......\n\n";
		cout<<"                          Easy : E            Hard : H\n\n\n";
		cout<<"                          Enter Your Choice : ";
		cin>>q;
		if ((q=='e') || (q=='E')){q=' ';PCMod=true;if(WhoPlayFirst==true)UserPlay();else PCEasyPlay();}
		else if ((q=='h') || (q=='H')){q=' ';PCMod=false;if(WhoPlayFirst==true)UserPlay();else PCHardPlay();}
		else ChoosePCMod();
	}
	 

	void UserPlay(){  // If User's Turn
		Drawing();
		cout<<"Enter Your Play ( 1 -> 7 or 99 for quit ) : ";
		x=0;
		cin>>x;
		if (cin.fail()){cout << "Error: you did not enter a number!" << endl << "Game Stopped Working!" << endl;exit(0);} // The game will stop working if you entered characters!
		if (x==99){ClearScr();exit(0);}
	    else if((x==1) || (x==2) || (x==3) || (x==4) || (x==5) || (x==6) || (x==7))CheckUserPlay();
		else UserPlay();  // if user didn't enter a value 1->7 it will ask to enter the Value again
        
        
	}	
        
	void CheckUserPlay(){  // Function to Check what user Played
		UserPlayed=false;
		for(i=1;i!=8;i++){if(x==i && f[i]=='X'){UserPlay();}}
		for(i=1;i!=8;i++){if(x==i && f[i]=='O'){UserPlay();}}
		for(i=1;i!=8;i++){if(x==i && a[i]!='X' && a[i]!='O' && UserPlayed==false){a[i]='X';UserPlayed=true;CheckUserWinner();}}
		for(i=1;i!=8;i++){if(x==i && b[i]!='X' && b[i]!='O' && UserPlayed==false){b[i]='X';UserPlayed=true;CheckUserWinner();}}
		for(i=1;i!=8;i++){if(x==i && c[i]!='X' && c[i]!='O' && UserPlayed==false){c[i]='X';UserPlayed=true;CheckUserWinner();}}
		for(i=1;i!=8;i++){if(x==i && d[i]!='X' && d[i]!='O' && UserPlayed==false){d[i]='X';UserPlayed=true;CheckUserWinner();}}
		for(i=1;i!=8;i++){if(x==i && e[i]!='X' && e[i]!='O' && UserPlayed==false){e[i]='X';UserPlayed=true;CheckUserWinner();}}
		for(i=1;i!=8;i++){if(x==i && f[i]!='X' && f[i]!='O' && UserPlayed==false){f[i]='X';UserPlayed=true;CheckUserWinner();}}
		UserPlay();
	}	
	
	void CheckUserWinner(){  // Function to check if user won
		for(i=1;i!=8;i++){if('X'==a[i] && 'X'==b[i] && 'X'==c[i] && 'X'==d[i]){a[i]='W',b[i]='W',c[i]='W',d[i]='W';UserWins();}}
		for(i=1;i!=8;i++){if('X'==b[i] && 'X'==c[i] && 'X'==d[i] && 'X'==e[i]){b[i]='W',c[i]='W',d[i]='W',e[i]='W';UserWins();}}
		for(i=1;i!=8;i++){if('X'==c[i] && 'X'==d[i] && 'X'==e[i] && 'X'==f[i]){c[i]='W',d[i]='W',e[i]='W',f[i]='W';UserWins();}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('X'==a[i] && 'X'==b[l] && 'X'==c[m] && 'X'==d[n]){a[i]='W',b[l]='W',c[m]='W',d[n]='W';UserWins();}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('X'==b[i] && 'X'==c[l] && 'X'==d[m] && 'X'==e[n]){b[i]='W',c[l]='W',d[m]='W',e[n]='W';UserWins();}}      
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('X'==c[i] && 'X'==d[l] && 'X'==e[m] && 'X'==f[n]){c[i]='W',d[l]='W',e[m]='W',f[n]='W';UserWins();}}
		for(i=4,l=3,m=2,n=1;i!=8,l!=7,m!=6,n!=5;i++,l++,m++,n++){if('X'==a[i] && 'X'==b[l] && 'X'==c[m] && 'X'==d[n]){a[i]='W',b[l]='W',c[m]='W',d[n]='W';UserWins();}}
		for(i=4,l=3,m=2,n=1;i!=8,l!=7,m!=6,n!=5;i++,l++,m++,n++){if('X'==b[i] && 'X'==c[l] && 'X'==d[m] && 'X'==e[n]){b[i]='W',c[l]='W',d[m]='W',e[n]='W';UserWins();}}
		for(i=4,l=3,m=2,n=1;i!=8,l!=7,m!=6,n!=5;i++,l++,m++,n++){if('X'==c[i] && 'X'==d[l] && 'X'==e[m] && 'X'==f[n]){c[i]='W',d[l]='W',e[m]='W',f[n]='W';UserWins();}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('X'==a[i] && 'X'==a[l] && 'X'==a[m] && 'X'==a[n]){a[i]='W',a[l]='W',a[m]='W',a[n]='W';UserWins();}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('X'==b[i] && 'X'==b[l] && 'X'==b[m] && 'X'==b[n]){b[i]='W',b[l]='W',b[m]='W',b[n]='W';UserWins();}}  
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('X'==c[i] && 'X'==c[l] && 'X'==c[m] && 'X'==c[n]){c[i]='W',c[l]='W',c[m]='W',c[n]='W';UserWins();}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('X'==d[i] && 'X'==d[l] && 'X'==d[m] && 'X'==d[n]){d[i]='W',d[l]='W',d[m]='W',d[n]='W';UserWins();}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('X'==e[i] && 'X'==e[l] && 'X'==e[m] && 'X'==e[n]){e[i]='W',e[l]='W',e[m]='W',e[n]='W';UserWins();}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('X'==f[i] && 'X'==f[l] && 'X'==f[m] && 'X'==f[n]){f[i]='W',f[l]='W',f[m]='W',f[n]='W';UserWins();}}
		StonesCounter();  // To count the played stones // if user didn't win yet so it will count the stones
		PCPlay();  // it is PC's turn
	}
	
	void UserWins(){  // If user won? this function will print the end
		ClearScr();
		q=' ';
		Drawing();
		cout<<"                  ---- Congradulations!, You Won The Game ----  \n";
		cout<<"                                 Play Again....? \n";
		cout<<"                            YES : Y            NO : N\n";
		cout<<"                            Enter Your Choice : ";
		cin>>q;
		if ((q=='y') || (q=='Y'))LoadingGame();
		else if ((q=='n') || (q=='N')){
			ClearScr();
			exit(0);
		}
		else UserWins();
	}
	
	void PCPlay(){ // If it is PC's Turn
		// This function will check if we choosed a hard pc or easy pc in the beginning 
		// then it will call the right function we choosed to be, easy or hard pc
		if(PCMod==true)PCEasyPlay();
		else PCHardPlay();
	}
		
	void PCEasyPlay(){  // Easy Playing PC (Dumb/Random)
		y=0;
		y=rand()%7+1; // to generate a number from 1->7
		CheckPCPlay();
	}
	
	void PCHardPlay(){  // Hard Playing PC ( Artificial Intelligence )
		i=0,l=0,m=0,n=0;
		y=0;

		for(i=1;i!=8;i++){if(b[i]=='X' && c[i]!='X' && c[i]!='O'){y=i;goto go;}}
		for(i=1;i!=8;i++){if(b[i]=='O' && c[i]!='X' && c[i]!='O'){y=i;goto go;}}
		
		for(i=1;i!=8;i++){if(a[i]=='X' && b[i]=='X' && c[i]!='X' && c[i]!='O'){y=i;goto go;}}
		for(i=1;i!=8;i++){if(b[i]=='X' && c[i]=='X' && d[i]!='X' && d[i]!='O'){y=i;goto go;}}
		for(i=1;i!=8;i++){if(c[i]=='X' && d[i]=='X' && e[i]!='X' && e[i]!='O'){y=i;goto go;}}
		
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if(a[i]=='X' && a[l]=='X' && a[m]=='X' && a[n]!='X' && a[n]!='O'){y=n;goto go;}}
		for(i=2,l=3,m=4,n=1;i!=6,l!=7,m!=8,n!=5;i++,l++,m++,n++){if(a[i]=='X' && a[l]=='X' && a[m]=='X' && a[n]!='X' && a[n]!='O'){y=n;goto go;}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if(b[i]=='X' && b[l]=='X' && b[m]=='X' && b[n]!='X' && b[n]!='O'){y=n;goto go;}}
		for(i=2,l=3,m=4,n=1;i!=6,l!=7,m!=8,n!=5;i++,l++,m++,n++){if(b[i]=='X' && b[l]=='X' && b[m]=='X' && b[n]!='X' && b[n]!='O'){y=n;goto go;}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if(c[i]=='X' && c[l]=='X' && c[m]=='X' && c[n]!='X' && c[n]!='O'){y=n;goto go;}}
		for(i=2,l=3,m=4,n=1;i!=6,l!=7,m!=8,n!=5;i++,l++,m++,n++){if(c[i]=='X' && c[l]=='X' && c[m]=='X' && c[n]!='X' && c[n]!='O'){y=n;goto go;}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if(d[i]=='X' && d[l]=='X' && d[m]=='X' && d[n]!='X' && d[n]!='O'){y=n;goto go;}}
		for(i=2,l=3,m=4,n=1;i!=6,l!=7,m!=8,n!=5;i++,l++,m++,n++){if(d[i]=='X' && d[l]=='X' && d[m]=='X' && d[n]!='X' && d[n]!='O'){y=n;goto go;}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if(e[i]=='X' && e[l]=='X' && e[m]=='X' && e[n]!='X' && e[n]!='O'){y=n;goto go;}}
		for(i=2,l=3,m=4,n=1;i!=6,l!=7,m!=8,n!=5;i++,l++,m++,n++){if(e[i]=='X' && e[l]=='X' && e[m]=='X' && e[n]!='X' && e[n]!='O'){y=n;goto go;}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if(f[i]=='X' && f[l]=='X' && f[m]=='X' && f[n]!='X' && f[n]!='O'){y=n;goto go;}}
		for(i=2,l=3,m=4,n=1;i!=6,l!=7,m!=8,n!=5;i++,l++,m++,n++){if(f[i]=='X' && f[l]=='X' && f[m]=='X' && f[n]!='X' && f[n]!='O'){y=n;goto go;}}
		
		for(i=2,l=3,m=1;i!=7,l!=8,m!=6;i++,l++,m++){if(a[i]=='X' && a[l]=='X' && a[m]!='X' && a[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(a[i]=='X' && a[l]=='X' && a[m]!='X' && a[m]!='O'){y=m;goto go;}}
		for(i=2,l=3,m=1;i!=7,l!=8,m!=6;i++,l++,m++){if(b[i]=='X' && b[l]=='X' && b[m]!='X' && b[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(b[i]=='X' && b[l]=='X' && b[m]!='X' && b[m]!='O'){y=m;goto go;}}
		for(i=2,l=3,m=1;i!=7,l!=8,m!=6;i++,l++,m++){if(c[i]=='X' && c[l]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(c[i]=='X' && c[l]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=2,l=3,m=1;i!=7,l!=8,m!=6;i++,l++,m++){if(d[i]=='X' && d[l]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(d[i]=='X' && d[l]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=2,l=3,m=1;i!=7,l!=8,m!=6;i++,l++,m++){if(e[i]=='X' && e[l]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(e[i]=='X' && e[l]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=2,l=3,m=1;i!=7,l!=8,m!=6;i++,l++,m++){if(f[i]=='X' && f[l]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(f[i]=='X' && f[l]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}} 
        
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}} 
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}} 
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}} 
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='X' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='X' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='X' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='X' && f[m]!='X' && f[m]!='O'){y=m;goto go;}} 
		
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=1,l=2,m=3;i!=6,l!=7,m!=8;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}} 
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}} 
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=3,l=1,m=2;i!=8,l!=6,m!=7;i++,l++,m++){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}} 
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(a[i]=='X' && b[l]=='X' && b[m]=='O' && c[m]!='X' && c[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(b[i]=='X' && c[l]=='X' && c[m]=='O' && d[m]!='X' && d[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(c[i]=='X' && d[l]=='X' && d[m]=='O' && e[m]!='X' && e[m]!='O'){y=m;goto go;}} 
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}}
		for(i=7,l=6,m=5;i!=2,l!=1,m!=0;i--,l--,m--){if(d[i]=='X' && e[l]=='X' && e[m]=='O' && f[m]!='X' && f[m]!='O'){y=m;goto go;}} 
        
		PCEasyPlay();  // If non of above conditions worked!, then PC will Play dumb/random
	go: CheckPCPlay();      
	}
	
	void CheckPCPlay(){  // Function to Check what PC Played
		PCPlayed=false;
		for(i=1;i!=8;i++){if(y==i && f[i]=='X'){PCPlay();}}
		for(i=1;i!=8;i++){if(y==i && f[i]=='O'){PCPlay();}}
		for(i=1;i!=8;i++){if(y==i && a[i]!='X' && a[i]!='O' && PCPlayed==false){a[i]='O';PCPlayed=true;CheckPCWinner();}}
		for(i=1;i!=8;i++){if(y==i && b[i]!='X' && b[i]!='O' && PCPlayed==false){b[i]='O';PCPlayed=true;CheckPCWinner();}}
		for(i=1;i!=8;i++){if(y==i && c[i]!='X' && c[i]!='O' && PCPlayed==false){c[i]='O';PCPlayed=true;CheckPCWinner();}}
		for(i=1;i!=8;i++){if(y==i && d[i]!='X' && d[i]!='O' && PCPlayed==false){d[i]='O';PCPlayed=true;CheckPCWinner();}}
		for(i=1;i!=8;i++){if(y==i && e[i]!='X' && e[i]!='O' && PCPlayed==false){e[i]='O';PCPlayed=true;CheckPCWinner();}}
		for(i=1;i!=8;i++){if(y==i && f[i]!='X' && f[i]!='O' && PCPlayed==false){f[i]='O';PCPlayed=true;CheckPCWinner();}}
		PCPlay();
	}	
	
	void CheckPCWinner(){  // Function to check if pc won
		for(i=1;i!=8;i++){if('O'==a[i] && 'O'==b[i] && 'O'==c[i] && 'O'==d[i]){a[i]='Z',b[i]='Z',c[i]='Z',d[i]='Z';PCWins();}}
		for(i=1;i!=8;i++){if('O'==b[i] && 'O'==c[i] && 'O'==d[i] && 'O'==e[i]){b[i]='Z',c[i]='Z',d[i]='Z',e[i]='Z';PCWins();}}
		for(i=1;i!=8;i++){if('O'==c[i] && 'O'==d[i] && 'O'==e[i] && 'O'==f[i]){c[i]='Z',d[i]='Z',e[i]='Z',f[i]='Z';PCWins();}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('O'==a[i] && 'O'==b[l] && 'O'==c[m] && 'O'==d[n]){a[i]='Z',b[l]='Z',c[m]='Z',d[n]='Z';PCWins();}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('O'==b[i] && 'O'==c[l] && 'O'==d[m] && 'O'==e[n]){b[i]='Z',c[l]='Z',d[m]='Z',e[n]='Z';PCWins();}}      
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('O'==c[i] && 'O'==d[l] && 'O'==e[m] && 'O'==f[n]){c[i]='Z',d[l]='Z',e[m]='Z',f[n]='Z';PCWins();}}
		for(i=4,l=3,m=2,n=1;i!=8,l!=7,m!=6,n!=5;i++,l++,m++,n++){if('O'==a[i] && 'O'==b[l] && 'O'==c[m] && 'O'==d[n]){a[i]='Z',b[l]='Z',c[m]='Z',d[n]='Z';PCWins();}}
		for(i=4,l=3,m=2,n=1;i!=8,l!=7,m!=6,n!=5;i++,l++,m++,n++){if('O'==b[i] && 'O'==c[l] && 'O'==d[m] && 'O'==e[n]){b[i]='Z',c[l]='Z',d[m]='Z',e[n]='Z';PCWins();}}
		for(i=4,l=3,m=2,n=1;i!=8,l!=7,m!=6,n!=5;i++,l++,m++,n++){if('O'==c[i] && 'O'==d[l] && 'O'==e[m] && 'O'==f[n]){c[i]='Z',d[l]='Z',e[m]='Z',f[n]='Z';PCWins();}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('O'==a[i] && 'O'==a[l] && 'O'==a[m] && 'O'==a[n]){a[i]='Z',a[l]='Z',a[m]='Z',a[n]='Z';PCWins();}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('O'==b[i] && 'O'==b[l] && 'O'==b[m] && 'O'==b[n]){b[i]='Z',b[l]='Z',b[m]='Z',b[n]='Z';PCWins();}}  
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('O'==c[i] && 'O'==c[l] && 'O'==c[m] && 'O'==c[n]){c[i]='Z',c[l]='Z',c[m]='Z',c[n]='Z';PCWins();}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('O'==d[i] && 'O'==d[l] && 'O'==d[m] && 'O'==d[n]){d[i]='Z',d[l]='Z',d[m]='Z',d[n]='Z';PCWins();}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('O'==e[i] && 'O'==e[l] && 'O'==e[m] && 'O'==e[n]){e[i]='Z',e[l]='Z',e[m]='Z',e[n]='Z';PCWins();}}
		for(i=1,l=2,m=3,n=4;i!=5,l!=6,m!=7,n!=8;i++,l++,m++,n++){if('O'==f[i] && 'O'==f[l] && 'O'==f[m] && 'O'==f[n]){f[i]='Z',f[l]='Z',f[m]='Z',f[n]='Z';PCWins();}}
		StonesCounter();  // To count the played stones // if user didn't win yet so it will count the stones
		UserPlay();  // It is PC's Turn
	}

	void PCWins(){  // If PC won? this function will print the end
		ClearScr();
		q=' ';
		Drawing();
		cout<<"                       ---- You Lost The Game ----  \n";
		cout<<"                                 Play Again....? \n";
		cout<<"                            YES : Y            NO : N\n";
		cout<<"                            Enter Your Choice : ";
		cin>>q;
		if ((q=='y') || (q=='Y'))LoadingGame();
		else if ((q=='n') || (q=='N')){
			ClearScr();
			exit(0);
		}
		else PCWins();
	}	
	
	void Drawing(){  // Drawing Function // it will draw the columns
		ClearScr();
		cout<<"                   _____ _____ _____ _____ _____ _____ _____  \n";
		cout<<"                  |     |     |     |     |     |     |     | \n";
		cout<<"                  |  "<<f[1]<<"  |  "<<f[2]<<"  |  "<<f[3]<<"  |  "<<f[4]<<"  |  "<<f[5]<<"  |  "<<f[6]<<"  |  "<<f[7]<<"  | \n";
		cout<<"                  |_____|_____|_____|_____|_____|_____|_____| \n";
		cout<<"                  |     |     |     |     |     |     |     | \n";
		cout<<"                  |  "<<e[1]<<"  |  "<<e[2]<<"  |  "<<e[3]<<"  |  "<<e[4]<<"  |  "<<e[5]<<"  |  "<<e[6]<<"  |  "<<e[7]<<"  | \n";
		cout<<"                  |_____|_____|_____|_____|_____|_____|_____| \n";
		cout<<"                  |     |     |     |     |     |     |     | \n";
		cout<<"                  |  "<<d[1]<<"  |  "<<d[2]<<"  |  "<<d[3]<<"  |  "<<d[4]<<"  |  "<<d[5]<<"  |  "<<d[6]<<"  |  "<<d[7]<<"  | \n";
		cout<<"                  |_____|_____|_____|_____|_____|_____|_____| \n";
		cout<<"                  |     |     |     |     |     |     |     | \n";
		cout<<"                  |  "<<c[1]<<"  |  "<<c[2]<<"  |  "<<c[3]<<"  |  "<<c[4]<<"  |  "<<c[5]<<"  |  "<<c[6]<<"  |  "<<c[7]<<"  | \n";
		cout<<"                  |_____|_____|_____|_____|_____|_____|_____| \n";
		cout<<"                  |     |     |     |     |     |     |     | \n";
		cout<<"                  |  "<<b[1]<<"  |  "<<b[2]<<"  |  "<<b[3]<<"  |  "<<b[4]<<"  |  "<<b[5]<<"  |  "<<b[6]<<"  |  "<<b[7]<<"  | \n";
		cout<<"                  |_____|_____|_____|_____|_____|_____|_____| \n";
		cout<<"                  |     |     |     |     |     |     |     | \n";
		cout<<"                  |  "<<a[1]<<"  |  "<<a[2]<<"  |  "<<a[3]<<"  |  "<<a[4]<<"  |  "<<a[5]<<"  |  "<<a[6]<<"  |  "<<a[7]<<"  | \n";
		cout<<"                  |_____|_____|_____|_____|_____|_____|_____| \n";
		cout<<"                     1     2     3     4     5     6     7    \n\n";
	} 
	
	void StonesCounter(){  // This Fucntion will end the game with DRAW (No Body Wins) if no body wins (Full Columns)
		j++;
		if(j>=42)NoOneWins(); // if the two players didn't win, and the columns are full then it will call (NoOneWins Function) and end the game
	}	
	
	void NoOneWins(){  //  If no one Wins
		ClearScr();
		q=' ';
		Drawing();
		cout<<"                               ---- D R A W ----  \n";
		cout<<"                                 Play Again....? \n";
		cout<<"                            YES : Y            NO : N\n";
		cout<<"                            Enter Your Choice : ";
		cin>>q;
		if ((q=='y') || (q=='Y'))LoadingGame();
		else if ((q=='n') || (q=='N')){
			ClearScr();
			exit(0);
		}
		else NoOneWins();
	}
	
	
	// OS CODES
	
	void ClearScr(){ // Clear Screen
	//	system("cls"); // For Windows
		system("clear"); // For Mac OS
	}
		
};



  
main(){
       Game g1;  // Object
	
       
}
