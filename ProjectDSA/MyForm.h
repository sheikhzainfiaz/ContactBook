#pragma once
#include "Form2.h"
#include "MyForm1.h"

namespace ProjectDSA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		static int UserID;
		int count = 0;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	public:
		MyForm1^ f = gcnew MyForm1();
		
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:



	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(572, 214);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(343, 26);
			this->textBox1->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(170, 136);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(10, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L" ";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(572, 324);
			this->textBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(343, 26);
			this->textBox2->TabIndex = 5;
			this->textBox2->UseSystemPasswordChar = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::UpArrow;
			this->pictureBox1->Location = System::Drawing::Point(572, 379);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(357, 47);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::UpArrow;
			this->pictureBox2->Location = System::Drawing::Point(821, 455);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(94, 15);
			this->pictureBox2->TabIndex = 7;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1011, 605);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PhoneBook";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		   
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ email = textBox1->Text;
	String^ password = textBox2->Text;

	// Validate input
	if (String::IsNullOrWhiteSpace(email) || String::IsNullOrWhiteSpace(password)) {
		MessageBox::Show("Please enter both email and password.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	try {
		// Connection string to your SQL Server database
		String^ connectionString = "Data Source=MZ\\SQLEXPRESS;Initial Catalog=ContactBookDB;Integrated Security=True;Encrypt=False;";

		// SQL query to check email and password
		String^ query = "SELECT Count(*) FROM Users WHERE Email = @Email AND Password = @Password";

		// Create a connection object
		SqlConnection^ connection = gcnew SqlConnection(connectionString);
		SqlCommand^ command = gcnew SqlCommand(query, connection);

		// Add parameters to prevent SQL injection
		command->Parameters->AddWithValue("@Email", email);
		command->Parameters->AddWithValue("@Password", password);

		// Open the connection
		connection->Open();

		// Execute the query
		
			int userCount = (int)command->ExecuteScalar();

		// Close the connection
		connection->Close();

		// Check if credentials are correct
		if (userCount > 0) {
			query = "SELECT UserID FROM Users WHERE Email = @Email AND Password = @Password";

			// Create a connection object
			SqlConnection^ connection = gcnew SqlConnection(connectionString);
			SqlCommand^ command = gcnew SqlCommand(query, connection);

			// Add parameters to prevent SQL injection
			command->Parameters->AddWithValue("@Email", email);
			command->Parameters->AddWithValue("@Password", password);

			// Open the connection
			connection->Open();

			// Execute the query

			int userCount = (int)command->ExecuteScalar();

			// Close the connection
			connection->Close();
			UserID = userCount;
			// Open Form2
			Form2^ form2 = gcnew Form2();
			form2->userid = UserID;
			form2->Show(); // Show Form2
			this->Hide();  // Hide Form1

			// Subscribe to Form2's FormClosed event to return to Form1
			form2->FormClosed += gcnew FormClosedEventHandler(this, &MyForm::OnForm2Closed);
		}
		else {
			MessageBox::Show("Invalid email or password. Please try again.", "Login Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	catch (Exception^ ex) {
		// Handle any errors
		MessageBox::Show("An error occurred: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	

}
	   private: System::Void OnForm2Closed(System::Object^ sender, FormClosedEventArgs^ e) {
		   this->Show();
		   
	   }
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm1^ f = gcnew MyForm1();
	f->Show();
	this->Hide();
	
	f->FormClosed += gcnew FormClosedEventHandler(this, &MyForm::OnForm2Closed);
}
	   private: System::Void OnMyForm1Closed(System::Object^ sender, FormClosedEventArgs^ e) {
		   this->Show();
		   Application::Exit();
	   }
};
}
