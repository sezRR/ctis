SELECT * FROM APPOINTMENTS;

CREATE OR REPLACE PROCEDURE MAKEAPPOINTMENT(
    INP_APPOINTMENTID APPOINTMENTS.APPOINTMENTID%TYPE,
    INP_PATIENTID APPOINTMENTS.PATIENTID%TYPE,
    INP_DOCTORID APPOINTMENTS.DOCTORID%TYPE,
    INP_APPOINTMENTDATE APPOINTMENTS.APPOINTMENTDATE%TYPE,
    INP_APPOINTMENTTIME APPOINTMENTS.APPOINTMENTTIME%TYPE
)
IS
    v_count NUMBER;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Checking...');
    SELECT COUNT(*) INTO v_count FROM APPOINTMENTS WHERE APPOINTMENTID = INP_APPOINTMENTID;
    IF v_count != 0 THEN
        DBMS_OUTPUT.PUT_LINE('There is an appointment with that Id!');
        RETURN;
    END IF;
    
    SELECT COUNT(*) INTO v_count FROM PATIENTS WHERE PATIENTID = INP_PATIENTID;
    IF v_count = 0 THEN
        DBMS_OUTPUT.PUT_LINE('There is no such patient!');
        RETURN;
    END IF;
    
    SELECT COUNT(*) INTO v_count FROM DOCTORS WHERE DOCTORID = INP_DOCTORID;
    IF v_count = 0 THEN
        DBMS_OUTPUT.PUT_LINE('There is no such doctor!');
        RETURN;
    END IF;
    
    SELECT COUNT(*) INTO v_count FROM APPOINTMENTS
    WHERE DOCTORID = INP_DOCTORID
    AND APPOINTMENTDATE = INP_APPOINTMENTDATE 
    AND APPOINTMENTTIME = INP_APPOINTMENTTIME;
    
    IF v_count != 0 THEN
        DBMS_OUTPUT.PUT_LINE('Desired slot is not available to make an appointment for that doctor!');
        RETURN;
    END IF;
    
    INSERT INTO APPOINTMENTS
    VALUES (INP_APPOINTMENTID, INP_PATIENTID, INP_DOCTORID, INP_APPOINTMENTDATE, INP_APPOINTMENTTIME, 'Scheduled');
    
    DBMS_OUTPUT.PUT_LINE('Appointment scheduled successfully.');
END;
/

SET SERVEROUTPUT ON;
ACCEPT p_appointmentid PROMPT "Enter Appointment Id:";
ACCEPT p_patientid PROMPT "Enter Patient Id:";
ACCEPT p_doctorid PROMPT "Enter Doctor Id:";
ACCEPT p_appointmentdate PROMPT "Enter Appointment Date (DD-MON-RR):";
ACCEPT p_appointmenttime PROMPT "Enter Appointment Time (HH:MI):";
DECLARE
BEGIN
    MAKEAPPOINTMENT(
        &p_appointmentid, 
        &p_patientid, 
        &p_doctorid, 
        TO_DATE('&p_appointmentdate', 'DD-MON-RR', 'NLS_DATE_LANGUAGE=ENGLISH'),
        '&p_appointmenttime'
    );
END;
/

SELECT * FROM APPOINTMENTS;
SHOW ERRORS PROCEDURE MAKEAPPOINTMENT;

ROLLBACK;

CREATE OR REPLACE PROCEDURE DISPLAYMEDICALREPORTS(
    INP_PATIENTID IN MEDICALRECORDS.PATIENTID%TYPE
)
IS
    v_count NUMBER := 0;
    CURSOR record_cursor IS
        SELECT * FROM MEDICALRECORDS WHERE PATIENTID = INP_PATIENTID;
    v_record MEDICALRECORDS%ROWTYPE;
