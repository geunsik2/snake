#include "a.h"

int ranking_db(int score, int best, int stage, int* scoreArr) {
	MYSQL conn = { 0 };			// ����ü�� ������ �� �ִ� ����ü ����
	MYSQL* connection = NULL;	// ���������� �����ϴ� ������ ����
	MYSQL_RES* sql_result;		// �޸𸮿� ������� �����ϰ� �޸��� ���۹����� sql_result�� �����Ѵ�.
	MYSQL_ROW sql_row;			// �޸𸮷� ������ ����� ��ü�� �� ������ �д´�.

	int query_stat = 0;			// ������ ����� ���� �ƴ��� Ȯ���ϱ� ���� ����.
	char query[255] = { 0 };	// �Էµ� id�� passwd�� DB�� query�ϱ� ���� �迭.

	// �ʱ�ȭ
	mysql_init(&conn);

	// ���� mysql_real_connect
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0);
	// ���� ������ �� ����� ������ �����Ͱ� �Ѿ���� ������ �� NULL�� �Ѿ�´�.

	if (connection == NULL) {	// ���� ���� �� ���п����� ����ϴ� �Լ�.
		fprintf(stderr, "���п���: %s\n", mysql_error(&conn));
		return 1;		// ������ ���Ḧ �˸���.
	}
	
	sprintf(query, "insert into ranking values" "('%s', '%d', '%d', '%d', '%d')", id, scoreArr[0], scoreArr[1], scoreArr[2], scoreArr[3]);
	// ranking ���̺� ���� �α��� ���� id�� Stage �� ������ �����Ѵ�.
	query_stat = mysql_query(connection, query);		// query�� ������. �Ķ����(��������, query���� ��� �迭)
														
	if (query_stat != 0) {		// ranking ���̺� id �ߺ� �� update���� �̿��Ͽ� ������ �����Ѵ�.
		sprintf(query, "update ranking set score1 = %d, score2 = %d, score3 = %d, score4 = %d where id = '%s'", scoreArr[0], scoreArr[1], scoreArr[2], scoreArr[3], id);

		query_stat = mysql_query(connection, query);	// query�� ������. �Ķ����(��������, query���� ��� �迭)
	}
	mysql_close(connection);
	return 0;
}