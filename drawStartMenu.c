#include "a.h"

int drawStartMenu(void) {   // show start menu. ����ȭ��. 
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // ǥ���ܼ������ �ڵ��� ��ȯ.
    MYSQL conn = { 0 };			// ����ü�� ������ �� �ִ� ����ü ����
    MYSQL* connection = NULL;	// ���������� �����ϴ� ������ ����
    MYSQL_RES* sql_result;		// �޸𸮿� ������� �����ϰ� �޸��� ���۹����� sql_result�� �����Ѵ�.
    MYSQL_ROW sql_row;			// �޸𸮷� ������ ����� ��ü�� �� ������ �д´�.

    int query_stat = 0;			// ������ ����� ���� �ƴ��� Ȯ���ϱ� ���� ����.
    char query[255] = { 0 };	// �Էµ� id�� passwd�� DB�� query�ϱ� ���� �迭.
    
    system("cls");

    while (1) {    
        int i = 0;
        SetConsoleTextAttribute(hand, 13);  // �ֿܼ����� ���ڻ��� ��ȫ��(13)���� �����Ѵ�.
        gotoxy(DEFAULT_X, DEFAULT_Y);       // Ŀ���� (0, 0) ��ǥ�� �̵�.
        printf("============================================");
        SetConsoleTextAttribute(hand, 14);  // �ֿܼ����� ���ڻ��� �����(14)���� �����Ѵ�.
        printf("================ Snake Game ================");
        SetConsoleTextAttribute(hand, 11);  // �ֿܼ����� ���ڻ��� �ϴû�(11)���� �����Ѵ�.
        printf("============================================");
        SetConsoleTextAttribute(hand, 15);  // �ֿܼ����� ���ڻ��� £�� �Ͼ��(15)���� �����Ѵ�.
        gotoxy(DEFAULT_X, DEFAULT_Y + 4);   // Ŀ���� (0, 4) ��ǥ�� �̵�.
        printf("> Key  : up, down, left, right,");
        gotoxy(DEFAULT_X, DEFAULT_Y + 5);   // Ŀ���� (0, 5) ��ǥ�� �̵�.
        printf("> Rank : 'r'");
        gotoxy(DEFAULT_X, DEFAULT_Y + 6);   // Ŀ���� (0, 5) ��ǥ�� �̵�.
        printf("> Exit : 't'");

        gotoxy(DEFAULT_X + 11, DEFAULT_Y + 14);     // Ŀ���� (11, 14) ��ǥ�� �̵�.
        printf("<Made by BlockDMask.>");
        gotoxy(DEFAULT_X + 11, DEFAULT_Y + 15);     // Ŀ���� (11, 15) ��ǥ�� �̵�.
        printf("<BlockDMask@gmail.com>");
        SetConsoleTextAttribute(hand, 14);      // �ֿܼ����� ���ڻ��� �����(14)���� �����Ѵ�. 

        gotoxy(DEFAULT_X + 5, DEFAULT_Y + 9);   // Ŀ���� (5, 9) ��ǥ�� �̵�.
        printf("-- press 's' to start --");
        Sleep(1000 / 3);    // 0.3�ʸ��� ����ؼ� �����̰� ���̰� �Ѵ�.
        gotoxy(DEFAULT_X + 5, DEFAULT_Y + 9);   // Ŀ���� (5, 9) ��ǥ�� �̵�.
        printf("                         ");
        Sleep(1000 / 3);    // 0.3�ʸ��� ����ؼ� �����̰� ���̰� �Ѵ�.

        int keyDown = getKeyDown();
        if (keyDown == 's' || keyDown == 'S') { // s�� S�� �ԷµǸ� �ֿܼ����� ���ڻ��� ���� ���(7)����
                                                // ���� �� TRUE�� ����.
            SetConsoleTextAttribute(hand, 7);
            return TRUE;
        }
        if (keyDown == 't' || keyDown == 'T') { // t�� T�� �ԷµǸ� �ֿܼ����� ���ڻ��� ���� ���(7)����
                                                // ���� �� FALSE�� ����.
            SetConsoleTextAttribute(hand, 7);
            return FALSE;
        }
        if (keyDown == 'r' || keyDown == 'R') { // r �Ǵ� R�� �ԷµǸ� �ֿܼ����� ���ڻ��� ���� ���(7)����
                                                // ���� �� ���� �� ������ ����Ѵ�.

            system("cls");
            SetConsoleTextAttribute(hand, 7);
            printf("����������������������������������������������������������������������������������������\n");
            printf("                   RANKING\n");
            printf("����������������������������������������������������������������������������������������\n");
            printf("> Back : 'r'");

            // �ʱ�ȭ
            mysql_init(&conn);

            // ���� mysql_real_connect
            connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0);
            // ���� ������ �� ����� ������ �����Ͱ� �Ѿ���� ������ �� NULL�� �Ѿ�´�.

            if (connection == NULL) {	// ���� ���� �� ���п����� ����ϴ� �Լ�.
                fprintf(stderr, "���п���: %s\n", mysql_error(&conn));
                return 1;		// ������ ���Ḧ �˸���.
            }

            sprintf(query, "select id, score1 from ranking where score1 order by 2 desc limit 3");
            // ranking ���̺��� score1�� ���� id�� score1�� ������������ 3����� ��ȸ�Ѵ�.
            query_stat = mysql_query(connection, query);	// query. DB�� �ִ� ������ Ȯ���Ѵ�.
            // query�� ����� ���ư����� 0�� ���ϵǰ� ������������ �����ϸ� 0�� �ƴ� ���� ���ϵȴ�.
            sql_result = mysql_store_result(connection);    // �޸𸮿� ����� query ����� sql_result�� �����Ѵ�. -> (���� ���� �ƴ� ���۹��� ����)
                                                            // ��, sql_result�� ��ü ������ ��� ���۹����� ����ִ�.
            
            gotoxy(0, 8);
            printf("       Stage [1]             Stage [2]\n");
            while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {	// sql_result�� NULL�� �ƴ� ������ ��ü ������ ��� sql_result�� �����ؼ�
                                                                        // sql_row�� �� �྿ �����´�. 
                i++;
                gotoxy(DEFAULT_X, DEFAULT_Y + (i + 9));
                printf(" %d�� -> %5s %s��", i, sql_row[0], sql_row[1]); // stage [1]�� ���̵�� ������ 3������ �ֿܼ� ����Ѵ�.
            }
            i = 0;
            mysql_free_result(sql_result);	// mysql_store_result()�� �޸𸮸� ��� �����ϰ� �ֱ� ������ �޸𸮸� �������ش�.

            sprintf(query, "select id, score2 from ranking where score2 order by 2 desc limit 3");
            // ranking ���̺��� score2�� ���� id�� score2�� ������������ 3����� ��ȸ�Ѵ�.
            query_stat = mysql_query(connection, query);	// query. DB�� �ִ� ������ Ȯ���Ѵ�.
            // query�� ����� ���ư����� 0�� ���ϵǰ� ������������ �����ϸ� 0�� �ƴ� ���� ���ϵȴ�.
            sql_result = mysql_store_result(connection);		// �޸𸮿� ����� query ����� sql_result�� �����Ѵ�. -> (���� ���� �ƴ� ���۹��� ����)
                                                                // ��, sql_result�� ��ü ������ ��� ���۹����� ����ִ�.
            while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {	// sql_result�� NULL�� �ƴ� ������ ��ü ������ ��� sql_result�� �����ؼ�
                                                                        // sql_row�� �� �྿ �����´�. 
                i++;
                gotoxy(DEFAULT_X + 12, DEFAULT_Y + (i + 9));
                printf(" %d�� -> %5s %s��", i, sql_row[0], sql_row[1]); // stage [2]�� ���̵�� ������ 3������ �ֿܼ� ����Ѵ�.
            }
            i = 0;
            mysql_free_result(sql_result);	// mysql_store_result()�� �޸𸮸� ��� �����ϰ� �ֱ� ������ �޸𸮸� �������ش�.

            sprintf(query, "select id, score3 from ranking where score3 order by 2 desc limit 3");
            // ranking ���̺��� score3�� ���� id�� score3�� ������������ 3����� ��ȸ�Ѵ�.
            query_stat = mysql_query(connection, query);	// query. DB�� �ִ� ������ Ȯ���Ѵ�.
            // query�� ����� ���ư����� 0�� ���ϵǰ� ������������ �����ϸ� 0�� �ƴ� ���� ���ϵȴ�.
            sql_result = mysql_store_result(connection);		// �޸𸮿� ����� query ����� sql_result�� �����Ѵ�. -> (���� ���� �ƴ� ���۹��� ����)
                                                                // ��, sql_result�� ��ü ������ ��� ���۹����� ����ִ�.

            gotoxy(0, 18);           
            printf("       Stage [3]             Stage [4]\n");            
            while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {	// sql_result�� NULL�� �ƴ� ������ ��ü ������ ��� sql_result�� �����ؼ�
                                                                        // sql_row�� �� �྿ �����´�. 
                i++;
                gotoxy(DEFAULT_X, DEFAULT_Y + (i + 19));
                printf(" %d�� -> %5s %s��", i, sql_row[0], sql_row[1]); // stage [3]�� ���̵�� ������ 3������ �ֿܼ� ����Ѵ�.
            }
            i = 0;
            mysql_free_result(sql_result);	// mysql_store_result()�� �޸𸮸� ��� �����ϰ� �ֱ� ������ �޸𸮸� �������ش�.
            
            sprintf(query, "select id, score4 from ranking where score4 order by 2 desc limit 3");
            // ranking ���̺��� score4�� ���� id�� score4�� ������������ 3����� ��ȸ�Ѵ�.
            query_stat = mysql_query(connection, query);	// query. DB�� �ִ� ������ Ȯ���Ѵ�.
            // query�� ����� ���ư����� 0�� ���ϵǰ� ������������ �����ϸ� 0�� �ƴ� ���� ���ϵȴ�.

            sql_result = mysql_store_result(connection);		// �޸𸮿� ����� query ����� sql_result�� �����Ѵ�. -> (���� ���� �ƴ� ���۹��� ����)
                                                                // ��, sql_result�� ��ü ������ ��� ���۹����� ����ִ�.
            while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {	// sql_result�� NULL�� �ƴ� ������ ��ü ������ ��� sql_result�� �����ؼ�
                                                                        // sql_row�� �� �྿ �����´�. 
                i++;
                gotoxy(DEFAULT_X + 12, DEFAULT_Y + (i + 19));
                printf(" %d�� -> %5s %s��", i, sql_row[0], sql_row[1]); // stage [4]�� ���̵�� ������ 3������ �ֿܼ� ����Ѵ�.
            }
            
            mysql_free_result(sql_result);	// mysql_store_result()�� �޸𸮸� ��� �����ϰ� �ֱ� ������ �޸𸮸� �������ش�.

            while (keyDown != 'r' || 'R') { // ����â���� r �Ǵ� R�� ������ ����ȭ������ ���ư���.
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