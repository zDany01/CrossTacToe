#pragma once
#define APP_NAME "Tic Tac Toe"
namespace CPP_CLI {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class GUI : public System::Windows::Forms::Form
	{
	private: int clickCount = 0;
	private: bool gameEnded = false;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: List<Button^>^ buttonGrid;

	public: GUI(void)
	{
		InitializeComponent();
		this->exitToolStripMenuItem->Click += gcnew EventHandler(this, &GUI::ExitToolStripMenu);
		this->restartToolStripMenuItem->Click += gcnew EventHandler(this, &GUI::RestartToolStripMenu);
		this->button1->Click += gcnew EventHandler(this, &GUI::GameLogic);
		this->button2->Click += gcnew EventHandler(this, &GUI::GameLogic);
		this->button3->Click += gcnew EventHandler(this, &GUI::GameLogic);
		this->button4->Click += gcnew EventHandler(this, &GUI::GameLogic);
		this->button5->Click += gcnew EventHandler(this, &GUI::GameLogic);
		this->button6->Click += gcnew EventHandler(this, &GUI::GameLogic);
		this->button7->Click += gcnew EventHandler(this, &GUI::GameLogic);
		this->button8->Click += gcnew EventHandler(this, &GUI::GameLogic);
		this->button9->Click += gcnew EventHandler(this, &GUI::GameLogic);
		this->Load += gcnew EventHandler(this, &GUI::GUI_Load);
	}

