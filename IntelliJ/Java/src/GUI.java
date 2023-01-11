import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
public class GUI extends JDialog implements ActionListener {
    private final Dimension defaultButtonSize = new Dimension(40,36);
    private List<JButton> buttonGrid = new ArrayList();
    public GUI(){
        InitializeComponent();
    }





    //<editor-fold desc="Events">
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == exitMenuItem) this.dispose();
    }
    //</editor-fold>
    //<editor-fold desc="Graphics">
    private JButton button1, button2, button3, button4, button5, button6, button7, button8, button9;
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
        buttonGrid.add(button1);
        buttonGrid.add(button2);
        buttonGrid.add(button3);
        buttonGrid.add(button4);
        buttonGrid.add(button5);
        buttonGrid.add(button6);
        buttonGrid.add(button7);
        buttonGrid.add(button8);
        buttonGrid.add(button9);
        for(int i = 0; i < buttonGrid.size(); i++){
            buttonGrid.set(i, new JButton());
            buttonGrid.get(i).setPreferredSize(defaultButtonSize);
            buttonGrid.get(i).setBackground(Color.white);
            buttonGrid.get(i).setInheritsPopupMenu(true);
            mainPanel.add(buttonGrid.get(i));
            if(i == 2 || i == 5) mainPanel.add(Box.createRigidArea(new Dimension(this.getWidth(),8)));
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
