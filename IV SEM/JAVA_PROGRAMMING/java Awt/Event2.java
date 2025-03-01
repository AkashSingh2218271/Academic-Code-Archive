import java.awt.*;
import java.awt.event.*;

public class Event2 extends Frame implements ActionListener {

    private Label l1, l2, l3;
    private TextField tf1, tf2, tf3;
    private Button b1, b2, b3, b4;

    public Event2() {
        l1 = new Label("First Number");
        l2 = new Label("Second Number");
        l3 = new Label("Result");

        tf1 = new TextField("0", 10);
        tf2 = new TextField("0", 10);
        tf3 = new TextField("0", 10);

        b1 = new Button("ADD");
        b2 = new Button("SUBTRACT");
        b3 = new Button("MULTIPLY");
        b4 = new Button("DIVIDE");

        add(l1);
        add(tf1);
        add(l2);
        add(tf2);
        add(l3);
        add(tf3);
        add(b1);
        add(b2);
        add(b3);
        add(b4);

        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);

        setTitle("ADDITION, SUBTRACTION, MULTIPLICATION AND DIVISION");
        setSize(400, 400);
        setVisible(true);
        setLayout(new FlowLayout());
    }

    public static void main(String args[]) {
        Event2 app = new Event2();
    }

    public void actionPerformed(ActionEvent evt) {
        int num1, num2;
        double result;
        
        try {
            num1 = Integer.parseInt(tf1.getText());
            num2 = Integer.parseInt(tf2.getText());
        } catch (NumberFormatException e) {
            tf3.setText("Invalid input");
            return;
        }

        if (evt.getSource() == b1) {
            result = num1 + num2;
            tf3.setText(String.valueOf(result));
        } else if (evt.getSource() == b2) {
            result = num1 - num2;
            tf3.setText(String.valueOf(result));
        } else if (evt.getSource() == b3) {
            result = num1 * num2;
            tf3.setText(String.valueOf(result));
        } else if (evt.getSource() == b4) {
            if (num2 != 0) {
                result = (double) num1 / num2;
                tf3.setText(String.valueOf(result));
            } else {
                tf3.setText("Cannot divide by zero");
            }
        }
    }
}
