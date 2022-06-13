#include "a.h"

int login_db(void) {
	MYSQL conn = { 0 };			// ����ü�� ������ �� �ִ� ����ü ����
	MYSQL* connection = NULL;	// ���������� �����ϴ� ������ ����
	MYSQL_RES* sql_result;		// �޸𸮿� ������� �����ϰ� �޸��� ���۹����� sql_result�� �����Ѵ�.
	MYSQL_ROW sql_row;			// �޸𸮷� ������ ����� ��ü�� �� ������ �д´�.

	int query_stat = 0;			// ������ ����� ���� �ƴ��� Ȯ���ϱ� ���� ����.
	int answer = 0;				// 1 �Է� �� ȸ�������ϰ� 2 �Է½� �α����ϱ� ���� ����.
	char passwd[50] = { 0 };	// passwd�� �Է¹޴� �迭
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

	while (1) {
		system("cls");
		HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // ǥ���ܼ������ �ڵ��� ��ȯ.
		SetConsoleTextAttribute(hand, 13);  // �ֿܼ����� ���ڻ��� ��ȫ��(13)���� �����Ѵ�.
		gotoxy(DEFAULT_X, DEFAULT_Y);       // Ŀ���� (0, 0) ��ǥ�� �̵�.
		printf("============================================");
		SetConsoleTextAttribute(hand, 14);  // �ֿܼ����� ���ڻ��� �����(14)���� �����Ѵ�.
		printf("================ Snake Game ================");
		SetConsoleTextAttribute(hand, 11);  // �ֿܼ����� ���ڻ��� �ϴû�(11)���� �����Ѵ�.
		printf("============================================");
		SetConsoleTextAttribute(hand, 15);  // �ֿܼ����� ���ڻ��� £�� �Ͼ��(15)���� �����Ѵ�.

		gotoxy(DEFAULT_X + 8, DEFAULT_Y + 14);
		printf("(1) ȸ������");
		gotoxy(DEFAULT_X + 8, DEFAULT_Y + 16);
		printf("(2) �α���");
		answer = getch();	// 1 �Է� �� ȸ������, 2 �Է� �� �α����Ѵ�.
		
		if (answer == '1') {
			system("cls");
			printf("--------------------------------------------");
			printf("                  ȸ������                  ");
			printf("--------------------------------------------\n\n");
			printf("���̵�: ");
			fgets(id, 50, stdin);		// id�� �Է¹޴´�. �Ķ����(id�� ����� ����, ũ��, ǥ���Է½�Ʈ��)
			CHOP(id);					// ����Ű�� �ԷµǸ� ����Ű�� �������� �����.

			printf("�н�����: ");
			fgets(passwd, 50, stdin);	// passwd�� �Է¹޴´�. �Ķ����(passwd�� ����� ����, ũ��, ǥ���Է½�Ʈ��)
			CHOP(passwd);				// ����Ű�� �ԷµǸ� ����Ű�� �������� �����.

			sprintf(query, "insert into login values" "('%s', '%s')", id, passwd);	// �Է¹��� id�� passwd�� DB�� �־�� �ϹǷ� query�Ѵ�.

			query_stat = mysql_query(connection, query);		// query�� ������. �Ķ����(��������, query���� ��� �迭)
																// ���������� �����ϸ� 0�� �����ϰ� �ƴ� �� 0�� �ƴ� ���� �����Ѵ�.

			if (query_stat != 0) {		// ������������ ������ �� exception ó���ϴ� �Լ�.
				fprintf(stderr, "\n\n���п���: %s\n\n", mysql_error(&conn));
				printf("ȸ������ ����\n\n");
				system("pause");
				continue;
			}
			else if (query_stat == 0) {		// ȸ�����Կ� ������ �� ranking ���̺� ������ id�� �������� �� ������ �����Ѵ�.
				printf("\n\nȸ������ ����\n\n");
				sprintf(query, "insert into ranking values" "('%s', '%d', '%d', '%d', '%d')", id, 0, 0, 0, 0);
				query_stat = mysql_query(connection, query);
				system("pause");
				continue;
			}
		}
		else if (answer == '2') {		// DB�� �ִ� id, passwd�� �Է��� id, passwd�� ������ �˻��Ѵ�.
			// �α���
			system("cls");
			printf("--------------------------------------------");
			printf("                   �α���                   ");
			printf("--------------------------------------------\n\n");
			printf("���̵�: ");
			fgets(id, 50, stdin);	// id�� �Է¹޴´�. �Ķ����(id�� ����� ����, ũ��, ǥ���Է½�Ʈ��)
			CHOP(id);				// ����Ű�� �ԷµǸ� ����Ű�� �������� �����.

			printf("�н�����: ");
			fgets(passwd, 50, stdin);	// passwd�� �Է¹޴´�. �Ķ����(passwd�� ����� ����, ũ��, ǥ���Է½�Ʈ��)
			CHOP(passwd);				// ����Ű�� �ԷµǸ� ����Ű�� �������� �����.

			sprintf(query, "select * from login where id = '%s' and passwd = '%s'", id, passwd);
			// ����ڰ� �Է��� id�� passwd�� ������ �˻��ϱ� ���� where�� �̿�.

			query_stat = mysql_query(connection, query);		// query�� ������. �Ķ����(��������, query���� ��� �迭)
																// ���������� �����ϸ� 0�� �����ϰ� �ƴ� �� 0�� �ƴ� ���� �����Ѵ�.
			
			sql_result = mysql_store_result(connection);
			if ((sql_row = mysql_fetch_row(sql_result)) != NULL) {	// �α��� ���� �� ����ȭ������ �̵��Ѵ�.
				printf("\n\n�α��� ����\n\n");
				break;
			}
			else {		// �α��� ���� �� �α��� ȭ������ �̵��Ѵ�.
				printf("\n\n�α��� ����\n\n");	
				system("pause");
				continue;
			}
		}
	}
	mysql_close(connection);
	system("pause");
}