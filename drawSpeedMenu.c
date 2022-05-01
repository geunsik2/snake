#include "a.h"

int drawSpeedMenu(int* scoreArr) {  // 맵 선택 메뉴와 점수를 보여준다.
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // 표준콘솔출력의 핸들을 반환.
    MYSQL conn = { 0 };			// 구조체에 접근할 수 있는 구조체 변수
    MYSQL* connection = NULL;	// 연결정보를 관리하는 포인터 변수
    MYSQL_RES* sql_result;		// 메모리에 결과값을 저장하고 메모리의 시작번지를 sql_result에 저장한다.
    MYSQL_ROW sql_row;			// 메모리로 가져온 결과값 전체를 행 단위로 읽는다.

    int query_stat = 0;			// 쿼리가 제대로 전달 됐는지 확인하기 위한 변수.
    char query[255] = { 0 };	// 입력된 id와 passwd를 DB에 query하기 위한 배열.

    // 초기화
    mysql_init(&conn);

    // 연결 mysql_real_connect
    connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0);
    // 연결 성공할 시 연결된 정보의 포인터가 넘어오고 실패할 시 NULL이 넘어온다.

    if (connection == NULL) {	// 연결 실패 시 실패원인을 출력하는 함수.
        fprintf(stderr, "실패원인: %s\n", mysql_error(&conn));
        return 1;		// 비정상 종료를 알린다.
    }

    SetConsoleTextAttribute(hand, 11);
    gotoxy(DEFAULT_X, DEFAULT_Y);
    printf("============================================");
    SetConsoleTextAttribute(hand, 14);
    gotoxy(DEFAULT_X, DEFAULT_Y + 1);
    printf("================ BEST SCORE ================");
    SetConsoleTextAttribute(hand, 13);
    gotoxy(DEFAULT_X, DEFAULT_Y + 2);
    printf("============================================");
    SetConsoleTextAttribute(hand, 15);

    sprintf(query, "select * from ranking where id = '%s'", id);    // 해당 id의 모든 스테이지 점수를 조회한다.
    query_stat = mysql_query(connection, query);	// query. DB에 있는 내용을 확인한다.
    // query가 제대로 날아갔으면 0이 리턴되고 비정상적으로 동작하면 0이 아닌 값이 리턴된다.
    if (query_stat != 0) {	// 비정상적으로 동작할 시 exception 처리하는 함수.
        fprintf(stderr, "실패원인: %s\n", mysql_error(&conn));
        return 1;
    }

    sql_result = mysql_store_result(connection);		// 메모리에 저장된 query 결과를 sql_result에 저장한다. -> (실제 값이 아닌 시작번지 저장)
                                                        // 즉, sql_result는 전체 내용이 담긴 시작번지를 담고있다.

    while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {	// sql_result가 NULL이 아닐 때까지 전체 내용이 담긴 sql_result에 접근해서
                                                                // sql_row에 한 행씩 가져온다.
        for (int i = 0; i < 4; i++) {
            gotoxy(DEFAULT_X, DEFAULT_Y + (i + 4)); // 커서를 (0, 4)부터 (0, 7)까지 이동한다.
            printf(" Stage [%d] : %s", i + 1, sql_row[i + 1]); // stage 별 점수를 콘솔에 출력한다.
            scoreArr[i] = atoi(sql_row[i + 1]);
        }
    }

    mysql_free_result(sql_result);	// mysql_store_result()가 메모리를 계속 점유하고 있기 때문에 메모리를 해제해준다.

    while (1) {
        int keyDown = getKeyDown();
        if (keyDown == '1') {   // 사용자로부터 1을 입력받으면 1을 리턴한다.
            SetConsoleTextAttribute(hand, 7);   // 콘솔에서의 글자색을 연한 흰색(7)으로 변경한다.
            return 1;
        }
        if (keyDown == '2') {   // 사용자로부터 2을 입력받으면 2를 리턴한다.
            SetConsoleTextAttribute(hand, 7);
            return 2;
        }
        if (keyDown == '3') {   // 사용자로부터 3을 입력받으면 3을 리턴한다.
            SetConsoleTextAttribute(hand, 7);
            return 3;
        }
        if (keyDown == '4') {   // 사용자로부터 4을 입력받으면 4를 리턴한다.
            SetConsoleTextAttribute(hand, 7);
            return 4;
        }
        SetConsoleTextAttribute(hand, 14);  // 콘솔에서의 글자색을 노란색(14)으로 변경한다.
        gotoxy(DEFAULT_X, DEFAULT_Y + 9);   // 커서를 (0, 9) 좌표로 이동.
        printf(">> Choose Stage : 1, 2, 3, 4");
        Sleep(1000 / 3);    // 0.3초마다 대기해서 깜빡이게 보이게 한다.
        gotoxy(DEFAULT_X, DEFAULT_Y + 9);
        printf(">>                          ");
        Sleep(1000 / 3);    // 0.3초마다 대기해서 깜빡이게 보이게 한다.
    }
    mysql_close(connection);
}