BEGIN
    SELECT COUNT(*) INTO v_count FROM MEDICALRECORDS WHERE PATIENTID = INP_PATIENTID;
    IF v_count = 0 THEN
        DBMS_OUTPUT.PUT_LINE('Looks like there is no medical record for that patient.');
    END IF;
    
    FOR v_record IN record_cursor LOOP
        DBMS_OUTPUT.PUT_LINE('Diagnosis: ' || v_record.DIAGNOSIS || ', Treatment: ' || v_record.TREATMENT || ', Record Date: ' || v_record.RECORDDATE);
    END LOOP;
END;
/

SET SERVEROUTPUT ON;
ACCEPT p_patientId PROMPT "Enter value for PatientId: "
BEGIN
    DISPLAYMEDICALREPORTS(&p_patientId);
END;
/

CREATE OR REPLACE FUNCTION DISPLAYDOCTORAPPOINTMENTS(
    INP_DOCTORID IN DOCTORS.DOCTORID%TYPE
) RETURN NUMBER
IS
    v_count NUMBER := 0;
    v_totalAppointments NUMBER := 0;
    CURSOR appointment_cursor IS
        SELECT * FROM APPOINTMENTS
        JOIN PATIENTS USING (PATIENTID)
        WHERE DOCTORID = INP_DOCTORID AND STATUS = 'Scheduled';
BEGIN
    FOR appointment IN appointment_cursor LOOP
        DBMS_OUTPUT.PUT_LINE('Appointment Date: ' || appointment.APPOINTMENTDATE || ', Patient Name: ' || appointment.PNAME || ', Status: ' || appointment.STATUS);
        v_totalAppointments := v_totalAppointments + 1;
    END LOOP;
    RETURN v_totalAppointments;
END;
/

SET SERVEROUTPUT ON;
ACCEPT p_doctorId PROMPT 'Enter value for DoctorId'
BEGIN
    DBMS_OUTPUT.PUT_LINE('Total Appointments: ' || DISPLAYDOCTORAPPOINTMENTS(&p_doctorId));
END;
/

SELECT * FROM APPOINTMENTS WHERE DOCTORID = 3;

CREATE OR REPLACE PROCEDURE RecordPrescription(
    INP_PRESCRIPTIONID IN NUMBER,
    INP_APPOINTMENTID IN NUMBER,
    INP_MEDICINE IN VARCHAR2,
    INP_DOSAGE IN VARCHAR2,
    INP_DURATION IN VARCHAR2,
    INP_INSTRUCTIONS IN VARCHAR2
)
IS
    v_count NUMBER;
BEGIN
    SELECT COUNT(*) INTO v_count FROM APPOINTMENTS WHERE APPOINTMENTID = INP_APPOINTMENTID AND STATUS = 'Completed';
    
    IF v_count = 0 THEN
        DBMS_OUTPUT.PUT_LINE('Prescription can only be recorded for completed appointments');
    END IF;
    
    INSERT INTO PRESCRIPTIONS(prescriptionid, appointmentid, medicine, dosage, duration, instructions)
    VALUES(INP_PRESCRIPTIONID, INP_APPOINTMENTID, INP_MEDICINE, INP_DOSAGE, INP_DURATION, INP_INSTRUCTIONS);
END;
/

INSERT INTO Appointments
(AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Status)
VALUES (7, 1, 1, TO_DATE('2024-12-14', 'YYYY-MM-DD'), '10:00', 'Completed');

SET SERVEROUTPUT ON;
DECLARE
 PrescriptionID NUMBER := 40;
 AppointmentID NUMBER := 11;
 Medicine VARCHAR2(100) := 'Paracetamol';
 Dosage VARCHAR2(50) := '500mg';
 Duration VARCHAR2(50) := '5 days';
 Instructions VARCHAR2(200) := 'Take 1 tablet every 6 hours';
BEGIN
 -- Call the RecordPrescription procedure with sample data
 RecordPrescription (PrescriptionID, AppointmentID, Medicine, Dosage, Duration, Instructions);
END;
/

SELECT * FROM APPOINTMENTS;
SELECT * FROM PRESCRIPTIONS;
ROLLBACK;
