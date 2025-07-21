#using <System.dll>
#using <System.Data.dll>
#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

ref class Database{
private:
    SqlConnection^ conn;
public:
    Database() {
        conn = gcnew SqlConnection("Data Source=MZ\\SQLEXPRESS;Initial Catalog=ContactBookDB;Integrated Security=True;Encrypt=False;");
    }

    void OpenConnection() {
        if (conn->State == ConnectionState::Closed)
            conn->Open();
    }

    void CloseConnection() {
        if (conn->State == ConnectionState::Open)
            conn->Close();
    }

    SqlConnection^ GetConnection() {
        return conn;
    }
};
