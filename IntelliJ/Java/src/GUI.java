import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
public class GUI extends JDialog implements ActionListener {
    private final Dimension defaultButtonSize = new Dimension(40,36);
    private final Dimension defaultDividerSize = new Dimension(202, 8);
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
            button.setPreferredSize(defaultButtonSize);
            button.setBackground(Color.white);
            button.setInheritsPopupMenu(true);
            buttonGrid.add(button);
            mainPanel.add(button);
            if(i == 2 || i == 5) mainPanel.add(Box.createRigidArea(defaultDividerSize));
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
