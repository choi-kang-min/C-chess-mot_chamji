#include<stdio.h> //   (다 알다시피)기본적으로 사용하는 헤더파일
#include<string.h> //   여러가지로 사용하는 헤더파일
#include<windows.h> //   system("cls") 등을 사용하기 위한 헤더파일
#include<stdlib.h> //   난수나 여러가지 것들을 사용하기 위한 헤더파일
#include<conio.h> //   노래 재생을 위한 헤더파일
#include<mmsystem.h> //   노래 재생을 위한 헤더파일
#include<memory.h> //   파일 입출력을 위한 헤더파일
#pragma comment(lib,"winmm.lib") //   노래 재생을 위한 파일
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //   콘솔창 입력바를 보이지 않게 하기 위한 코드
void setcursortype(CURSOR_TYPE c) { 
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
int hamsu(int o, int p); //   말 함수
int king_check();
int queen_check();
int rook_check();
int bishop_check();
int knight_check();
int black_pawn_check();
int white_pawn_check();
int upgrade(int v, int d); //   폰의 승급(좌표 2개 입력 받음)
int endgame(); //   게임 종료 함수
int high_q(); //   게임이 처음 시작할 때에만 실행되는 함수
int kill(); //   말 죽이는 함수
int random_color(); //   색깔리 랜덤으로 나오는 함수
int quallity(); //   말 알림창에서의 재미있는 함수
int qwer(); //   처음 체스를 둘 때 점점 빠르게 놓아지는 걸 구현하기 위한 함수
int moonuei();       //비어있는 곳은 이걸로  //사용
int panbyeoul(); //   어떤 말을 선택했는지에 따라서 함수를 실행하는 함수
int nintendo(int asap); //   switch문으로
int count_turn(); //사용
int retry();
char chess_pan_backup[10][10][4] = { {"Rb", "Nb", "Bb", "Kb", "Qb", "Bb", "Nb", "Rb"},/*1칸*/ {"Pb", "Pb", "Pb", "Pb", "Pb", "Pb", "Pb", "Pb"},/*2칸*/ {""},/*3칸*/ {"",""},/*4칸*/ {"", ""},/*5칸*/ {""},/*6칸*/  {"Pw", "Pw", "Pw", "Pw", "Pw", "Pw", "Pw", "Pw"},/*7칸*/{"Rw", "Nw", "Bw", "Kw", "Qw", "Bw", "Nw", "Rw"}/*8칸*/  ,{""}, {""} };
char chess_pan[10][10][4] = { {"Rb", "Nb", "Bb", "Kb", "Qb", "Bb", "Nb", "Rb"},/*1칸*/ {"Pb", "Pb", "Pb", "Pb", "Pb", "Pb", "Pb", "Pb"},/*2칸*/ {""},/*3칸*/ {"Nw",""},/*4칸*/ {"Rb", "", "", "Bw", "Qb", "Kw"},/*5칸*/ {""},/*6칸*/  {"Pw", "Pw", "Pw", "Pw", "Pw", "Pw", "Pw", "Pw"},/*7칸*/{"Rw", "Nw", "Bw", "", "Qw", "Bw", "Nw", "Rw"}/*8칸*/  ,{""}, {""}};
//1. 말 종류, 2.  말 색깔, 3. 말 선택, g= 선택, c = 이동 가능 d = 죽이기 가능, k = 체크 4. 폰 전용 2칸 가기 함수 및 앙파상, 승진 함수 g = 2칸, a = 앙파상,
//R = 룩, N = 나이트, B = 비숍, Q = 퀸, K = 킹, P = 폰
void purple_char() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); }
void sky_char() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); }
void blue_char() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); }
void black_char() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); }
void yellow_char() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); }
void white_char() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); }
void green_char() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); }
void red_char() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); }
void dwhite_char() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); }
void gray_char() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); }
int choice_height;  //사용
int choice_widch;  //사용
char choice_widch_char; //사용
int move_height;
int move_widch;
char move_widch_char;
int turn = 0;//말 그대로 턴 계산   /사용
int count_pan = 1;
int i, j;//체스판 반복문 전용 변수   //사용
int random_;
int pop = 0;
int asdf;
int stop_sec = 75;
int upgrade1 = 0, upgrade2 = 0; //
int a = 0; //   quallity함수에서 사용되는 변수
int ending; //   종료를 도와주는 함수
int redo = 0; //   다시 입력하기 위한 변수
int bye; //   종료하기 위한 변수

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	setcursortype(NOCURSOR); //   커서 없앰
	system("mode con cols=40 lines=35"); //   콘솔 창 크기 설정
	Sleep(500);
	high_q(); //   처음 한정으로 
	PlaySound(TEXT("amo.wav"), 0, SND_FILENAME | SND_ASYNC);
	tutorial(); //   말 그대로 기본적인 것들
	system("cls");
	PlaySound(TEXT("set.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //   노래 재생코드
	gray_char();
	printf("\n     --------- white turn!!! ---------\n");
	Sleep(150);
	system("cls");
	dwhite_char();
	printf("\n     --------- white turn!!! ---------\n");
	Sleep(150);
	system("cls");
	white_char();
	printf("\n     --------- white turn!!! ---------\n");
	Sleep(150);
	printf("\n");
	for (i = 0; i < 8; i++) //   체스판 그리는 함수, 1회 최초 한정
	{
		yellow_char();
		printf(" -%d-", 8 - i);
		printf(" ");
		for (j = 0; j < 8; j++)
		{
			if (chess_pan[i][j][1] == 'b') {
				blue_char();
				if (chess_pan[i][j][2] == 'g')
					purple_char();
				else if (chess_pan[i][j][2] == 'd')
					red_char();
				printf(" [%c]", chess_pan[i][j][0]);
				qwer();
			}
			else if (chess_pan[i][j][1] == 'w') {
				yellow_char();
				if (chess_pan[i][j][2] == 'g')
					purple_char();
				else if (chess_pan[i][j][2] == 'd')
					red_char();
				printf(" [%c]", chess_pan[i][j][0]);//체스판
				qwer();
			}
			else { //비어있는 부분으로 체크무늬로 되에잇는 체스판의 배경을 나타냄
				if (i % 2 == 0 && j % 2 == 0 || i % 2 != 0 && j % 2 != 0)
					white_char();
				else
					sky_char();
				if (chess_pan[i][j][2] == 'c')
					green_char();
				printf(" [ ]");
				qwer();
			}
		}
		printf("\n\n");
	}
	yellow_char();
	PlaySound(TEXT("back.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
	printf("      -A- -B- -C- -D- -E- -F- -G- -H-");
	printf("\n\n");
	while (1) {//   말 선택부터 말 이동까지의 오ㅏ일문
		while (1) {//   말 선택에서의 오ㅏ일문
			sky_char();
			printf("\n\n   움직일 말을 선택하셈 : ");
			scanf(" %c %d", &choice_widch_char, &choice_height);
			choice_height -= 1;
			choice_widch = nintendo(choice_widch_char); 
			if (choice_widch == 8) {
				system("cls");
				moonuei();
				printf("\a좌표를 범위 안에 입력해주세요\n");
				continue;
			}
			else if (choice_height < 0 || choice_height>7) {
				system("cls");
				moonuei();
				printf("\a  좌표를 범위 안에 입력해주세요\n");
				continue;
			}
			if (!(choice_height > 0 && choice_height < 7)) {
				if (choice_widch == 8) {
					system("cls");
					moonuei();
					printf("\a  좌표를 범위 안에 입력해주세요\n");
					continue;
				}
			}
			if (turn == 0) {
				if (chess_pan[7 - choice_height][choice_widch][1] == 'b') {
					system("cls");
					moonuei();
					printf("\a - 하얀 말의 턴입니다. \n   하얀 말을 선택해주세요\n");
					continue;
				}
			}
			else if (turn == 1) {
				if (chess_pan[7 - choice_height][choice_widch][1] == 'w') {
					system("cls");
					moonuei();
					printf("\a - 검은 말의 턴입니다. \n   검은 말을 선택해주세요\n");
					continue;
				}
			}
			if (chess_pan[7 - choice_height][choice_widch][0] == NULL) {
				system("cls");
				moonuei();
				printf("\a  비...비었어??");
				continue;
			}
			break;
		}
		/// ///////////////////////////////////////////////////////////////////////////////////////////////////
		chess_pan[7 - choice_height][choice_widch][2] = 'g';
		system("cls");
		panbyeoul();
		moonuei();
		while (1) {
			sky_char();
			printf("\n\n  이동할 곳을 선택하셈 : ");
			scanf(" %c %d", &move_widch_char, &move_height);
			move_height -= 1;
			move_widch = nintendo(move_widch_char); //이제 이 코드는 제것입니다.
			if (move_widch == 8) {
				system("cls");
				moonuei();
				printf("\a  좌표를 범위 안에 입력해주세요\n");
				continue;
			}
			else if (move_height < 0 || move_height>7) {
				system("cls");
				moonuei();
				printf("\a  좌표를 범위 안에 입력해주세요\n");
				continue;
			}
			if (!(move_height > 0 && move_height < 7)) {
				if (move_widch == 8) {
					system("cls");
					moonuei();
					printf("\a  좌표를 범위 안에 입력해주세요\n");
					continue;
				}
			}
			if (chess_pan[7 - move_height][move_widch][2] == NULL) {
				system("cls");
				moonuei();
				if (chess_pan[7 - move_height][move_widch][1] == 'w') {
					if (turn == 0) printf("\a  본인의 팀입니다.\n");
					else printf("상대팀 말입니다.\n");
				}
				else if (chess_pan[7 - move_height][move_widch][1] == 'b') {
					if (turn == 1) printf("\a  본인의 팀입니다.\n");
					else printf("상대팀 말입니다.\n");
				}
				else {
					printf("\a  뭐...뭐야.. 아무것도 없잖아!\n");
				}
				continue;
			}
			if (chess_pan[7 - move_height][move_widch][2] == 'g') {
				system("cls");
				moonuei();
				redo = 1;
				break;
			}
			if (chess_pan[7 - move_height][move_widch][2] == 't') {
				quallity();
				continue;
			}
			if (chess_pan[7 - move_height][move_widch][2] == 'c' || chess_pan[7 - move_height][move_widch][2] == 'd' || chess_pan[7 - move_height][move_widch][2] == 'a')
				break;
			else {
				system("cls");
				moonuei();
				printf("\a  오류\n");
			}
		} //이동
		if (redo == 0) { //   다시하기를 하지 않으면
			if (chess_pan[7 - move_height][move_widch][2] == 'a') { //   앙파상 
				kill();
				if (chess_pan[7 - choice_height][choice_widch + 1][2] == 'a') {
					chess_pan[7 - move_height - 1][move_widch][0] = chess_pan[7 - choice_height][choice_widch][0];
					chess_pan[7 - move_height - 1][move_widch][1] = chess_pan[7 - choice_height][choice_widch][1];
					chess_pan[7 - move_height - 1][move_widch][2] = chess_pan[7 - choice_height][choice_widch][2];
					chess_pan[7 - move_height][move_widch][0] = NULL;
					chess_pan[7 - move_height][move_widch][1] = NULL;
					chess_pan[7 - move_height][move_widch][2] = NULL;
				}
				else { //   앙파상 반대쪽
					chess_pan[7 - move_height - 1][move_widch][0] = chess_pan[7 - choice_height][choice_widch][0];
					chess_pan[7 - move_height - 1][move_widch][1] = chess_pan[7 - choice_height][choice_widch][1];
					chess_pan[7 - move_height - 1][move_widch][2] = chess_pan[7 - choice_height][choice_widch][2];

					chess_pan[7 - move_height][move_widch][0] = NULL;
					chess_pan[7 - move_height][move_widch][1] = NULL;
					chess_pan[7 - move_height][move_widch][2] = NULL;
				}

			}
			if (chess_pan[7 - move_height][move_widch][2] == 'c') { //   이동
				chess_pan[7 - move_height][move_widch][0] = chess_pan[7 - choice_height][choice_widch][0];
				chess_pan[7 - move_height][move_widch][1] = chess_pan[7 - choice_height][choice_widch][1];
				chess_pan[7 - move_height][move_widch][2] = chess_pan[7 - choice_height][choice_widch][2];
			}
			else if (chess_pan[7 - move_height][move_widch][2] == 'd') { //   말 죽이는 코드
				kill(); //   말 죽이는 함수
			}
			int aa = 0, aaa = 7; //   함수에게 값을 전달하기 위한 변수
			for (int m = 0; m < 8; m++) {
				if (chess_pan[0][m][0] == 'P') {
					upgrade1 = 1;
					upgrade(aa, m); //   폰 - 승진함수 - 하얀말
				}
				else if (chess_pan[7][m][0] == 'P') {
					upgrade2 = 1;
					upgrade(aaa, m); //   폰 - 승진함수 - 검은말
				}
			} //   이동한 후 이전에 있었던 곳의 흔적을 없애지 위한 코드
			chess_pan[7 - choice_height][choice_widch][0] = NULL;
			chess_pan[7 - choice_height][choice_widch][1] = NULL;
			chess_pan[7 - choice_height][choice_widch][2] = NULL;
			system("cls");
			for (int q = 0; q < 10; q++) { //   효과 없애기
				for (int w = 0; w < 10; w++) {
					chess_pan[q][w][2] = NULL;
				}
			}
			ending = endgame();
			if (ending == 1||ending == -1) {
				PlaySound(TEXT("back.wav"), 0, SND_FILENAME | SND_ASYNC );
				system("cls");
				moonuei();
				if (ending == 1) {
					printf("\n\n    white win!");
				}
				else if (ending == -1) {
					printf("\n\n    black win!");
				}
				Sleep(2000);
				while (1) {
					printf("\n\n      게임을 다시할까요?\n        1. 못참지     2. 아뇨\n   ");
					scanf(" %d", &bye);
					if (bye == 1) {
						retry();
						if (ending == 1) {
							PlaySound(TEXT("back.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
						}
						if (ending == -1) {
							PlaySound(TEXT("check.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
						}
						break;
					}
					else if (bye == 2)
						return 0;
				}
				turn = 1;
			}
			count_turn(); //   턴을 세 줌 - 1/검은말, 0/하얀말
			
		}
		else {
			redo = 0;
			for (int q = 0; q < 10; q++) { //   다시 해도 효과 없애야함
				for (int w = 0; w < 10; w++) {
					chess_pan[q][w][2] = NULL;
				}
			}
		}
		system("cls"); //   말 없애기 다시 세팅
		moonuei();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int hamsu(int o, int p) {
	if (o < 0 || o > 7) return 0;
	if (p < 0 || p > 7) return 0;
	if (chess_pan[o][p][0] != '\0') {
		if (chess_pan[o][p][1] == 'w')
			chess_pan[o][p][2] = (turn == 0) ? 't' : 'd';
		else if (chess_pan[o][p][1] == 'b')
			chess_pan[o][p][2] = (turn == 1) ? 't' : 'd';
	}
	else
		chess_pan[o][p][2] = 'c';
}
int kill() {
	chess_pan[7 - move_height][move_widch][0] = NULL;
	chess_pan[7 - move_height][move_widch][1] = NULL;
	chess_pan[7 - move_height][move_widch][2] = NULL;
	chess_pan[7 - move_height][move_widch][0] = chess_pan[7 - choice_height][choice_widch][0];
	chess_pan[7 - move_height][move_widch][1] = chess_pan[7 - choice_height][choice_widch][1];
	chess_pan[7 - move_height][move_widch][2] = chess_pan[7 - choice_height][choice_widch][2];
}
int king_check() {/////////////////////////////////////////////////////////////////////완성
	printf("k");
	hamsu(7 - choice_height+1, choice_widch);
	hamsu(7 - choice_height+1, choice_widch+1);
	hamsu(7 - choice_height+1, choice_widch-1);
	hamsu(7 - choice_height, choice_widch+1);
	hamsu(7 - choice_height, choice_widch-1);
	hamsu(7 - choice_height-1, choice_widch+1);
	hamsu(7 - choice_height-1, choice_widch-1);
	hamsu(7 - choice_height-1, choice_widch);

}
int queen_check() {//////////////////////////////////////////////////////////////////////////////완성
	printf("q");
	//위
	for (int tired1 = 1; tired1 < 8; tired1++) {
		if (7 - choice_height - tired1 < 0 || 7 - choice_height - tired1 > 7)
			break;
		else if (choice_widch < 0 || choice_widch > 7)
			break;
		if (chess_pan[7 - choice_height - tired1][choice_widch][0] != '\0') {
			if (chess_pan[7 - choice_height - tired1][choice_widch][1] == 'w')
				chess_pan[7 - choice_height - tired1][choice_widch][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height - tired1][choice_widch][1] == 'b')
				chess_pan[7 - choice_height - tired1][choice_widch][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height - tired1][choice_widch][2] = 'c';
	}//아래
	for (int tired2 = 1; tired2 < 8; tired2++) {
		if (7 - choice_height + tired2 < 0 || 7 - choice_height + tired2 > 7)
			break;
		else if (choice_widch < 0 || choice_widch>7)
			break;
		if (chess_pan[7 - choice_height + tired2][choice_widch][0] != '\0') {
			if (chess_pan[7 - choice_height + tired2][choice_widch][1] == 'w')
				chess_pan[7 - choice_height + tired2][choice_widch][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height + tired2][choice_widch][1] == 'b')
				chess_pan[7 - choice_height + tired2][choice_widch][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height + tired2][choice_widch][2] = 'c';
	}//오른쪽
	for (int tired3 = 1; tired3 < 8; tired3++) {
		if (7 - choice_height < 0 || 7 - choice_height > 7)
			break;
		else if (choice_widch + tired3 < 0 || choice_widch + tired3 > 7)
			break;
		if (chess_pan[7 - choice_height][choice_widch + tired3][0] != '\0') {
			if (chess_pan[7 - choice_height][choice_widch + tired3][1] == 'w')
				chess_pan[7 - choice_height][choice_widch + tired3][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height][choice_widch + tired3][1] == 'b')
				chess_pan[7 - choice_height][choice_widch + tired3][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height][choice_widch + tired3][2] = 'c';
	}//왼쪽
	for (int tired4 = 1; tired4 < 8; tired4++) {
		if (7 - choice_height < 0 || 7 - choice_height > 7)
			break;
		else if (choice_widch - tired4 < 0 || choice_widch - tired4 > 7)
			break;
		if (chess_pan[7 - choice_height][choice_widch - tired4][0] != '\0') {
			if (chess_pan[7 - choice_height][choice_widch - tired4][1] == 'w')
				chess_pan[7 - choice_height][choice_widch - tired4][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height][choice_widch - tired4][1] == 'b')
				chess_pan[7 - choice_height][choice_widch - tired4][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height][choice_widch - tired4][2] = 'c';
	} //왼위
	for (int tired5 = 1; tired5 < 8; tired5++) {
		if (7 - choice_height - tired5 < 0 || 7 - choice_height - tired5 > 7)
			break;
		else if (choice_widch - tired5 < 0 || choice_widch - tired5 > 7)
			break;
		if (chess_pan[7 - choice_height - tired5][choice_widch - tired5][0] != '\0') {
			if (chess_pan[7 - choice_height - tired5][choice_widch - tired5][1] == 'w')
				chess_pan[7 - choice_height - tired5][choice_widch - tired5][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height - tired5][choice_widch - tired5][1] == 'b')
				chess_pan[7 - choice_height - tired5][choice_widch - tired5][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height - tired5][choice_widch - tired5][2] = 'c';
	} //왼아래
	for (int tired6 = 1; tired6 < 8; tired6++) {
		if (7 - choice_height + tired6 < 0 || 7 - choice_height + tired6 > 7)
			break;
		else if (choice_widch - tired6 < 0 || choice_widch - tired6 > 7)
			break;
		if (chess_pan[7 - choice_height + tired6][choice_widch - tired6][0] != '\0') {
			if (chess_pan[7 - choice_height + tired6][choice_widch - tired6][1] == 'w')
				chess_pan[7 - choice_height + tired6][choice_widch - tired6][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height + tired6][choice_widch - tired6][1] == 'b')
				chess_pan[7 - choice_height + tired6][choice_widch - tired6][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height + tired6][choice_widch - tired6][2] = 'c';
	} //오아래
	for (int tired7 = 1; tired7 < 8; tired7++) {
		if (7 - choice_height + tired7 < 0 || 7 - choice_height + tired7 > 7)
			break;
		else if (choice_widch + tired7 < 0 || choice_widch + tired7 > 7)
			break;
		if (chess_pan[7 - choice_height + tired7][choice_widch + tired7][0] != '\0') {
			if (chess_pan[7 - choice_height + tired7][choice_widch + tired7][1] == 'w')
				chess_pan[7 - choice_height + tired7][choice_widch + tired7][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height + tired7][choice_widch + tired7][1] == 'b')
				chess_pan[7 - choice_height + tired7][choice_widch + tired7][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height + tired7][choice_widch + tired7][2] = 'c';
	} //오위
	for (int tired8 = 1; tired8 < 8; tired8++) {
		if (7 - choice_height - tired8 < 0 || 7 - choice_height - tired8 > 7)
			break;
		else if (choice_widch + tired8 < 0 || choice_widch + tired8 > 7)
			break;
		if (chess_pan[7 - choice_height - tired8][choice_widch + tired8][0] != '\0') {
			if (chess_pan[7 - choice_height - tired8][choice_widch + tired8][1] == 'w')
				chess_pan[7 - choice_height - tired8][choice_widch + tired8][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height - tired8][choice_widch + tired8][1] == 'b')
				chess_pan[7 - choice_height - tired8][choice_widch + tired8][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height - tired8][choice_widch + tired8][2] = 'c';
	}
}
int rook_check() {///////////////////////////////////////////////////////////////////////////완성
	printf("r");
	//위
	for (int tired1 = 1; tired1 < 8; tired1++) {
		if (7 - choice_height - tired1 < 0 || 7 - choice_height - tired1 > 7)
			break;
		else if (choice_widch < 0 || choice_widch > 7)
			break;
		if (chess_pan[7 - choice_height - tired1][choice_widch][0] != '\0') {
			if (chess_pan[7 - choice_height - tired1][choice_widch][1] == 'w')
				chess_pan[7 - choice_height - tired1][choice_widch][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height - tired1][choice_widch][1] == 'b')
				chess_pan[7 - choice_height - tired1][choice_widch][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height - tired1][choice_widch][2] = 'c';
	}//아래
	for (int tired2 = 1; tired2 < 8; tired2++) {
		if (7 - choice_height + tired2 < 0 || 7 - choice_height + tired2 > 7)
			break;
		else if (choice_widch < 0 || choice_widch>7)
			break;
		if (chess_pan[7 - choice_height + tired2][choice_widch][0] != '\0') {
			if (chess_pan[7 - choice_height + tired2][choice_widch][1] == 'w')
				chess_pan[7 - choice_height + tired2][choice_widch][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height + tired2][choice_widch][1] == 'b')
				chess_pan[7 - choice_height + tired2][choice_widch][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height + tired2][choice_widch][2] = 'c';
	}//오른쪽
	for (int tired3 = 1; tired3 < 8; tired3++) {
		if (7 - choice_height < 0 || 7 - choice_height > 7)
			break;
		else if (choice_widch + tired3 < 0 || choice_widch + tired3 > 7)
			break;
		if (chess_pan[7 - choice_height][choice_widch + tired3][0] != '\0') {
			if (chess_pan[7 - choice_height][choice_widch + tired3][1] == 'w')
				chess_pan[7 - choice_height][choice_widch + tired3][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height][choice_widch + tired3][1] == 'b')
				chess_pan[7 - choice_height][choice_widch + tired3][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height][choice_widch + tired3][2] = 'c';
	}//왼쪽
	for (int tired4 = 1; tired4 < 8; tired4++) {
		if (7 - choice_height < 0 || 7 - choice_height > 7)
			break;
		else if (choice_widch - tired4 < 0 || choice_widch - tired4 > 7)
			break;
		if (chess_pan[7 - choice_height][choice_widch - tired4][0] != '\0') {
			if (chess_pan[7 - choice_height][choice_widch - tired4][1] == 'w')
				chess_pan[7 - choice_height][choice_widch - tired4][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height][choice_widch - tired4][1] == 'b')
				chess_pan[7 - choice_height][choice_widch - tired4][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height][choice_widch - tired4][2] = 'c';
		
	}
}
int bishop_check() {///////////////////////////////////////////////////////////////////////////////////완성
	printf("b"); //왼위
	for (int tired5 = 1; tired5 < 8; tired5++) {
		if (7 - choice_height - tired5 < 0 || 7 - choice_height - tired5 > 7)
			break;
		else if (choice_widch - tired5 < 0 || choice_widch - tired5 > 7)
			break;
		if (chess_pan[7 - choice_height - tired5][choice_widch - tired5][0] != '\0') {
			if (chess_pan[7 - choice_height - tired5][choice_widch - tired5][1] == 'w')
				chess_pan[7 - choice_height - tired5][choice_widch - tired5][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height - tired5][choice_widch - tired5][1] == 'b')
				chess_pan[7 - choice_height - tired5][choice_widch - tired5][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height - tired5][choice_widch - tired5][2] = 'c';
	} //왼아래
	for (int tired6 = 1; tired6 < 8; tired6++) {
		if (7 - choice_height + tired6 < 0 || 7 - choice_height + tired6 > 7)
			break;
		else if (choice_widch - tired6 < 0 || choice_widch - tired6 > 7)
			break;
		if (chess_pan[7 - choice_height + tired6][choice_widch - tired6][0] != '\0') {
			if (chess_pan[7 - choice_height + tired6][choice_widch - tired6][1] == 'w')
				chess_pan[7 - choice_height + tired6][choice_widch - tired6][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height + tired6][choice_widch - tired6][1] == 'b')
				chess_pan[7 - choice_height + tired6][choice_widch - tired6][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height + tired6][choice_widch - tired6][2] = 'c';
	} //오아래
	for (int tired7 = 1; tired7 < 8; tired7++) {
		if (7 - choice_height + tired7 < 0 || 7 - choice_height + tired7 > 7)
			break;
		else if (choice_widch + tired7 < 0 || choice_widch + tired7 > 7)
			break;
		if (chess_pan[7 - choice_height + tired7][choice_widch + tired7][0] != '\0') {
			if (chess_pan[7 - choice_height + tired7][choice_widch + tired7][1] == 'w')
				chess_pan[7 - choice_height + tired7][choice_widch + tired7][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height + tired7][choice_widch + tired7][1] == 'b')
				chess_pan[7 - choice_height + tired7][choice_widch + tired7][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height + tired7][choice_widch + tired7][2] = 'c';
	} //오위
	for (int tired8 = 1; tired8 < 8; tired8++) {
		if (7 - choice_height - tired8 < 0 || 7 - choice_height - tired8 > 7)
			break;
		else if (choice_widch + tired8 < 0 || choice_widch + tired8 > 7)
			break;
		if (chess_pan[7 - choice_height - tired8][choice_widch + tired8][0] != '\0') {
			if (chess_pan[7 - choice_height - tired8][choice_widch + tired8][1] == 'w')
				chess_pan[7 - choice_height - tired8][choice_widch + tired8][2] = (turn == 0) ? 't' : 'd';
			else if (chess_pan[7 - choice_height - tired8][choice_widch + tired8][1] == 'b')
				chess_pan[7 - choice_height - tired8][choice_widch + tired8][2] = (turn == 1) ? 't' : 'd';
			break;
		}
		else chess_pan[7 - choice_height - tired8][choice_widch + tired8][2] = 'c';
	}
}
int knight_check() {
	printf("n");//앞오
	hamsu(7 - choice_height+2, choice_widch+1);
	hamsu(7 - choice_height+2, choice_widch-1);
	hamsu(7 - choice_height+1, choice_widch+2);
	hamsu(7 - choice_height+1, choice_widch-2);
	hamsu(7 - choice_height-1, choice_widch+2);
	hamsu(7 - choice_height-1, choice_widch-2);
	hamsu(7 - choice_height-2, choice_widch+1);
	hamsu(7 - choice_height-2, choice_widch-1);

}
int white_pawn_check() {/////////////////////////////////////////////////////////////////완성
	printf("wp");//앞
	chess_pan[7 - choice_height][choice_widch][3] = '\0';
	if (chess_pan[7 - choice_height - 1][choice_widch][0] != '\0') {
		if (chess_pan[7 - choice_height - 1][choice_widch][1] == 'w')
			chess_pan[7 - choice_height - 1][choice_widch][2] = (turn == 0) ? 't' : NULL;
		else if (chess_pan[7 - choice_height - 1][choice_widch][1] == 'b')
			chess_pan[7 - choice_height - 1][choice_widch][2] = (turn == 1) ? 't' : NULL;
	}
	else
		chess_pan[7 - choice_height - 1][choice_widch][2] = 'c';
	//오른쪽
	if (chess_pan[7 - choice_height - 1][choice_widch + 1][0] != '\0') {
		if (chess_pan[7 - choice_height - 1][choice_widch + 1][1] == 'w')
			chess_pan[7 - choice_height - 1][choice_widch + 1][2] = (turn == 0) ? 't' : 'd';
		else if (chess_pan[7 - choice_height - 1][choice_widch + 1][1] == 'b')
			chess_pan[7 - choice_height - 1][choice_widch + 1][2] = (turn == 1) ? 't' : 'd';
	}
	//왼쪽
	if (chess_pan[7 - choice_height - 1][choice_widch - 1][0] != '\0') {
		if (chess_pan[7 - choice_height - 1][choice_widch - 1][1] == 'w')
			chess_pan[7 - choice_height - 1][choice_widch - 1][2] = (turn == 0) ? 't' : 'd';
		else if (chess_pan[7 - choice_height - 1][choice_widch - 1][1] == 'b')
			chess_pan[7 - choice_height - 1][choice_widch - 1][2] = (turn == 1) ? 't' : 'd';
	}
	//두칸 앞
	if (chess_pan[7 - choice_height - 2][choice_widch][0] == '\0' && choice_height == 1) {
		chess_pan[7 - choice_height - 2][choice_widch][2] = 'c';
	}
	if (7 - choice_height == 3) {
		if (chess_pan[7 - choice_height][choice_widch + 1][0] == 'P' && chess_pan[7 - choice_height][choice_widch + 1][1] == 'b') {
			chess_pan[7 - choice_height][choice_widch + 1][2] = 'a';
		}
		else if (chess_pan[7 - choice_height][choice_widch - 1][0] == 'p' && chess_pan[7 - choice_height][choice_widch - 1][1] == 'b') {
			chess_pan[7 - choice_height][choice_widch - 1][2] = 'a';
		}
	}
}
int black_pawn_check() {//완성
	printf("bp");// 뒤
	if (chess_pan[7 - choice_height + 1][choice_widch][0] != '\0') {
		if (chess_pan[7 - choice_height + 1][choice_widch][1] == 'w')
			chess_pan[7 - choice_height + 1][choice_widch][2] = (turn == 0) ? 't' : NULL;
		else if (chess_pan[7 - choice_height + 1][choice_widch][1] == 'b')
			chess_pan[7 - choice_height + 1][choice_widch][2] = (turn == 1) ? 't' : NULL;
	}
	else
		chess_pan[7 - choice_height + 1][choice_widch][2] = 'c';
	//오른쪽
	if (chess_pan[7 - choice_height + 1][choice_widch + 1][0] != '\0') {
		if (chess_pan[7 - choice_height + 1][choice_widch + 1][1] == 'w')
			chess_pan[7 - choice_height + 1][choice_widch + 1][2] = (turn == 0) ? 't' : 'd';
		else if (chess_pan[7 - choice_height + 1][choice_widch + 1][1] == 'b')
			chess_pan[7 - choice_height + 1][choice_widch + 1][2] = (turn == 1) ? 't' : 'd';
	}
	//왼쪽
	if (chess_pan[7 - choice_height + 1][choice_widch - 1][0] != '\0') {
		if (chess_pan[7 - choice_height + 1][choice_widch - 1][1] == 'w')
			chess_pan[7 - choice_height + 1][choice_widch - 1][2] = (turn == 0) ? 't' : 'd';
		else if (chess_pan[7 - choice_height + 1][choice_widch - 1][1] == 'b')
			chess_pan[7 - choice_height + 1][choice_widch - 1][2] = (turn == 1) ? 't' : 'd';
	}
	//두칸 앞
	if (chess_pan[7 - choice_height + 2][choice_widch][0] == '\0' && choice_height == 6) {
		chess_pan[7 - choice_height + 2][choice_widch][2] = 'c';
	}
	if (7 - choice_height == 3) {
		if (chess_pan[7 - choice_height][choice_widch + 1][0] == 'P' && chess_pan[7 - choice_height][choice_widch + 1][1] == 'w') {
			chess_pan[7 - choice_height][choice_widch + 1][2] = 'a';
		}
		else if (chess_pan[7 - choice_height][choice_widch - 1][0] == 'p' && chess_pan[7 - choice_height][choice_widch - 1][1] == 'w') {
			chess_pan[7 - choice_height][choice_widch - 1][2] = 'a';
		}
	}
}
int moonuei() {  //체스판 그리는 함수/////////////////////////////////////////////////////////////
	white_char();
	printf("\n     --------- ");
	if (turn == 0)
	{
		white_char();
		printf("white turn!!!");
	}
	else if (turn == 1) {
		blue_char();
		printf("black turn!!!");
	}
	white_char();
	printf(" ---------\n");
	printf("\n");
	for (i = 0; i < 8; i++)
	{
		yellow_char();
		printf(" -%d-", 8 - i);
		printf(" ");
		for (j = 0; j < 8; j++)
		{
			if (chess_pan[i][j][1] == 'b') {
				blue_char();
				if (chess_pan[i][j][2] == 'g')
					purple_char();
				else if (chess_pan[i][j][2] == 'd') {
					red_char();
				}
				else if (chess_pan[i][j][2] == 'a') {
					red_char();
				}
				printf(" [%c]", chess_pan[i][j][0]);//체스판
			}
			else if (chess_pan[i][j][1] == 'w') {
				yellow_char();
				if (chess_pan[i][j][2] == 'g')
					purple_char();
				else if (chess_pan[i][j][2] == 'd') {
					red_char();
				}
				else if (chess_pan[i][j][2] == 'a') {
					red_char();
				}
				printf(" [%c]", chess_pan[i][j][0]);//체스판
			}
			else {
				if (i % 2 == 0 && j % 2 == 0 || i % 2 != 0 && j % 2 != 0)
					white_char();
				else
					sky_char();
				if (chess_pan[i][j][2] == 'c')
					green_char();
				printf(" [");
				if (chess_pan[i][j][2] == 'c') printf("*");
				else printf(" ");
				printf("]");
			}
		}
		printf("\n\n");
	}
	yellow_char();
	printf("      -A- -B- -C- -D- -E- -F- -G- -H-\n\n");
}
int tutorial() {
	int q = 0;
	while (q < 55) {
		system("cls");
		random_color();
		printf("\n\n\n\n                제작자\n\n            최강민 - 조윤겸");
		yellow_char();
		printf("\n         (feat.312호의 망령들)");
		Sleep(25);
		q++;
	}
	getch();
	system("cls");
	PlaySound(TEXT("pass.wav"), 0, SND_FILENAME | SND_ASYNC);
	printf("\n\n\n                 <안내>\n\n");
	white_char();
	Sleep(30);
	printf("   K = 왕(king)\n");
	Sleep(30);
	printf("   Q = 여왕(queen)\n");
	Sleep(30);
	printf("   B = 비숍(bishop)\n");
	Sleep(30);
	printf("   N = 나이트(knight)\n");
	Sleep(30);
	printf("   R = 룩(rook)\n");
	Sleep(30);
	printf("   P = 폰(pawn)\n\n");
	Sleep(30);
	purple_char();
	printf("        분홍색");
	Sleep(30);
	white_char();
	printf("은 검은 말,\n");
	Sleep(30);
	yellow_char();
	printf("        노란색");
	Sleep(30);
	white_char();
	printf("은 하얀 말임.\n");
	Sleep(30);
	getch();
	PlaySound(TEXT("pass.wav"), 0, SND_FILENAME | SND_ASYNC);
	printf("\n       말을 선택/이동할 때는 \n       하단에 있는 ");
	Sleep(30);
	yellow_char();
	printf("알파벳");
	Sleep(30);
	white_char();
	printf("과 \n       왼쪽에 있는 ");
	Sleep(30);
	yellow_char();
	printf("숫자");
	Sleep(30);
	white_char();
	printf("순으로 \n       좌표를 입력하셈.");
	Sleep(30);
	sky_char();
	printf("\n\n     예시 (A2 -> 맨 왼쪽 하얀색 폰)");
	printf("\n\n\n          enter로 게임 시작!!");
	getch();
}
int nintendo(int asap) {
	switch (asap) {
	case 'a':
	case 'A':
		return 0;
		break;
	case 'b':
	case 'B':
		return 1;
		break;
	case 'c':
	case 'C':
		return 2;
		break;
	case 'd':
	case 'D':
		return 3;
		break;
	case 'e':
	case 'E':
		return 4;
		break;
	case 'f':
	case 'F':
		return 5;
		break;
	case 'g':
	case 'G':
		return 6;
		break;
	case 'h':
	case 'H':
		return 7;
		break;
	default:
		return 8;
		break;
	}
}
int count_turn() {
	switch (turn) {
	case 0:
		turn = 1;
		break;
	case 1:
		turn = 0;
		break;
	}
}
int panbyeoul() {
	if (chess_pan[7 - choice_height][choice_widch][0] == 'P') {
		if (chess_pan[7 - choice_height][choice_widch][1] == 'b')
			black_pawn_check();
		else if (chess_pan[7 - choice_height][choice_widch][1] == 'w')
			white_pawn_check();
	}
	else if (chess_pan[7 - choice_height][choice_widch][0] == 'R')
		rook_check();
	else if (chess_pan[7 - choice_height][choice_widch][0] == 'N')
		knight_check();
	else if (chess_pan[7 - choice_height][choice_widch][0] == 'B')
		bishop_check();
	else if (chess_pan[7 - choice_height][choice_widch][0] == 'Q')
		queen_check();
	else if (chess_pan[7 - choice_height][choice_widch][0] == 'K')
		king_check();
	else printf("oryu");
}
int qwer() {
	Sleep(stop_sec);
	stop_sec -= 1;
}
int random_color() {
	random_ = rand() % 8;
	switch (random_) {
	case 0:
		purple_char();
		break;
	case 1:
		black_char();
		break;
	case 2:
		white_char();
		break;
	case 3:
		sky_char();
		break;
	case 4:
		blue_char();
		break;
	case 5:
		green_char();
		break;
	case 6:
		red_char();
		break;
	case 7:
		yellow_char();
		break;
	default:
		random_color();
		break;
	}
}
int quallity() {
	system("cls");
	moonuei();
	if (a == 0) {
		printf("  본인의 팀입니다. \n");
		a++;
	}
	else if (a == 1) {
		printf("  같은 팀입니다. \n");
		a++;
	}
	else if (a == 2) {
		printf("  본인과 같은 팀입니다;;\n");
		a++;
	}
	else if (a == 3) {
		printf("  님 팀이리고요\n");
		a++;
	}
	else if (a == 4) {
		printf("  님 팀이라니까?\n");
		a++;
	}
	else if (a == 5) {
		printf("  님 팀이라고!\n");
		a++;
	}
	else if (a == 6) {
		printf("  ...\n");
		a++;
	}
	else {
		printf("도대체 왜 저러는 거지?\n");
	}
}
int upgrade(int v, int d){
	while (1) {
		system("cls");
		moonuei();
		int ac, oryu = 0;
		printf("\n\n\n\n  용사여 본인은 무엇을 원하나?\n\n");
		ac, oryu = 0;
		printf("  1. 나는 룩(R)이 되고 싶다.\n");
		printf("  2. 본인은 비숍(B)이 되고 싶군.\n");
		printf("  3. 저는 나이트(N)가 되려 합니다.\n");
		printf("  4. 자신을 퀸(Q)으로 승급한다.\n");
		printf("  5. 나는 나 자신이 좋소. \n\n    응답 : ");
		scanf(" %d", &ac);
		system("cls");
		moonuei();
		printf("\n\n");
		switch (ac) {
		case 1:
			printf("  굳이? 일단 ㄱ");
			Sleep(1000);
			chess_pan[v][d][0] = 'R';
			Sleep(1000);
			getchar();
			break;
		case 2:
			printf("  굳이? 일단 ㄱ");
			Sleep(1000);
			chess_pan[v][d][0] = 'B';
			Sleep(1000);
			getchar();
			break;
		case 3:
			printf("  당신같은 폰을 기다려왔다능");
			Sleep(1000);
			chess_pan[v][d][0] = 'N';
			Sleep(1000);
			getchar();
			break;
		case 4:
			printf("  당신은 퀸(Q)으로 승급하였습니다.");
			Sleep(1000);
			chess_pan[v][d][0] = 'Q';
			Sleep(1000);
			getchar();
			break;
		case 5:
			printf("  안돼 안 바꿔줘, 바꿀 생각 없어\n  빨리 돌아가");
			Sleep(2000);
			oryu = 1;
			getchar();
			break;
		case 6:
			printf("  ...?");
			Sleep(1000);
			oryu = 1;
			getchar();
			break;
		default:
			printf("  미안하지만 나.. 거지야...");
			Sleep(1000);
			oryu = 1;
			getchar();
			break;
		}
		
		if (oryu == 1) continue;
		break;
	}
}
int endgame(){
	int tempo = 0, why;
	for (int q = 0; q < 10; q++) { //   효과 없애기
		for (int w = 0; w < 10; w++) {
			if (chess_pan[q][w][0] == 'K') tempo++;
		}
	}
	if (tempo == 2) why = 0;
	else if (tempo != 2 && turn == 0) why = 1;
	else if (tempo != 2 && turn == 1) why = -1;
	return why;
}
int high_q() {
	gray_char();
	printf("\n\n\n\n         최상의 플레이를 위해 \n  프롬프트 창을 검은색으로 바꿔주세요\n         (막 누르지 말아주셈)");
	Sleep(50);
	system("cls");
	dwhite_char();
	printf("\n\n\n\n         최상의 플레이를 위해 \n  프롬프트 창을 검은색으로 바꿔주세요\n         (막 누르지 말아주셈)");
	white_char();
	Sleep(50);
	system("cls");
	printf("\n\n\n\n         최상의 플레이를 위해 \n  프롬프트 창을 검은색으로 바꿔주세요\n         (막 누르지 말아주셈)");
	dwhite_char();
	Sleep(2000);
	system("cls");
	printf("\n\n\n\n         최상의 플레이를 위해 \n  프롬프트 창을 검은색으로 바꿔주세요\n         (막 누르지 말아주셈)");
	gray_char();
	Sleep(30);
	system("cls");
	printf("\n\n\n\n         최상의 플레이를 위해 \n  프롬프트 창을 검은색으로 바꿔주세요\n         (막 누르지 말아주셈)");
	Sleep(30);
	system("cls");
	Sleep(1000);
	PlaySound(TEXT("altale.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
	yellow_char();//1
	Sleep(500);
	printf("\n\n\n           D\n");
	Sleep(40);
	system("cls");//2
	printf("\n\n\n           D\n");
	printf("           D\n");
	Sleep(60);
	system("cls");//3
	printf("\n\n\n           D\n");
	printf("           D\n");
	sky_char();
	printf("           D\n");
	Sleep(70);
	yellow_char();
	system("cls");//4
	printf("\n\n\n\n           D\n");
	sky_char();
	printf("           D\n");
	printf("      DDD  DDDD   DDD   DDD   DDD\n");
	Sleep(80);
	system("cls");//5
	printf("\n\n\n\n\n           D\n");
	printf("      DDD  DDDD   DDD   DDD   DDD\n");
	blue_char();
	printf("     D   D D   D D   D D     D\n");
	Sleep(100);
	sky_char();
	system("cls");//6
	printf("\n\n\n\n\n\n      DDD  DDDD   DDD   DDD   DDD\n");
	blue_char();
	printf("     D   D D   D D   D D     D\n");
	printf("     D     D   D DDDDD  DDD   DDD\n");
	Sleep(80);
	system("cls");
	printf("\n\n\n\n\n\n\n     D   D D   D D   D D     D\n");
	printf("     D     D   D DDDDD  DDD   DDD\n");
	black_char();
	printf("     D   D D   D D         D     D\n");
	Sleep(60);
	blue_char();
	system("cls");
	printf("\n\n\n\n\n\n\n\n     D     D   D DDDDD  DDD   DDD\n");
	black_char();
	printf("     D   D D   D D         D     D\n");
	printf("      DDD  D   D  DDD   DDD   DDD\n");
	Sleep(40);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n     D   D D   D D         D     D\n");
	printf("      DDD  D   D  DDD   DDD   DDD\n");
	Sleep(20);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n      DDD  D   D  DDD   DDD   DDD\n");
	Sleep(100);
	system("cls");
	printf("\n\n\n\n\n\n\n     D   D D   D D   D D     D\n");
	printf("     D     D   D DDDDD  DDD   DDD\n");
	black_char();
	printf("     D   D D   D D         D     D\n");
	Sleep(80);
	system("cls");
	printf("\n\n\n\n\n           D\n");
	printf("      DDD  DDDD   DDD   DDD   DDD\n");
	blue_char();
	printf("     D   D D   D D   D D     D\n");
	Sleep(80);
	system("cls");
	Sleep(80);
	system("cls");
	yellow_char();
	printf("\n\n\n");
	printf("           D                            \n");
	printf("           D\n");
	yellow_char();
	sky_char();
	printf("           D                            \n");
	printf("      DDD  DDDD   DDD   DDD   DDD       \n");
	blue_char();
	printf("     D   D D   D D   D D     D          \n");
	printf("     D     D   D DDDDD  DDD   DDD       \n");
	black_char();
	printf("     D   D D   D D         D     D      \n");
	printf("      DDD  D   D  DDD   DDD   DDD       \n");
	Sleep(100);
	system("cls");
	Sleep(100);
	yellow_char();
	printf("\n\n----------------------------------------\n");
	printf("---------- D ---------------------------\n");
	printf("---------- D ");
	yellow_char();
	printf("---------------------------\n");
	sky_char();
	printf("---------- D ---------------------------\n");
	printf("----- DDD  DDDD   DDD   DDD   DDD ------\n");
	blue_char();
	printf("---- D   D D   D D   D D     D    ------\n");
	printf("---- D     D   D DDDDD  DDD   DDD  -----\n");
	black_char();
	printf("---- D   D D   D D         D     D -----\n");
	printf("----  DDD  D   D  DDD   DDD   DDD  -----\n");
	Sleep(440);
	system("cls");
	yellow_char();
	printf("\n\n----------------------------------------\n");
	printf("---------- D ---------------------------\n");
	printf("---------- D ");
	yellow_char();
	printf("-- wow! so amazing! -------\n");
	sky_char();
	printf("---------- D ---------------------------\n");
	printf("----- DDD  DDDD   DDD   DDD   DDD ------\n");
	blue_char();
	printf("---- D   D D   D D   D D     D    ------\n");
	printf("---- D     D   D DDDDD  DDD   DDD  -----\n");
	black_char();
	printf("---- D   D D   D D         D     D -----\n");
	printf("----  DDD  D   D  DDD   DDD   DDD  -----\n");
	white_char();
	printf("\n\n\n\n              Please ");
	yellow_char();
	printf("enter             \n        'Enter'");
	white_char();
	printf(" key to start(?)         ");
	white_char();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n  \n  - Copyright belongs to\n    Kang_min and Yoon_gyeom.");
	while (!kbhit());
}
int retry() {
	for (int j = 0; j < 8; j++) {
		for (int k = 0; k < 8; k++) {
			for (int l = 0; l < 4; l++) {
				chess_pan[j][k][l] = chess_pan_backup[j][k][l];
			}
		}
	}
}