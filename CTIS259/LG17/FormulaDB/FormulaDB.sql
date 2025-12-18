alter table DRIVER
   drop constraint FK_DRIVER_REFERENCE_TEAM;

alter table SPONSORS
   drop constraint FK_SPONSORS_REFERENCE_SPONSOR;

alter table SPONSORS
   drop constraint FK_SPONSORS_REFERENCE_TEAM;

drop table DRIVER cascade constraints;

drop table SPONSOR cascade constraints;

drop table SPONSORS cascade constraints;

drop table TEAM cascade constraints;

/*==============================================================*/
/* Table: DRIVER                                                */
/*==============================================================*/
create table DRIVER  (
   NAME                 VARCHAR2(20)                    not null,
   ID                   VARCHAR2(2),
   BIRTHDATE            DATE                            not null,
   YEARSOFEXPERIENCE    INTEGER,
   GENDER               CHAR                            not null,
   COUNTRY              VARCHAR2(15)                    not null,
   constraint PK_DRIVER primary key (NAME)
);

/*==============================================================*/
/* Table: SPONSOR                                               */
/*==============================================================*/
create table SPONSOR  (
   COMPANY              VARCHAR2(10)                    not null,
   CITY                 VARCHAR2(15),
   ACTIVE               VARCHAR2(3)                     not null,
   constraint PK_SPONSOR primary key (COMPANY)
);

/*==============================================================*/
/* Table: SPONSORS                                              */
/*==============================================================*/
create table SPONSORS  (
   COMPANY              VARCHAR2(10)                    not null,
   ID                   VARCHAR2(2)                     not null,
   SUPPORTED_AMOUNT     NUMBER(10,3)                    not null,
   constraint PK_SPONSORS primary key (COMPANY, ID)
);

/*==============================================================*/
/* Table: TEAM                                                  */
/*==============================================================*/
create table TEAM  (
   ID                   VARCHAR2(2)                     not null,
   NAME                 VARCHAR2(15)                    not null,
   constraint PK_TEAM primary key (ID)
);

alter table DRIVER
   add constraint FK_DRIVER_REFERENCE_TEAM foreign key (ID)
      references TEAM (ID);

alter table SPONSORS
   add constraint FK_SPONSORS_REFERENCE_SPONSOR foreign key (COMPANY)
      references SPONSOR (COMPANY);

alter table SPONSORS
   add constraint FK_SPONSORS_REFERENCE_TEAM foreign key (ID)
      references TEAM (ID);

