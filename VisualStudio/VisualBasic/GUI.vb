Public Class GUI

    Private Sub ExitToolStripMenu(ByVal sender As Object, ByVal e As EventArgs) Handles exitToolStripMenuItem.Click
        Application.Exit()
    End Sub

    Private Sub RestartToolStripMenu(ByVal sender As Object, ByVal e As EventArgs) Handles restartToolStripMenuItem.Click
        Throw New NotImplementedException()
    End Sub

End Class
