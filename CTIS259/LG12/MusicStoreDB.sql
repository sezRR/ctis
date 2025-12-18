-- Drop tables with CASCADE CONSTRAINTS option
DROP TABLE OrderItems CASCADE CONSTRAINTS;
DROP TABLE Orders CASCADE CONSTRAINTS;
DROP TABLE Customers CASCADE CONSTRAINTS;
DROP TABLE Songs CASCADE CONSTRAINTS;
DROP TABLE Albums CASCADE CONSTRAINTS;
DROP TABLE Artists CASCADE CONSTRAINTS;

-- Create Artists table
CREATE TABLE Artists (
    ArtistID NUMBER(1),
    ArtistName VARCHAR(30),
    Genre VARCHAR(50),
    CONSTRAINT ARTISTS_PK PRIMARY KEY(ArtistID)
);

-- Create Albums table
CREATE TABLE Albums (
    AlbumID NUMBER(3),
    AlbumTitle VARCHAR(255),
    ReleaseYear NUMBER(4),
    ArtistID NUMBER(1),
    AlbumPrice NUMBER(10, 2),
    CONSTRAINT Albums_PK PRIMARY KEY(AlbumID),
    CONSTRAINT ALBUMS_FK FOREIGN KEY (ArtistID) REFERENCES Artists(ArtistID)
);

-- Create Songs table
CREATE TABLE Songs (
    SongID NUMBER(2),
    SongTitle VARCHAR(255),
    Duration VARCHAR(8), -- Format: 'mm:ss'
    AlbumID NUMBER(3),
    Genre VARCHAR(50),
    CONSTRAINT Songs_PK PRIMARY KEY(SongID),
    CONSTRAINT SONGS_FK FOREIGN KEY (AlbumID) REFERENCES Albums(AlbumID)
);

-- Create Customers table
CREATE TABLE Customers (
    CustomerID NUMBER(2),
    FirstName VARCHAR(255),
    LastName VARCHAR(255),
    Email VARCHAR(255),
    Phone VARCHAR(20),
    CONSTRAINT Customers_PK PRIMARY KEY(CustomerID)
);

-- Create Orders table
CREATE TABLE Orders (
    OrderID NUMBER(3),
    CustomerID NUMBER(2),
    OrderDate DATE,
    TotalAmount NUMBER(10, 2),
    CONSTRAINT Orders_PK PRIMARY KEY(OrderID),
    CONSTRAINT ORDERS_FK FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID)
);

-- Create OrderItems table
CREATE TABLE OrderItems (
    OrderItemID INT PRIMARY KEY,
    OrderID NUMBER(3),
    AlbumID NUMBER(3),
    Quantity NUMBER(2),
    CONSTRAINT ORDERITEMS_FK1 FOREIGN KEY (OrderID) REFERENCES Orders(OrderID),
    CONSTRAINT ORDERITEMS_FK2 FOREIGN KEY (AlbumID) REFERENCES Albums(AlbumID)
);

SET DEFINE OFF;
-- Insert data into Artists table
INSERT INTO Artists (ArtistID, ArtistName, Genre) 
VALUES (1, 'John Doe', 'Rock');
INSERT INTO Artists (ArtistID, ArtistName, Genre)
VALUES (2, 'Jane Smith', 'Pop');
INSERT INTO Artists (ArtistID, ArtistName, Genre) 
VALUES (3, 'Michael Johnson', 'Hip Hop');
INSERT INTO Artists (ArtistID, ArtistName, Genre) 
VALUES (4, 'Emily White', 'R&B');
INSERT INTO Artists (ArtistID, ArtistName, Genre) 
VALUES (5, 'Chris Brown', 'Pop');
INSERT INTO Artists (ArtistID, ArtistName, Genre) 
VALUES (6, 'Alex Turner', 'Rock');
INSERT INTO Artists (ArtistID, ArtistName, Genre) 
VALUES (7, 'Alicia Keys', 'R&B');

