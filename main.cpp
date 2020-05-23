#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <random>
#include <algorithm>

using namespace std;

class MemoryMatchGame{
public:
  void startGame(){
    auto gen = default_random_engine(time(0));
    shuffle(elements, elements + 50,gen);
    clearScreen();
    level=getlevel();
    clearScreen();
    speed=getSpeed();
    clearScreen();
    nElements=getNElements();
    nRows=getNRows();
    getBoardElements();
    getSolutionBoard();
    playGame();


  }
private:
  int width=12;
  string theme="Periodic Table Elements";
  string face="Element";
  string _level;
  string _speed;
  int level;
  int speed;
  string solutionBoard[8][8];
  bool conditionBoard[8][8];
  string boardElements[64];
  string board[8][8];
  int nElements;
  int nRows;
  int firstr;
  int firstc;
  int secondr;
  int secondc;
  string _firstr;
  string _firstc;
  string _secondr;
  string _secondc;

  string elements[50]={"Hydrogen","Helium","Lithium","Beryllium","Boron","Carbon","Nitrogen","Oxygen","Fluorine","Neon","Sodium","Magnesium","Aluminum","Silicon","Phosphorus","Sulfur","Chlorine","Argon","Potassium","Calcium","Scandium","Titanium","Vanadium","Chromium","Manganese","Iron","Cobalt","Nickel","Copper","Zinc","Gallium","Germanium","Arsenic","Selenium","Bromine","Krypton","Rubidium","Strontium","Yttrium","Zirconium","Niobium","Molybdenum","Technetium","Ruthenium","Rhodium","Palladium","Silver","Cadmium","Indium","Tin"};
  int score=0;

