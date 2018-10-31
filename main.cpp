/* Snake ..              *
** Play  : 29/8/96      **
** start : 5/9/96       **
** end : 22/3/97        **
** make by Ario :P      **
*                       */

#include "functions.h"

int main()
{
    ofstream setting_o ("setting.dat", ios :: in );
    ifstream setting_i ("setting.dat", ios :: in );
    ofstream score_o ("score.dat", ios :: in );
    ifstream score_i ("score.dat", ios :: in );

    if ( ! setting_i.is_open() || ! score_i.is_open() )
    {
        ofstream setting_o ("setting.dat", ios :: out );
        ofstream score_o ("score.dat", ios :: out );

        if ( setting_o.is_open() || score_o.is_open() )
        {
            setting_o << 150 << endl ;  // Speed
            setting_o << 58 << endl ;   // M - Rectangle Width
            setting_o << 26 << endl ;   // N - Rectangle height
            setting_o << 10 << endl ;   // Snake code color

            for ( i = 0 ; i < SCORES ; i++ )
            {
                score_o << Score[i] << endl ;
            }

        }
        else
        {
            cerr << " Err : File not found \n\n" ;
        }
        cout << " Err : something is wrong .. please re-start game \n If one more time this error showed \n Run game as administrator \n\n" ;
        cout << " Press any key to Exit " ;
        getch() ;
        return 0 ;
    }
    else
    {
        setting_i >> p[0] >> p[1] >> p[2] >> p[3] ;
        for ( i = 0 ; i < SCORES ; i++ ) score_i >> Score[i] ;
    }

    srand(time(0)) ; //------------------------------ Call SRAND
Start :
    menu_[0] = 1 ;
    menu_[1] = 1 ;
    system("cls") ;
    /* initialize from file */
    speed = p[0] ;
    m = p[1] ;
    n = p[2] ;
    snake_color_code = p[3] ;
    /* initialize from file */

    int temp = 0 ; // for menu select
    bool SELECT_M = false ; //for menu while bet
    int Max ; // for score array
    int input ; // for file
    //SELECT_M = true ;
    //temp = 1 ;

    if ( menu_[0] )
    {
        temp = 1 ;
        menu_[0] = false ;
        goto after_1 ;
    }

    GOTO_FIR
    while(!SELECT_M)
    {
        dir =  getch() ;
        if ( dir == ENTER ) SELECT_M = 1;

        if ( dir == -32 || dir == 0 || dir == 224 )
        {
            dir = getch();
            Sleep(100);
            switch (dir)
            {
            case UP :
                if (temp <= 1) temp=5 ;
                temp -= 1; //:D
                break;

            case DOWN :
                if ( temp>=4 ) temp=0;
                temp ++ ;
                break;
            }
        }
after_1 :
        if ( temp == 1 )
        {
            system("cls");

            sc(240);

            cout << "\n Play    " ;
            sc(7);
            cout << "\n Scores "
                 << "\n Setting"
                 << "\n About " ;
            //GOTO_FIR
        }
        if (temp == 2 )
        {
            system("cls");
            cout << "\n Play " ;
            sc(240);
            cout << "\n Scores  " ;
            sc(7);
            cout << "\n Setting"
                 << "\n About " ;
            GOTO_FIR
        }
        if (temp==3)
        {
            system("cls");
            cout << "\n Play " ;
            cout << "\n Scores  " ;
            sc(240);
            cout << "\n Setting " ;
            sc (7) ;
            cout << "\n About " ;
            GOTO_FIR
        }
        if (temp==4)
        {
            system("cls");
            cout << "\n Play " ;
            cout << "\n Scores  " ;
            cout << "\n Setting " ;
            sc(240);
            cout << "\n About   " ;
            sc (7) ;
            GOTO_FIR
        }
        if (SELECT_M)
        {
            system("cls");
        }

    }
    switch ( temp )
    {
    case 4 :
        sc ( 11 ) ;
        cout << endl <<
           "    ###    ########  ##    ##    ##     ##    ###    ########   " << endl <<
           "   ## ##   ##     ##  ##  ##     ###   ###   ## ##   ##     ##  " << endl <<
           "  ##   ##  ##     ##   ####      #### ####  ##   ##  ##     ##  " << endl <<
           " ##     ## ########     ##       ## ### ## ##     ## ##     ##  " << endl <<
           " ######### ##   ##      ##       ##     ## ######### ##     ##  " << endl <<
           " ##     ## ##    ##     ##       ##     ## ##     ## ##     ##  " << endl <<
           " ##     ## ##     ##    ##       ##     ## ##     ## ########   " << endl ;
        sc ( 8 ) ;
        cout << " Credit Ary Mad - 2017 " << endl
             << " Weblog : codingtime.blogfa.com " << endl
             << " E-mail : alirezamky@hotmail.com " << endl ;

        sc ( 240 ) ;
        cout << endl << " Press 'Enter' To back menu " ;
        sc ( 7 ) ;
        while ( 1 )
        {
            dir =  getch() ;
            if ( dir == ENTER ) goto Start ;
        }
        break ;
    case 3 :

        menu_setting :
        menu_[1] = true ;
        temp = 0 ;
        SELECT_M = false ;

        system("cls");
        cout.setf(ios::left);
        cout.fill(' ');

        if ( menu_[1] )
        {
            temp = 1 ;
            menu_[1] = false ;
            goto after_2 ;
        }
        while(!SELECT_M)
        {
            dir =  getch() ;
            if ( dir == ENTER ) SELECT_M = true ;

            if ( dir == -32 || dir == 0 || dir == 224 )
            {
                dir = getch();
                Sleep(100);
                switch (dir)
                {
                case UP :
                    if (temp <= 1) temp=7 ;
                    temp -= 1; //:D
                    break;

                case DOWN :
                    if ( temp>=6 ) temp=0;
                    temp ++ ;
                    break;
                }
            }
after_2 :
            if ( temp == 1 )
            {
                system("cls");
                cout << endl ;
                sc ( 240 ) ;
                cout.width (MENU) ;
                cout << " Speed (ms) : " << " " << setw(4) << p[0] << endl ;
                sc ( 7 ) ;
                cout.width (MENU) ;
                cout << " Width : " << " " << p[1] << endl ;
                cout.width (MENU) ;
                cout << " height : " << " " << p[2] << endl ;
                cout.width (MENU) ;
                cout << " Snake color : " << " " << p[3] ;
                sc ( snake_color_code ) ;
                cout << "    " << (char)205 << "@" ;
                sc ( 7 ) ;
                cout << endl ;
                cout << " Reset to default " << endl ;
                cout << " Apply and back to menu " ;
                GOTO_FIR
            }
            if (temp == 2 )
            {
                system("cls");
                cout << endl ;
                cout.width (MENU) ;
                cout << " Speed (ms) : " << " " << p[0] << endl ;
                sc ( 240 ) ;
                cout.width (MENU) ;
                cout << " Width : " << " " << setw(4) << p[1] << endl ;
                sc ( 7 ) ;
                cout.width (MENU) ;
                cout << " height : " << " " << p[2] << endl ;
                cout.width (MENU) ;
                cout << " Snake color : " << " " << p[3] ;
                sc ( snake_color_code ) ;
                cout << "    " << (char)205 << "@" ;
                sc ( 7 ) ;
                cout << endl ;
                cout << " Reset to default " << endl ;
                cout << " Apply and back to menu " ;
                GOTO_FIR
            }
            if (temp==3)
            {
                system("cls");
                cout << endl ;
                cout.width (MENU) ;
                cout << " Speed (ms) : " << " " << p[0] << endl ;
                cout.width (MENU) ;
                cout << " Width : " << " " << p[1] << endl ;
                sc ( 240 ) ;
                cout.width (MENU) ;
                cout << " height : " << " " << setw(4) << p[2] << endl ;
                sc ( 7 ) ;
                cout.width (MENU) ;
                cout << " Snake color : " << " " << p[3] ;
                sc ( snake_color_code ) ;
                cout << "    " << (char)205 << "@" ;
                sc ( 7 ) ;
                cout << endl ;
                cout << " Reset to default " << endl ;
                cout << " Apply and back to menu "  ;
                GOTO_FIR
            }
            if (temp==4)
            {
                system("cls");
                cout << endl ;
                cout.width (MENU) ;
                cout << " Speed (ms) : " << " " << p[0] << endl ;
                cout.width (MENU) ;
                cout << " Width : " << " " << p[1] << endl ;
                cout.width (MENU) ;
                cout << " height : " << " " << p[2] << endl ;
                sc ( 240 ) ;
                cout.width (MENU) ;
                cout << " Snake color : " << " " << setw(4) << p[3] ;
                sc ( snake_color_code ) ;
                cout << "  " << (char)205 << "@" ;
                sc ( 7 ) ;
                cout << endl ;
                cout << " Reset to default " << endl ;
                cout << " Apply and back to menu " ;
                GOTO_FIR
            }
            if (temp==5)
            {
                system("cls");
                cout << endl ;
                cout.width (MENU) ;
                cout << " Speed (ms) : " << " " << p[0] << endl ;
                cout.width (MENU) ;
                cout << " Width : " << " " << p[1] << endl ;
                cout.width (MENU) ;
                cout << " height : " << " " << p[2] << endl ;
                cout.width (MENU) ;
                cout << " Snake color : " << " " << p[3] ;
                sc ( snake_color_code ) ;
                cout << "    " << (char)205 << "@" ;
                sc ( 240 ) ;
                cout << endl ;
                cout << " Reset to default        " << endl ;
                sc ( 7 ) ;
                cout << " Apply and back to menu  " ;
                GOTO_FIR
            }
            if (temp==6)
            {
                system("cls");
                cout << endl ;
                cout.width (MENU) ;
                cout << " Speed (ms) : " << " " << p[0] << endl ;
                cout.width (MENU) ;
                cout << " Width : " << " " << p[1] << endl ;
                cout.width (MENU) ;
                cout << " height : " << " " << p[2] << endl ;
                cout.width (MENU) ;
                cout << " Snake color : " << " " << p[3] ;
                sc ( snake_color_code ) ;
                cout << "    " << (char)205 << "@" ;
                cout << endl ;
                sc ( 7 ) ;
                cout << " Reset to default " << endl ;
                sc ( 240 ) ;
                cout << " Apply and back to menu  " ;
                sc ( 7 ) ;
                GOTO_FIR
            }
        }

        //cout << temp ;
        //Sleep(1000);
        setting_o.open("setting.dat",ios::trunc);
        for ( i = 0 ; i < 4 ; i++ ) setting_o << p[i] << endl  ;
        setting_o.close() ;

        if ( temp == 1 ) //Speed
        {
            gotoxy ( 21, 1 ) ;
            sc ( 240 ) ;
            cout << "   " ; //for clean number ;
            gotoxy ( 21, 1 ) ;
            sc ( 7 ) ;
again_1 :
            /* insert to file */
            cin >> speed ;//Speed
            p[0] = speed ;
            /* insert to file */

            if ( speed > 9001 || speed < 99 )
            {
                gotoxy(0,6) ;
                cout << " Err : this color code invalid ( 100 - 9000 ) : " ;
                goto again_1 ;
            }

            goto menu_setting ;
        }


        if ( temp == 2 ) //Width
        {
            gotoxy ( 21, 2 ) ;
            sc ( 240 ) ;
            cout << "   " ; //for clean number ;
            gotoxy ( 21, 2 ) ;
            sc ( 7 ) ;
again_2 :
            /* insert to file */
            cin >> m ;//Width
            p[1] = m ;
            /* insert to file */

            if ( m > 58 || m < 11 )
            {
                gotoxy(0,6) ;
                cout << " Err : this color code invalid ( 10 - 58 ) : " ;
                goto again_2 ;
            }
            goto menu_setting ;

        }

        if ( temp == 3 ) //height
        {
            gotoxy ( 21, 3 ) ;
            sc ( 240 ) ;
            cout << "   " ; //for clean number ;
            gotoxy ( 21, 3 ) ;
            sc ( 7 ) ;
again_3 :
            cin >> n ;
            p[2] = n ;

            if ( n > 41 || n < 11 )
            {
                gotoxy(0,6) ;
                cout << " Err : this color code invalid ( 10 - 40 ) : " ;
                goto again_3 ;
            }
            goto menu_setting ;
        }
        if ( temp == 4 ) //Snake color
        {
            gotoxy ( 21, 4 ) ;
            sc ( 240 ) ;
            cout << "   " ; //for clean number ;
            gotoxy ( 21, 4 ) ;
            sc ( 7 ) ;
again :
            cin >> snake_color_code ;
            p[3] = snake_color_code ;

            if ( snake_color_code >= 16 || snake_color_code == 0 )
            {
                gotoxy(0,6) ;
                cout << " Err : this color code invalid ( 1 - 15 ) : " ;
                goto again ;
            }
            goto menu_setting ;
        }
        if ( temp == 5 ) // reset to default
        {
            p[0] = 150 ;
            p[1] = 58 ;
            p[2] = 26 ;
            p[3] = 10 ;
            goto menu_setting ;
        }
        if ( temp == 6 ) //Apply and back to menu
        {
            SELECT_M = false ;
            temp = 0 ;
            goto Start ;
        }



        break ;
    case 2:
        cout << endl ;
        for ( i = SCORES - 1 ; i >= 0 ; i-- )
        {
            cout << " " << SCORES - i << "- " << Score[i] << endl ;
        }
        sc ( 240 ) ;
        cout << " Press 'Enter' To back menu " ;
        sc ( 7 ) ;

        while ( 1 )
        {
            dir =  getch() ;
            if ( dir == ENTER ) goto Start ;
        }
        break ;
    case 1 :
        ///1 --------------------------------------------------------------------------------------------------------------------///
start_snake:
        bug = 2 ;
        length = SNAKE_LEN + 1 ;
        system("cls");
        eat = true ;

        x = ( 5 * 2 * m ) / 10 ; //------------------ location snake _ X _ 70% M
        y = ( 5 * n ) / 10 ; //---------------------- location snake _ Y _ 50% N

        //---------------------------- Playground rectangle
        bool** rec = new bool* [n+1] ;
        for ( i = 0 ; i <= n ; ++ i )
        {
            rec[i] = new bool[ m * 2 ] ;
        }
        //---------------------------- Playground rectangle

        for ( i = 0 ; i <= n ; i++ )
        {
            for ( j = 0 ; j < m * 2 + 1 ; j++ )
            {
                rec [ i ] [ j ] = false ;//1_1_ MOSHAKHAS KARDAN MAHDODE BAZI
            }
        }
        for ( j = 2 ; j <= 2 * ( m - 1 ) ; j++ )
        {
            for ( i = 1 ; i <= n - 1 ; i++ )
            {
                rec [ i ] [ j ] = true ; //1_2_ MOSHAKHAS KARDAN MAHDODE BAZI
            }
        }
        //------------------------------- 1_3_ CHAP KARDAN BAZI
        sc( 9 ) ; //BLUE COLOR CODE
        for ( i = 0 ; i <= n ; i++ )
        {
            for ( j = 0 ; j <= m * 2 ; j++ )
            {
                //Sleep(5)  ;
                cout << (char)177 ;
            }
            cout << endl ;
        }
        //Sleep( 100 ) ;
        for ( j = 2 ; j < 2 * m - 1 ; j++ )
        {
            for ( i = 1 ; i < n ; i++ )
            {
                //Sleep(1)  ;
                gotoxy( j, i ) ;
                cout << " " ;
                GOTO_COR
            }
            cout << endl ;
        }
        sc(7) ; //COLOR CODE
        //------------------------------- END 1_3_ CHAP KARDAN BAZI

        score () ;

        gotoxy ( x, y ) ;

        sc( snake_color_code ) ;
        cout << (char)205 << "@" ;
        sc( 7 ) ;
        GOTO_COR

        rec [y][x] = true ;

        //print_rec( rec ) ;
        ///2 --------------------------------------------------------------------------------------------------------------------///


        //------------------------- Start with press RIGHT button -------------------//
        do
        {
            dir = getch() ;
            if ( dir == -32 || dir == 0 || dir == 224 )
                dir = getch() ;


        }
        while ( dir != RIGHT );
        //------------------------- Start with press RIGHT button -------------------//

        bool lu, ld, ru, rd, ur, ul, dr, dl ;
        lu = ld = ru = rd = ur = ul = dr = dl = false ;
        int length_temp ;
        int fp ; // -----------for Fixed point character

        sc ( snake_color_code ) ;
s:
        switch ( dir )
        {
        case RIGHT : /// ---------------------------------------------------- RIGHT ----------------------///
Right :
            fp = x ;
            length_temp = length ;
            do
            {
                score () ;

                ++ x ; // MOVE TO RIGHT
                if ( !(rec[y][x]) ) goto lose ;
                rec [y][x] = false ;

                /* Print */
                gotoxy ( x,y ) ;
                cout << "@" ;
                gotoxy ( x-1, y ) ;
                cout << (char)205 ;
                /* End print */

                /* * print up - Right and down - Right char */
                if ( dr && length_temp - 1 )
                {
                    length_temp -- ;
                    gotoxy( fp, y );
                    cout << (char)200 ;
                }
                if ( ur && length_temp - 1 )
                {
                    length_temp -- ;
                    gotoxy( fp, y );
                    cout << (char)201 ;
                }
                /* * END print Right - up and Left - up char */

                Delete ( x, y, 1, rec ) ;    // Add 2 in to vector //
                Food ( rec ) ;

                Sleep( speed/2 ) ; // Delay
                GOTO_COR
            }
            while ( !(kbhit()) ) ;
            ur = dr = false ;

            /* IF PRESS A KEY */
            dir = getch() ;
            if ( dir == -32 || dir == 0 || dir == 224 ) // AGE JAHAT HA BUDAN
            {
                dir = getch() ;
                if ( dir == UP )// AGE UP BUD
                {
                    ru = true ;
                    goto s ;
                }
                if ( dir == DOWN )// AGE DOWN BUD
                {
                    rd = true ;
                    goto s ;
                }
                else goto Right ; // AGE LEFT OR RIGHT BUD
            }
            goto Right ;
            /* END IF PRESS A KEY */

            break ;


        case LEFT : /// ---------------------------------------------------- LEFT -----------------------///
            fp = x ;
            length_temp = length ;
Left :
            do
            {
                score () ;

                -- x ; // MOVE TO RIGHT
                if ( !(rec[y][x]) ) goto lose ;
                rec [y][x] = false ;

                /* Print */
                gotoxy ( x,y ) ;
                cout << "@" ;
                gotoxy ( x+1, y ) ;
                cout << (char)205 ;
                /* End print */

                /* * print up - Right and down - Right char */
                if ( dl && length_temp - 1 )
                {
                    length_temp -- ;
                    gotoxy( fp, y );
                    cout << (char)188 ;
                }
                if ( ul && length_temp - 1 )
                {
                    length_temp -- ;
                    gotoxy( fp, y );
                    cout << (char)187 ;
                }
                /* * END print Right - up and Left - up char */

                Delete ( x, y, 2, rec ) ;    // Add 2 in to vector //
                Food ( rec ) ;

                Sleep( speed/2 ) ; // Delay
                GOTO_COR
            }
            while ( !(kbhit()) ) ;
            ul = dl = false ;

            /* IF PRESS A KEY */
            dir = getch() ;
            if ( dir == -32 || dir == 0 || dir == 224 ) // AGE JAHAT HA BUDAN
            {
                dir = getch() ;
                if ( dir == UP )// AGE UP BUD
                {
                    lu = true ;
                    goto s ;
                }
                if ( dir == DOWN )
                {
                    ld = true ;
                    goto s ;// AGE DOWN BUD
                }
                else goto Left ; // AGE LEFT OR RIGHT BUD
            }
            goto Left ;
            /* END IF PRESS A KEY */

            break ;


        case UP : /// ---------------------------------------------------- UP -------------------------///
            fp = y ;
            length_temp = length ;
Up :
            do
            {
                score () ;

                -- y ; // MOVE TO RIGHT
                if ( !(rec[y][x]) ) goto lose ;
                rec [y][x] = false ;

                /* Print */
                gotoxy ( x, y ) ;
                cout << "@" ;
                gotoxy ( x, y + 1  ) ;
                cout << (char)186 ;

                /* * print Right - up and Left - up char */
                if ( ru && length_temp - 1 )
                {
                    length_temp -- ;
                    gotoxy( x, fp );
                    cout << (char)188 ;
                }
                if ( lu && length_temp - 1 )
                {
                    length_temp -- ;
                    gotoxy( x, fp );
                    cout << (char)200 ;
                }
                /* * END print Right - up and Left - up char */
                /* End print */

                Delete ( x, y, 3, rec) ;    // Add 3 in to vector //
                Food ( rec ) ;

                Sleep( speed ) ; // Delay
                GOTO_COR
            }
            while ( !(kbhit()) ) ;
            ru = lu = false ;

            /* IF PRESS A KEY */
            dir = getch() ;
            if ( dir == -32 || dir == 0 || dir == 224 ) // AGE JAHAT HA BUDAN
            {
                dir = getch() ;
                if ( dir == RIGHT )
                {
                    ur = true ;
                    goto s ;
                }
                if ( dir == LEFT )
                {
                    ul = true ;
                    goto s ;
                }
                else goto Up ; // AGE LEFT OR RIGHT BUD
            }
            goto Up ;
            /* END IF PRESS A KEY */

            break ;
        case DOWN : /// ---------------------------------------------------- DOWN -----------------------///
            fp = y ;
            length_temp = length ;
Down :
            do
            {
                score () ;

                ++ y ; // MOVE TO RIGHT
                if ( !(rec[y][x]) ) goto lose ;
                rec [y][x] = false ;

                /* Print */
                gotoxy ( x, y ) ;
                cout << "@" ;
                gotoxy ( x, y - 1  ) ;
                cout << (char)186 ;

                /* * print Right - Down and Left - Down char */
                if ( rd && length_temp - 1 )
                {
                    length_temp -- ;
                    gotoxy( x, fp );
                    cout << (char)187 ;
                }
                if ( ld && length_temp - 1 )
                {
                    length_temp -- ;
                    gotoxy( x, fp );
                    cout << (char)201 ;
                }
                /* * END print Right - up and Left - up char */
                /* End print */

                Delete ( x, y, 4, rec) ;    // Add 4 in to vector //
                Food ( rec ) ;

                Sleep( speed ) ; // Delay
                GOTO_COR
            }
            while ( !(kbhit()) ) ;
            rd = ld = false ;

            /* IF PRESS A KEY */
            dir = getch() ;
            if ( dir == -32 || dir == 0 || dir == 224 ) // AGE JAHAT HA BUDAN
            {
                dir = getch() ;
                if ( dir == RIGHT )
                {
                    dr = true ;
                    goto s ;
                }
                if ( dir == LEFT )
                {
                    dl = true ;
                    goto s ;
                }
                else goto Down ; // AGE LEFT OR RIGHT BUD
            }
            goto Down ;
            /* END IF PRESS A KEY */
            break ;
        }
lose : /// ---------------------------------------------------- LOSE -----------------//
        /* LOSE PAGE */
        sc ( 255 ) ;
        //gotoxy ( ( 4 * n ) / 10 , ( 4 * 2 * m ) / 10 ) ;
        for ( i = ( 4 * n ) / 10 ; i <= ( 6 * n ) / 10 ; i++ )
        {
            for ( j = ( 4 * 2 * m ) / 10 ; j <= ( 6 * 2 * m ) / 10 ; j++ )
            {
                gotoxy ( j, i ) ;
                cout << " " ;
            }
            cout << endl ;
        }
        /* LOSE PAGE */
        /* ADD SCORE IN ARRAY */
        Sort_scores(Score);
        Max = Score[SCORES-1] ;

        if ( length - 1 > Max )
        {
            if ( S == 5 ) S = 0 ;
            Score[S++] = length - 1 ;
        }

        Sort_scores(Score);

        score_i.open("score.dat",ios::trunc);
        for ( i = 0 ; i < SCORES ; i++ )
        {
            score_o << Score[i] << endl ;
        }
        score_o.close() ;

        /* ADD SCORE IN ARRAY */

        sc ( 240 ) ;
        gotoxy ( ( 44 * 2 * m ) / 100, ( 44 * n ) / 100 ) ;
        cout << "Score : " << setw(5) << length - 1 ;
        gotoxy ( ( 44 * 2 * m ) / 100, ( 44 * n ) / 100 + 1 ) ;
        cout << "play again ?" ;
        //gotoxy ( ( 44 * 2 * m ) / 100, ( 44 * n ) / 100 + 2 ) ;
        //cout << "To back menu" ;
        gotoxy ( ( 43 * 2 * m ) / 100, ( 44 * n ) / 100 + 2 ) ;
        cout << "just press y / n " ;

        do
        {
            dir = getch() ;
            if ( dir == 'y' || dir == 'Y')
            {
                sc (7) ;
                temp_delete = true ;
                goto start_snake ;
            }
            if ( dir == 'n' || dir == 'N' )
            {
                sc (7) ;
                temp_delete = true ;
                goto Start ;
            }
        }
        while ( dir != 'y' || dir != 'n' || dir != 'Y' || dir != 'N');

        sc ( 7 ) ;
        //print_rec( rec ) ;
        break ;
    }
    return 0;
}