-- Insert data into Albums table
INSERT INTO Albums (AlbumID, AlbumTitle, ReleaseYear, ArtistID, AlbumPrice) 
VALUES (111, 'Sample Album 1', 2022, 1,12.99);
INSERT INTO Albums (AlbumID, AlbumTitle, ReleaseYear, ArtistID, AlbumPrice) 
VALUES (222, 'Pop Hits 2023', 2023, 2, 8.99);
INSERT INTO Albums (AlbumID, AlbumTitle, ReleaseYear, ArtistID, AlbumPrice)  
VALUES (333, 'Hip Hop Revolution', 2021, 3, 11.25);
INSERT INTO Albums (AlbumID, AlbumTitle, ReleaseYear, ArtistID, AlbumPrice)  
VALUES (444, 'R&B Soulful', 2020, 4, 15.4);
INSERT INTO Albums (AlbumID, AlbumTitle, ReleaseYear, ArtistID, AlbumPrice) 
VALUES (555, 'Greatest Hits', 2019, 5,5.2);
INSERT INTO Albums (AlbumID, AlbumTitle, ReleaseYear, ArtistID, AlbumPrice)  
VALUES (666, 'Rock Classics', 2018, 6, 14.15);
INSERT INTO Albums (AlbumID, AlbumTitle, ReleaseYear, ArtistID, AlbumPrice)  
VALUES (777, 'R&B Anthems', 2017, 7, 10.75);
INSERT INTO Albums (AlbumID, AlbumTitle, ReleaseYear, ArtistID, AlbumPrice)  
VALUES (888, 'Sample Album 2', 2023, 1, 8.95);
INSERT INTO Albums (AlbumID, AlbumTitle, ReleaseYear, ArtistID, AlbumPrice)  
VALUES (999, 'Rap Revolution', 2023, 3, 11.50);

-- Insert data into Songs table
INSERT INTO Songs (SongID, SongTitle, Duration, AlbumID, Genre) 
VALUES (1, 'Rock Anthem', '04:15', 111, 'Rock');
INSERT INTO Songs (SongID, SongTitle, Duration, AlbumID, Genre) 
VALUES (2, 'Pop Ballad', '03:50', 222, 'Pop');
INSERT INTO Songs (SongID, SongTitle, Duration, AlbumID, Genre) 
VALUES (3, 'Hip Hop Groove', '03:30', 333, 'Hip Hop');
INSERT INTO Songs (SongID, SongTitle, Duration, AlbumID, Genre) 
VALUES (4, 'R&B Love Song', '04:05', 444, 'R&B');
INSERT INTO Songs (SongID, SongTitle, Duration, AlbumID, Genre) 
VALUES (5, 'Pop Dance', '03:20', 555, 'Pop');
INSERT INTO Songs (SongID, SongTitle, Duration, AlbumID, Genre) 
VALUES (6, 'Rock Ballad', '05:00', 666, 'Rock');
INSERT INTO Songs (SongID, SongTitle, Duration, AlbumID, Genre) 
VALUES (7, 'R&B Slow Jam', '04:30', 777, 'R&B');
INSERT INTO Songs (SongID, SongTitle, Duration, AlbumID, Genre)
VALUES (8, 'Pop Sensation', '03:45', 888, 'Pop');
INSERT INTO Songs (SongID, SongTitle, Duration, AlbumID, Genre)
VALUES (9, 'Hip Hop Groove', '03:15', 999, 'Hip Hop');
INSERT INTO Songs (SongID, SongTitle, Duration, AlbumID, Genre)
VALUES (10, 'Pop Grooves', '03:25', 111, 'Pop');
INSERT INTO Songs (SongID, SongTitle, Duration, AlbumID, Genre)
VALUES (11, 'Rock Revolution', '04:10', 222, 'Rock');
INSERT INTO Songs (SongID, SongTitle, Duration, AlbumID, Genre)
VALUES (12, 'Hip Hop Hustle', '03:45', 333, 'Hip Hop');

