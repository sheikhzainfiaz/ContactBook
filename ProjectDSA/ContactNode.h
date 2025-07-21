#pragma once


    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;
    ref class ContactNode
    {
    public:
        
        int UserID;
        String^ Name;
        String^ Number;
        String^ Email;
        ContactNode^ Next;

        ContactNode(int userId, String^ name, String^ number, String^ email) {
            
            UserID = userId;
            Name = name;
            Number = number;
            Email = email;
            Next = nullptr;
        }
    };