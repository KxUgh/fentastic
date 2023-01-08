#include<bits/stdc++.h>
#include "pograph.h"

using namespace pograph;

const Color DARK_SQUARES(172,129,94);
const Color LIGHT_SQUARES(228,206,172);
const int SQUARE_WIDTH = 132;
const int SQUARE_HEIGHT = 132;
const Pixel TRANSPARENCY(Color(0,255,0));

Sprite WHITE_KING("pieces/white_king.ppm",TRANSPARENCY);
Sprite WHITE_QUEEN("pieces/white_queen.ppm",TRANSPARENCY);
Sprite WHITE_ROOK("pieces/white_rook.ppm",TRANSPARENCY);
Sprite WHITE_BISHOP("pieces/white_bishop.ppm",TRANSPARENCY);
Sprite WHITE_KNIGHT("pieces/white_knight.ppm",TRANSPARENCY);
Sprite WHITE_PAWN("pieces/white_pawn.ppm",TRANSPARENCY);
Sprite BLACK_KING("pieces/black_king.ppm",TRANSPARENCY);
Sprite BLACK_QUEEN("pieces/black_queen.ppm",TRANSPARENCY);
Sprite BLACK_ROOK("pieces/black_rook.ppm",TRANSPARENCY);
Sprite BLACK_BISHOP("pieces/black_bishop.ppm",TRANSPARENCY);
Sprite BLACK_KNIGHT("pieces/black_knight.ppm",TRANSPARENCY);
Sprite BLACK_PAWN("pieces/black_pawn.ppm",TRANSPARENCY);
Sprite EMPTY_SQUARE = Sprite();


Sprite* board[8][8];


void usage(char* name){
    printf("    Usage:\n");
    printf("%s [output_file.ppm] [FEN]\n",name);
}

void interpretFEN(std::string fen, char* program){
    int boardX=0;
    int boardY=0;

    for(int i=0;i<=(int)fen.size();++i){
        if(boardY==7&&boardX>7) return;
        if(fen[i]=='/'){
            boardX=0;
            ++boardY;
        }else if(fen[i]>='1'&& fen[i]<='8'){
            boardX+= fen[i]-'0';
        }else if(fen[i]=='K'){
            board[boardX][boardY] = &WHITE_KING;
            ++boardX;
        }else if(fen[i]=='Q'){
            board[boardX][boardY] = &WHITE_QUEEN;
            ++boardX;
        }else if(fen[i]=='R'){
            board[boardX][boardY] = &WHITE_ROOK;
            ++boardX;
        }else if(fen[i]=='B'){
            board[boardX][boardY] = &WHITE_BISHOP;
            ++boardX;
        }else if(fen[i]=='N'){
            board[boardX][boardY] = &WHITE_KNIGHT;
            ++boardX;
        }else if(fen[i]=='P'){
            board[boardX][boardY] = &WHITE_PAWN;
            ++boardX;
        }else if(fen[i]=='k'){
            board[boardX][boardY] = &BLACK_KING;
            ++boardX;
        }else if(fen[i]=='q'){
            board[boardX][boardY] = &BLACK_QUEEN;
            ++boardX;
        }else if(fen[i]=='r'){
            board[boardX][boardY] = &BLACK_ROOK;
            ++boardX;
        }else if(fen[i]=='b'){
            board[boardX][boardY] = &BLACK_BISHOP;
            ++boardX;
        }else if(fen[i]=='n'){
            board[boardX][boardY] = &BLACK_KNIGHT;
            ++boardX;
        }else if(fen[i]=='p'){
            board[boardX][boardY] = &BLACK_PAWN;
            ++boardX;
        }else{
            usage(program);
            printf("Invalid FEN\n");
            exit(1);
        }
    }
    usage(program);
    printf("Invalid FEN\n");
    exit(1);
}


int main(int argc, char**argv){
    char* program = *argv++;

    if(argc!=3){
        usage(program);
        printf("Invalid number of arguments\n");
        exit(1);
    }
    char* output = *argv++;
    char* fen = *argv++;
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            board[i][j] = &EMPTY_SQUARE;
        }
    }
    
    interpretFEN(fen,program);

    Canvas canvas(SQUARE_WIDTH*8,SQUARE_HEIGHT*8);
    canvas.fillBackground(DARK_SQUARES);
    Rect lightSquare(Point(0,0),132,132,LIGHT_SQUARES);

    for(int y=0;y<8;++y){
        for(int x=0;x<8;++x){
            if((x+y)%2==0){
                lightSquare.corner = Point(x*SQUARE_WIDTH,y*SQUARE_HEIGHT);
                canvas.drawRect(lightSquare);
            }
        }
    }
    for(int y=0;y<8;++y){
        for(int x=0;x<8;++x){
            canvas.drawSprite(*board[x][y],x*SQUARE_WIDTH,y*SQUARE_HEIGHT);
        }
    }
    generatePPM(output,canvas);

    return 0;
}