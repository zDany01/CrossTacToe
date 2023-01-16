Public Class GUI
    Private Const APP_NAME As String = "Tic Tac Toe"
    Private clickCount As Integer = 0
    Private gameEnded As Boolean = False
    Private buttonGrid(9) As Button

    Private Sub GUI_Load(ByVal sender As Object, ByVal e As EventArgs) Handles Me.Load
        buttonGrid = New Button() {button1, button2, button3, button4, button5, button6, button7, button8, button9}
    End Sub

    Private Sub ResetGame()
        For Each button As Button In buttonGrid
            button.ResetText()
            button.ForeColor = Button.DefaultForeColor
        Next
        gameEnded = False
        clickCount = 0
    End Sub
    Private Sub FinishGame(ByVal pattern As (Button, Button, Button))
        pattern.Item1.ForeColor = Color.Green
        pattern.Item2.ForeColor = Color.Green
        pattern.Item3.ForeColor = Color.Green
        gameEnded = True
        If MsgBox($"Player {IIf(pattern.Item2.Text = "X", "one", "two")} has won!", MsgBoxStyle.RetryCancel + MsgBoxStyle.Information, APP_NAME) = MsgBoxResult.Retry Then ResetGame()
    End Sub
    Private Sub ExitToolStripMenu(ByVal sender As Object, ByVal e As EventArgs) Handles exitToolStripMenuItem.Click
        Application.Exit()
    End Sub
    Private Sub RestartToolStripMenu(ByVal sender As Object, ByVal e As EventArgs) Handles restartToolStripMenuItem.Click
        If MsgBox("Are you sure?", MsgBoxStyle.Question + MsgBoxStyle.YesNo, APP_NAME) = MsgBoxResult.Yes Then ResetGame()
    End Sub
    Private Sub GameLogic(ByVal sender As Object, ByVal e As EventArgs) Handles button1.Click, button2.Click, button3.Click, button4.Click, button5.Click, button6.Click, button7.Click, button8.Click, button9.Click
        If gameEnded Then Return
        Dim currentButton As Button = CType(sender, Button)
        If currentButton.Text = String.Empty Then
            currentButton.Text = IIf(clickCount Mod 2 = 0, "X", "O")
            clickCount += 1

            For i As Integer = 1 To buttonGrid.Count - 1 Step +3
                If (buttonGrid(i - 1).Text = "X" AndAlso buttonGrid(i).Text = "X" AndAlso buttonGrid(i + 1).Text = "X") OrElse (buttonGrid(i - 1).Text = "O" AndAlso buttonGrid(i).Text = "O" AndAlso buttonGrid(i + 1).Text = "O") Then FinishGame((buttonGrid(i - 1), buttonGrid(i), buttonGrid(i + 1)))
            Next
            For i As Integer = 3 To 5
                If (buttonGrid(i - 3).Text = "X" AndAlso buttonGrid(i).Text = "X" AndAlso buttonGrid(i + 3).Text = "X") OrElse (buttonGrid(i - 3).Text = "O" AndAlso buttonGrid(i).Text = "O" AndAlso buttonGrid(i + 3).Text = "O") Then FinishGame((buttonGrid(i - 3), buttonGrid(i), buttonGrid(i + 3)))
            Next
            If (buttonGrid(0).Text = "X" AndAlso buttonGrid(4).Text = "X" AndAlso buttonGrid(8).Text = "X") OrElse (buttonGrid(0).Text = "O" AndAlso buttonGrid(4).Text = "O" AndAlso buttonGrid(8).Text = "O") Then
                FinishGame((buttonGrid(0), buttonGrid(4), buttonGrid(8)))
            ElseIf (buttonGrid(2).Text = "X" AndAlso buttonGrid(4).Text = "X" AndAlso buttonGrid(6).Text = "X") OrElse (buttonGrid(2).Text = "O" AndAlso buttonGrid(4).Text = "O" AndAlso buttonGrid(6).Text = "O") Then
                FinishGame((buttonGrid(2), buttonGrid(4), buttonGrid(6)))
            ElseIf clickCount = 9 AndAlso MsgBox("Draw", MsgBoxStyle.Information + MsgBoxStyle.RetryCancel, APP_NAME) = MsgBoxResult.Retry Then
                ResetGame()
            End If
        Else
            MsgBox("You can't modify already modified panels", MsgBoxStyle.Exclamation + MsgBoxStyle.OkOnly, APP_NAME)
        End If
    End Sub

End Class
