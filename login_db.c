#include "a.h"

int login_db(void) {
	MYSQL conn = { 0 };			// 구조체에 접근할 수 있는 구조체 변수
	MYSQL* connection = NULL;	// 연결정보를 관리하는 포인터 변수
	MYSQL_RES* sql_result;		// 메모리에 결과값을 저장하고 메모리의 시작번지를 sql_result에 저장한다.
	MYSQL_ROW sql_row;			// 메모리로 가져온 결과값 전체를 행 단위로 읽는다.

	int query_stat = 0;			// 쿼리가 제대로 전달 됐는지 확인하기 위한 변수.
	int answer = 0;				// 1 입력 시 회원가입하고 2 입력시 로그인하기 위한 변수.
	char passwd[50] = { 0 };	// passwd를 입력받는 배열
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

	while (1) {
		system("cls");
		HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // 표준콘솔출력의 핸들을 반환.
		SetConsoleTextAttribute(hand, 13);  // 콘솔에서의 글자색을 분홍색(13)으로 변경한다.
		gotoxy(DEFAULT_X, DEFAULT_Y);       // 커서를 (0, 0) 좌표로 이동.
		printf("============================================");
		SetConsoleTextAttribute(hand, 14);  // 콘솔에서의 글자색을 노란색(14)으로 변경한다.
		printf("================ Snake Game ================");
		SetConsoleTextAttribute(hand, 11);  // 콘솔에서의 글자색을 하늘색(11)으로 변경한다.
		printf("============================================");
		SetConsoleTextAttribute(hand, 15);  // 콘솔에서의 글자색을 짙은 하얀색(15)으로 변경한다.

		gotoxy(DEFAULT_X + 8, DEFAULT_Y + 14);
		printf("(1) 회원가입");
		gotoxy(DEFAULT_X + 8, DEFAULT_Y + 16);
		printf("(2) 로그인");
		answer = getch();	// 1 입력 시 회원가입, 2 입력 시 로그인한다.
		
		if (answer == '1') {
			system("cls");
			printf("--------------------------------------------");
			printf("                  회원가입                  ");
			printf("--------------------------------------------\n\n");
			printf("아이디: ");
			fgets(id, 50, stdin);		// id를 입력받는다. 파라미터(id가 저장될 변수, 크기, 표준입력스트링)
			CHOP(id);					// 엔터키가 입력되면 엔터키를 공백으로 만든다.

			printf("패스워드: ");
			fgets(passwd, 50, stdin);	// passwd를 입력받는다. 파라미터(passwd가 저장될 변수, 크기, 표준입력스트링)
			CHOP(passwd);				// 엔터키가 입력되면 엔터키를 공백으로 만든다.

			sprintf(query, "insert into login values" "('%s', '%s')", id, passwd);	// 입력받은 id와 passwd를 DB에 넣어야 하므로 query한다.

			query_stat = mysql_query(connection, query);		// query를 날린다. 파라미터(연결정보, query문이 담길 배열)
																// 정상적으로 동작하면 0을 리턴하고 아닐 시 0이 아닌 값을 리턴한다.

			if (query_stat != 0) {		// 비정상적으로 동작할 시 exception 처리하는 함수.
				fprintf(stderr, "\n\n실패원인: %s\n\n", mysql_error(&conn));
				printf("회원가입 실패\n\n");
				system("pause");
				continue;
			}
			else if (query_stat == 0) {		// 회원가입에 성공할 시 ranking 테이블에 가입한 id와 스테이지 별 점수를 삽입한다.
				printf("\n\n회원가입 성공\n\n");
				sprintf(query, "insert into ranking values" "('%s', '%d', '%d', '%d', '%d')", id, 0, 0, 0, 0);
				query_stat = mysql_query(connection, query);
				system("pause");
				continue;
			}
		}
		else if (answer == '2') {		// DB에 있는 id, passwd와 입력한 id, passwd가 같은지 검사한다.
			// 로그인
			system("cls");
			printf("--------------------------------------------");
			printf("                   로그인                   ");
			printf("--------------------------------------------\n\n");
			printf("아이디: ");
			fgets(id, 50, stdin);	// id를 입력받는다. 파라미터(id가 저장될 변수, 크기, 표준입력스트링)
			CHOP(id);				// 엔터키가 입력되면 엔터키를 공백으로 만든다.

			printf("패스워드: ");
			fgets(passwd, 50, stdin);	// passwd를 입력받는다. 파라미터(passwd가 저장될 변수, 크기, 표준입력스트링)
			CHOP(passwd);				// 엔터키가 입력되면 엔터키를 공백으로 만든다.

			sprintf(query, "select * from login where id = '%s' and passwd = '%s'", id, passwd);
			// 사용자가 입력한 id와 passwd가 같은지 검사하기 위해 where절 이용.

			query_stat = mysql_query(connection, query);		// query를 날린다. 파라미터(연결정보, query문이 담길 배열)
																// 정상적으로 동작하면 0을 리턴하고 아닐 시 0이 아닌 값을 리턴한다.
			
			sql_result = mysql_store_result(connection);
			if ((sql_row = mysql_fetch_row(sql_result)) != NULL) {	// 로그인 성공 시 메인화면으로 이동한다.
				printf("\n\n로그인 성공\n\n");
				break;
			}
			else {		// 로그인 실패 시 로그인 화면으로 이동한다.
				printf("\n\n로그인 실패\n\n");	
				system("pause");
				continue;
			}
		}
	}
	mysql_close(connection);
	system("pause");
}