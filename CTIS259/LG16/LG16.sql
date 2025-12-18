-- ORA
SET SERVEROUTPUT ON;
CREATE OR REPLACE PROCEDURE disp_employee
(dept IN number)
IS
  CURSOR emp_cursor IS
  SELECT LAST_NAME, FIRST_NAME, SALARY
  FROM EMPLOYEES
  WHERE DEPARTMENT_ID = dept;
  e_rec emp_cursor%rowtype;
BEGIN
  for e_rec IN emp_cursor loop
  DBMS_OUTPUT.put_line(e_rec.last_name || ', ' || e_rec.first_name || ', ' || e_rec.salary);
  END LOOP;
END;
/


exec disp_employee(80);


CREATE OR REPLACE PROCEDURE emp_sal
(dept IN number, raise_amount in NUMBER)
IS
BEGIN
  UPDATE employees
  SET salary = salary * raise_amount
  WHERE department_id = dept;

  if sql%notfound then
    DBMS_OUTPUT.PUT_LINE('there is no employee');
  elsif sql%found then
    DBMS_OUTPUT.PUT_LINE(sql%rowcount || ' record have been updated!');
  END IF;
END;
/

exec emp_sal(&dept_id, &raise_amount);
rollback;

select * from employees;

CREATE OR REPLACE VIEW EMPLOYEES_VU
AS SELECT EMPLOYEE_ID, LAST_NAME "EMPLOYEE", DEPARTMENT_ID
FROM EMPLOYEES;

SELECT EMPLOYEE, DEPARTMENT_ID FROM EMPLOYEES_VU;

SELECT * FROM LOCATIONS;

CREATE OR REPLACE VIEW LOCATIONS_VIEW
AS SELECT DEPARTMENT_ID, DEPARTMENT_NAME, LOCATION_ID, CITY FROM LOCATIONS
JOIN DEPARTMENTS USING (LOCATION_ID);

SELECT * FROM LOCATIONS_VIEW;

create table dept
as
select department_id id, department_name name
from departments;
alter table dept add constraint dept_pk primary key(id);

CREATE SEQUENCE DEPT_ID_SEQ
START WITH 200
INCREMENT BY 10
MINVALUE 0
MAXVALUE 1000;

SELECT * FROM DEPT;

INSERT INTO DEPT VALUES (DEPT_ID_SEQ.NEXTVAL, 'A');


-- STU
CREATE TABLE PERSONNEL (
  ID NUMBER(3) NOT NULL,
  NAME VARCHAR2(20) NOT NULL,
  SNAME VARCHAR2(20) NOT NULL,
  AGE NUMBER(38) NOT NULL,
  ADDRESS CHAR(25),
  SALARY NUMBER(10, 2)
);

INSERT INTO PERSONNEL (ID,NAME,SNAME, AGE,ADDRESS,SALARY)
VALUES (1, 'Mike', 'Jones', 32, 'Newyork', 2750.00 );

INSERT INTO PERSONNEL (ID,NAME,SNAME, AGE,ADDRESS,SALARY)
VALUES (2, 'Daniel', 'Gonzales', 25, 'Rome', 3500.00 );

INSERT INTO PERSONNEL (ID,NAME,SNAME, AGE,ADDRESS,SALARY)
VALUES (3, 'Tommy', 'John', 23, 'London', 2000.00 );

INSERT INTO PERSONNEL (ID,NAME,SNAME, AGE,ADDRESS,SALARY)
VALUES (4, 'Daniel', 'Smith', 25, 'Istanbul', 6500.00 );

INSERT INTO PERSONNEL (ID,NAME,SNAME, AGE,ADDRESS,SALARY)
VALUES (5, 'Mark', 'Johnson', 38, 'California', 4850.00 );

INSERT INTO PERSONNEL (ID,NAME,SNAME, AGE,ADDRESS,SALARY)
VALUES (6, 'Maria', 'Rodrigez', 34, 'Ankara', 4500.00 );

commit;

select * from PERSONNEL;

SET SERVEROUTPUT ON;
DECLARE
 total_rows number(2);
BEGIN
 UPDATE personnel
 SET salary = salary + 500;
 IF sql%notfound THEN
 dbms_output.put_line('There is no personnel in the list');
 ELSIF sql%found THEN
 total_rows := sql%rowcount;
 dbms_output.put_line('There are '||total_rows || ' personnel');
commit;
 END IF;
END;
/

DECLARE
  CURSOR personnel_cur is
    SELECT id, name, sname, salary
    FROM personnel;
  c_rec personnel_cur%rowtype;
BEGIN
  OPEN personnel_cur into c_rec;
  LOOP
    FETCH personnel_cur into c_rec;
    EXIT WHEN personnel_cur%notfound;
    DBMS_OUTPUT.put_line(c_rec.id|| ' ' || c_rec.name || ' ' || c_rec.sname || ' earns ' || c_rec.salary || ' $');
  END LOOP;
  CLOSE personnel_cur;
END;
/