CREATE OR REPLACE VIEW find_total
AS SELECT CID, CUSTNAME, CUSTSURNAME, SUM(QUANTITY) "#of items bought" FROM CUST
JOIN RECEIPT USING (CID)
JOIN RECEIPT_DETAILS USING (RID)
GROUP BY CID, CUSTNAME, CUSTSURNAME
ORDER BY "#of items bought" DESC;

SELECT * FROM FIND_TOTAL;

CREATE OR REPLACE VIEW product_report
AS SELECT PID, PNAME, SUM(QUANTITY) "#ofSold" FROM PRODUCT
JOIN RECEIPT_DETAILS USING(PID)
GROUP BY PID, PNAME
ORDER BY PID, PNAME;

SELECT * FROM PRODUCT_REPORT;

CREATE OR REPLACE FUNCTION find_total_sales(YEAR_INP IN NUMBER) RETURN NUMBER
IS
    total_sale NUMBER(6, 2) := 0;
BEGIN
    SELECT SUM(TOTAL) INTO TOTAL_SALE FROM RECEIPT WHERE EXTRACT(YEAR FROM RDATE) = YEAR_INP;
    
    return total_sale;
END;
/

SET SERVEROUTPUT ON;
UNDEFINE inp_year;
ACCEPT inp_year PROMPT "Enter the year to find the total sales:";
DECLARE
    v_year NUMBER := &inp_year;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Sales in ' || v_year || ': ' || FIND_TOTAL_SALES(v_year));
END;
/

CREATE OR REPLACE FUNCTION MARKET_COUPON
RETURN NUMBER
IS
    coupon_given NUMBER := 0;
    cust_coupon NUMBER(6, 2);
    CURSOR cust_cursor IS
        SELECT CID, CUSTNAME, CUSTSURNAME, SUM(TOTAL) "TOTAL" FROM RECEIPT
                        JOIN CUST USING(CID)
                        GROUP BY CID, CUSTNAME, CUSTSURNAME;
BEGIN
    FOR customer IN cust_cursor LOOP
        DBMS_OUTPUT.PUT_LINE(customer.CID || ' ' || customer.CUSTNAME || ' ' || customer.CUSTSURNAME || ': your total shopping amount is: ' || customer.TOTAL);
        coupon_given := coupon_given + 1;
        CASE
            WHEN customer.TOTAL >= 300 THEN
                cust_coupon := customer.TOTAL / 5;
            WHEN customer.TOTAL >= 200 THEN
                cust_coupon := customer.TOTAL / 10;
            WHEN customer.TOTAL >= 100 THEN
                cust_coupon := customer.TOTAL / 20;
            ELSE
                coupon_given := coupon_given - 1;
                DBMS_OUTPUT.PUT_LINE('Your total shopping amount is < 100, sorry!');
        END CASE;
        
        IF customer.TOTAL >= 100 THEN
            DBMS_OUTPUT.PUT_LINE('YOU WON ' || cust_coupon || ' TL MARKET COUPON :)');
        END IF;
        
        DBMS_OUTPUT.PUT_LINE('');
    END LOOP;
    
    RETURN COUPON_GIVEN;
END;
/

SET SERVEROUTPUT ON;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Total number of coupons: ' || MARKET_COUPON());
END;
/