-- Insert data into Customers table
INSERT INTO Customers (CustomerID, FirstName, LastName, Email, Phone) 
VALUES (1, 'Alice', 'Johnson', 'alice@example.com', '123-456-7890');
INSERT INTO Customers (CustomerID, FirstName, LastName, Email, Phone) 
VALUES (2, 'Bob', 'Smith', 'bob@example.com', '234-567-8901');
INSERT INTO Customers (CustomerID, FirstName, LastName, Email, Phone) 
VALUES (3, 'Charlie', 'Brown', 'charlie@example.com', '345-678-9012');
INSERT INTO Customers (CustomerID, FirstName, LastName, Email, Phone) 
VALUES (4, 'David', 'Lee', 'david@example.com', '456-789-0123');
INSERT INTO Customers (CustomerID, FirstName, LastName, Email, Phone) 
VALUES (5, 'Eva', 'Williams', 'eva@example.com', '567-890-1234');
INSERT INTO Customers (CustomerID, FirstName, LastName, Email, Phone) 
VALUES (6, 'Frank', 'Davis', 'frank@example.com', '678-901-2345');
INSERT INTO Customers (CustomerID, FirstName, LastName, Email, Phone) 
VALUES (7, 'Grace', 'Taylor', 'grace@example.com', '789-012-3456');
INSERT INTO Customers (CustomerID, FirstName, LastName, Email, Phone) 
VALUES (8, 'Henry', 'Martin', 'henry@example.com', '890-123-4567');
INSERT INTO Customers (CustomerID, FirstName, LastName, Email, Phone) 
VALUES (9, 'Ivy', 'Johnson', 'ivy@example.com', '901-234-5678');
INSERT INTO Customers (CustomerID, FirstName, LastName, Email, Phone) 
VALUES (10, 'Jack', 'Anderson', 'jack@example.com', '012-345-6789');

-- Insert data into Orders table
INSERT INTO Orders (OrderID, CustomerID, OrderDate, TotalAmount) 
VALUES (101, 1, TO_DATE('2022-01-15', 'YYYY-MM-DD'), 21.98);
INSERT INTO Orders (OrderID, CustomerID, OrderDate, TotalAmount) 
VALUES (202, 2, TO_DATE('2023-02-20', 'YYYY-MM-DD'), 22.50);
INSERT INTO Orders (OrderID, CustomerID, OrderDate, TotalAmount) 
VALUES (303, 2, TO_DATE('2022-03-25', 'YYYY-MM-DD'), 15.4);
INSERT INTO Orders (OrderID, CustomerID, OrderDate, TotalAmount) 
VALUES (404, 4, TO_DATE('2023-04-10', 'YYYY-MM-DD'), 15.6);
INSERT INTO Orders (OrderID, CustomerID, OrderDate, TotalAmount) 
VALUES (505, 5, TO_DATE('2023-05-05', 'YYYY-MM-DD'), 56.6);
INSERT INTO Orders (OrderID, CustomerID, OrderDate, TotalAmount) 
VALUES (606, 6, TO_DATE('2023-06-18', 'YYYY-MM-DD'), 21.50);
INSERT INTO Orders (OrderID, CustomerID, OrderDate, TotalAmount) 
VALUES (707, 5, TO_DATE('2023-05-10', 'YYYY-MM-DD'), 21.50);

-- Insert data into OrderItems table
INSERT INTO OrderItems (OrderItemID, OrderID, AlbumID, Quantity) 
VALUES (1, 101, 111, 1);
INSERT INTO OrderItems (OrderItemID, OrderID, AlbumID, Quantity) 
VALUES (2, 101, 222, 1);
INSERT INTO OrderItems (OrderItemID, OrderID, AlbumID, Quantity) 
VALUES (3, 202, 333, 2);
INSERT INTO OrderItems (OrderItemID, OrderID, AlbumID, Quantity) 
VALUES (4, 303, 444, 1);
INSERT INTO OrderItems (OrderItemID, OrderID, AlbumID, Quantity) 
VALUES (5, 404, 555, 3);
INSERT INTO OrderItems (OrderItemID, OrderID, AlbumID, Quantity) 
VALUES (6, 505, 666, 4);
INSERT INTO OrderItems (OrderItemID, OrderID, AlbumID, Quantity) 
VALUES (7, 606, 777, 2);
INSERT INTO OrderItems (OrderItemID, OrderID, AlbumID, Quantity) 
VALUES (8, 707, 777, 2);

COMMIT;