#include<iostream>
#include<cstdlib>
using namespace std;

int playervalue, computervalue;


void Game(){
    //selecting  random value
    computervalue=rand()% 3 + 1;

    //options for player
    cout<<"1 Rock"<<endl;
    cout<<"2 Paper"<<endl;
    cout<<"3 Scissor"<<endl;
    cout<<"Enter your option"<<endl;
    
    //Taking input from user
    cin>>playervalue;

    //Showing player option
    switch (playervalue)
    {
    case 1:
        cout<<"Your option Rock"<<endl;
        break;
    case 2:
        cout<<"Your option Paper"<<endl;
        break;
    case 3:
        cout<<"Your option Scissor"<<endl;
        break;
    
    default:
        cout<<"Invalid Option"<<endl;
        playervalue=true;
        break;
    }
    
    //algorithm
   if(playervalue==computervalue){
        cout<<"Draw"<<endl;
    }
    else if ((playervalue == 1 && computervalue == 3) || (playervalue == 2 && computervalue == 1) || (playervalue == 3 && computervalue == 1)){
        cout<<"You Win!"<<endl;
        cout<<"Computer Option is "<<computervalue<<endl;
    }
    else
    {
        cout<<"Computer Win"<<endl;
        cout<<"Computer Option is "<<computervalue<<endl;
    }

}

main(){

    Game();

    return 0; 
}