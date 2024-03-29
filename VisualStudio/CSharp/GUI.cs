﻿using System;
using System.Drawing;
using System.Windows.Forms;

namespace CSharp
{
    public partial class GUI : Form
    {
        private const string APP_NAME = "Tic Tac Toe";
        private int clickCount = 0;
        private bool gameEnded = false;
        private Button[] buttonGrid;

        public GUI()
        {
            InitializeComponent();
            this.exitToolStripMenuItem.Click += (object sender, EventArgs _) => Application.Exit();
            this.restartToolStripMenuItem.Click += RestartToolStripMenu;
            this.button1.Click += GameLogic;
            this.button2.Click += GameLogic;
            this.button3.Click += GameLogic;
            this.button4.Click += GameLogic;
            this.button5.Click += GameLogic;
            this.button6.Click += GameLogic;
            this.button7.Click += GameLogic;
            this.button8.Click += GameLogic;
            this.button9.Click += GameLogic;
            this.Load += GUI_Load;
        }

        private void GUI_Load(object sender, EventArgs e)
        {
            buttonGrid = new Button[9] { button1, button2, button3, button4, button5, button6, button7, button8, button9 };
        }
        private void ResetGame()
        {
            foreach (Button button in buttonGrid)
            {
                button.ResetText();
                button.ForeColor = Button.DefaultForeColor;
            }
            gameEnded = false;
            clickCount = 0;
        }
        private void FinishGame((Button, Button, Button) pattern)
        {
            pattern.Item1.ForeColor = Color.Green;
            pattern.Item2.ForeColor = Color.Green;
            pattern.Item3.ForeColor = Color.Green;
            gameEnded = true;
            if (MessageBox.Show($"Player {(pattern.Item2.Text == "X" ? "one" : "two")} has won!", APP_NAME, MessageBoxButtons.RetryCancel, MessageBoxIcon.Information) == DialogResult.Retry) ResetGame();
        }
        private void RestartToolStripMenu(object sender, EventArgs e)
        {
            if (MessageBox.Show("Are you sure?", APP_NAME, MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes) ResetGame();
        }
        private void GameLogic(object sender, EventArgs e)
        {
            if (gameEnded) return;
            Button currentButton = (Button)sender;
            if (currentButton.Text == string.Empty)
            {
                currentButton.Text = clickCount++ % 2 == 0 ? "X" : "O";

                for (int i = 1; i < buttonGrid.Length; i += 3) if ((buttonGrid[i - 1].Text, buttonGrid[i].Text, buttonGrid[i + 1].Text) == ("X", "X", "X") || (buttonGrid[i - 1].Text, buttonGrid[i].Text, buttonGrid[i + 1].Text) == ("O", "O", "O")) FinishGame((buttonGrid[i - 1], buttonGrid[i], buttonGrid[i + 1]));
                for (int i = 3; i < 6; i++) if ((buttonGrid[i - 3].Text, buttonGrid[i].Text, buttonGrid[i + 3].Text) == ("X", "X", "X") || (buttonGrid[i - 3].Text, buttonGrid[i].Text, buttonGrid[i + 3].Text) == ("O", "O", "O")) FinishGame((buttonGrid[i - 3], buttonGrid[i], buttonGrid[i + 3]));
                if ((buttonGrid[0].Text, buttonGrid[4].Text, buttonGrid[8].Text) == ("X", "X", "X") || (buttonGrid[0].Text, buttonGrid[4].Text, buttonGrid[8].Text) == ("O", "O", "O")) FinishGame((buttonGrid[0], buttonGrid[4], buttonGrid[8]));
                else if ((buttonGrid[2].Text, buttonGrid[4].Text, buttonGrid[6].Text) == ("X", "X", "X") || (buttonGrid[2].Text, buttonGrid[4].Text, buttonGrid[6].Text) == ("O", "O", "O")) FinishGame((buttonGrid[2], buttonGrid[4], buttonGrid[6]));
                else if (clickCount == 9 && MessageBox.Show("Draw", APP_NAME, MessageBoxButtons.RetryCancel, MessageBoxIcon.Information) == DialogResult.Retry) ResetGame();
            }
            else MessageBox.Show("You can't modify already modified panels", APP_NAME, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
        }
    }
}
