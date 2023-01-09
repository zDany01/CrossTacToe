import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.List;
public class GUI extends JDialog implements MouseListener, ActionListener {
    private final Dimension defaultButtonSize = new Dimension(40,34);
    private List<JButton> buttonGrid = new ArrayList();
    public GUI(){
        InitializeComponent();
    }

    //Events
    @Override
    public void mouseClicked(MouseEvent e) {
        if(SwingUtilities.isRightMouseButton(e)) contextMenu.show(this, e.getX(), e.getY());
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == exitMenuItem) this.dispose();
    }


    @Override
    public void mousePressed(MouseEvent e) {}
    @Override
    public void mouseReleased(MouseEvent e){}
    @Override
    public void mouseEntered(MouseEvent e) {}
    @Override
    public void mouseExited(MouseEvent e) { }



    //Graphics
    private JButton button1, button2, button3, button4, button5, button6, button7, button8, button9;
    private JPopupMenu contextMenu;
    private JMenuItem restartMenuItem, exitMenuItem;
    private void InitializeComponent(){
        this.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
        this.setSize(202,189);
        this.setResizable(false);
        this.setTitle("TicTacToe");
        this.setLayout(new FlowLayout(FlowLayout.CENTER,20,0));
        this.setComponentOrientation(ComponentOrientation.LEFT_TO_RIGHT);
        this.addMouseListener(this);
        this.getContentPane().add(Box.createRigidArea(new Dimension(this.getWidth(),13)));
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
            this.getContentPane().add(buttonGrid.get(i));
            if(i == 2 || i == 5) this.getContentPane().add(Box.createRigidArea(new Dimension(this.getWidth(),8)));
        }
        contextMenu = new JPopupMenu();
        restartMenuItem = new JMenuItem("Restart");
        exitMenuItem = new JMenuItem("Exit");
        restartMenuItem.addActionListener(this);
        exitMenuItem.addActionListener(this);
        contextMenu.add(restartMenuItem);
        contextMenu.add(exitMenuItem);
    }
}
