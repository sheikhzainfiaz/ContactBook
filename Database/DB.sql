-- 1️⃣ Create Database
CREATE DATABASE ContactBookDB;
GO

-- 2️⃣ Use the Database
USE ContactBookDB;
GO

-- 3️⃣ Create dbo.Users table
CREATE TABLE dbo.Users (
    UserID INT PRIMARY KEY NOT NULL,
    Email NVARCHAR(100) NOT NULL,
    Password NVARCHAR(50) NOT NULL
);
GO

-- 4️⃣ Create dbo.Contact table
CREATE TABLE dbo.Contact (
    UserID INT FOREIGN KEY REFERENCES dbo.Users(UserID) NOT NULL,
    Number VARCHAR(11) NOT NULL,
    Name VARCHAR(100) NOT NULL,
    Email VARCHAR(255) NOT NULL
);
GO

-- 5️⃣ Insert dummy user 'zain'
INSERT INTO dbo.Users (UserID, Email, Password)
VALUES (1, 'zain@example.com', 'zain123');
GO

-- 6️⃣ Insert dummy contact linked to zain
INSERT INTO dbo.Contact (UserID, Number, Name, Email)
VALUES (1, '03001234567', 'Ali Ahmed', 'ali.ahmed@example.com');
GO

-- 7️⃣ Select to view data
SELECT * FROM dbo.Users;
SELECT * FROM dbo.Contact;
