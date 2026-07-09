#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

class C4_Board {
    public:
        int board[7][6] = {0}; //Board
        int curr_cord = 0; // positon in x axis

        //Move Function
        void move(int idx,int move)
        {
            if(move%2==0){
                for(int i{5}; i>=0; i--){
                    if(board[idx-1][i]==0){
                        board[idx-1][i]=2;
                        curr_cord = i;
                        break;
                    }
                }
            }
            else{
                for(int i{5}; i>=0; i--){
                    if(board[idx-1][i]==0){
                        board[idx-1][i]=1;
                        curr_cord = i;
                        break;
                    }
                }
            }
        }

        //Display function
        void display() {
            for(int i{}; i<6; i++){
                for(int j{}; j<7; j++){
                    cout<<board[j][i]<<" ";
                }
                cout<<endl;
            }
            cout<<"-------------"<<endl;
            cout<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<endl;
        }

        //Win logic Function
        bool win(int idx,int curr_cord){
            int compare = board[idx][curr_cord];
            //Right diagonals
            if(idx+3<7 and curr_cord+3<6 and idx>=0 and curr_cord>=0){
                if(board[idx+1][curr_cord+1]==compare and board[idx+2][curr_cord+2]==compare and board[idx+3][curr_cord+3]==compare){
                    return true;
                }
            }
            if(idx-1>=0 and curr_cord-1>=0 and idx+2<7 and curr_cord+2<6){
                if(board[idx+1][curr_cord+1]==compare and board[idx+2][curr_cord+2]==compare and board[idx-1][curr_cord-1]==compare){
                    return true;
                }
            }
            if(idx-2>=0 and curr_cord-2>=0 and idx+1<7 and curr_cord+1<6){
                if(board[idx+1][curr_cord+1]==compare and board[idx-2][curr_cord-2]==compare and board[idx-1][curr_cord-1]==compare){
                    return true;
                }
            }
            if(idx-3>=0 and curr_cord-3>=0 and idx<7 and curr_cord<6){
                if(board[idx-3][curr_cord-3]==compare and board[idx-2][curr_cord-2]==compare and board[idx-1][curr_cord-1]==compare){
                    return true;
                }
            }

            //Left Diagonals
            if(idx+3<7 and curr_cord<6 and idx>=0 and curr_cord-3>=0){
                if(board[idx+1][curr_cord-1]==compare and board[idx+2][curr_cord-2]==compare and board[idx+3][curr_cord-3]==compare){
                    return true;
                }
            }
            if(idx-1>=0 and curr_cord-2>=0 and idx+2<7 and curr_cord+1<6){
                if(board[idx+1][curr_cord-1]==compare and board[idx+2][curr_cord-2]==compare and board[idx-1][curr_cord+1]==compare){
                    return true;
                }
            }
            if(idx-2>=0 and curr_cord-1>=0 and idx+1<7 and curr_cord+2<6){
                if(board[idx+1][curr_cord-1]==compare and board[idx-2][curr_cord+2]==compare and board[idx-1][curr_cord+1]==compare){
                    return true;
                }
            }
            if(idx-3>=0 and curr_cord>=0 and idx<7 and curr_cord+3<6){
                if(board[idx-3][curr_cord+3]==compare and board[idx-2][curr_cord+2]==compare and board[idx-1][curr_cord+1]==compare){
                    return true;
                }
            }

            //Horizontals

            if(idx+3<7 and idx>=0 and curr_cord>=0 and curr_cord<6){
                if(board[idx+1][curr_cord]==compare and board[idx+2][curr_cord]==compare and board[idx+3][curr_cord]==compare)
                return true;
            }
            if(idx-1>=0 and idx+2<7 and curr_cord>=0 and curr_cord<6){
                if(board[idx+1][curr_cord]==compare and board[idx+2][curr_cord]==compare and board[idx-1][curr_cord]==compare)
                return true;
            }
            if(idx-2>=0 and idx+1<7 and curr_cord>=0 and curr_cord<6){
                if(board[idx+1][curr_cord]==compare and board[idx-1][curr_cord]==compare and board[idx-2][curr_cord]==compare)
                return true;
            }
            if(idx-3>=0 and idx<7 and curr_cord>=0 and curr_cord<6){
                if(board[idx-1][curr_cord]==compare and board[idx-2][curr_cord]==compare and board[idx-3][curr_cord]==compare)
                return true;
            }

            //Vertical

            if(idx>=0 and idx<7 and curr_cord+3>=0 and curr_cord+3<6){
                if(board[idx][curr_cord+1]==compare and board[idx][curr_cord+2]==compare and board[idx][curr_cord+3]==compare){
                    return true;
                }
            }
            if(idx>=0 and idx<7 and curr_cord-1>=0 and curr_cord+2<6){
                if(board[idx][curr_cord+1]==compare and board[idx][curr_cord+2]==compare and board[idx][curr_cord-1]==compare){
                    return true;
                }
            }
            if(idx>=0 and idx<7 and curr_cord-2>=0 and curr_cord+1<6){
                if(board[idx][curr_cord+1]==compare and board[idx][curr_cord-2]==compare and board[idx][curr_cord-1]==compare){
                    return true;
                }
            }
            if(idx>=0 and idx<7 and curr_cord-3>=0 and curr_cord<6){
                if(board[idx][curr_cord-1]==compare and board[idx][curr_cord-2]==compare and board[idx][curr_cord-3]==compare){
                    return true;
                }
            }

            return false;
        }

};
//Main Functio
int main() {
    C4_Board *game = new C4_Board();

    int m = 1; //Move counter
    while (true) {
        game->display();
        int i{1};
        cin>>i;
        if(i>0 and i<=7){
            game->move(i,m);
        }
        else{
            cout<<"Out of bound! Retry"<<endl;
            m++;
        }
        if(game->win(i-1,game->curr_cord)){
            if(m%2==0){
                cout<<"Yayyy Player 2 have won!!!!!"<<endl;
            }
            else if(m%2!=0){
                cout<<"Yayyy Player 1 have won!!!!!"<<endl;
            }
            break;
        }
        m++;
    }

    delete game;
    m = 1;
    return 0;
}
