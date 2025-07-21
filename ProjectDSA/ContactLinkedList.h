#pragma once
#include "ContactNode.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;

ref class ContactLinkedList
{
private:
    ContactNode^ head;
    SqlConnection^ conn;

public:
    int userid;

    ContactLinkedList(int user) {
        userid = user;
        conn = gcnew SqlConnection("Data Source=MZ\\SQLEXPRESS;Initial Catalog=ContactBookDB;Integrated Security=True;Encrypt=False;");
        head = nullptr;
        try {
            PopulateFromDatabase();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    ContactLinkedList(int user, String^ searchString) {
        userid = user;
        conn = gcnew SqlConnection("Data Source=MZ\\SQLEXPRESS;Initial Catalog=ContactBookDB;Integrated Security=True;Encrypt=False;");
        head = nullptr;
        try {
            SearchAndPopulate(searchString);
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    // Function to populate the linked list from the database
    void PopulateFromDatabase() {
        try {
            if (conn->State == ConnectionState::Closed)
                conn->Open();

            SqlCommand^ cmd = gcnew SqlCommand("SELECT UserID, Name, Number, Email FROM Contact WHERE UserID = @userId", conn);
            cmd->Parameters->AddWithValue("@userId", userid);

            SqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                int userId = Convert::ToInt32(reader["UserID"]);
                String^ name = reader["Name"]->ToString();
                String^ phone = reader["Number"]->ToString();
                String^ email = reader["Email"]->ToString();

                // Create a new ContactNode and add it to the linked list
                ContactNode^ newNode = gcnew ContactNode(userId, name, phone, email);
                newNode->Next = head;
                head = newNode;
            }

            reader->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error while populating from database: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            if (conn->State == ConnectionState::Open)
                conn->Close();
        }
    }

    // Function to search and populate linked list based on searchString
    void SearchAndPopulate(String^ searchString) {
        try {
            if (conn->State == ConnectionState::Closed)
                conn->Open();

            SqlCommand^ cmd;
            
                // Search by number for the specific userid
                cmd = gcnew SqlCommand("SELECT UserID, Name, Number, Email FROM Contact WHERE UserID = @userId AND (Number LIKE @searchValue OR Name LIKE @searchValue)", conn);
                cmd->Parameters->AddWithValue("@userId", userid);
                cmd->Parameters->AddWithValue("@searchValue","%"+searchString + "%");
            
            

            SqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                int userId = Convert::ToInt32(reader["UserID"]);
                String^ name = reader["Name"]->ToString();
                String^ phone = reader["Number"]->ToString();
                String^ email = reader["Email"]->ToString();

                // Create a new ContactNode and add it to the linked list
                ContactNode^ newNode = gcnew ContactNode(userId, name, phone, email);
                newNode->Next = head;
                head = newNode;
            }

            reader->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error while searching and populating: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            if (conn->State == ConnectionState::Open)
                conn->Close();
        }
    }

    String^ AddContact(int userId, String^ name, String^ phone, String^ email) {
        String^ msg;
        try {
            if (conn->State == ConnectionState::Closed)
                conn->Open();

            SqlCommand^ cmd = gcnew SqlCommand("INSERT INTO Contact(UserID, Name, Number, Email) VALUES(@userId, @name, @number, @email);", conn);
            cmd->Parameters->AddWithValue("@userId", userId);
            cmd->Parameters->AddWithValue("@name", name);
            cmd->Parameters->AddWithValue("@number", phone);
            cmd->Parameters->AddWithValue("@email", email);

            int result = cmd->ExecuteNonQuery();

            if (result > 0) {
                ContactNode^ newNode = gcnew ContactNode(userId, name, phone, email);
                newNode->Next = head;
                head = newNode;
                
            }
            msg = "Contact Added SuccessFully";

        }
        catch (Exception^ ex) {
            msg = "Error while adding contact: " + ex->Message;
            
        }
        finally {
            if (conn->State == ConnectionState::Open)
                conn->Close();
        }
        return msg;
    }

    void DisplayContacts() {
        ContactNode^ current = head;
        while (current != nullptr) {
            // Replace with UI-specific code to display contact details
            // Example: Add to a ListView or DataGridView
            current = current->Next;
        }
    }

    ContactNode^ GetHead() {
        return head;
    }
    void DeleteContact(String^ number) {
        try {
            // Delete the contact from the database
            if (conn->State == ConnectionState::Closed)
                conn->Open();

            SqlCommand^ cmd = gcnew SqlCommand("DELETE FROM Contact WHERE UserID = @userId AND Number = @number", conn);
            cmd->Parameters->AddWithValue("@userId", userid);
            cmd->Parameters->AddWithValue("@number", number);

            int result = cmd->ExecuteNonQuery();

            if (result > 0) {
                // If the contact was successfully deleted from the database, remove it from the linked list
                if (head != nullptr) {
                    if (head->UserID == userid && head->Number->Equals(number)) {
                        // If the head node matches, delete it
                        ContactNode^ temp = head;
                        head = head->Next;
                        delete temp;
                    }
                    else {
                        // Traverse the list to find and remove the matching node
                        ContactNode^ current = head;
                        while (current->Next != nullptr) {
                            if (current->Next->UserID == userid && current->Next->Number->Equals(number)) {
                                ContactNode^ temp = current->Next;
                                current->Next = current->Next->Next;
                                delete temp;
                                break;
                            }
                            current = current->Next;
                        }
                    }
                }

                MessageBox::Show("Contact deleted successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            else {
                MessageBox::Show("No matching contact found to delete.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error while deleting contact: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            if (conn->State == ConnectionState::Open)
                conn->Close();
        }
    }
    void ModifyContact(String^ currentNumber, String^ newName, String^ newNumber, String^ newEmail) {
        try {
            // Update the contact in the database
            if (conn->State == ConnectionState::Closed)
                conn->Open();

            SqlCommand^ cmd = gcnew SqlCommand(
                "UPDATE Contact SET Name = @newName, Number = @newNumber, Email = @newEmail WHERE UserID = @userId AND Number = @currentNumber", conn
            );
            cmd->Parameters->AddWithValue("@userId", userid);
            cmd->Parameters->AddWithValue("@currentNumber", currentNumber);
            cmd->Parameters->AddWithValue("@newName", newName);
            cmd->Parameters->AddWithValue("@newNumber", newNumber);
            cmd->Parameters->AddWithValue("@newEmail", newEmail);

            int result = cmd->ExecuteNonQuery();

            if (result > 0) {
                // If the contact was successfully updated in the database, update it in the linked list
                ContactNode^ current = head;
                while (current != nullptr) {
                    if (current->UserID == userid && current->Number->Equals(currentNumber)) {
                        // Update the contact details in the linked list
                        current->Name = newName;
                        current->Number = newNumber;
                        current->Email = newEmail;
                        break;
                    }
                    current = current->Next;
                }

                MessageBox::Show("Contact modified successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            else {
                MessageBox::Show("No matching contact found to modify.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error while modifying contact: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            if (conn->State == ConnectionState::Open)
                conn->Close();
        }
    }

};
