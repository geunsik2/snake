#include "a.h"

int drawSpeedMenu(int* scoreArr) {  // �� ���� �޴��� ������ �����ش�.
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // ǥ���ܼ������ �ڵ��� ��ȯ.
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

    sprintf(query, "select * from ranking where id = '%s'", id);    // �ش� id�� ��� �������� ������ ��ȸ�Ѵ�.
    query_stat = mysql_query(connection, query);	// query. DB�� �ִ� ������ Ȯ���Ѵ�.
    // query�� ����� ���ư����� 0�� ���ϵǰ� ������������ �����ϸ� 0�� �ƴ� ���� ���ϵȴ�.
    if (query_stat != 0) {	// ������������ ������ �� exception ó���ϴ� �Լ�.
        fprintf(stderr, "���п���: %s\n", mysql_error(&conn));
        return 1;
    }

    sql_result = mysql_store_result(connection);		// �޸𸮿� ����� query ����� sql_result�� �����Ѵ�. -> (���� ���� �ƴ� ���۹��� ����)
                                                        // ��, sql_result�� ��ü ������ ��� ���۹����� ����ִ�.

    while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {	// sql_result�� NULL�� �ƴ� ������ ��ü ������ ��� sql_result�� �����ؼ�
                                                                // sql_row�� �� �྿ �����´�.
        for (int i = 0; i < 4; i++) {
            gotoxy(DEFAULT_X, DEFAULT_Y + (i + 4)); // Ŀ���� (0, 4)���� (0, 7)���� �̵��Ѵ�.
            printf(" Stage [%d] : %s", i + 1, sql_row[i + 1]); // stage �� ������ �ֿܼ� ����Ѵ�.
            scoreArr[i] = atoi(sql_row[i + 1]);
        }
    }

    mysql_free_result(sql_result);	// mysql_store_result()�� �޸𸮸� ��� �����ϰ� �ֱ� ������ �޸𸮸� �������ش�.

    while (1) {
        int keyDown = getKeyDown();
        if (keyDown == '1') {   // ����ڷκ��� 1�� �Է¹����� 1�� �����Ѵ�.
            SetConsoleTextAttribute(hand, 7);   // �ֿܼ����� ���ڻ��� ���� ���(7)���� �����Ѵ�.
            return 1;
        }
        if (keyDown == '2') {   // ����ڷκ��� 2�� �Է¹����� 2�� �����Ѵ�.
            SetConsoleTextAttribute(hand, 7);
            return 2;
        }
        if (keyDown == '3') {   // ����ڷκ��� 3�� �Է¹����� 3�� �����Ѵ�.
            SetConsoleTextAttribute(hand, 7);
            return 3;
        }
        if (keyDown == '4') {   // ����ڷκ��� 4�� �Է¹����� 4�� �����Ѵ�.
            SetConsoleTextAttribute(hand, 7);
            return 4;
        }
        SetConsoleTextAttribute(hand, 14);  // �ֿܼ����� ���ڻ��� �����(14)���� �����Ѵ�.
        gotoxy(DEFAULT_X, DEFAULT_Y + 9);   // Ŀ���� (0, 9) ��ǥ�� �̵�.
        printf(">> Choose Stage : 1, 2, 3, 4");
        Sleep(1000 / 3);    // 0.3�ʸ��� ����ؼ� �����̰� ���̰� �Ѵ�.
        gotoxy(DEFAULT_X, DEFAULT_Y + 9);
        printf(">>                          ");
        Sleep(1000 / 3);    // 0.3�ʸ��� ����ؼ� �����̰� ���̰� �Ѵ�.
    }
    mysql_close(connection);
}
