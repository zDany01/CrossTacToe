Public Class GUI
    Const APP_NAME As String = "Tic Tac Toe"
    Private clickCount As Integer = 0
    Private gameEnded As Boolean = False
    Private buttonGrid As List(Of Button) = New List(Of Button)

    Private Sub GUI_Load(sender As Object, e As EventArgs) Handles Me.Load
        buttonGrid.Add(button1)
        buttonGrid.Add(button2)
        buttonGrid.Add(button3)
        buttonGrid.Add(button4)
        buttonGrid.Add(button5)
        buttonGrid.Add(button6)
        buttonGrid.Add(button7)
        buttonGrid.Add(button8)
        buttonGrid.Add(button9)
    End Sub

    Private Sub ResetGame()
        For Each button As Button In buttonGrid
            button.Text = ""
            button.ForeColor = Button.DefaultForeColor
        Next
        gameEnded = False
        clickCount = 0
    End Sub
    Private Sub FinishGame(pattern As (Button, Button, Button))
        pattern.Item1.ForeColor = Color.Green
        pattern.Item2.ForeColor = Color.Green
        pattern.Item3.ForeColor = Color.Green
        gameEnded = True
        If MsgBox($"Player {IIf(pattern.Item2.Text = "X", "one", "two")} has won!", MsgBoxStyle.RetryCancel, APP_NAME) = MsgBoxResult.Retry Then ResetGame()
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
        If currentButton.Text = "" Then
            currentButton.Text = IIf(clickCount Mod 2 = 0, "X", "O")
            clickCount += 1

            For i As Integer = 1 To buttonGrid.Count - 1 Step +3
                If (buttonGrid.Item(i).Text = "X" AndAlso buttonGrid.Item(i - 1).Text = "X" AndAlso buttonGrid.Item(i + 1).Text = "X") OrElse (buttonGrid.Item(i).Text = "O" AndAlso buttonGrid.Item(i - 1).Text = "O" AndAlso buttonGrid.Item(i + 1).Text = "O") Then FinishGame((buttonGrid.Item(i - 1), buttonGrid.Item(i), buttonGrid.Item(i + 1)))
            Next
            For i As Integer = 3 To 5
                If (buttonGrid.Item(i).Text = "X" AndAlso buttonGrid.Item(i - 3).Text = "X" AndAlso buttonGrid.Item(i + 3).Text = "X") OrElse (buttonGrid.Item(i).Text = "O" AndAlso buttonGrid.Item(i - 3).Text = "O" AndAlso buttonGrid.Item(i + 3).Text = "O") Then FinishGame((buttonGrid.Item(i - 3), buttonGrid.Item(i), buttonGrid.Item(i + 3)))
            Next
            If (buttonGrid.Item(0).Text = "X" AndAlso buttonGrid.Item(4).Text = "X" AndAlso buttonGrid.Item(8).Text = "X") OrElse (buttonGrid.Item(0).Text = "O" AndAlso buttonGrid.Item(4).Text = "O" AndAlso buttonGrid.Item(8).Text = "O") Then
                FinishGame((buttonGrid.Item(0), buttonGrid.Item(4), buttonGrid.Item(8)))
            ElseIf (buttonGrid.Item(2).Text = "X" AndAlso buttonGrid.Item(4).Text = "X" AndAlso buttonGrid.Item(6).Text = "X") OrElse (buttonGrid.Item(2).Text = "O" AndAlso buttonGrid.Item(4).Text = "O" AndAlso buttonGrid.Item(6).Text = "O") Then
                FinishGame((buttonGrid.Item(2), buttonGrid.Item(4), buttonGrid.Item(6)))
            ElseIf clickCount = 9 AndAlso MsgBox($"Draw", MsgboxStyle.Information + MsgBoxStyle.RetryCancel, APP_NAME) = MsgBoxResult.Retry Then
                ResetGame()
            End If
        Else
            MsgBox("You can't modify already modified panels", MsgBoxStyle.Exclamation + MsgBoxStyle.OkOnly, APP_NAME)
        End If
    End Sub

End Class
