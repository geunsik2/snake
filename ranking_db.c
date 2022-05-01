#include "a.h"

int ranking_db(int score, int best, int stage, int* scoreArr) {
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
	
	sprintf(query, "insert into ranking values" "('%s', '%d', '%d', '%d', '%d')", id, scoreArr[0], scoreArr[1], scoreArr[2], scoreArr[3]);
	// ranking 테이블에 현재 로그인 중인 id와 Stage 별 점수를 삽입한다.
	query_stat = mysql_query(connection, query);		// query를 날린다. 파라미터(연결정보, query문이 담길 배열)
														
	if (query_stat != 0) {		// ranking 테이블에 id 중복 시 update문을 이용하여 점수만 변경한다.
		sprintf(query, "update ranking set score1 = %d, score2 = %d, score3 = %d, score4 = %d where id = '%s'", scoreArr[0], scoreArr[1], scoreArr[2], scoreArr[3], id);

		query_stat = mysql_query(connection, query);	// query를 날린다. 파라미터(연결정보, query문이 담길 배열)
	}
	mysql_close(connection);
	return 0;
}