	private: System::Void GUI_Load(Object^ sender, EventArgs^ e) {
		buttonGrid = gcnew List<Button^>();
		buttonGrid->Add(button1);
		buttonGrid->Add(button2);
		buttonGrid->Add(button3);
		buttonGrid->Add(button4);
		buttonGrid->Add(button5);
		buttonGrid->Add(button6);
		buttonGrid->Add(button7);
		buttonGrid->Add(button8);
		buttonGrid->Add(button9);
	}
	private: System::Void ResetGame() {
		for each (Button ^ button in buttonGrid)
		{
			button->Text = "";
			button->ForeColor = Control::DefaultForeColor;
		}
		gameEnded = false;
		clickCount = 0;
	}
	private: System::Void FinishGame(ValueTuple<Button^, Button^, Button^>^ pattern) {
		pattern->Item1->ForeColor = Color::Green;
		pattern->Item2->ForeColor = Color::Green;
		pattern->Item3->ForeColor = Color::Green;
		gameEnded = true;
		if (MessageBox::Show("Player " + (pattern->Item2->Text == "X" ? "one" : "two") + " has won!", APP_NAME, MessageBoxButtons::RetryCancel, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::Retry) ResetGame();
	}
	private: System::Void ExitToolStripMenu(Object^ sender, EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void RestartToolStripMenu(Object^ sender, EventArgs^ e) {
		if (MessageBox::Show("Are you sure?", APP_NAME, MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) ResetGame();
	}
	private: bool CheckForAllValues(String^ item1, String^ item2, String^ item3, String^ value) {
		return item1 == value && item2 == value && item3 == value;
	}
	private: System::Void GameLogic(Object^ sender, EventArgs^ e) {
		if (gameEnded) return;
		Button^ currentButton = (Button^)sender;
		if (currentButton->Text == "") {
			currentButton->Text = clickCount++ % 2 == 0 ? "X" : "O";

			for (int i = 1; i < buttonGrid->Count; i += 3)
				if (CheckForAllValues(buttonGrid[i - 1]->Text, buttonGrid[i]->Text, buttonGrid[i + 1]->Text, "X") || CheckForAllValues(buttonGrid[i - 1]->Text, buttonGrid[i]->Text, buttonGrid[i + 1]->Text, "O")) FinishGame(gcnew ValueTuple<Button^, Button^, Button^>(buttonGrid[i - 1], buttonGrid[i], buttonGrid[i + 1]));
			for (int i = 3; i < 6; i++)
				if (CheckForAllValues(buttonGrid[i - 3]->Text, buttonGrid[i]->Text, buttonGrid[i + 3]->Text, "X") || CheckForAllValues(buttonGrid[i - 3]->Text, buttonGrid[i]->Text, buttonGrid[i + 3]->Text,"O")) FinishGame(gcnew ValueTuple<Button^, Button^, Button^>(buttonGrid[i - 3], buttonGrid[i], buttonGrid[i + 3]));
			if (CheckForAllValues(buttonGrid[0]->Text, buttonGrid[4]->Text, buttonGrid[8]->Text, "X") || CheckForAllValues(buttonGrid[0]->Text, buttonGrid[4]->Text, buttonGrid[8]->Text, "O")) FinishGame(gcnew ValueTuple<Button^, Button^, Button^>(buttonGrid[0], buttonGrid[4], buttonGrid[8]));
			else if (CheckForAllValues(buttonGrid[2]->Text, buttonGrid[4]->Text, buttonGrid[6]->Text, "X") || CheckForAllValues(buttonGrid[2]->Text, buttonGrid[4]->Text, buttonGrid[6]->Text, "O")) FinishGame(gcnew ValueTuple<Button^, Button^, Button^>(buttonGrid[2], buttonGrid[4], buttonGrid[6]));
			else if (clickCount == 9 && MessageBox::Show("Draw", APP_NAME, MessageBoxButtons::RetryCancel, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::Retry) ResetGame();
		}
		else MessageBox::Show("You can't modify already modified panels", APP_NAME, MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}

	protected: ~GUI()
	{
		if (components)
		{
			delete components;
		}
	}











	private: System::Windows::Forms::ContextMenuStrip^ ContextMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ restartToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->ContextMenu = (gcnew System::Windows::Forms::ContextMenuStrip());
			   this->restartToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->button9 = (gcnew System::Windows::Forms::Button());
			   this->button8 = (gcnew System::Windows::Forms::Button());
			   this->button7 = (gcnew System::Windows::Forms::Button());
			   this->button6 = (gcnew System::Windows::Forms::Button());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->ContextMenu->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // ContextMenu
			   // 
			   this->ContextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->restartToolStripMenuItem,
					   this->exitToolStripMenuItem
			   });
			   this->ContextMenu->Name = L"ContextMenu";
			   this->ContextMenu->Size = System::Drawing::Size(111, 48);
			   // 
			   // restartToolStripMenuItem
			   // 
			   this->restartToolStripMenuItem->Name = L"restartToolStripMenuItem";
			   this->restartToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			   this->restartToolStripMenuItem->Text = L"Restart";
			   // 
			   // exitToolStripMenuItem
			   // 
			   this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			   this->exitToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			   this->exitToolStripMenuItem->Text = L"Exit";
			   // 
			   // button9
			   // 
			   this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button9->Location = System::Drawing::Point(132, 100);
			   this->button9->Name = L"button9";
			   this->button9->Size = System::Drawing::Size(42, 38);
			   this->button9->TabIndex = 17;
			   this->button9->UseVisualStyleBackColor = true;
			   // 
			   // button8
			   // 
			   this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button8->Location = System::Drawing::Point(72, 100);
			   this->button8->Name = L"button8";
			   this->button8->Size = System::Drawing::Size(42, 38);
			   this->button8->TabIndex = 16;
			   this->button8->UseVisualStyleBackColor = true;
			   // 
			   // button7
			   // 
			   this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button7->Location = System::Drawing::Point(12, 100);
			   this->button7->Name = L"button7";
			   this->button7->Size = System::Drawing::Size(42, 38);
			   this->button7->TabIndex = 15;
			   this->button7->UseVisualStyleBackColor = true;
			   // 
			   // button6
			   // 
			   this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button6->Location = System::Drawing::Point(132, 56);
			   this->button6->Name = L"button6";
			   this->button6->Size = System::Drawing::Size(42, 38);
			   this->button6->TabIndex = 14;
			   this->button6->UseVisualStyleBackColor = true;
			   // 
			   // button5
			   // 
			   this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button5->Location = System::Drawing::Point(72, 56);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(42, 38);
			   this->button5->TabIndex = 13;
			   this->button5->UseVisualStyleBackColor = true;
			   // 
			   // button4
			   // 
			   this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button4->Location = System::Drawing::Point(12, 56);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(42, 38);
			   this->button4->TabIndex = 12;
			   this->button4->UseVisualStyleBackColor = true;
			   // 
			   // button3
			   // 
			   this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button3->Location = System::Drawing::Point(132, 12);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(42, 38);
			   this->button3->TabIndex = 11;
			   this->button3->UseVisualStyleBackColor = true;
			   // 
			   // button2
			   // 
			   this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button2->Location = System::Drawing::Point(72, 12);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(42, 38);
			   this->button2->TabIndex = 10;
			   this->button2->UseVisualStyleBackColor = true;
			   // 
			   // button1
			   // 
			   this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button1->Location = System::Drawing::Point(12, 12);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(42, 38);
			   this->button1->TabIndex = 9;
			   this->button1->UseVisualStyleBackColor = true;
			   // 
			   // GUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(186, 150);
			   this->ContextMenuStrip = this->ContextMenu;
			   this->Controls->Add(this->button9);
			   this->Controls->Add(this->button8);
			   this->Controls->Add(this->button7);
			   this->Controls->Add(this->button6);
			   this->Controls->Add(this->button5);
			   this->Controls->Add(this->button4);
			   this->Controls->Add(this->button3);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->button1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"GUI";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"TicTacToe";
			   this->ContextMenu->ResumeLayout(false);
			   this->ResumeLayout(false);

		   }
#pragma endregion
	};
}
