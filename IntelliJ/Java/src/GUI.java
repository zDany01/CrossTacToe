import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

public class GUI extends JDialog implements ActionListener {
    private final Dimension DEFAULT_BUTTON_SIZE = new Dimension(40,36);
    private final Dimension DEFAULT_DIVIDER_SIZE = new Dimension(202, 8);
    private final Font SANS_SERIF_BOLD = new Font(Font.SANS_SERIF, Font.BOLD, 16);
    private final String[] RETRY_ABORT = {"Retry", "Abort"};
    private final String APP_NAME = "Tic Tac Toe";
    private int clickCount = 0;
    private boolean gameEnded = false;
    private List<JButton> buttonGrid = new ArrayList(9);
    public GUI(){
        InitializeComponent();
    }


    private void ResetGame(){
        for(JButton button : buttonGrid){
            button.setText("");
            button.setForeground(null);
        }
        gameEnded = false;
        clickCount = 0;
    }
    private void FinishGame(JButton pattern1, JButton pattern2, JButton pattern3){
        pattern1.setForeground(Color.green);
        pattern2.setForeground(Color.green);
        pattern3.setForeground(Color.green);
        gameEnded = true;
        if(JOptionPane.showOptionDialog(this, String.format("Player %s has won!", pattern2.getText().equals("X") ? "one" : "two"), APP_NAME, JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE, null, RETRY_ABORT, 0) == 0) ResetGame();
    }
    private void GameLogic(JButton currentButton){
        if (gameEnded) return;
        if(currentButton.getText().equals("")){
            currentButton.setText(clickCount++ % 2 == 0 ? "X" : "O");
            for(int i = 1; i < buttonGrid.size(); i+= 3) if ((buttonGrid.get(i-1).getText().equals("X") && buttonGrid.get(i).getText().equals("X") && buttonGrid.get(i+1).getText().equals("X")) || (buttonGrid.get(i-1).getText().equals("O") && buttonGrid.get(i).getText().equals("O") && buttonGrid.get(i+1).getText().equals("O"))) FinishGame(buttonGrid.get(i-1), buttonGrid.get(i), buttonGrid.get(i+1));
            for(int i = 3; i < 6; i++) if ((buttonGrid.get(i-3).getText().equals("X") && buttonGrid.get(i).getText().equals("X") && buttonGrid.get(i+3).getText().equals("X")) || (buttonGrid.get(i-3).getText().equals("O") && buttonGrid.get(i).getText().equals("O") && buttonGrid.get(i+3).getText().equals("O"))) FinishGame(buttonGrid.get(i-3), buttonGrid.get(i), buttonGrid.get(i+3));
            if ((buttonGrid.get(0).getText().equals("X") && buttonGrid.get(4).getText().equals("X") && buttonGrid.get(8).getText().equals("X")) || (buttonGrid.get(0).getText().equals("O") && buttonGrid.get(4).getText().equals("O") && buttonGrid.get(8).getText().equals("O"))) FinishGame(buttonGrid.get(0), buttonGrid.get(4), buttonGrid.get(8));
            else if ((buttonGrid.get(2).getText().equals("X") && buttonGrid.get(4).getText().equals("X") && buttonGrid.get(6).getText().equals("X")) || (buttonGrid.get(2).getText().equals("O") && buttonGrid.get(4).getText().equals("O") && buttonGrid.get(6).getText().equals("O"))) FinishGame(buttonGrid.get(2), buttonGrid.get(4), buttonGrid.get(6));
            else if (clickCount == 9 && JOptionPane.showOptionDialog(this, "Draw", APP_NAME, JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE, null, RETRY_ABORT, 0) == 0) ResetGame();
        } else JOptionPane.showConfirmDialog(this, "You can't modify already modified panels", APP_NAME, JOptionPane.DEFAULT_OPTION, JOptionPane.WARNING_MESSAGE);
    }




    //<editor-fold desc="Events">
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == exitMenuItem) this.dispose();
        else if (e.getSource() == restartMenuItem && JOptionPane.showConfirmDialog(this, "Are you sure?", APP_NAME, JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE) == JOptionPane.YES_OPTION) ResetGame();
        else if (e.getSource() instanceof JButton) GameLogic((JButton)e.getSource());
    }
    //</editor-fold>
    //<editor-fold desc="Graphics">
    private JPopupMenu contextMenu;
    private JMenuItem restartMenuItem, exitMenuItem;
    private void InitializeComponent(){
        this.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
        this.setSize(202,189);
        this.setResizable(false);
        this.setTitle("TicTacToe");
        this.setLocationRelativeTo(null); //Start at CenterScreen
        JPanel mainPanel = new JPanel();
        mainPanel.setSize(this.getSize());
        this.add(mainPanel);
        mainPanel.setLayout(new FlowLayout(FlowLayout.CENTER,20,0));
        mainPanel.setComponentOrientation(ComponentOrientation.LEFT_TO_RIGHT);
        mainPanel.add(Box.createRigidArea(new Dimension(this.getWidth(),13)));
        contextMenu = new JPopupMenu();
        mainPanel.setComponentPopupMenu(contextMenu);
        for(int i = 0; i < 9; i++){
            JButton button = new JButton();
            button.setPreferredSize(DEFAULT_BUTTON_SIZE);
            button.setBackground(Color.white);
            button.setInheritsPopupMenu(true);
            button.addActionListener(this);
            button.setFont(SANS_SERIF_BOLD);
            button.setMargin(new Insets(0, 0, 0, 0));
            buttonGrid.add(button);
            mainPanel.add(button);
            if(i == 2 || i == 5) mainPanel.add(Box.createRigidArea(DEFAULT_DIVIDER_SIZE));
        }
        restartMenuItem = new JMenuItem("Restart");
        exitMenuItem = new JMenuItem("Exit");
        restartMenuItem.addActionListener(this);
        exitMenuItem.addActionListener(this);
        contextMenu.add(restartMenuItem);
        contextMenu.add(exitMenuItem);
    }
    //</editor-fold>
}
