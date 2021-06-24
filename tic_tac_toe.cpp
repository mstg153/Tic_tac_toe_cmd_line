//Sai Teja

#include<bits/stdc++.h>

using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char user_symbol;
int user_no;


void draw_board(){
	cout<<" "<<board[0][0]<<" | "<<board[0][1]<< " | "<<board[0][2]<<endl;
	cout<<"-----------"<<endl;
	cout<<" "<<board[1][0]<<" | "<<board[1][1]<< " | "<<board[1][2]<<endl;
	cout<<"-----------"<<endl;
	cout<<" "<<board[2][0]<<" | "<<board[2][1]<< " | "<<board[2][2]<<endl;
}

void place_marker(int n){
	if(n>9 || n<1)
		cout<<"!!ERROR"<<endl;
	
	int row=(n-1)/3;
	int col= (n-1) %3;
	if(board[row][col] == 'X' || board[row][col]=='O'){
		cout<<"Already Marked"<<":"<<"choose another"<<endl;
		cout<<"It's "<<user_no<< " \'s : enter position"<<endl;
		cin>>n;
		place_marker(n);
	}
	else
		board[row][col] = user_symbol;
}

bool result(){
	for(int i=0;i<3;i++){
		if(board[i][0]== board[i][1] && board[i][1]== board[i][2] )
			return 1;
		if(board[0][i]== board[1][i] && board[1][i]== board[2][i] )
			return 1;
	}
	if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
		return 1;
	if(board[2][0]==board[1][1] && board[1][1] ==board[0][2] )
		return 1;
	return 0;
}

void swap_detials(){
	if(user_symbol=='X')
		user_symbol='O';
	else 
		user_symbol='X';

	if(user_no== 1)
		user_no =2;
	else user_no=1;
}

void play(){
	cout<<"Choose user_marker"<<endl;
	cin>>user_symbol;
	user_no=1;
	draw_board();
	int winner=0;
	for(int i=0;i<9;i++){
		int n;
		cout<<"It's "<<user_no<< " \'s : enter position"<<endl;
		cin>>n;
		place_marker(n);
		draw_board();
		if(result()){
			winner= user_no;
			break;
		}
		
		swap_detials();
	}
	if(winner!= 0)
		cout<<winner<<"  "<<"WINS" <<endl;
	else 
		cout<<"Its a TIE"<<endl;
}


int main(){
	
	play();
	return 0;
}
