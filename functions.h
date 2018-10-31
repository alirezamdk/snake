/* Snake ..              *
** Play  : 29/8/1396    **
** start : 5/9/96       **
** make by Ario :P      **
*                       */


#include <iostream>
#include <iomanip>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <vector>
#include <fstream>

#define GOTO_COR gotoxy( 0 , 0 );
#define GOTO_FIR gotoxy( 0 , 10 ) ;
#define SCORES 5
#define MENU 20
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
#define SNAKE_LEN 4
using namespace std;


/* global variables */
COORD coord = { 0 , 0 } ;//-----for GOTOXY function 2d variable

int speed ; //-------------Speed VAR
int m ; //-----------------Rectangle Width
int n ; //-----------------Rectangle height
int snake_color_code ; //--snake color code
int length = SNAKE_LEN + 1 ; //-----Length VAR
int Move ; //-------------------Move VAR
int i ; //----------------------Loop counter
int j ; //----------------------Loop counter
int x ; //----------------------location snake _ X _ 50% M
int y ; //----------------------location snake _ Y _ 50% N
int t_x ;//---------------------arrived to food bet variable x
int t_y ;//---------------------arrived to food bet variable y
int S = 0 ;//-------------------For array scores counter
int bug = 2 ; //----------------For fix a small bug !
int Score[SCORES] = {0} ;//-----Score array initialize
char dir ; //-------------------Direction
bool eat = true ;//-------------eat a food bet variable
bool temp_delete = true ;//-----for Delete function
bool menu_[2] ; //--------------for menus
int p[4] ; //-------------------for file

vector<int> Move_ ( length ) ;
vector<int> X_ ( length );
vector<int> Y_ ( length );
/* global variables */

void gotoxy(int x, int y) //goto x y function
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void sc(int a) //color function
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}
void print_rec ( bool** rec)
{
    cout << endl ;
    for ( i = 0 ; i <= n ; i++ )
    {
        for ( j = 0 ; j <= m * 2 ; j++ )
        {
            cout << rec [ i ] [ j ]  ;
        }
        cout << endl ;
    }

}
void Food (bool** rec )
{
    if ( x == t_x && y == t_y ) //--- AGE BE FOOD RESID
    {
        eat = true ;
        ++ length ;
    }
    while( eat ) //---- MAKE FOOD :))
    {
        do
        {
            t_x = rand()% ( 2 * m - 1 ) ;
            t_y = rand()% ( n - 1 ) ;
        }
        while ( !(rec [t_y][t_x]) ); //- JAHAEI KE MAR HAST TOLID NASHE ..

        gotoxy(t_x, t_y);
        sc(12);
        cout << "*" ;
        sc(10);

        eat = false ;

        GOTO_COR
    }//--------------- END MAKE FOOD
}
void score ()
{
    gotoxy(8,0);
    sc ( 144 ) ;
    cout << char ( 16 ) << "Score : " << setfill (' ') << setw(5) << length - 1 << " " << char ( 17 ) ;
    GOTO_COR
    sc ( snake_color_code ) ;
}

void Delete ( int x_d , int y_d , int m , bool** rec )
{
    //if ( (Move_[ Move_.size() - length ] != Move_[ Move_.size() - 1 ]  ) )
    GOTO_COR
    Move_.push_back( m ) ;
    X_.push_back( x_d ) ;
    Y_.push_back( y_d ) ;

    if ( temp_delete )
    {

        for ( i = 0 ; i < length ; i ++ )
        {
            Move_[i] = 2 ;
            Y_[i] = y ;
            X_[i] = x - i ;
            //cout << X_[i] << "\t" ;
        }

        temp_delete = false ;
    }

    //cout << Move_[  Move_.size() -  length ] << " " << Move_[length] ;
    switch ( Move_[  Move_.size() -  length ] )
    {
    case 1 : //----------------------------------------- Right

        gotoxy ( X_[  Move_.size() -  length ] , Y_[  Move_.size() -  length ] ) ;
        rec [Y_[  Move_.size() -  length ]] [ X_[  Move_.size() -  length ] ] = true ;
        cout << " " ;
        if ( bug >= 1 )
        {
            gotoxy ( X_[  Move_.size() -  length ] - 1 , Y_[  Move_.size() -  length ] ) ;
            cout << " " ;
            //Sleep(4000);
            -- bug;
        }
        GOTO_COR
        break ;

    case 2 : //----------------------------------------- Left

        gotoxy ( X_[  Move_.size() -  length ] , Y_[  Move_.size() -  length ] ) ;
        rec [Y_[  Move_.size() -  length ]] [ X_[  Move_.size() -  length ] ] = true ;
        cout << " " ;
        GOTO_COR
        break ;

    case 3 : //----------------------------------------- Up

        gotoxy ( X_[  Move_.size() -  length ] , Y_[  Move_.size() -  length ] ) ;
        rec [Y_[  Move_.size() -  length ]] [ X_[  Move_.size() -  length ] ] = true ;
        cout << " " ;
        GOTO_COR
        break ;

    case 4 : //----------------------------------------- Down

        gotoxy ( X_[  Move_.size() -  length ] , Y_[  Move_.size() -  length ] ) ;
        rec [Y_[  Move_.size() -  length ]] [ X_[  Move_.size() -  length ] ] = true ;
        cout << " " ;
        GOTO_COR
        break ;

    }
}
void Sort_scores(int x[])
{

    for ( i = SCORES - 1 ; i > 0 ; i-- )
    {
        for ( j = 0 ; j < i ; j++ )
        {
            if ( x [ j ] > x [ j+1 ] )
            {
                swap ( x[j+1] , x[j] );
            }  //end of if
        }
    }

}