  int getlevel(){
    cout<<"WELCOME TO THE MEMORY MATCHING GAME BASED ON PERIODIC TABLE ELEMENTS."<<endl;
    cout<<endl;
    cout<<"Please Select Level Of Play."<<endl;
    cout<<endl;
    cout<<"Press 1 for 4X4 grid (Easy)"<<endl;
    cout<<"Press 2 for 6X6 grid (Moderate)"<<endl;
    cout<<"Press 3 for 8X8 grid (Hard)"<<endl;

    while (true){
            cin>>_level;
            if ((_level!="1")and(_level!="2")and(_level!="3")){
                cout<<"Invalid Level. Please Press a valid button"<<endl;
            }else{
                return stoi(_level);
                break;}
        }
  }
  void clearScreen(){
    for (int i=0;i<300;i++){
      cout<<"\n";
      cout<<flush;
    }
  }
  int getSpeed(){
      cout<<"---------------------MEMORY MATCH GAME---------------------------"<<endl;
      cout<<"Level : "<<level<<endl;
      cout<<endl;
      cout<<"Please Select Speed Of Play."<<endl;
      cout<<endl;
      cout<<"Press 1 for a time gap of 2 seconds (Hard)"<<endl;
      cout<<"Press 2 for a time gap of 4 seconds (Moderate)"<<endl;
      cout<<"Press 3 for a time gap of 6 seconds (Easy)"<<endl;

      while (true){
        cin>>_speed;
        if ((_speed!="1")and(_speed!="2")and(_speed!="3")){
            cout<<"Invalid Speed. Please Enter a valid speed: "<<endl;
        }else{
            return stoi( _speed );
            break;}
    }
  }
  int getNElements(){
      if(level==1){return 16;}
      else if (level==2){return 36;}
      else{return 64;}
    }
  int getNRows(){
      if(level==1){return 4;}
      else if (level==2){return 6;}
      else{return 8;}
    }
  void getBoardElements(){
      for(int i=0;i<(nElements/2);i++){
        boardElements[2*i]=elements[i];
        boardElements[2*i+1]=elements[i];
      }
      auto gen=default_random_engine(time(0));
      shuffle(boardElements, boardElements + nElements,gen);
   }
  void getSolutionBoard(){
    int x=0;
    for (int i=0;i<nRows;i++){
        for (int j=0;j<nRows;j++){
            solutionBoard[i][j]=boardElements[x];
            conditionBoard[i][j]=false;
            x++;
        }
    }
  }
  void getBoard(){
      for (int i=0;i<nRows;i++){
        for (int j=0;j<nRows;j++){
            if (conditionBoard[i][j]){
                board[i][j]=solutionBoard[i][j];
            }else{board[i][j]=face;}
        }
    }
  }
  bool finished(){
      bool x=true;
      for (int i=0;i<nRows;i++){
        for(int j=0;j<nRows;j++){
            if (conditionBoard[i][j]==false){
                x=false;
                break;
            }
        }
        if (x==false){
            break;
        }
        }
   return x;
  }
  void sleep(float seconds){
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    while(clock() < startClock+secondsAhead){;}
}
  void getConditionBoard(bool x){
      if (x==true){conditionBoard[firstr][firstc]=true;
        conditionBoard[secondr][secondc]=true;
      }else{
          conditionBoard[firstr][firstc]=true;
          conditionBoard[secondr][secondc]=true;
          score-=2;
          cout<<"WRONG GUESS. SCORE DEDUCTED BY 2 POINTS!"<<endl;
          cout<<endl;
          showBoard();
          sleep(2.0*speed);
          conditionBoard[firstr][firstc]=false;
          conditionBoard[secondr][secondc]=false;
          clearScreen();
      }
}
  void getInput(){
      cout<<"Enter Row of First Card:";
      while (true){
        cin>>_firstr;
        if (isdigit(_firstr[0])==false){
            cout<<"Invalid Row For First Card. Please Enter a valid Row: ";
        }else{
            firstr= stoi( _firstr);
            if(firstr>0 && firstr<nRows+1){
                    firstr-=1;
                break;
            }else{cout<<"Invalid Row For First Card. Please Enter a valid Row: ";}
            }
        }
      cout<<"Enter Column of First Card:";
      while (true){
        cin>>_firstc;
        if (isdigit(_firstc[0])==false){
            cout<<"Invalid Column For First Card. Please Enter a valid Column: ";
        }else{
            firstc= stoi( _firstc );
            if(firstc>0 && firstc<nRows+1){
                    firstc-=1;
                break;
            }else{cout<<"Invalid Column For First Card. Please Enter a valid Column: ";}
            }
        }
       cout<<"Enter Row of Second Card:";
       while (true){
         cin>>_secondr;
         if (isdigit(_secondr[0])==false){
            cout<<"Invalid Row For Second Card. Please Enter a valid Row: ";
        }else{
            secondr= stoi( _secondr );
            if(secondr>0 && secondr<nRows+1){
                    secondr-=1;
                break;
            }else{cout<<"Invalid Row For Second Card. Please Enter a valid Row: ";}
            }
        }
       cout<<"Enter Column of Second Card:";
       while (true){
         cin>>_secondc;
         if (isdigit(_secondc[0])==false){
            cout<<"Invalid Column For Second Card. Please Enter a valid Column: ";
        }else{
            secondc= stoi( _secondc );
            if(secondc>0 && secondc<nRows+1){
                    secondc-=1;
                break;
            }else{cout<<"Invalid Column For Second Card. Please Enter a valid Column: ";}
            }
        }
  }
  void showBoard(){
          getBoard();
          cout<<left;
          cout<<setw(width)<<"";
          for (int i=0;i<nRows;i++){
            cout<<left;
            cout<<setw(width)<<i+1;
            cout<<right;
          }
          cout<<endl;
          for (int i=0;i<nRows;i++){
            cout<<left;
            cout<<setw(width-3)<<i+1;
            for (int j=0;j<nRows;j++){
                cout<<setw(width)<<board[i][j];
            }
            cout<<right;
            cout<<endl;
            cout<<endl;
          }
  }
  void showSolution(){
      for(int i=0;i<nRows;i++){
        for(int j=0;j<nRows;j++){
            cout<<setw(width)<<solutionBoard[i][j];
        }
        cout<<endl;
      }
  }
  void playGame(){
      while (true){
          if(finished()){break;}
          cout<<"-------------------------------MEMORY MATCH GAME-----------------------------"<<endl;
          cout<<"Level : "<<level<<"          "<<"Speed : "<<2*speed<<"seconds"<<"          "<<"Score : "<<score<<endl;
          cout<<endl;
          cout<<"-------------------------------------Board-----------------------------------"<<endl;
          cout<<endl;
          cout<<endl;
          showBoard();
          getInput();
          clearScreen();
          int x=gameLogic();
          if (x==0){
            cout<<endl;
            cout<<"You chose an already chosen card. Try Again!"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
          }
          else if(x==1){
            cout<<endl;
            cout<<"First And Second Card Can't Be Same."<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
          }
          else{continue;}
    }
    showBoard();
    cout<<"You have successfully completed this game with a score of "<<score<<" points."<<endl;
    cout<<"Well Done!"<<endl;
    string final;
    cin>>final;

  }
  int gameLogic(){
    bool res=false;
    if (conditionBoard[firstr][firstc]==true||conditionBoard[secondr][secondc]==true){
            return 0;}
    else if(firstr==secondr&&firstc==secondc){return 1;}
    else{
    if (solutionBoard[firstr][firstc]==solutionBoard[secondr][secondc]){res=true;}
    if (res){score+=10;}
    getConditionBoard(res);
    return 2;
    }
  }
};

int main(){
    MemoryMatchGame x;
    x.startGame();
  return 0;
}
