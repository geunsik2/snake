#include "a.h"

int drawStartMenu(void) {   // show start menu. 메인화면. 
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // 표준콘솔출력의 핸들을 반환.
    MYSQL conn = { 0 };			// 구조체에 접근할 수 있는 구조체 변수
    MYSQL* connection = NULL;	// 연결정보를 관리하는 포인터 변수
    MYSQL_RES* sql_result;		// 메모리에 결과값을 저장하고 메모리의 시작번지를 sql_result에 저장한다.
    MYSQL_ROW sql_row;			// 메모리로 가져온 결과값 전체를 행 단위로 읽는다.

    int query_stat = 0;			// 쿼리가 제대로 전달 됐는지 확인하기 위한 변수.
    char query[255] = { 0 };	// 입력된 id와 passwd를 DB에 query하기 위한 배열.
    
    system("cls");

    while (1) {    
        int i = 0;
        SetConsoleTextAttribute(hand, 13);  // 콘솔에서의 글자색을 분홍색(13)으로 변경한다.
        gotoxy(DEFAULT_X, DEFAULT_Y);       // 커서를 (0, 0) 좌표로 이동.
        printf("============================================");
        SetConsoleTextAttribute(hand, 14);  // 콘솔에서의 글자색을 노란색(14)으로 변경한다.
        printf("================ Snake Game ================");
        SetConsoleTextAttribute(hand, 11);  // 콘솔에서의 글자색을 하늘색(11)으로 변경한다.
        printf("============================================");
        SetConsoleTextAttribute(hand, 15);  // 콘솔에서의 글자색을 짙은 하얀색(15)으로 변경한다.
        gotoxy(DEFAULT_X, DEFAULT_Y + 4);   // 커서를 (0, 4) 좌표로 이동.
        printf("> Key  : up, down, left, right,");
        gotoxy(DEFAULT_X, DEFAULT_Y + 5);   // 커서를 (0, 5) 좌표로 이동.
        printf("> Rank : 'r'");
        gotoxy(DEFAULT_X, DEFAULT_Y + 6);   // 커서를 (0, 5) 좌표로 이동.
        printf("> Exit : 't'");

        gotoxy(DEFAULT_X + 11, DEFAULT_Y + 14);     // 커서를 (11, 14) 좌표로 이동.
        printf("<Made by BlockDMask.>");
        gotoxy(DEFAULT_X + 11, DEFAULT_Y + 15);     // 커서를 (11, 15) 좌표로 이동.
        printf("<BlockDMask@gmail.com>");
        SetConsoleTextAttribute(hand, 14);      // 콘솔에서의 글자색을 노란색(14)으로 변경한다. 

        gotoxy(DEFAULT_X + 5, DEFAULT_Y + 9);   // 커서를 (5, 9) 좌표로 이동.
        printf("-- press 's' to start --");
        Sleep(1000 / 3);    // 0.3초마다 대기해서 깜빡이게 보이게 한다.
        gotoxy(DEFAULT_X + 5, DEFAULT_Y + 9);   // 커서를 (5, 9) 좌표로 이동.
        printf("                         ");
        Sleep(1000 / 3);    // 0.3초마다 대기해서 깜빡이게 보이게 한다.

        int keyDown = getKeyDown();
        if (keyDown == 's' || keyDown == 'S') { // s나 S가 입력되면 콘솔에서의 글자색을 연한 흰색(7)으로
                                                // 변경 후 TRUE를 리턴.
            SetConsoleTextAttribute(hand, 7);
            return TRUE;
        }
        if (keyDown == 't' || keyDown == 'T') { // t나 T가 입력되면 콘솔에서의 글자색을 연한 흰색(7)으로
                                                // 변경 후 FALSE를 리턴.
            SetConsoleTextAttribute(hand, 7);
            return FALSE;
        }
        if (keyDown == 'r' || keyDown == 'R') { // r 또는 R이 입력되면 콘솔에서의 글자색을 연한 흰색(7)으로
                                                // 변경 후 유저 별 순위를 출력한다.

            system("cls");
            SetConsoleTextAttribute(hand, 7);
            printf("────────────────────────────────────────────\n");
            printf("                   RANKING\n");
            printf("────────────────────────────────────────────\n");
            printf("> Back : 'r'");

            // 초기화
            mysql_init(&conn);

            // 연결 mysql_real_connect
            connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0);
            // 연결 성공할 시 연결된 정보의 포인터가 넘어오고 실패할 시 NULL이 넘어온다.

            if (connection == NULL) {	// 연결 실패 시 실패원인을 출력하는 함수.
                fprintf(stderr, "실패원인: %s\n", mysql_error(&conn));
                return 1;		// 비정상 종료를 알린다.
            }

            sprintf(query, "select id, score1 from ranking where score1 order by 2 desc limit 3");
            // ranking 테이블의 score1에 대한 id와 score1만 내림차순으로 3행까지 조회한다.
            query_stat = mysql_query(connection, query);	// query. DB에 있는 내용을 확인한다.
            // query가 제대로 날아갔으면 0이 리턴되고 비정상적으로 동작하면 0이 아닌 값이 리턴된다.
            sql_result = mysql_store_result(connection);    // 메모리에 저장된 query 결과를 sql_result에 저장한다. -> (실제 값이 아닌 시작번지 저장)
                                                            // 즉, sql_result는 전체 내용이 담긴 시작번지를 담고있다.
            
            gotoxy(0, 8);
            printf("       Stage [1]             Stage [2]\n");
            while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {	// sql_result가 NULL이 아닐 때까지 전체 내용이 담긴 sql_result에 접근해서
                                                                        // sql_row에 한 행씩 가져온다. 
                i++;
                gotoxy(DEFAULT_X, DEFAULT_Y + (i + 9));
                printf(" %d위 -> %5s %s점", i, sql_row[0], sql_row[1]); // stage [1]의 아이디와 점수를 3위까지 콘솔에 출력한다.
            }
            i = 0;
            mysql_free_result(sql_result);	// mysql_store_result()가 메모리를 계속 점유하고 있기 때문에 메모리를 해제해준다.

            sprintf(query, "select id, score2 from ranking where score2 order by 2 desc limit 3");
            // ranking 테이블의 score2에 대한 id와 score2만 내림차순으로 3행까지 조회한다.
            query_stat = mysql_query(connection, query);	// query. DB에 있는 내용을 확인한다.
            // query가 제대로 날아갔으면 0이 리턴되고 비정상적으로 동작하면 0이 아닌 값이 리턴된다.
            sql_result = mysql_store_result(connection);		// 메모리에 저장된 query 결과를 sql_result에 저장한다. -> (실제 값이 아닌 시작번지 저장)
                                                                // 즉, sql_result는 전체 내용이 담긴 시작번지를 담고있다.
            while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {	// sql_result가 NULL이 아닐 때까지 전체 내용이 담긴 sql_result에 접근해서
                                                                        // sql_row에 한 행씩 가져온다. 
                i++;
                gotoxy(DEFAULT_X + 12, DEFAULT_Y + (i + 9));
                printf(" %d위 -> %5s %s점", i, sql_row[0], sql_row[1]); // stage [2]의 아이디와 점수를 3위까지 콘솔에 출력한다.
            }
            i = 0;
            mysql_free_result(sql_result);	// mysql_store_result()가 메모리를 계속 점유하고 있기 때문에 메모리를 해제해준다.

            sprintf(query, "select id, score3 from ranking where score3 order by 2 desc limit 3");
            // ranking 테이블의 score3에 대한 id와 score3만 내림차순으로 3행까지 조회한다.
            query_stat = mysql_query(connection, query);	// query. DB에 있는 내용을 확인한다.
            // query가 제대로 날아갔으면 0이 리턴되고 비정상적으로 동작하면 0이 아닌 값이 리턴된다.
            sql_result = mysql_store_result(connection);		// 메모리에 저장된 query 결과를 sql_result에 저장한다. -> (실제 값이 아닌 시작번지 저장)
                                                                // 즉, sql_result는 전체 내용이 담긴 시작번지를 담고있다.

            gotoxy(0, 18);           
            printf("       Stage [3]             Stage [4]\n");            
            while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {	// sql_result가 NULL이 아닐 때까지 전체 내용이 담긴 sql_result에 접근해서
                                                                        // sql_row에 한 행씩 가져온다. 
                i++;
                gotoxy(DEFAULT_X, DEFAULT_Y + (i + 19));
                printf(" %d위 -> %5s %s점", i, sql_row[0], sql_row[1]); // stage [3]의 아이디와 점수를 3위까지 콘솔에 출력한다.
            }
            i = 0;
            mysql_free_result(sql_result);	// mysql_store_result()가 메모리를 계속 점유하고 있기 때문에 메모리를 해제해준다.
            
            sprintf(query, "select id, score4 from ranking where score4 order by 2 desc limit 3");
            // ranking 테이블의 score4에 대한 id와 score4만 내림차순으로 3행까지 조회한다.
            query_stat = mysql_query(connection, query);	// query. DB에 있는 내용을 확인한다.
            // query가 제대로 날아갔으면 0이 리턴되고 비정상적으로 동작하면 0이 아닌 값이 리턴된다.

            sql_result = mysql_store_result(connection);		// 메모리에 저장된 query 결과를 sql_result에 저장한다. -> (실제 값이 아닌 시작번지 저장)
                                                                // 즉, sql_result는 전체 내용이 담긴 시작번지를 담고있다.
            while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {	// sql_result가 NULL이 아닐 때까지 전체 내용이 담긴 sql_result에 접근해서
                                                                        // sql_row에 한 행씩 가져온다. 
                i++;
                gotoxy(DEFAULT_X + 12, DEFAULT_Y + (i + 19));
                printf(" %d위 -> %5s %s점", i, sql_row[0], sql_row[1]); // stage [4]의 아이디와 점수를 3위까지 콘솔에 출력한다.
            }
            
            mysql_free_result(sql_result);	// mysql_store_result()가 메모리를 계속 점유하고 있기 때문에 메모리를 해제해준다.

            while (keyDown != 'r' || 'R') { // 순위창에서 r 또는 R이 누르면 메인화면으로 돌아간다.
                keyDown = getch();
                if (keyDown == 'r' || keyDown == 'R') {
                    system("cls");
                    break;
                }
            }
        }  
    }
    mysql_close(connection);
}