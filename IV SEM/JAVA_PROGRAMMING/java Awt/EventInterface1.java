import java.awt.*;
import java.awt.event.*;

public class EventInterface1 extends Frame implements ActionListener{
    private Label lb1Count;
    private TextField tfCount;
    private Button btnCount;
    private int count = 0;
    
    public EventInterface1() {
        FlowLayout f1 = new FlowLayout();
        setLayout(f1);
        lb1Count = new Label("counter");
        add(lb1Count);
        tfCount = new TextField("0", 10);
        tfCount.setEditable(false);
        add(tfCount);
        btnCount = new Button("count");
        add(btnCount);
        btnCount.addActionListener(this);
        setTitle("AWT COUNTER");
        setSize(250, 100);
        setVisible(true);
    }
    
    public static void main(String[] args) {
        EventInterface1 app = new EventInterface1();
    }
    
    public void actionPerformed(ActionEvent evt) {
        ++count;
        tfCount.setText(count + " ");
    }
}
