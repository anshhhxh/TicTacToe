#include<iostream>
using namespace std;
class TicTacToe{
        string player1;
        string player2;
        int chance=0;
    public:
    string a[10]={"","1","2","3","4","5","6","7","8","9"};
        int m=1;
    void base(){
        m=1;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(j==2){
                    cout<<a[m];
                
                }
                else{
                    cout<<a[m]<<" | ";
                }
                m++;
            }cout<<endl;
            if(i==2){
                break;                
                }
            else{
                cout<<" _  _  _"<<endl;;
            }
            cout<<endl;

        }
    }
    bool checkwin(){
        bool win=false;
        if(a[1]==a[2] && a[2]==a[3]){
            return true;
        }
        if(a[4]==a[5] && a[5]==a[6]){
            return true;
        }
        if(a[7]==a[8] && a[8]==a[9]){
            return true;
        }
        if(a[1]==a[4] && a[4]==a[7]){
            return true;
        }
        if(a[2]==a[5] && a[5]==a[8]){
            return true;
        }
        if(a[3]==a[6] && a[6]==a[9]){
            return true;
        }
        if(a[1]==a[5] && a[5]==a[9]){
            return true;
        }
        if(a[3]==a[5] && a[5]==a[7]){
            return true;
        }
    }
    int tie(){
        if(chance==9){
        return chance;
        }
        return 0;
    }
     void play() {
        do {
            cout << "Player1: Choose between X and O: ";
            cin >> player1;
            if (player1 == "x" || player1 == "o") break;
            cout << "Invalid choice! Please choose 'x' or 'o'.\n";
        } while (true);

        player2 = (player1 == "x") ? "o" : "x";

        int ch = 1, choice;
        base();

        do {
            cout << (ch % 2 != 0 ? "Player1" : "Player2") << ", enter a number (1-9): ";
            cin >> choice;

            if (choice < 1 || choice > 9 || a[choice] == "x" || a[choice] == "o") {
                cout << "Invalid input! Choose an empty position between 1 and 9.\n";
                continue;
            }

            a[choice] = (ch % 2 != 0) ? player1 : player2;
            base();
            chance++;
            ch++;

            if (checkwin()) {
                cout << "Congratulations! " << ((ch % 2 == 0) ? "Player1" : "Player2") << " wins!\n";
                break;
            }

            if (tie()) {
                cout << "It's a tie!\n";
                break;
            }
        } while (true);
    }
};


int main(){
    int again;
    TicTacToe t1;
    do{
        t1.play();
        cout<<"Do you wish to play again?       1/0.......";
        cin>>again;
        if(again==0){
            cout<<"The End!!!";
            break;
        }
    }while(1);
    
    return 0;
}