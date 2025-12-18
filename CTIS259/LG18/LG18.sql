CREATE OR REPLACE VIEW BORROWING_COUNTS
AS SELECT STUID, STNAME, STSURNAME, COUNT(*) "number of borrowings" FROM STUDENTS
JOIN BORROWING ON STID = STUID
GROUP BY STUID, STNAME, STSURNAME
ORDER BY STUID;

SELECT * FROM BORROWING_COUNTS;

CREATE OR REPLACE PROCEDURE CALCULATEPUNISHMENT
IS
BEGIN
    UPDATE BORROWING
    SET PUNISHMENT = (RETURNDATE - DUEDATE) * 2.25
    WHERE RETURNDATE > DUEDATE;
    
    IF sql%ROWCOUNT = 0 THEN
        DBMS_OUTPUT.PUT_LINE('No punishment to calculate.');
    ELSE
        DBMS_OUTPUT.PUT_LINE(sql%ROWCOUNT || ' records have been updated!');
    END IF;

    DBMS_OUTPUT.PUT_LINE('punishment calculation done :)');
END;
/

SET SERVEROUTPUT ON;
BEGIN
    CALCULATEPUNISHMENT();
END;
/

CREATE OR REPLACE PROCEDURE DISPLAYBOOKS
IS
BEGIN
    DBMS_OUTPUT.PUT_LINE('List of Available Books');
    FOR book IN (SELECT * FROM BOOKS WHERE STATUS = 'A') LOOP
        DBMS_OUTPUT.PUT_LINE(book.ISBN || ' ' || book.TITLE || ' ' || book.STATUS);
    END LOOP;
END;
/

CREATE OR REPLACE PROCEDURE DISPLAYBOOKS_CURSOR
IS
    CURSOR book_cursor IS
        SELECT * FROM BOOKS WHERE STATUS = 'A';
BEGIN
    DBMS_OUTPUT.PUT_LINE('List of Available Books');
    FOR book IN book_cursor LOOP
        DBMS_OUTPUT.PUT_LINE(book.ISBN || ' ' || book.TITLE || ' ' || book.STATUS);
    END LOOP;
END;
/

SET SERVEROUTPUT ON;
BEGIN
    DISPLAYBOOKS();
    DISPLAYBOOKS_CURSOR();
END;
/

CREATE OR REPLACE PROCEDURE RESERVE_BOOK(
    BOOK_ISBN IN BOOKS.ISBN%TYPE,
    STUDENT_ID IN STUDENTS.STID%TYPE
)
IS
    DUE_DATE DATE;
    DESIRED_BOOK BOOKS%ROWTYPE;
BEGIN
    SELECT * INTO DESIRED_BOOK FROM BOOKS WHERE ISBN = BOOK_ISBN;
    
    IF DESIRED_BOOK.STATUS = 'N' THEN
        DBMS_OUTPUT.PUT_LINE('SORRY! The book is NOT available!');
    END IF;

    DUE_DATE := SYSDATE + 15;
    
    -- INSERT BORROWING
    INSERT INTO BORROWING 
    VALUES (STUDENT_ID, BOOK_ISBN, SYSDATE, NULL, DUE_DATE, 0);
    
    -- UPDATE STATUS
    UPDATE BOOKS
    SET STATUS = 'N'
    WHERE ISBN = BOOK_ISBN;
    
    COMMIT;
    
    DBMS_OUTPUT.PUT_LINE('The Book' || BOOK_ISBN || ' borrowed');
END;
/

SET SERVEROUTPUT ON;
ACCEPT p_isbn PROMPT "Enter the ISBN of the book:";
ACCEPT p_stuid PROMPT "Enter the Student Id:";
BEGIN
    RESERVE_BOOK('&p_isbn', &p_stuid);
END;
/

CREATE OR REPLACE FUNCTION PUNISHMENTLEVEL
RETURN NUMBER
IS
    red_level_students NUMBER := 0;
BEGIN
    FOR stu IN (SELECT STID, STNAME, STSURNAME, SUM(PUNISHMENT) "PUNISHMENT" FROM BORROWING JOIN STUDENTS ON STID = STUID GROUP BY STID, STNAME, STSURNAME) LOOP
        DBMS_OUTPUT.PUT(stu.STID || ' ' || stu.STNAME || ' ' || stu.STSURNAME || ': ');
        CASE
            WHEN stu.PUNISHMENT > 10 THEN
                red_level_students := red_level_students + 1;
                DBMS_OUTPUT.PUT('Red');
            WHEN stu.PUNISHMENT < 10 AND stu.PUNISHMENT >= 1 THEN
                DBMS_OUTPUT.PUT('Yellow');
            WHEN stu.PUNISHMENT = 0 THEN
                DBMS_OUTPUT.PUT('Green');
        END CASE;
        DBMS_OUTPUT.PUT_LINE(' Level user with the punishment payment ' || stu.PUNISHMENT || ' TL');
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('');
    RETURN red_level_students;
END;
/

CREATE OR REPLACE FUNCTION PUNISHMENTLEVEL_CURSOR
RETURN NUMBER
IS
    red_level_students NUMBER := 0;
    CURSOR stu_cursor IS
        SELECT STID, STNAME, STSURNAME, SUM(PUNISHMENT) "PUNISHMENT" FROM BORROWING 
        JOIN STUDENTS ON STID = STUID 
        GROUP BY STID, STNAME, STSURNAME;
BEGIN
    FOR stu IN (stu_cursor) LOOP
        DBMS_OUTPUT.PUT(stu.STID || ' ' || stu.STNAME || ' ' || stu.STSURNAME || ': ');
        CASE
            WHEN stu.PUNISHMENT > 10 THEN
                red_level_students := red_level_students + 1;
                DBMS_OUTPUT.PUT('Red');
            WHEN stu.PUNISHMENT < 10 AND stu.PUNISHMENT >= 1 THEN
                DBMS_OUTPUT.PUT('Yellow');
            WHEN stu.PUNISHMENT = 0 THEN
                DBMS_OUTPUT.PUT('Green');
        END CASE;
        DBMS_OUTPUT.PUT_LINE(' Level user with the punishment payment ' || stu.PUNISHMENT || ' TL');
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('');
    RETURN red_level_students;
END;
/

SET SERVEROUTPUT ON;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Total number Red Level Users: ' || PUNISHMENTLEVEL());
    DBMS_OUTPUT.PUT_LINE('Total number Red Level Users: ' || PUNISHMENTLEVEL_CURSOR());
END;
/